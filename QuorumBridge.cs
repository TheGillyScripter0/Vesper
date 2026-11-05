using System;
using System.IO;
using System.IO.Pipes;
using System.Reflection;
using System.Threading.Tasks;

class Program
{
    static object core;
    static Type coreType;

    static async Task Main()
    {
        AppDomain.CurrentDomain.AssemblyResolve += (s, a) =>
        {
            string name = new AssemblyName(a.Name).Name;
            if (name == "QuorumAPI" || name == "vesper_core")
            {
                string dir = Path.GetDirectoryName(Assembly.GetEntryAssembly().Location);
                string path = Path.Combine(dir, "vesper_core.dll");
                if (File.Exists(path)) return Assembly.LoadFrom(path);
            }
            return null;
        };

        var asm = Assembly.Load("vesper_core");
        coreType = asm.GetType("QuorumAPI.QuorumModule");
        var startComm = coreType.GetProperty("_AutoUpdateLogs", BindingFlags.Public | BindingFlags.Static);
        if (startComm != null) startComm.SetValue(null, false);

        core = Activator.CreateInstance(coreType);
        coreType.GetMethod("StartCommunication").Invoke(core, null);
        coreType.GetMethod("SetAutoAttach").Invoke(core, new object[] { true });

        while (true)
        {
            try
            {
                using (var pipe = new NamedPipeServerStream(
                    "vesper_svc", PipeDirection.InOut, 1,
                    PipeTransmissionMode.Byte, PipeOptions.Asynchronous))
                {
                    await pipe.WaitForConnectionAsync();
                    using (var r = new StreamReader(pipe))
                    using (var w = new StreamWriter(pipe) { AutoFlush = true })
                    {
                        string cmd = await r.ReadLineAsync();
                        if (string.IsNullOrEmpty(cmd)) continue;

                        if (cmd == "PING") await w.WriteLineAsync("pong");
                        else if (cmd == "ISATTACHED")
                        {
                            bool attached = (bool)coreType.GetMethod("IsAttached").Invoke(core, null);
                            await w.WriteLineAsync(attached ? "true" : "false");
                        }
                        else if (cmd == "ATTACH")
                        {
                            var task = (Task)coreType.GetMethod("AttachAPI", Type.EmptyTypes).Invoke(core, null);
                            await task.ConfigureAwait(false);
                            var resultProp = task.GetType().GetProperty("Result");
                            var result = resultProp.GetValue(task);
                            await w.WriteLineAsync(result.ToString());
                        }
                        else if (cmd == "KILL")
                        {
                            coreType.GetMethod("KillRoblox", BindingFlags.Public | BindingFlags.Static).Invoke(null, null);
                            await w.WriteLineAsync("ok");
                        }
                        else if (cmd == "EXEC")
                        {
                            string lenStr = await r.ReadLineAsync();
                            if (!int.TryParse(lenStr, out int len))
                            {
                                await w.WriteLineAsync("ERR:bad-length");
                                continue;
                            }
                            char[] buf = new char[len];
                            int total = 0;
                            while (total < len)
                            {
                                int n = await r.ReadAsync(buf, total, len - total);
                                if (n <= 0) break;
                                total += n;
                            }
                            string script = new string(buf, 0, total);
                            try
                            {
                                var result = coreType.GetMethod("ExecuteScript").Invoke(core, new object[] { script });
                                await w.WriteLineAsync("OK:" + result);
                            }
                            catch (Exception ex)
                            {
                                await w.WriteLineAsync("ERR:" + ex.Message);
                            }
                        }
                        else await w.WriteLineAsync("ERR:unknown");
                    }
                }
            }
            catch { await Task.Delay(500); }
        }
    }
}
