#pragma once
#include <cstdint>
#if defined(_WIN32)
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#ifndef REBASE
#define REBASE(x) (x + reinterpret_cast<uintptr_t>(GetModuleHandleA(0)))
#endif
#endif

#pragma once
#include <cstdint>
#include <Windows.h>

#define REBASE(addr)(addr+reinterpret_cast<uintptr_t>(GetModuleHandleA(nullptr)))

namespace Offsets
{
    namespace FLog
    {
        namespace AdContentLoaderLog
        {
            const uintptr_t DownloadingExternalVideoAdsFailedUrl=REBASE(0x10992F0);
            const uintptr_t UnexpectedCreativeAssetTypeType=REBASE(0x10986A0);
        }
        namespace AdGuiLog
        {
            const uintptr_t AdGuiLoadContentDoesMatchCurrent=REBASE(0x108BBF0);
            const uintptr_t AdGuiPreloadContentFailedAdServiceFound=REBASE(0x108B460);
        }
        namespace AdOpportunityTracker
        {
            const uintptr_t IsInstanceCurrentlyMeetingImpressionCrit=REBASE(0x1085230);
        }
        namespace AdPlayerBrowser
        {
            const uintptr_t AdPlayerGetsWebWindowRequestOpen=REBASE(0x16CCAF0);
            const uintptr_t AdPlayerLetActiveTabPostWebMessageAsStri=REBASE(0x16C8A10);
            const uintptr_t AdPlayerStep1HandleTabNavCompletedAdPlay=REBASE(0x16C7260);
            const uintptr_t AdPlayerStep1TabInitializeWebviewNavigat=REBASE(0x16C9CF0);
            const uintptr_t AdPlayerStep2AdPlayerLoadAdSetActiveCall=REBASE(0x781280);
            const uintptr_t AdPlayerStep4AdPlayerShowAdSetActiveCall=REBASE(0x7815E0);
            const uintptr_t WebView2BrowserSetWebRenderingActiveTabH=REBASE(0x16CD990);
            const uintptr_t WebView2BrowserTabContentWebViewDoesExis=REBASE(0x16C9AD0);
            const uintptr_t WebView2BrowserTabMessageReceivedSWebvie=REBASE(0x16C8140);
            const uintptr_t WebView2BrowserTabWebViewControllerDoesE=REBASE(0x16C9BE0);
            const uintptr_t WebView2BrowserWebMessageReceivedButHand=REBASE(0x16D3DC0);
        }
        namespace AdService
        {
            const uintptr_t AdServiceOnServiceProviderFailedSubmitGa=REBASE(0x1055160);
            const uintptr_t FailedFindPlayerDemandAdResult=REBASE(0x1066880);
            const uintptr_t FailedGetTranslationKey=REBASE(0x1065F10);
            const uintptr_t InvalidTeleportPlaceId=REBASE(0x1059A60);
        }
        namespace AdaptiveConfig
        {
            const uintptr_t ACSPoll200ButRecognizedBoolean=REBASE(0x5C97400);
            const uintptr_t IssuingACSPollUrlPlaceId=REBASE(0x5C95EC0);
            const uintptr_t ResponseReceivedStatusErr=REBASE(0x5C967A0);
        }
        namespace AdornRenderStats
        {
            const uintptr_t Rendering2DAdornItemsItems=REBASE(0x3F16BF0);
            const uintptr_t Rendering3DAdornItemsItems=REBASE(0x3F16CD0);
        }
        namespace AdornableLifetime
        {
            const uintptr_t AdornableCollectorDeleted=REBASE(0x3F16410);
            const uintptr_t CollectorAdding2DAdorn=REBASE(0x3F1666E);
            const uintptr_t CollectorAdding3DAdorn=REBASE(0x3F16818);
            const uintptr_t DestroyingAdornable=REBASE(0x3F162C0);
        }
        namespace AdsLifecycleManager
        {
            const uintptr_t AdsLifecycleManagerInitializeAdsSdkBlock=REBASE(0x1040290);
            const uintptr_t AdsLifecycleManagerRegisterAppFailedCrea=REBASE(0x10429C0);
            const uintptr_t AdsSDKInitializationFailed=REBASE(0x10408B0);
            const uintptr_t FurtherSDKInitializationRequiredDebuggin=REBASE(0x1040CA0);
            const uintptr_t LifecycleIDMismatchExpectedGotApplyGmaEl=REBASE(0x103F130);
            const uintptr_t LoadInterstitialAdAdUnitId=REBASE(0x103EC00);
            const uintptr_t MediaAdsEligibilityCheckTook3f=REBASE(0x103F740);
            const uintptr_t NewLocalPlayerDetectedStartingAds=REBASE(0x10423A0);
            const uintptr_t SendingMediaAdsEligibilityCheck=REBASE(0x103F4D0);
        }
        namespace AerodynamicsLogs
        {
            const uintptr_t AerodynamicMeshesProvided=REBASE(0x2E3B0D2);
            const uintptr_t BlockingRequestMeshPartMeshAeroOcclusion=REBASE(0xD8ECF0);
            const uintptr_t CreatedInterpolationBasedForceModelOcclu=REBASE(0x2E3B190);
            const uintptr_t EmptyMeshZeroAerodynamicForceModel=REBASE(0x2E3AB95);
            const uintptr_t OccludedMeshFoundReadySetMeshes=REBASE(0x2E3AA67);
            const uintptr_t ProcessingReducedMeshForceModelOccluded=REBASE(0x2E3A0F0);
            const uintptr_t SerializeTriangleCount=REBASE(0xD30F50);
            const uintptr_t SetAeroBooleanPrimitive=REBASE(0xDE05E0);
            const uintptr_t SettingEmptySerializedAeroMeshFetched=REBASE(0xD8E8C0);
        }
        namespace AgeCheck
        {
            const uintptr_t AgeCheckedRCCManagerAttemptFailedUserIdH=REBASE(0x4A47A10);
            const uintptr_t AgeCheckedRCCManagerAttemptSendingAMPReq=REBASE(0x4A471D0);
            const uintptr_t AgeCheckedRCCManagerRetrySkippedDMGone=REBASE(0x4A48660);
            const uintptr_t AgeCheckedRCCManagerRetryTimerFiredAttem=REBASE(0x4A48870);
            const uintptr_t AgeCheckedRCCManagerVerifyAndUpdateAgeCh=REBASE(0x4A46F60);
            const uintptr_t PlayerNotifyAgeCheckPassedOpFFlagEnableP=REBASE(0x3DEB860);
            const uintptr_t PlayerNotifyAgeCheckPassedSkippingReplic=REBASE(0x3DEBB02);
            const uintptr_t PlayerPromptAgeCheckThrottledLastFireSAg=REBASE(0x3DEB140);
        }
        namespace AnalyticsDeferredEphemeralReportingDiagnostic
        {
            const uintptr_t AddingStat=REBASE(0x2B80830);
            const uintptr_t ConvertingCSVBulkCounters=REBASE(0x2B83D30);
            const uintptr_t SendNowBlocking=REBASE(0x2B84650);
            const uintptr_t StartingDeferredEphemeralTimerThread=REBASE(0x2B81410);
            const uintptr_t TimerThreadImplAdjustingSessionCountTime=REBASE(0x2B815B0);
        }
        namespace AnalyticsDeferredReporterDiagnostic
        {
            const uintptr_t ExitingDeferredReporterTimerThread=REBASE(0x2B8D170);
            const uintptr_t RequestShutdownEarlyReturnBecauseAlready=REBASE(0x2B8BEB0);
            const uintptr_t SentQueuedEventsTarget=REBASE(0x2B8DBA0);
            const uintptr_t StartingDeferredReporterTimerThread=REBASE(0x2B8CFD0);
        }
        namespace AnalyticsService
        {
            const uintptr_t AnalyticsProcessorCouldnTParseInputJson=REBASE(0x3B4D590);
            const uintptr_t AnalyticsServiceFailedParseEventValueErr=REBASE(0x61E5260);
            const uintptr_t AnalyticsServiceStartingUpAnalyticsServi=REBASE(0x3B4E440);
            const uintptr_t ClassCanOnlyInitializedThroughInitialize=REBASE(0x3B4E370);
            const uintptr_t HttpRequestGetImplCallbackHttpErrCodeSta=REBASE(0x3B59D90);
            const uintptr_t HttpRequestGetImplRequestUrl=REBASE(0x3B59AE0);
            const uintptr_t HttpRequestPostImplHttpErrCodeStatusErrM=REBASE(0x3B5B9E0);
            const uintptr_t HttpRequestPostImplRequestOKUrlBodySizeB=REBASE(0x3B59730);
            const uintptr_t SendBatchEventsSentEventsBody=REBASE(0x3B5A9D0);
        }
        namespace AnimatedImage
        {
            const uintptr_t AnimatedImageParseFailed=REBASE(0x40A30F0);
            const uintptr_t AnimatedImagePrewarmFailedContentProvide=REBASE(0x4009840);
            const uintptr_t AnimatedImageServiceAddAnimatedImageClip=REBASE(0x400CF10);
            const uintptr_t AnimatedImageServiceUserCreatedTracksUnk=REBASE(0x4008370);
        }
        namespace AnimatingEverythingLog
        {
            const uintptr_t AnimationRigGetPropertyValueTypeTargetIn=REBASE(0x1980A80);
            const uintptr_t AnimationRigParseAnimatableCouldParseWir=REBASE(0x1980C60);
        }
        namespace AnimationClipProvider
        {
            const uintptr_t SerializerLoadInstances=REBASE(0x17A6B60);
        }
        namespace AnimationGraphSA
        {
            const uintptr_t AnimationGraphGraphExceedsNodesServerAut=REBASE(0x19F70E0);
            const uintptr_t PreparingServerAuthorityPredictionPredic=REBASE(0x19F5CA0);
            const uintptr_t RollbackNodeFoundAttributeSkipping=REBASE(0x19F9420);
            const uintptr_t RollbackNodeFoundIdSkipping=REBASE(0x19F97D0);
        }
        namespace AnimationStreamTrackTrace
        {
            const uintptr_t AnimationStreamTrackPlay=REBASE(0x1790D10);
            const uintptr_t AnimationStreamTrackStop=REBASE(0x1791150);
        }
        namespace AppBridge
        {
            const uintptr_t AppBridgeComponentsHaveBeenFinalized=REBASE(0x4CB1480);
            const uintptr_t EndAppBridgeCustomEmergencyStopPolicy=REBASE(0x4CB46A0);
            const uintptr_t FlipTimeStampFastStringCouldParsed=REBASE(0x624E890);
            const uintptr_t OnUserInitiatedLaunch=REBASE(0x4CB2FE0);
            const uintptr_t SignalUpdateEmergencyStatus=REBASE(0x4CB4490);
            const uintptr_t StartAppBridgeCustomEmergencyStopPolicy=REBASE(0x4CB45B0);
        }
        namespace AppBridgeWebRequest
        {
            const uintptr_t AccountSettingsEmailRequestDestructor=REBASE(0x770C30);
            const uintptr_t AccountSettingsEmailRequestLoadAsyncURL=REBASE(0x4CFD260);
            const uintptr_t AccountSettingsEmailRequestVerifiedBoolM=REBASE(0x4CFD6F0);
            const uintptr_t UserAppLaunchInfoRequestDestructor=REBASE(0x770D70);
            const uintptr_t UserAppLaunchInfoRequestResponseObject=REBASE(0x4CF3DE0);
            const uintptr_t UserRoleRequestDestructor=REBASE(0x770CD0);
            const uintptr_t UserRoleRequestLoadAsyncURL=REBASE(0x4CFBBB0);
            const uintptr_t UserRoleRequestResponseValidJsonObject=REBASE(0x4CFC040);
        }
        namespace AppConfiguration
        {
            const uintptr_t AppConfigurationFetchResponseCodeBody=REBASE(0x11E2F30);
            const uintptr_t AppConfigurationFetchUrl=REBASE(0x11E26F0);
            const uintptr_t AppConfigurationFetchWasForced=REBASE(0x11E1370);
            const uintptr_t AppConfigurationGetCachedDataStorageKeyD=REBASE(0x11DECC0);
            const uintptr_t AppConfigurationGetConfigurationByBehavi=REBASE(0x11E0070);
            const uintptr_t AppConfigurationGetConfigurationTypeUser=REBASE(0x11DF9F0);
            const uintptr_t AppConfigurationReadDeviceCacheData=REBASE(0x11DF170);
            const uintptr_t AppConfigurationReset=REBASE(0x11E09C0);
            const uintptr_t AppConfigurationResetExpires=REBASE(0x11E12E0);
            const uintptr_t AppConfigurationSetCachedDataStorageKeyD=REBASE(0x11DEFD0);
            const uintptr_t AppConfigurationUpdateConfigurationDEPRE=REBASE(0x11E2240);
            const uintptr_t AppConfigurationUpdateConfigurationTypeU=REBASE(0x11E2490);
            const uintptr_t AppConfigurationWriteDeviceCacheData=REBASE(0x11DF480);
            const uintptr_t GetUrlGotChannelBehavior=REBASE(0x11DDCD0);
        }
        namespace AppLifecycleManager
        {
            const uintptr_t AppLifecycleStateManagerUpdatingState=REBASE(0x4D94520);
        }
        namespace AppPlatformQoSEmergency
        {
            const uintptr_t AppPlatformQoSEmergencyHandlerWasDestroy=REBASE(0x4D96B90);
            const uintptr_t BackendLevelDetailEnabledBasedCookie=REBASE(0x4D96D60);
            const uintptr_t NativeHandlerFailedCancelAllActions=REBASE(0x4D97F10);
            const uintptr_t NativeHandlerFailedShowBlockingAction=REBASE(0x4D976F0);
            const uintptr_t OnUpdatedFlagsEmergencyIgnoredBecauseUse=REBASE(0x4D97380);
            const uintptr_t PlatformCouldExecuteCancelAllActions=REBASE(0x4D99E20);
            const uintptr_t PlatformCouldExecuteWarningActionBecause=REBASE(0x4D99710);
            const uintptr_t PlatformCouldOpenSystemDialog=REBASE(0x4D998C0);
        }
        namespace AppRemoteCheckStarterModule
        {
            const uintptr_t AppRemoteCheckStarterModuleFinishedStage=REBASE(0x51B3610);
        }
        namespace AppShellReporter
        {
            const uintptr_t AppShellReporterActionEnabled=REBASE(0x4D8A990);
            const uintptr_t AppShellReporterActionTaken=REBASE(0x4D8D6A0);
            const uintptr_t ConnectingFPSCounterRenderStepped=REBASE(0x4D8BFF0);
            const uintptr_t DisconnectingFPSCounterRenderStepped=REBASE(0x4D8CDC0);
            const uintptr_t FiringAppShellFeatureSwitchedSignalType=REBASE(0x30E53A0);
            const uintptr_t LuaAppMemoryCategoryUsage=REBASE(0x4D8C660);
            const uintptr_t ReportingLoadTimeTookSeconds=REBASE(0x4D8AAF0);
            const uintptr_t StartingCollectPostStatsTimer=REBASE(0x4D8C3A0);
        }
        namespace AppTracing
        {
            const uintptr_t AppTracingReportErrorFoundDoReport=REBASE(0x5CE0C30);
            const uintptr_t AppTracingReportSentClearingStartupSpan=REBASE(0x2BA6190);
            const uintptr_t TracerServiceFinishSpanSpanIdFound=REBASE(0x5CE1B90);
            const uintptr_t TracerServiceStartSpanStartupSpanCreated=REBASE(0x5CE1880);
            const uintptr_t TracingTransportSendFailedHTTPStatusCode=REBASE(0x2B7EF80);
        }
        namespace AppUpdate
        {
            const uintptr_t AppUpdateAdapterCheckForUpdateCouldnTGet=REBASE(0x4CB92C0);
            const uintptr_t AppUpdateAdapterCheckForUpdateCouldnTSet=REBASE(0x4CBF730);
            const uintptr_t AppUpdateAdapterCheckForUpdateGetUserCha=REBASE(0x4CBE5E0);
            const uintptr_t AppUpdateAdapterCheckForUpdateSkippingUp=REBASE(0x4CBC180);
            const uintptr_t AppUpdateAdapterGetLatestVersionRequestF=REBASE(0x4CBB380);
            const uintptr_t AppUpdateAdapterGetUserChannelRequestFai=REBASE(0x4CB9DB0);
            const uintptr_t AppUpdateAdapterInit=REBASE(0x4CB8490);
            const uintptr_t AppUpdateAdapterStop=REBASE(0x7547B0);
            const uintptr_t ChannelProductionUpdateChecksAreBeing=REBASE(0x4CB8B50);
            const uintptr_t CouldnTFindUpdaterPath=REBASE(0x4CB5D50);
            const uintptr_t DebugAppUpdateStatusRecognizedDefaulting=REBASE(0x4CB86B0);
            const uintptr_t GetChannelAndTokenAdapterSetReturningEmp=REBASE(0x320E2F0);
            const uintptr_t GetProtocolLaunchUpdateTypeAdapterSetRet=REBASE(0x320E0B0);
            const uintptr_t WindowsUpdateAdapterPerformManagedUpdate=REBASE(0x4CB5F00);
            const uintptr_t WindowsUpdateAdapterSetChannelPreference=REBASE(0x4CB7900);
            const uintptr_t WindowsUpdateAdapterStartBackgroundDownl=REBASE(0x4CB6A40);
        }
        namespace AppendOnlyBuffer
        {
            const uintptr_t CacheDirectoryPathEmpty=REBASE(0x2A6E1D0);
            const uintptr_t ExpectedSizeMustGreaterThanZeroAuto=REBASE(0x2A6E5F0);
            const uintptr_t FailedCloseFileRc=REBASE(0x2A6D500);
            const uintptr_t FailedCloseFileWhileExtractingFile=REBASE(0x2A6DED0);
            const uintptr_t FailedFlushFileRc=REBASE(0x2A6DB90);
            const uintptr_t FailedGetFilePosition=REBASE(0x2A6DA90);
            const uintptr_t FailedGetTemporaryDirectoryPath=REBASE(0x617D5E0);
            const uintptr_t FailedRemoveTemporaryFile=REBASE(0x2A6D6F0);
            const uintptr_t FailedWriteFile=REBASE(0x2A6D940);
            const uintptr_t FileAppendOnlyBufferFailedCreateTemporar=REBASE(0x2A6D1F0);
            const uintptr_t GrowableHeapAppendOnlyBufferFailedAlloca=REBASE(0x2A6CE60);
            const uintptr_t GrowableHeapAppendOnlyBufferFailedGrowBy=REBASE(0x2A6CC10);
            const uintptr_t GrowableHeapAppendOnlyBufferRequestedCap=REBASE(0x2A6EAB0);
        }
        namespace ApplicationFrameRate
        {
            const uintptr_t Target2fMsUserCapFPS=REBASE(0x2A68A60);
        }
        namespace AssetDeliveryProxy
        {
            const uintptr_t AssetDeliveryProxyErrorOccurredRetrievin=REBASE(0x15FE990);
            const uintptr_t AssetDeliveryProxyErrorOccurredWhilePars=REBASE(0x6128090);
            const uintptr_t AssetDeliveryProxyScheduleRestartNeedRes=REBASE(0x16000D0);
            const uintptr_t AssetDeliveryProxyStartStartingHttpServe=REBASE(0x15FFA89);
        }
        namespace AssetPreloading
        {
            const uintptr_t InvalidAssetTypeContinuing=REBASE(0x33AE080);
            const uintptr_t PreloadSuccessAssetUrlPrio=REBASE(0x33AFD60);
            const uintptr_t SignalFired=REBASE(0x33B1EC0);
            const uintptr_t StatsCacheHitCounterNotFetchedCounterFet=REBASE(0x33B12B0);
        }
        namespace AssetProvider
        {
            const uintptr_t CreatedWorkflowIdLoadAssetAssetType=REBASE(0x2698010);
            const uintptr_t CreatedWorkflowIdRefreshAsset=REBASE(0x26AFC40);
            const uintptr_t ExecutingCallbackWorkflowId=REBASE(0x1175340);
            const uintptr_t PrewarmStreamFailedStatus=REBASE(0x268A770);
            const uintptr_t UnsupportedAssetDeliveryQueryParamAsseti=REBASE(0x2681230);
        }
        namespace AssetQualityService
        {
            const uintptr_t AllUploadsCompleteDispatchingSchedule=REBASE(0x33A1810);
            const uintptr_t FetchedGltfContentOk=REBASE(0x339AA80);
            const uintptr_t FetchedSummaryContentOk=REBASE(0x3399BD0);
            const uintptr_t FetchedValidationContent=REBASE(0x33994E0);
            const uintptr_t FromModelsAsyncENTRYModelsAssetTypeIds=REBASE(0x33A43F0);
            const uintptr_t Log=REBASE(0x33A2A60);
            const uintptr_t PollErrorStatusMessage=REBASE(0x33AA100);
            const uintptr_t PollIterationTaskIdElapsedMs=REBASE(0x33970F0);
            const uintptr_t PollParsedJobStatusValidationStages=REBASE(0x3397F90);
            const uintptr_t ScheduleErrorStatusMessage=REBASE(0x339F4C0);
            const uintptr_t ScheduleGotTaskIdEnteringPollLoop=REBASE(0x339EBD0);
            const uintptr_t ScheduleRewroteEmptySettingsOptionsProto=REBASE(0x339DBF0);
            const uintptr_t UploadErrorStatusMessage=REBASE(0x33AA470);
            const uintptr_t UploadOKContentUrl=REBASE(0x33A6480);
            const uintptr_t UploadRbxmRbxmBytesUrl=REBASE(0x339C430);
            const uintptr_t UploadResponseMissingContentUrlStoreHash=REBASE(0x339CEF0);
            const uintptr_t VisualizationMeshFaceReferencesOutBounds=REBASE(0x338B690);
            const uintptr_t VisualizationMeshTruncatedTrianglesExcee=REBASE(0x61B6040);
        }
        namespace AssetReadLogger
        {
            const uintptr_t AssetReadBeforeStartupQueueingLater=REBASE(0x3A68750);
            const uintptr_t AssetReadLoggerAssetPathRawStageIsFirstR=REBASE(0x3A68D60);
        }
        namespace AssetReader
        {
            const uintptr_t AssetRelativePathBasePath=REBASE(0x3A652E0);
            const uintptr_t SetBasePathSetBasePath=REBASE(0x3A662C0);
        }
        namespace AssetRequestTrace
        {
            const uintptr_t FailedBatchAssetApiURLValidityCheck=REBASE(0x11D8320);
        }
        namespace AssetUpdateNotificationSubscriber
        {
            const uintptr_t AssetUpdateCSMSubscriptionFailed=REBASE(0x3340210);
        }
        namespace AssetsManifestManager
        {
            const uintptr_t CheckingExistenceOTAAssetsManifestOTA=REBASE(0x15CB720);
            const uintptr_t ReadingOTAAssetsManifestOTAConfig=REBASE(0x15E4B10);
            const uintptr_t ValidAssetsManifestSaveOTAConfig=REBASE(0x15E47C0);
        }
        namespace AssetsUploadApiFlow
        {
            const uintptr_t AssetIdModerationStatusPollingMissing=REBASE(0x3548060);
            const uintptr_t AssetIdModerationStatusPollingReached=REBASE(0x3547C80);
            const uintptr_t AssetsUploadFailedOperationIdAssetIdAsse=REBASE(0x35494B0);
            const uintptr_t AssetsUploadSucceededAssetIdVersionNumbe=REBASE(0x35492A0);
            const uintptr_t OperationIdUploadUrlModelInvalidAddition=REBASE(0x3BAE700);
        }
        namespace AsyncCodecTrace
        {
            const uintptr_t ERRORDroppingFrameCurrentPtsMs=REBASE(0x3CD6F50);
            const uintptr_t SetKPlayerStateBuffering2=REBASE(0x3CCBD00);
            const uintptr_t WebmReadPacketReturnFrameIndex=REBASE(0x1E1EFB0);
        }
        namespace AsyncCodecTraceVerbose
        {
            const uintptr_t RvCodecStepPopDecoderPts=REBASE(0x1E1B130);
            const uintptr_t RvCodecStepPopEncoderPts=REBASE(0x1E1B260);
        }
        namespace AsyncHttpQueue
        {
            const uintptr_t FillMemoryCacheURLFormat=REBASE(0x111C120);
            const uintptr_t FoundUrlFailedListCodeMsg=REBASE(0x11D2FF0);
        }
        namespace AtomicCacheWrite
        {
            const uintptr_t FailedRename=REBASE(0x15E3950);
        }
        namespace Audio
        {
            const uintptr_t FMODThreadPrioritySetFailed=REBASE(0x2897900);
            const uintptr_t FailedRestartSharedRecordingDeviceIndex=REBASE(0x28A0A60);
            const uintptr_t OnRecordListChanged=REBASE(0x28A3E60);
            const uintptr_t OutputDevice=REBASE(0x289B1D0);
            const uintptr_t RecordingBufferUnderrunDeltaTime=REBASE(0x28B73C8);
            const uintptr_t RecordingBufferUnderrunStopped=REBASE(0x28B74E6);
            const uintptr_t RecordingStoppedShared=REBASE(0x28A2D20);
            const uintptr_t SharedFmodRecordingFailedStartRecordingD=REBASE(0x28B31B0);
            const uintptr_t SharedFmodRecordingFormatMismatchDriverE=REBASE(0x28B2820);
            const uintptr_t SharedFmodRecordingStoppedDriver=REBASE(0x28B3660);
            const uintptr_t SharedFmodRecordingUpdateFailedRequestin=REBASE(0x28A0D80);
        }
        namespace AudioDeviceInputLog
        {
            const uintptr_t AttachDspAudioInputProcessor=REBASE(0x45A3510);
            const uintptr_t AttachOutputReferenceSink=REBASE(0x45A50E0);
            const uintptr_t DestroyAudioProcessing=REBASE(0x45A56D0);
            const uintptr_t DetachDspAudioInputProcessor=REBASE(0x45A4A3D);
            const uintptr_t ParticipantSelfRecorderLocalOnlyCapture=REBASE(0x45A3E50);
            const uintptr_t ParticipantSubscriberCalling=REBASE(0x45A3BA0);
        }
        namespace AudioFocusManager
        {
            const uintptr_t AudioFocusManagerAudioFocusManagerConstr=REBASE(0x5D0EC60);
            const uintptr_t AudioFocusManagerAudioFocusManagerDestru=REBASE(0x5D0EEE0);
        }
        namespace AudioFocusService
        {
            const uintptr_t AudioFocusServiceAudioFocusServiceConstr=REBASE(0x5D0DBE0);
            const uintptr_t AudioFocusServiceAudioFocusServiceDestru=REBASE(0x5D0DE20);
            const uintptr_t AudioFocusServiceAudioFocusServiceUnregi=REBASE(0x5D0DFD0);
        }
        namespace AudioInputProcessorTrace
        {
            const uintptr_t Activating=REBASE(0x19B0430);
            const uintptr_t ConnectedAudioInputViaFmod=REBASE(0x19BAF90);
            const uintptr_t Deactivating=REBASE(0x19B05C0);
            const uintptr_t FmodClose=REBASE(0x19BAE30);
            const uintptr_t FmodOpenFailedInitializeDsp=REBASE(0x19BA900);
            const uintptr_t InputCaptureAudioSinkAvailableConnecting=REBASE(0x19BC780);
            const uintptr_t RemovingCallbackAudioNode=REBASE(0x19BCC00);
            const uintptr_t StartProcessingAudioInput=REBASE(0x19B08F0);
            const uintptr_t StopProcessingAudioInput=REBASE(0x19B10B0);
        }
        namespace AudioSpeechToTextLog
        {
            const uintptr_t AudioSpeechToTextSoundServiceFound=REBASE(0x4577350);
            const uintptr_t DiagnosticAudioRequestSelected=REBASE(0x45EDB50);
            const uintptr_t DiagnosticAudioSessionEligible=REBASE(0x45ED720);
            const uintptr_t EncodedAudioPointerNullAfterCall=REBASE(0x4578B50);
            const uintptr_t STTSeqResponseIDCanceled=REBASE(0x457A4C0);
            const uintptr_t STTSeqResponseIDPushedInto=REBASE(0x457A350);
            const uintptr_t STTSeqResponseIDReceivedText=REBASE(0x457A710);
            const uintptr_t SendDataVAD=REBASE(0x4576320);
        }
        namespace AuroraInputLogging
        {
            const uintptr_t ClientDroppingActionStateChangeAction=REBASE(0x40CB490);
            const uintptr_t ClientFailedWriteEvenSingleFrame=REBASE(0x478C420);
            const uintptr_t InputActionTypeNoneAction=REBASE(0x478B980);
            const uintptr_t ServerControlStateFieldSizeExceedsRemain=REBASE(0x4790C40);
            const uintptr_t ServerDroppingMisalignedControlStateEntr=REBASE(0x478FD40);
            const uintptr_t ServerMultipleStatesReceivedAction=REBASE(0x478DB60);
            const uintptr_t ServerPeerApplyingActionsStepPredicted=REBASE(0x40D28C0);
            const uintptr_t ServerPeerRemovedInputBuffer=REBASE(0x40C3F40);
            const uintptr_t ServerPeerUpdateInputOffsetInputFrameCli=REBASE(0x40D0C20);
            const uintptr_t ServerSmoothStepOffsetUpwardsLockResultC=REBASE(0x40D373A);
            const uintptr_t ServerUnexpectedScratchVersion=REBASE(0x4790FC0);
        }
        namespace AuroraReplication
        {
            const uintptr_t ClientReceivedPropertyLocalTimeRemoteTim=REBASE(0x46E10A0);
        }
        namespace AuroraRollback
        {
            const uintptr_t ClientReceivedDataFromReplicatorRemoteTi=REBASE(0x33BB120);
            const uintptr_t InstancePredicted=REBASE(0x33BAEC0);
            const uintptr_t NowResimulatingDelta=REBASE(0x33C2060);
            const uintptr_t ScriptsUnableRollbackWorldstepLanded=REBASE(0x33C0F10);
        }
        namespace AuroraScript
        {
            const uintptr_t AuroraScriptUpdateFixedStepAligned=REBASE(0x422A1E0);
            const uintptr_t InstanceNetAttributeSchemaChangedSignalW=REBASE(0x422AF40);
            const uintptr_t NumberFieldsMoreThanNumberSynchronized=REBASE(0x4229260);
            const uintptr_t ObjectReceivedMessagePredictedSourceRunn=REBASE(0x4232BF0);
            const uintptr_t RollingObjectBackBecauseReceivedMessage=REBASE(0x42250A0);
            const uintptr_t ThrowingAwayMessagesResimulatedTouchEven=REBASE(0x42330E0);
            const uintptr_t ThrowingAwayMessagesWhenEnqueuingUnpredi=REBASE(0x4226CC0);
        }
        namespace AuroraScriptAPI
        {
            const uintptr_t SafeUseAuroraScriptsMayCauseMispredictio=REBASE(0x41AC7F0);
        }
        namespace AuroraScriptRollback
        {
            const uintptr_t ClientRelativeServerSteps=REBASE(0x421C9C0);
            const uintptr_t ERRORSomeObjectsWereAbleRolled=REBASE(0x4216BC0);
            const uintptr_t RollingBackUnalignedWorldstepIdMoreLikel=REBASE(0x42165F0);
            const uintptr_t UnableRunWorldStepIdBecauseWorldStep=REBASE(0x4217920);
        }
        namespace AuroraScriptService
        {
            const uintptr_t BehaviorWasAlreadyBoundInstance=REBASE(0x421CC00);
            const uintptr_t BehaviorWasBoundInstance=REBASE(0x421DE30);
            const uintptr_t OverwritingDuplicateAuroraScript=REBASE(0x4218C40);
            const uintptr_t TryingAccessBehaviorButSService=REBASE(0x4218910);
            const uintptr_t TryingAccessBehaviorGUIDButS=REBASE(0x42180C0);
        }
        namespace AvatarAutoSetup
        {
            const uintptr_t AvatarAutoSetupBaseJobPollingResponse=REBASE(0x1C23FB0);
            const uintptr_t AvatarAutoSetupBaseJobSaveResultSuccessf=REBASE(0x1C22C80);
            const uintptr_t AvatarAutoSetupCreateJobReceivedInvalidJ=REBASE(0x1C235E0);
            const uintptr_t AvatarAutoSetupDownloadResultError=REBASE(0x1C26100);
            const uintptr_t AvatarAutoSetupUploadModelError=REBASE(0x1BEDC50);
            const uintptr_t AvatarAutoSetupUploadModelUploadedSucces=REBASE(0x1BEC860);
            const uintptr_t CancelJobFailed=REBASE(0x1C25E10);
            const uintptr_t FailedDeleteAutoSetupResultError=REBASE(0x1C23100);
            const uintptr_t FailedPollJobStatus=REBASE(0x1C24880);
            const uintptr_t HandleJobDone=REBASE(0x1C24AC0);
            const uintptr_t JobCompletedSuccessfullyIDGenerationId=REBASE(0x1C22690);
        }
        namespace AvatarChangeTelemetry
        {
            const uintptr_t HeartbeatFiredAfter1fSInterval=REBASE(0x5317E70);
            const uintptr_t UserIdSkippedUniverseIdAllowList=REBASE(0x5317040);
        }
        namespace AvatarChatServiceTrace
        {
            const uintptr_t AvatarChatServiceAvatarChatServiceConstr=REBASE(0x1948D50);
            const uintptr_t AvatarChatServiceAvatarChatServiceDestru=REBASE(0x1949150);
            const uintptr_t AvatarChatServiceFetchUserPermissionsInv=REBASE(0x194B930);
            const uintptr_t AvatarChatServiceLuaEnableVoiceCalledEna=REBASE(0x194A540);
            const uintptr_t AvatarChatServiceOnServiceProviderInvoke=REBASE(0x1949360);
            const uintptr_t AvatarChatServicePostEnableUserVoiceReso=REBASE(0x194B3D0);
            const uintptr_t AvatarChatServiceSetClientFeaturesInvoke=REBASE(0x194F290);
            const uintptr_t AvatarChatServiceSetServerFeaturesInvoke=REBASE(0x194ACF0);
            const uintptr_t AvatarChatServiceUpdateSubsessionStatsPl=REBASE(0x194BCA0);
            const uintptr_t ClearingCacheUser=REBASE(0x1949CE0);
        }
        namespace AvatarChatSubsessionAnalyticsV3Trace
        {
            const uintptr_t CameraOn=REBASE(0x191F3D0);
            const uintptr_t LastSendRecvStateHhuCurrentStateHhu=REBASE(0x191F160);
            const uintptr_t MicOn=REBASE(0x191F5B0);
            const uintptr_t UpdateTrackerModeMode=REBASE(0x19ACCE0);
        }
        namespace AvatarCreation
        {
            const uintptr_t AvatarCreationSubmitFailedStatus=REBASE(0x1C1BEC0);
            const uintptr_t FailedDeleteAutoSetupResultError=REBASE(0x1BE5E50);
            const uintptr_t FailedDownloadContentStatus=REBASE(0x1BE67F0);
            const uintptr_t FailedPollJobStatus=REBASE(0x1C1CAF0);
            const uintptr_t HandleJobDone2D=REBASE(0x1BE0A10);
            const uintptr_t HandleJobDone3D=REBASE(0x1BE7C30);
            const uintptr_t JobFailedIDError=REBASE(0x1C1B410);
            const uintptr_t PollingJobJobType=REBASE(0x1C1D5F0);
        }
        namespace AvatarJoinMetrics
        {
            const uintptr_t AllSurfaceAppearancesLoadedLocalHumanoid=REBASE(0x52FF260);
            const uintptr_t CameraDirection=REBASE(0x53030BC);
            const uintptr_t FCEndedHumanoid=REBASE(0x5304C40);
            const uintptr_t FCStartedHumanoid=REBASE(0x53044A0);
            const uintptr_t TCEndedHumanoid=REBASE(0x5303D80);
            const uintptr_t TCStartedHumanoid=REBASE(0x5303760);
            const uintptr_t TotalClientAssetRequestTime=REBASE(0x530234E);
        }
        namespace AvatarMemoryTracker
        {
            const uintptr_t AvatarMemoryTrackerAliveWhenSynchronizin=REBASE(0x3AAD240);
            const uintptr_t DereferenceMeshXTotalReferencers=REBASE(0x3AB1333);
            const uintptr_t DereferenceTextureXTotalReferencers=REBASE(0x3AB5DC5);
            const uintptr_t InvalidateHumanoid=REBASE(0x39AFD50);
            const uintptr_t TrackHumanoidRole=REBASE(0x3AACAC0);
            const uintptr_t TrackMeshXBodyPart=REBASE(0x3AB2D70);
            const uintptr_t TrackMeshXFileMesh=REBASE(0x3AB2B50);
            const uintptr_t TrackMeshXHead=REBASE(0x3AB3010);
            const uintptr_t TrackTextureXDecal=REBASE(0x3AB6AC0);
            const uintptr_t TrackTextureXEditableImage=REBASE(0x3AB6CE0);
            const uintptr_t TrackTextureXFileMesh=REBASE(0x3AB7490);
            const uintptr_t TrackTextureXMaterialVariant=REBASE(0x3AB7900);
            const uintptr_t TrackTextureXMeshPart=REBASE(0x3AB76B0);
            const uintptr_t TrackTextureXSurfaceAppearance=REBASE(0x3AB7270);
            const uintptr_t TrackTextureXTextureComposition=REBASE(0x3AB7000);
            const uintptr_t UntrackMeshX=REBASE(0x3AB148D);
            const uintptr_t UntrackTextureX=REBASE(0x3AB5F04);
        }
        namespace AvatarSettings
        {
            const uintptr_t AvatarSettingsDiscardServerCanOnlyCalled=REBASE(0x192CD10);
            const uintptr_t AvatarSettingsDiscardServerError=REBASE(0x192D130);
            const uintptr_t AvatarSettingsDoInitialDefaultAvatarRule=REBASE(0x192A5B0);
            const uintptr_t AvatarSettingsOnUniverseConfigurationLoa=REBASE(0x1931C10);
            const uintptr_t AvatarSettingsPublishRequestBody=REBASE(0x192C070);
            const uintptr_t AvatarSettingsRelayRefreshPluginStateDro=REBASE(0x192A455);
        }
        namespace BackPressureThrottling
        {
            const uintptr_t SuccessfulRequestUrlRemovingEntryEndpoin=REBASE(0x2CB0E10);
        }
        namespace BackendAdsProviderLog
        {
            const uintptr_t AdsAPICommunicationFailed=REBASE(0x10354E0);
        }
        namespace BacktraceReporter
        {
            const uintptr_t BacktraceSubmissionRequestBody=REBASE(0x5CA4BD0);
            const uintptr_t FileUploadReturnedErrorCodeBody=REBASE(0x5CA8150);
            const uintptr_t MainThreadCannotEmptyNullMustKey=REBASE(0x5CA3510);
        }
        namespace BadgeService
        {
            const uintptr_t CheckUserBadgesAsyncGotBadgeAwardEntries=REBASE(0x3202400);
            const uintptr_t CheckUserBadgesAsyncProvidedBadgeIdTypeN=REBASE(0x31FF640);
            const uintptr_t GetUserBadgesAsyncFailedParseAwardedDate=REBASE(0x31FB510);
            const uintptr_t GetUserBadgesAsyncProvidedBadgeIdTypeNum=REBASE(0x3200720);
            const uintptr_t ResponseJsonObject=REBASE(0x32059E0);
            const uintptr_t UserHasBadgeAsyncDataModelNull=REBASE(0x31FE520);
            const uintptr_t UserHasBadgeAsyncResponseBadgeIdDoesMatc=REBASE(0x31FEEA0);
        }
        namespace BandwidthTracker
        {
            const uintptr_t BandwidthStabilizedMbpsDownloadedTotalBy=REBASE(0x2A6F270);
            const uintptr_t ErrorReadingCacheFileMagicNumber=REBASE(0x2A70040);
            const uintptr_t ErrorWritingBwDataRecordCacheFile=REBASE(0x2A6FB50);
            const uintptr_t FoundBwDataRecordMyNetworkIdCacheIndexBw=REBASE(0x2A70F90);
            const uintptr_t GotNetworkId=REBASE(0x2A6F810);
        }
        namespace BaseExperienceController
        {
            const uintptr_t BaseExperienceControllerBaseExperienceCo=REBASE(0x4D8DA30);
        }
        namespace BaseUrlProtocol
        {
            const uintptr_t CurrentBaseHostTargetBaseHost=REBASE(0x44F42F0);
            const uintptr_t FinishedSettingUpLinkingProtocolHandler=REBASE(0x44F2840);
            const uintptr_t ReceivingDeepLinkingMessageMatchedURL=REBASE(0x44F2F30);
            const uintptr_t TargetBaseURLRestartAppApply=REBASE(0x44F3250);
        }
        namespace BatchAssetApiLog
        {
            const uintptr_t BatchAssetApiCreated=REBASE(0x10E8A70);
            const uintptr_t BatchAssetApiDeleted=REBASE(0x10E8DF0);
            const uintptr_t InvalidAssetQueryParameter=REBASE(0x10E7AC0);
        }
        namespace BenchmarkCapture
        {
            const uintptr_t MoreThanDataModelsRegisteredSessionAddit=REBASE(0x4B00810);
        }
        namespace BrowserServiceDiagnose
        {
            const uintptr_t BrowserServiceDiagnoseApplicationCloseBr=REBASE(0x75D0B0);
            const uintptr_t BrowserServiceDiagnoseApplicationDoClose=REBASE(0x75CDD0);
            const uintptr_t BrowserServiceDiagnoseApplicationDoOpenU=REBASE(0x75BA60);
            const uintptr_t BrowserServiceDiagnoseApplicationExecute=REBASE(0x76D3A0);
            const uintptr_t BrowserServiceDiagnoseApplicationProcess=REBASE(0x75C140);
            const uintptr_t BrowserServiceDiagnoseBrowserServiceClos=REBASE(0x2F7BC10);
            const uintptr_t BrowserServiceDiagnoseBrowserServiceEmit=REBASE(0x2F7C820);
            const uintptr_t BrowserServiceDiagnoseBrowserServiceOnSe=REBASE(0x2F7A390);
            const uintptr_t BrowserServiceDiagnoseBrowserServiceRetu=REBASE(0x2F7C3F0);
            const uintptr_t BrowserServiceDiagnoseCanFindSvcVersionL=REBASE(0x16BEB40);
        }
        namespace BtidUtil
        {
            const uintptr_t BrowserTrackerIdRequestRBXEventTrackerV2=REBASE(0x4CB4E00);
            const uintptr_t CookieBTIDSameWebBTIDPassed=REBASE(0x4CB5310);
            const uintptr_t ErrorConvertingBTIDStringNumberInput=REBASE(0x624E960);
        }
        namespace BufferPool
        {
            const uintptr_t Buffer0xRecycled=REBASE(0x37E3280);
            const uintptr_t Buffer0xRequestFoundMatchSize=REBASE(0x37E2F40);
        }
        namespace CDEC
        {
            const uintptr_t FailedConvertConvexDecompositionIntoCSGC=REBASE(0x2B6A0C0);
            const uintptr_t MaxIterationsExceededMixedSignEdgesSize=REBASE(0x2B73F70);
        }
        namespace CSG3Details
        {
            const uintptr_t CSG3AssetFetchContinuatorAllJoinedError=REBASE(0x5114F50);
            const uintptr_t CSG3AssetFetchContinuatorErrorCallingCom=REBASE(0x5115C80);
            const uintptr_t CSGAPIEmptyResult=REBASE(0xCF0DB0);
            const uintptr_t CsgfloatInitCSGEPSILONCSGSPLITTER=REBASE(0x410D660);
            const uintptr_t GetCSG3PrimitiveTypeSpecialShapeUnknownT=REBASE(0x50E9170);
            const uintptr_t InstanceTransformPartInstanceScale=REBASE(0x50E9AC0);
            const uintptr_t InstanceTransformPartOperationScale=REBASE(0x50E93D0);
            const uintptr_t SolidModelingAPIEmptyResult=REBASE(0x510CFD0);
            const uintptr_t SolidModelingAPIError=REBASE(0x510CDE0);
        }
        namespace CSG3Errors
        {
            const uintptr_t CSGAPIBadMesh=REBASE(0x50D9B60);
            const uintptr_t CSGExceptionCompute=REBASE(0x625D800);
            const uintptr_t CSGManifoldException=REBASE(0x625C900);
            const uintptr_t CSGOperations3UnableCombineSelectionInva=REBASE(0x5103780);
            const uintptr_t CSGOperationsDumpCSGV3DCDSerializeFailed=REBASE(0x50CA8E0);
            const uintptr_t CsgfloatInitIterationsExhaustedWhileCalc=REBASE(0x410D1F8);
            const uintptr_t DCDRecomputeTaskSilentlyFailedRecomputeP=REBASE(0x50D3A70);
            const uintptr_t DCDStageHasRecomputePromise=REBASE(0x50D7130);
            const uintptr_t InstanceTransformUnsupportedPrimitiveTyp=REBASE(0x50E97DB);
        }
        namespace CSGErrors
        {
            const uintptr_t TaskSerializeException=REBASE(0x625D970);
            const uintptr_t UnknownCSG4Operation=REBASE(0x5111580);
            const uintptr_t UnknownTaskPartType=REBASE(0x51148A0);
        }
        namespace CallLegStatusesParse
        {
            const uintptr_t ParseCallLegStatusesCallLegsExceedsCapDr=REBASE(0x4E9CBC0);
        }
        namespace CallManager
        {
            const uintptr_t CallManagerAcceptedCallBeingCancelled=REBASE(0x5C12CA0);
            const uintptr_t CallManagerAcceptedCallBeingRejected=REBASE(0x5C12990);
            const uintptr_t CallManagerBadTransitCallState=REBASE(0x5C11720);
            const uintptr_t CallManagerReceivedCallWhileOne=REBASE(0x5C09E00);
            const uintptr_t CallManagerRequestAcceptCallFailed=REBASE(0x5C128B0);
            const uintptr_t CallManagerRequestFinishCallFailed=REBASE(0x5C12BC0);
            const uintptr_t CallManagerRequestUpdateCallDetails=REBASE(0x5C12ED0);
        }
        namespace Calling
        {
            const uintptr_t CallBackendEndLegRequestFailed=REBASE(0x4E9A430);
        }
        namespace CallingCore
        {
            const uintptr_t BroadcastRemoved=REBASE(0x4E89B70);
            const uintptr_t BroadcastState=REBASE(0x4E89800);
            const uintptr_t HandleCreateCallOutgoingCallParticipantS=REBASE(0x4E8A1F0);
            const uintptr_t HandleEndCallReason=REBASE(0x4E8A450);
            const uintptr_t HandleReceiveIncomingCallIncomingVoIPPus=REBASE(0x4E89DB0);
        }
        namespace CallingLegClient
        {
            const uintptr_t BrowserTrackerIdUnavailableValueSendingD=REBASE(0x4E92100);
            const uintptr_t CreateCallSucceededStatusButResponseHad=REBASE(0x4E914C0);
            const uintptr_t RequestFailedErrStatusBody=REBASE(0x4E90F00);
        }
        namespace CallingManager
        {
            const uintptr_t AnswerCallSuchCallIgnoring=REBASE(0x4E89F50);
            const uintptr_t CallInstanceUpdateDroppedManagerAlreadyT=REBASE(0x4E908C0);
            const uintptr_t CallInstanceUpdateUnknownCallMirroringEN=REBASE(0x4E8C9E0);
            const uintptr_t CreateCallCreateAlreadyPendingRejecting=REBASE(0x4E8E590);
            const uintptr_t CreateCallResponseLongerPendingCreateIgn=REBASE(0x4E8ED30);
            const uintptr_t EndCallReasonRecognizedIgnoring=REBASE(0x4E8FD40);
            const uintptr_t ReceiveIncomingCallPayloadHadCallIdChann=REBASE(0x4E8D650);
        }
        namespace CameraTrace
        {
            const uintptr_t CameraCaptureClose=REBASE(0x5A20160);
            const uintptr_t CameraCaptureOpenGetBestCapabilitiesCall=REBASE(0x5A20590);
            const uintptr_t CameraCapturePause=REBASE(0x5A20940);
            const uintptr_t CameraCapturePlay=REBASE(0x5A20370);
            const uintptr_t InvalidIAMCameraControlInterfaceUnableSe=REBASE(0x5A1E9C0);
            const uintptr_t UnableGetYUVBufferVideoStream=REBASE(0x5A1EB90);
        }
        namespace CaptureEngine
        {
            const uintptr_t CleanUp=REBASE(0x3D0AA20);
            const uintptr_t CreateAudioCodecPar=REBASE(0x3D04530);
            const uintptr_t CreateCallbackDsp=REBASE(0x3D07D00);
            const uintptr_t CreateEncoderAsync=REBASE(0x3D05950);
            const uintptr_t CreateEncoderDEPRECATED=REBASE(0x3D047D0);
            const uintptr_t CreateStrand=REBASE(0x3D0A2A0);
            const uintptr_t CreatingMuxerContainerFormat=REBASE(0x3D06240);
            const uintptr_t CreatingTextureSoftwareGraphicBufferCapt=REBASE(0x3D10DD0);
            const uintptr_t DetachAudioOutputNode=REBASE(0x3D08590);
            const uintptr_t DroppedFramesSeconds=REBASE(0x3D125F0);
            const uintptr_t DroppingAudioFrameDueFullAudio=REBASE(0x3D06D20);
            const uintptr_t DroppingAudioFrameNegativePTS=REBASE(0x3D08D50);
            const uintptr_t EncoderInitializationCancelled=REBASE(0x3D05CA0);
            const uintptr_t EnoughMemoryStartVideoCaptureAvailable=REBASE(0x3CFF010);
            const uintptr_t FailedCreateDownloadBufferRenderBuffer=REBASE(0x3CC3220);
            const uintptr_t FailedRenameMCPCaptureDue=REBASE(0x3D0D1A0);
            const uintptr_t FailedStartVideoCapture=REBASE(0x3D09DC0);
            const uintptr_t FailedWritePacketMuxerError=REBASE(0x3D093D0);
            const uintptr_t GotContiguousViewBufferIndexWidth=REBASE(0x3CC2B40);
            const uintptr_t GraphicBufferSourceCreatedDimensionsXFps=REBASE(0x3CC12B0);
            const uintptr_t InvalidConfigurationSnapshotRangeSkippin=REBASE(0x3CC11C8);
            const uintptr_t OnStoppedEmptyWhenFinalizingVideo=REBASE(0x3D03810);
            const uintptr_t SelectedVideoCodecId=REBASE(0x3D03FF0);
            const uintptr_t SendEofVideoEncoder=REBASE(0x3D08A20);
            const uintptr_t SomethingWentWrongDuringVideoCapture=REBASE(0x3D09F90);
            const uintptr_t SoundServiceNullCannotAttachAudioOutput=REBASE(0x3D08150);
            const uintptr_t StartProcessing=REBASE(0x3D0A760);
            const uintptr_t StartingAsyncDownloadTextureDownloadBuff=REBASE(0x3CC369D);
            const uintptr_t StateAdvanceFailed=REBASE(0x3CC16C0);
            const uintptr_t StateUpdate=REBASE(0x3CC1590);
            const uintptr_t StopInternal=REBASE(0x3D00D20);
            const uintptr_t StoppingGraphicBufferSource=REBASE(0x3CC18B0);
            const uintptr_t UpdatePresentationTime=REBASE(0x3D0B1D0);
            const uintptr_t VideoCaptureEngineInitializeEngineStateI=REBASE(0x3D0F660);
        }
        namespace CaptureService
        {
            const uintptr_t CaptureUploadSuccessfulAssetId=REBASE(0x3FE23B0);
            const uintptr_t CheckingGPUAgainstBlacklistAllCaptures=REBASE(0x3FDC9E0);
            const uintptr_t CheckingGPUAgainstGraphicsAPIBlacklist=REBASE(0x3FC4590);
            const uintptr_t CleanupVideoCapture=REBASE(0x3FC30E0);
            const uintptr_t DevCaptureParamsOverridenScriptUI=REBASE(0x3FB9230);
            const uintptr_t ErrorRetrievingCapture=REBASE(0x62071C0);
            const uintptr_t FailedFinalizeScreenshotCaptureDataModel=REBASE(0x3FBC620);
            const uintptr_t FailedReadScreenshotCaptureDataPath=REBASE(0x3089160);
            const uintptr_t FailedRemoveSelfTestFile=REBASE(0x3FC3DC0);
            const uintptr_t FailedStoreVideoError=REBASE(0x62066B0);
            const uintptr_t GrantExperiencePermissionsAssetIdUnivers=REBASE(0x3FDFCE0);
            const uintptr_t LoadSelfTestResult=REBASE(0x3FB53C0);
            const uintptr_t OnServiceProvider=REBASE(0x3FB5910);
            const uintptr_t OnStartedVideoCaptureStartedResult=REBASE(0x3FF2E60);
            const uintptr_t SaveCapturesToExternalStorageAsyncCaptur=REBASE(0x3FCE580);
            const uintptr_t SaveSelfTestResult=REBASE(0x3FB4DA0);
            const uintptr_t StartTestCaptureCouldQueryDiskSpaceProce=REBASE(0x3FC2C70);
            const uintptr_t StartUploadCaptureAsyncError=REBASE(0x3FFCE40);
            const uintptr_t StartUploadCaptureAsyncErrorPollingAsset=REBASE(0x3FE6790);
            const uintptr_t StopVideoCaptureInternalInternal=REBASE(0x3FC62B0);
            const uintptr_t UploadCaptureAndPostMomentError=REBASE(0x3FEBE90);
            const uintptr_t UploadCaptureAndPostMomentErrorPollingAs=REBASE(0x3FEBFA0);
            const uintptr_t UploadCaptureAsyncError=REBASE(0x3FFC5C0);
            const uintptr_t UploadCaptureAsyncErrorFetchingAssetId=REBASE(0x3FFB860);
            const uintptr_t UploadCaptureAsyncErrorPollingAssetIdOpe=REBASE(0x3FE2A90);
            const uintptr_t UploadCaptureAsyncErrorUploadingAssetFet=REBASE(0x3FE2E30);
            const uintptr_t UploadPostAsyncError=REBASE(0x3FED370);
            const uintptr_t UploadingScreenshotCaptureSignature=REBASE(0x3FE42D0);
            const uintptr_t VideoCaptureTimerJobStepDataModelJobWall=REBASE(0x3FB4090);
            const uintptr_t VideoF12CaptureWritePermissionTest=REBASE(0x6207730);
        }
        namespace CaptureStorage
        {
            const uintptr_t AttemptRemoveMetadataIndexNonExistent=REBASE(0x3EAC270);
            const uintptr_t BeforeCleanup=REBASE(0x3EB1D50);
            const uintptr_t CannotAddMetadataIndexCaptureInvalid=REBASE(0x3EABBD0);
            const uintptr_t CannotUpdateMetadataIndexCaptureEmpty=REBASE(0x3EACAB0);
            const uintptr_t DeserializedVideoKeyThumbnailKeySignatur=REBASE(0x3EDF870);
            const uintptr_t FailedCreateDirectories=REBASE(0x3EAEE40);
            const uintptr_t FailedCreateUserDirectory=REBASE(0x61FED10);
            const uintptr_t FailedDeserializeVideoCapture=REBASE(0x61FEE00);
            const uintptr_t FailedParseCaptureKeyIndexKey=REBASE(0x61FE920);
            const uintptr_t FailedParseCaptureTypeIndexKey=REBASE(0x61FE780);
            const uintptr_t FailedParseCreationTimestampIndexKey=REBASE(0x61FE850);
            const uintptr_t FailedRemoveTempDirectoryDue=REBASE(0x3EADBF0);
            const uintptr_t MetadataEmptyCannotUpdateVideoCapture=REBASE(0x3EB0CC0);
            const uintptr_t ParsedEmptyCaptureKeyIndexKey=REBASE(0x3EAB1E0);
            const uintptr_t ParsedEmptyMetadataKeyIndexKey=REBASE(0x3EAB490);
            const uintptr_t ParsedInvalidCaptureTypeIndexKey=REBASE(0x3EAAF20);
            const uintptr_t ParsedInvalidCreationTimestampIndexKey=REBASE(0x3EAB090);
            const uintptr_t RbxStorageInitializedCannotAccessStorage=REBASE(0x3EAF2A0);
            const uintptr_t SerializingVideoKeyThumbnailKeySignature=REBASE(0x3EDEE40);
        }
        namespace ChangeHistoryPerformance
        {
            const uintptr_t ChangeHistoryServiceAttachedMsDataSizeMB=REBASE(0x31EEF20);
            const uintptr_t DetachingChangeHistoryServiceDataSizeMBW=REBASE(0x31EE960);
            const uintptr_t FinishedClearingWaypoints=REBASE(0x31EE650);
            const uintptr_t RecordCreationTookMsVisitDescendants=REBASE(0x31EFC80);
        }
        namespace ChangeMouseCommand
        {
            const uintptr_t RejectingNewMouseCommandBecauseActive=REBASE(0x3409670);
            const uintptr_t SettingMouseCommandDefault=REBASE(0x3409060);
            const uintptr_t SettingMouseCommandNullTool=REBASE(0x3409290);
        }
        namespace CharacterRepresentation
        {
            const uintptr_t Primary=REBASE(0x531F880);
        }
        namespace ChatFiltering
        {
            const uintptr_t Client2ServerFilterStringForBroadcastLld=REBASE(0x2F93A70);
            const uintptr_t Client2ServerResponseError=REBASE(0x2F94F30);
            const uintptr_t ErrorGettingChatResponse=REBASE(0x619DD10);
            const uintptr_t FilterStringForBroadcastLld=REBASE(0x2F97B60);
            const uintptr_t GotChatResponseChatFilterTranslate=REBASE(0x2FA5790);
            const uintptr_t GotResponseIngestUniverseMessageRequest=REBASE(0x2FA5300);
            const uintptr_t GotTextFilterResponse=REBASE(0x2FA7E40);
            const uintptr_t SendingChatFilterTranslateRequestUserId=REBASE(0x2FA2F00);
            const uintptr_t SendingTextFilterRequest=REBASE(0x2FA6080);
            const uintptr_t TextServiceFilterAndTranslateStringAsync=REBASE(0x3F3BED0);
            const uintptr_t TextServiceFilterStringAsyncSuccessLld=REBASE(0x3F3DB80);
            const uintptr_t V2TextFilterSelectionPlayerUserId=REBASE(0x3EE9B40);
        }
        namespace ClientBlockedImage
        {
            const uintptr_t BlockedDLL=REBASE(0x4EFD140);
        }
        namespace ClientMemStatus
        {
            const uintptr_t L1=REBASE(0x4EFC5C0);
            const uintptr_t Log=REBASE(0x4EF48E0);
        }
        namespace ClientRunInfo
        {
            const uintptr_t BaseUrl=REBASE(0x4CB1E70);
        }
        namespace ClientSettings
        {
            const uintptr_t DurationBlockingLoadCachedSettingsFromFi=REBASE(0x45244E0);
            const uintptr_t ErrorLoadingIXPSettingsDisk=REBASE(0x6220C00);
            const uintptr_t ExceptionWhileGettingLocalSettingsFile=REBASE(0x6220AE0);
            const uintptr_t FlagCacheDebugDurationLoggingSuccessfull=REBASE(0x45259F0);
            const uintptr_t GetClientSettingsFromLocalLoadedBytes=REBASE(0x4522110);
            const uintptr_t LoadClientSettingsFromLocalCouldnTFetchA=REBASE(0x4522340);
            const uintptr_t LoadIxpSettingsFromLocalCouldnTFetchAnyD=REBASE(0x4522EC0);
            const uintptr_t ResolveOverriddenLocalSettingsFileUsingL=REBASE(0x4521660);
            const uintptr_t SaveClientSettingsToLocalWroteZuBytesDis=REBASE(0x45234D0);
            const uintptr_t TombstoneInitializedCheckResult=REBASE(0x4523BC0);
        }
        namespace CloseDataModel
        {
            const uintptr_t AsyncContentInitializationCompleteCanCon=REBASE(0x358AB40);
            const uintptr_t AsyncContentInitializationStart=REBASE(0x358C250);
            const uintptr_t AutoReconnectWaitReturned=REBASE(0x3596220);
            const uintptr_t BindToCloseThreadPreCreateFailed=REBASE(0x61C3430);
            const uintptr_t ClearingWorkspaceInstancesPartsScripts=REBASE(0x3418A10);
            const uintptr_t ConcurrentPatchLoadPathWaitingPatchLoad=REBASE(0x35890D0);
            const uintptr_t ConcurrentPatchLoadStart=REBASE(0x358A550);
            const uintptr_t CreateDataModelHeartbeat=REBASE(0x358CCF0);
            const uintptr_t DataModelChangeTrackerSkippedTotalSystem=REBASE(0x358D8F0);
            const uintptr_t Drain=REBASE(0x3595500);
            const uintptr_t DrainAskedParticipantsReportedOutstandin=REBASE(0x3591D60);
            const uintptr_t DrainFailed=REBASE(0x3595A20);
            const uintptr_t DrainTimedOutOutstandingUnresolvedCandid=REBASE(0x35947D0);
            const uintptr_t FinishedWaitingLock=REBASE(0x358D770);
            const uintptr_t RemovingAllChildrenIgnoringParentLock=REBASE(0x3596FA0);
            const uintptr_t SettingDataCenterID=REBASE(0x40F88E0);
            const uintptr_t SettingPlaceVersion=REBASE(0x35A77B0);
        }
        namespace CloudLocalizationTableVerbose
        {
            const uintptr_t ErrorCloudLocalizationTableLoading=REBASE(0x14024F0);
        }
        namespace Clouds
        {
            const uintptr_t CloudsAlreadyExistsAlreadyActiveAction=REBASE(0x3D524F0);
            const uintptr_t CloudsCreated=REBASE(0x3D51FC0);
            const uintptr_t SettingCloudsWorkspace=REBASE(0x34025F0);
            const uintptr_t SomehowRemovingCloudsWorkspaceWhenNone=REBASE(0x3D521E0);
        }
        namespace Commerce
        {
            const uintptr_t CommerceServicePrepareCommerceProductPur=REBASE(0x1324420);
            const uintptr_t ErrorFetchingOrderStatusCheckoutSessionI=REBASE(0x1324150);
        }
        namespace ComponentManager
        {
            const uintptr_t ComponentCreatedBecauseTakesRequiredDepe=REBASE(0x824F20);
            const uintptr_t ComponentCreatedLazily=REBASE(0x825EF0);
            const uintptr_t ComponentGraphIncompleteBecauseWasRegist=REBASE(0x1DCD6F0);
            const uintptr_t ComponentParentKeyHasAlreadyBeen=REBASE(0x1DD7640);
            const uintptr_t CreatedComponentMs=REBASE(0x1DD4050);
            const uintptr_t CreatedComponentTreeRootComponentCompone=REBASE(0x1DD0DA0);
            const uintptr_t DeletingComponent=REBASE(0x1DD8BB0);
            const uintptr_t DeletingComponentTreeRootComponent=REBASE(0x1DD7C80);
            const uintptr_t DidnTFindKeyComponent=REBASE(0x1DD7280);
            const uintptr_t RegistrationHandlesStillAliveDuringDestr=REBASE(0x1DCCB70);
            const uintptr_t ShuttingDownComponent=REBASE(0x1DD8E10);
            const uintptr_t SuccessfullyRegisteredComponentCreationC=REBASE(0x1DCCF70);
            const uintptr_t SuccessfullyRegisteredComponentDeletionC=REBASE(0x1DCD150);
            const uintptr_t SuccessfullyRegisteredComponentDependenc=REBASE(0x1DCEB60);
            const uintptr_t SuccessfullyRegisteredComponentShutdownC=REBASE(0x1DCD330);
            const uintptr_t SuccessfullyRegisteredGetGraphMetadataCa=REBASE(0x1DCD510);
            const uintptr_t TryingCreateDependentComponentsComponent=REBASE(0x1DD4660);
        }
        namespace ConfigService
        {
            const uintptr_t GetValueFailedExperimentationServiceAvai=REBASE(0x31B3F40);
        }
        namespace ConnectionStatusMonitor
        {
            const uintptr_t LabelingConnectionStatus=REBASE(0x2A45740);
            const uintptr_t RemovingConnectionStatusLabel=REBASE(0x2A458C0);
        }
        namespace ConnectivityProtocolCore
        {
            const uintptr_t NetworkStatusChangeValue=REBASE(0x5CE5760);
        }
        namespace ConnectivityV2Core
        {
            const uintptr_t NetworkChangeCur=REBASE(0x213DCF0);
            const uintptr_t NetworkChangeSettledLossCur=REBASE(0x213E200);
        }
        namespace ContentProviderRequests
        {
            const uintptr_t CacheableContentProviderFetchCachedAsset=REBASE(0x11B5AA0);
            const uintptr_t ExceptionThrownWhileAttemptingLoadInstan=REBASE(0x6106260);
            const uintptr_t GotContentString=REBASE(0x117CA60);
            const uintptr_t GotUnexpectedErrorAssetPermissionCheck=REBASE(0x118C170);
            const uintptr_t HSRDataContentProviderFetchAssetIdTookMs=REBASE(0x191C420);
            const uintptr_t ParsingContent=REBASE(0x117DD50);
            const uintptr_t SlimContentProviderFetchAssetIdTookMs=REBASE(0x10E1040);
            const uintptr_t SlimContentProviderFetchRequestMade=REBASE(0x10E1A40);
            const uintptr_t SolidModelContentProviderFetchAssetIdToo=REBASE(0x3059B70);
            const uintptr_t ValidAssetID=REBASE(0x118BBC0);
        }
        namespace ContentResidency
        {
            const uintptr_t StartingOverbudgetBytesUsageBudgetNeed=REBASE(0x371A590);
        }
        namespace Cookie
        {
            const uintptr_t ExceptionParsingNetscapeCookieString=REBASE(0x618ACF0);
        }
        namespace CookieStorage
        {
            const uintptr_t FailedDecryptAuthTokenLoginCredentials=REBASE(0x44DEC90);
            const uintptr_t FailedEncryptNewCookie=REBASE(0x44DF050);
            const uintptr_t MalformedCookieReceivedCookieUpdateFaile=REBASE(0x44DDC40);
            const uintptr_t TelemetriesAreSent=REBASE(0x44DFC20);
        }
        namespace CoordinatorMemoryPressure
        {
            const uintptr_t CoordinatorHandleLowMemoryWarningRequest=REBASE(0x20B11F0);
            const uintptr_t MemoryPressureAfter1fSecondsRelax=REBASE(0x20B1390);
        }
        namespace CrashMetricStorage
        {
            const uintptr_t CrashMetricStorageSuccessfullyParsedCras=REBASE(0x20CF5D0);
            const uintptr_t CrashMetricStorageUnknownPostProcessStag=REBASE(0x20D1F80);
            const uintptr_t CrashMetricStorageUpdatedPlayTimeSinceLa=REBASE(0x20D18C0);
        }
        namespace CrashReportLog
        {
            const uintptr_t CannotSetNullptrBacktraceAttributeCheck=REBASE(0x512A730);
            const uintptr_t CrashHandlerDoesExist=REBASE(0x512CD70);
            const uintptr_t FailedAddFileAttachment=REBASE(0x512DC80);
            const uintptr_t FailedInitializeCrashDatabase=REBASE(0x5127550);
            const uintptr_t FailedPushBytesDataIntoFifo=REBASE(0x5127B50);
            const uintptr_t Implemented=REBASE(0x51280C0);
            const uintptr_t PlatformHasPendingCrashReporting=REBASE(0x51281B0);
            const uintptr_t PoppedBytesDataFifo=REBASE(0x5127910);
            const uintptr_t RunBookKeepingUnhandledException=REBASE(0x5124030);
            const uintptr_t SetAnnotationCstringName=REBASE(0x5127E00);
            const uintptr_t SimulateCrashReason=REBASE(0x512B3B0);
            const uintptr_t TerminatedDueWasHangingPastTimeout=REBASE(0x512F700);
        }
        namespace CrashpadInitializationTelemetry
        {
            const uintptr_t FailedSendCrashpadInitializationFailureC=REBASE(0x512E930);
            const uintptr_t TimedOutWaitingCrashpadInitializationFai=REBASE(0x512E5A0);
        }
        namespace CreateAssetasync
        {
            const uintptr_t AssetPublishFlowPrepareInstancesForUploa=REBASE(0x33736F0);
            const uintptr_t CouldCloneInstance=REBASE(0x3376AF0);
            const uintptr_t CouldParentInstanceUnderRobloxServerStor=REBASE(0x3372570);
            const uintptr_t CreateAssetAsyncCalled=REBASE(0x3373A10);
            const uintptr_t CreateAssetAsyncCompletedSuccessfully=REBASE(0x33745C0);
            const uintptr_t CreateAssetAsyncFailedError=REBASE(0x3374840);
            const uintptr_t FailedParseTexturePackPBRTexturesMay=REBASE(0x337BF80);
            const uintptr_t SuccessfullyUploadedTexturePackPropsetAs=REBASE(0x337B600);
        }
        namespace CreatorConfigAssetProvider
        {
            const uintptr_t UnknownCreatorConfigAssetProviderOperati=REBASE(0x1169F60);
        }
        namespace CreatorConfigPlatformProvider
        {
            const uintptr_t CreatorConfigCSMFetchFailedResource=REBASE(0x32EE950);
            const uintptr_t DroppingCreatorConfigCSMNotification=REBASE(0x32EDAA0);
            const uintptr_t PinnedAssetFetchFailedFallingBack=REBASE(0x32F3660);
            const uintptr_t StartedCreatorConfigCSMSubscriptionUnive=REBASE(0x32ED180);
        }
        namespace CreatorConfigProvider
        {
            const uintptr_t HttpRequestFailedOperationStatusCode=REBASE(0x1169540);
            const uintptr_t NewVersionUpdateReceivedOldVersion=REBASE(0x1169A80);
            const uintptr_t ParsingMaterializedConfigViaAssetFailed=REBASE(0x1169C80);
            const uintptr_t PollFailedAfterRetries=REBASE(0x11697F0);
            const uintptr_t ServiceInitializedSeconds=REBASE(0x3307180);
        }
        namespace CreatorExperimentationProvider
        {
            const uintptr_t ConfigEvaluatedTargetingSeconds=REBASE(0x331BD70);
            const uintptr_t ConfigInitializedSeconds=REBASE(0x1168F50);
            const uintptr_t GetExperimentValueFailedAfterRetries=REBASE(0x1168CC0);
            const uintptr_t HttpRequestFailedOperationStatusCode=REBASE(0x11689F0);
            const uintptr_t HydrationTimedOutAfterWaits=REBASE(0x1169140);
            const uintptr_t PlayerHydratedSeconds=REBASE(0x331A770);
            const uintptr_t UnknownCreatorExperienceConfigApiType=REBASE(0x11688E0);
        }
        namespace CrossExperienceExecutor
        {
            const uintptr_t CrossExperienceExecutorCannotFindExecuta=REBASE(0x4EA7EE0);
        }
        namespace CrossExperienceVoiceController
        {
            const uintptr_t CrossExperienceVoiceControllerBeginProce=REBASE(0x4D6D730);
            const uintptr_t CrossExperienceVoiceControllerFinalized=REBASE(0x4D69FD0);
            const uintptr_t CrossExperienceVoiceControllerGameShutdo=REBASE(0x4D6F450);
            const uintptr_t CrossExperienceVoiceControllerIgnoringNo=REBASE(0x4D67250);
            const uintptr_t CrossExperienceVoiceControllerInitialize=REBASE(0x4D69530);
            const uintptr_t CrossExperienceVoiceControllerJoinDataMo=REBASE(0x4D6D800);
            const uintptr_t CrossExperienceVoiceControllerRemoveAllO=REBASE(0x4D6C7B0);
            const uintptr_t CrossExperienceVoiceControllerRemovingAl=REBASE(0x4D6D410);
            const uintptr_t CrossExperienceVoiceControllerRemovingOb=REBASE(0x4D678A0);
            const uintptr_t CrossExperienceVoiceControllerStopBeginB=REBASE(0x4D6CB50);
            const uintptr_t CrossExperienceVoiceControllerStopDestro=REBASE(0x4D6EFC0);
            const uintptr_t CrossExperienceVoiceControllerSubmitStar=REBASE(0x4D6F1F0);
            const uintptr_t DuplicateObserverIdFoundCleaningUpPrevio=REBASE(0x4D67FF0);
            const uintptr_t GeneratedStoredNewClientNumber=REBASE(0x4D6A760);
            const uintptr_t MemoryDelta2fMBTotal=REBASE(0x4D66826);
            const uintptr_t StoredClientNumberWasCorruptGenerating=REBASE(0x6252DD0);
            const uintptr_t TimingOutWhenAttemptingJoinParty=REBASE(0x4D6BDF0);
            const uintptr_t TryingTurnDownCrossExperienceVoiceTunabl=REBASE(0x4D6B9E0);
        }
        namespace CsmConnectionManager
        {
            const uintptr_t CsmConnectionManagerConnectionSucceeded=REBASE(0x4978390);
            const uintptr_t CsmConnectionManagerInitializeNetworkHan=REBASE(0x4977EB0);
            const uintptr_t CsmConnectionManagerInvokeRpcAsyncConnec=REBASE(0x4979560);
            const uintptr_t CsmConnectionManagerInvokeRpcAsyncInvali=REBASE(0x497A110);
            const uintptr_t CsmConnectionManagerReconnected=REBASE(0x49781D0);
            const uintptr_t CsmConnectionManagerStartAsyncNetworkHan=REBASE(0x4978FE0);
            const uintptr_t ListenHubEventEventHandlerGettingExecute=REBASE(0x49789F0);
            const uintptr_t ReportExtendedInvokeClusterUniverseIdMet=REBASE(0x497ADE0);
            const uintptr_t ReportExtendedInvokeResultClusterUnivers=REBASE(0x497B0F0);
            const uintptr_t ReportExtendedReceivedClusterUniverseIdT=REBASE(0x497B5D0);
        }
        namespace CursorCache
        {
            const uintptr_t InvalidImage=REBASE(0x3BEBF10);
            const uintptr_t PerformingEvictionCycle=REBASE(0x3BEC4F0);
            const uintptr_t RetryingAttempt=REBASE(0x3BEB940);
        }
        namespace CursorChanges
        {
            const uintptr_t MouseLockTypeChanged=REBASE(0x16DAEA0);
            const uintptr_t UpdatingCursor=REBASE(0x16D8800);
        }
        namespace CyclicExecutiveThrottling
        {
            const uintptr_t AvgWorldStepFreq=REBASE(0x3D90740);
            const uintptr_t DataModelPhysicsStepDtDtCyclicExecutiveD=REBASE(0x150A010);
            const uintptr_t RequestingSimulationRadiusReductionDueAw=REBASE(0x3D90400);
        }
        namespace CyclicExecutiveWorldSteps
        {
            const uintptr_t WorldStepsIteration=REBASE(0x1496613);
        }
        namespace D3D11SwapChain
        {
            const uintptr_t GetSwapChainSizeNullSwapChain=REBASE(0x27CCD40);
            const uintptr_t PresentNullSwapChainSkipping=REBASE(0x27C3870);
            const uintptr_t ResizeSwapchainNullSwapChainSkipping=REBASE(0x27C3A80);
            const uintptr_t ResizeSwapchainResizeBuffersExplicitXSwa=REBASE(0x27C3B93);
            const uintptr_t ResizeSwapchainResizeBuffersFailedHrXSwa=REBASE(0x27C3CCD);
            const uintptr_t ResizeWindowDataSwapChainWindowHandleDim=REBASE(0x27CC9A0);
            const uintptr_t ValidateResizeTriggeredSwapChainDimsX=REBASE(0x27C8CF1);
        }
        namespace DataModelJobs
        {
            const uintptr_t GCJobFinishDataModel=REBASE(0x4260DC0);
            const uintptr_t GCStepStartDataModel=REBASE(0x4265A90);
            const uintptr_t HeartbeatFinishDataModel=REBASE(0x3511180);
            const uintptr_t PacketReceiveFinishDataModel=REBASE(0x482D240);
            const uintptr_t ParallelGCCallbackFlushingStartedData=REBASE(0x42642A0);
            const uintptr_t PhysicsJobFinishDataModel=REBASE(0x35108A0);
            const uintptr_t ProcessShutdownTasksFinish=REBASE(0x3587870);
            const uintptr_t ProcessTasksStart=REBASE(0x3587290);
            const uintptr_t WaitingScriptsFinishDataModel=REBASE(0x42A1BC0);
        }
        namespace DataModelPatchAnalytics
        {
            const uintptr_t ClientBundleSplitTreatment=REBASE(0x15E2130);
        }
        namespace DataModelPatchConfig
        {
            const uintptr_t InvalidFlatPluginArrayJSONInput=REBASE(0x15DDBD0);
            const uintptr_t IsContentCachedInBackupFoundCacheBackupC=REBASE(0x15DCB40);
        }
        namespace DataModelPatchConfigCollection
        {
            const uintptr_t LoadConfigsCACHEDAssetVersion=REBASE(0x15D6CA0);
            const uintptr_t ReadingOTAConfigs=REBASE(0x15D8530);
            const uintptr_t RegisteringStorageKey=REBASE(0x15D6A90);
            const uintptr_t WritingOTAConfigs=REBASE(0x15D8DE0);
        }
        namespace DataModelPatchConfigurer
        {
            const uintptr_t CleanUpBackupCacheDeletedFile=REBASE(0x15BB490);
            const uintptr_t DeferSignatureCheckExecuteScheduledDefer=REBASE(0x15CAFC0);
            const uintptr_t DeferSignatureCheckSchedulingDeferredSig=REBASE(0x15CA090);
            const uintptr_t DeferredRbxmLastSessionParkedJoinNever=REBASE(0x15CFFE0);
            const uintptr_t DeserializeAndVerifyPatchBlake2b=REBASE(0x15C25D0);
            const uintptr_t DownloadPatchV2DeserializeSigningInfoAnd=REBASE(0x6124E10);
            const uintptr_t DownloadPostTtiPatchV2DeserializeSigning=REBASE(0x6125020);
            const uintptr_t DownloadedPatchSucceeded=REBASE(0x15D2D40);
            const uintptr_t DownloadedPostTTIPatchFailedPromoting=REBASE(0x15D3230);
            const uintptr_t EarlyExitScheduleOTAPollingTimerCalled0I=REBASE(0x15D3DF0);
            const uintptr_t GetCachedPatchFailedLoadCoreScriptPatch=REBASE(0x15BDFA0);
            const uintptr_t GetCachedPatchGetPatchLocalBackupCache=REBASE(0x15BD940);
            const uintptr_t GetCachedPatchLoadingPatchThrowsExceptio=REBASE(0x6124700);
            const uintptr_t LoadConfigsUserKey=REBASE(0x15CEAE0);
            const uintptr_t OTAPatchFoundBackupCacheSkipping=REBASE(0x15D2500);
            const uintptr_t OTAPollingEnabledSet=REBASE(0x15D61F0);
            const uintptr_t OTAUpdateTimedOutWaitingDeferred=REBASE(0x15CF7D0);
            const uintptr_t PerformDeferredSignatureCheckSkipBecause=REBASE(0x15CA5D0);
            const uintptr_t RetrievingPatch=REBASE(0x15CF110);
            const uintptr_t StartOTAPolling=REBASE(0x15D4180);
            const uintptr_t StopOtaPollingTimer=REBASE(0x15D0760);
            const uintptr_t TryOpenLocalCachedRBXMFile=REBASE(0x15BD670);
            const uintptr_t WriteToBackupDirFailedWriteTmpFile=REBASE(0x15C00D0);
        }
        namespace DataModelPatcher
        {
            const uintptr_t PostTTIAlreadyFiredSkippingOne=REBASE(0x15B7330);
            const uintptr_t PostTTICorePackagesLuauForgeChunksFOUND=REBASE(0x15B6BD0);
            const uintptr_t PostTTIPatchClientDataModelCompletedPatc=REBASE(0x15B3890);
            const uintptr_t PostTTIRegisteringTriggerLuaAppInteracti=REBASE(0x15B7090);
            const uintptr_t PostTTISignatureVerificationSKIPPEDDebug=REBASE(0x15B75E0);
        }
        namespace DataModelStarterModule
        {
            const uintptr_t LaunchingExperience=REBASE(0x51B3E00);
        }
        namespace DataStore
        {
            const uintptr_t AbleExtractUserIdsCastError=REBASE(0x61FD3F0);
            const uintptr_t AbleExtractUserIdsMetadataResultsTuple=REBASE(0x61FD7C0);
            const uintptr_t AddBudgetsOnCloseAddThrottleCounterOrder=REBASE(0x3E65070);
            const uintptr_t BackendResponseDidHaveScopePrefix=REBASE(0x3E87F20);
            const uintptr_t CanTDecodeReturnedValue=REBASE(0x3E48B40);
            const uintptr_t ClosingDownDataStoreServiceBackendProces=REBASE(0x3E617E0);
            const uintptr_t ConditionalSetKey=REBASE(0x3E7FA60);
            const uintptr_t DeserializationWebResponseFailed=REBASE(0x3E4A970);
            const uintptr_t ErrorRefreshingLocks=REBASE(0x3E6EFD0);
            const uintptr_t Exception=REBASE(0x3E819F0);
            const uintptr_t ExecutingThrottledRequestsSizeBudget=REBASE(0x3E6A380);
            const uintptr_t FailedPublishErrorPointsAPICounters=REBASE(0x61036F0);
            const uintptr_t FetchedKeyService=REBASE(0x3E82D10);
            const uintptr_t FetchedKeysService=REBASE(0x3E4A800);
            const uintptr_t FetchingKeys=REBASE(0x3E4B420);
            const uintptr_t GetVersionAsyncKey=REBASE(0x3E7C630);
            const uintptr_t GotCachedVersionReturning=REBASE(0x3E35230);
            const uintptr_t GotCachedVersionReturningDataVersion=REBASE(0x3E753A0);
            const uintptr_t GrantHandleFailedResolveFallingBack=REBASE(0x3EB4FD0);
            const uintptr_t InitializedDataStoreUrl=REBASE(0x3E4A500);
            const uintptr_t InvalidStructureResponseArrayElementInva=REBASE(0x3EB29A0);
            const uintptr_t LastReturnedKeyString=REBASE(0x3EB4210);
            const uintptr_t LockAsyncKey=REBASE(0x3E89850);
            const uintptr_t LockedKeysFound=REBASE(0x3E6D0A0);
            const uintptr_t LocksRefreshedSuccessfully=REBASE(0x3E6EF00);
            const uintptr_t MD5ChecksumErrorKeyExpectedBut=REBASE(0x3E820E0);
            const uintptr_t PuttingRequestOrderedSetQueueDue=REBASE(0x3E69FF0);
            const uintptr_t PuttingRequestStandardSetQueueDue=REBASE(0x3E69D50);
            const uintptr_t RefetchBudgetSoResetRefetchAll=REBASE(0x3E6B020);
            const uintptr_t RefetchKeyFailed=REBASE(0x3E99210);
            const uintptr_t RefetchingKeysBudgetOnUpdateSizeCachedKe=REBASE(0x3E4BC00);
            const uintptr_t RequestDataInQueueForceExcuseThrottledRe=REBASE(0x5BE2250);
            const uintptr_t RequestDataInQueueProcessAfterRequestedW=REBASE(0x5BE25F0);
            const uintptr_t RequestQueueExceededWhenRefetchingKey=REBASE(0x3E95220);
            const uintptr_t ResponseEmptyKey=REBASE(0x3E83250);
            const uintptr_t ReturningFetchedValueKey=REBASE(0x3E34FA0);
            const uintptr_t SetAsyncKey=REBASE(0x3E38010);
            const uintptr_t SetAsyncRoundtripErrorValue=REBASE(0x3E76A80);
            const uintptr_t SetKeyService=REBASE(0x3E83670);
            const uintptr_t SubscribedKey=REBASE(0x3E4A040);
            const uintptr_t ThrottlingBatchGetAsyncBudgetAfter=REBASE(0x3E69AB0);
            const uintptr_t UnexpectedErrorConvertingVariantResponse=REBASE(0x3EB3350);
            const uintptr_t UnexpectedVersionNumberFormat=REBASE(0x3E81250);
            const uintptr_t UnknownDataStoreApiType=REBASE(0x115E510);
            const uintptr_t UnknownDataStoreClientErrorType=REBASE(0x115BD30);
            const uintptr_t UnknownDataStoreType=REBASE(0x115E9D0);
            const uintptr_t UnknownDataStoresV1ServerErrorCode=REBASE(0x115A7A0);
            const uintptr_t UnknownDataStoresV2ServerErrorCode=REBASE(0x115AEA0);
            const uintptr_t UnlockAsyncKey=REBASE(0x3E8A690);
            const uintptr_t ValueLength=REBASE(0x3E36570);
            const uintptr_t VersionReceived=REBASE(0x3E85BF0);
        }
        namespace DataStoreBudget
        {
            const uintptr_t AddingInitialBudgetGetsBudgetSets=REBASE(0x3E63F80);
        }
        namespace DebugDurationLogging
        {
            const uintptr_t ActiveFlowNameList=REBASE(0x5C90D8C);
            const uintptr_t ActiveSubFlowNameList=REBASE(0x5C90FF1);
            const uintptr_t DurationLoggerAlertTookMsExceedingThresh=REBASE(0x5C8CC70);
            const uintptr_t DurationLoggerReportedFlowFlowDurationFl=REBASE(0x5C8D690);
            const uintptr_t MilestoneTimestampLd=REBASE(0x5C8B7E0);
        }
        namespace DebugEnableStreamOutToDiskLog
        {
            const uintptr_t CachedInstanceCountCacheMBUsed=REBASE(0x47AF8B0);
        }
        namespace DebugHttpTrace
        {
            const uintptr_t HttpRequestCurlUncompressedPostData=REBASE(0x2C788F0);
        }
        namespace DebugNetworkBandwidthAudit
        {
            const uintptr_t BandwidthAuditVersion2GroupTransportBack=REBASE(0x46FAB39);
            const uintptr_t BandwidthAuditVersion2GroupTransportRole=REBASE(0x46FA171);
        }
        namespace DebugQuadTreeLogging2
        {
            const uintptr_t QueryQuadTreeButBoundsInfinite=REBASE(0x409F2FB);
            const uintptr_t QueryQuadTreeButPositionInfinite=REBASE(0x3F99F60);
        }
        namespace DeeplinkIntentContext
        {
            const uintptr_t ReceivedIdUrlSource=REBASE(0x5182AB0);
            const uintptr_t SessionChangedSidTagActiveDlics=REBASE(0x5181790);
            const uintptr_t TerminalEmitIdCategoryReasonState=REBASE(0x5183570);
            const uintptr_t TerminalObserverRegisteredSessionManager=REBASE(0x146E160);
            const uintptr_t TerminatedIdCategoryReason=REBASE(0x51831A0);
        }
        namespace DefaultAppRatingPromptProtocol
        {
            const uintptr_t AppRatingPromptAvailable=REBASE(0xFE9440);
        }
        namespace DefaultMediaPickerProtocol
        {
            const uintptr_t MediaPickingWasCancelled=REBASE(0x5137960);
        }
        namespace DeferredAssetManager
        {
            const uintptr_t DeferredAssetFailedLoadResultResponse=REBASE(0x4D9A650);
        }
        namespace DeferredRbxmJoin
        {
            const uintptr_t DeferredRbxmAbandoningOwedSwapStoppingGa=REBASE(0x1477AF0);
            const uintptr_t DeferredRbxmDeferringJoinDownloadProgres=REBASE(0x1475B00);
            const uintptr_t DeferredRbxmDownloadFailedStayingLuaAppJ=REBASE(0x14767A0);
            const uintptr_t DeferredRbxmHoldingSurfaceSwapUntilGame=REBASE(0x1476E80);
            const uintptr_t DeferredRbxmJoinOutcome=REBASE(0x14776B0);
            const uintptr_t DeferredRbxmLuaAppDMContextPreGame=REBASE(0x1471F00);
            const uintptr_t DeferredRbxmPreGameAppliedJoiningPlaceId=REBASE(0x1472130);
            const uintptr_t DeferredRbxmResumingUGCJoinAfterDownload=REBASE(0x1476B80);
            const uintptr_t DeferredRbxmStatusPublished=REBASE(0x1472810);
            const uintptr_t DeferredRbxmSurfaceRestoredSwapStillOwed=REBASE(0x1477E20);
            const uintptr_t DeferredRbxmSwapReadyButJoinWas=REBASE(0x1477270);
            const uintptr_t DeferredRbxmUserCancelledSkippingResume=REBASE(0x14763C0);
        }
        namespace DesignFoundationsCore
        {
            const uintptr_t ClearTokensPlatformImplementationRegiste=REBASE(0x51311E0);
            const uintptr_t SetPlatformImplRegisteringPlatformImplem=REBASE(0x5130E70);
            const uintptr_t UpdateTokensPlatformImplementationRegist=REBASE(0x51310D0);
        }
        namespace DesignFoundationsService
        {
            const uintptr_t ClearTokensIDesignFoundationsCoreAvailab=REBASE(0x4EA4A10);
            const uintptr_t SetTokensPayloadColorTokensTableDropping=REBASE(0x4EA5940);
            const uintptr_t SetTokensUnrecognizedCategoryIgnoringEng=REBASE(0x4EA5EE0);
        }
        namespace DesignFoundationsWin32
        {
            const uintptr_t Win32DesignFoundationsImplOnTokensCleare=REBASE(0x5131BB0);
            const uintptr_t Win32DesignFoundationsImplRegisteringPla=REBASE(0x51316E0);
        }
        namespace DeviceDisplayHandler
        {
            const uintptr_t GetBrightnessAvailableCurrentPlatform=REBASE(0x26B17D0);
            const uintptr_t SetBrightnessAvailableCurrentPlatform=REBASE(0x26B16D0);
            const uintptr_t SetBrightnessToDefaultAvailableCurrentPl=REBASE(0x26B18D0);
            const uintptr_t SetKeepAwakeAvailableCurrentPlatform=REBASE(0x26B1A10);
        }
        namespace DeviceRecovery
        {
            const uintptr_t DEVICERECOVERYDeviceRemovedTrueReason0x=REBASE(0x27C9300);
            const uintptr_t DEVICERECOVERYEndFrameEarlyExitDue=REBASE(0x27C9BA0);
            const uintptr_t DeviceLostSettingDoResetTrueAttempt=REBASE(0x36752D0);
            const uintptr_t DeviceRecoveryQualityCapSetFrames=REBASE(0x3675820);
            const uintptr_t TriggerReasonAttemptIn60sVramLocalMBVram=REBASE(0x3674BA0);
        }
        namespace DigitalSignatureBinary
        {
            const uintptr_t DigestRangeOutsideStreamLength=REBASE(0x4B9D060);
        }
        namespace DisplayWakeLock
        {
            const uintptr_t CreatingDisplayWakeLock=REBASE(0xC329A0);
            const uintptr_t ReleasingWakeLock=REBASE(0x31A2730);
        }
        namespace DisplayWakeLockGuard
        {
            const uintptr_t DisplayWakeLockGuardSubsystemShuttingDow=REBASE(0x146E7C0);
            const uintptr_t DisplayWakeLockGuardSubsystemStarting=REBASE(0x26B1290);
        }
        namespace DomainAllowListChecker
        {
            const uintptr_t CheckingIfUrlAllowedContextUrl=REBASE(0x4D35180);
            const uintptr_t EncounteredExceptionWhilePerformingRegex=REBASE(0x62518D0);
        }
        namespace DragDetectorLog
        {
            const uintptr_t CharacterAddedRespawnDragDetectorCalling=REBASE(0x4626290);
            const uintptr_t DragDetectorDestroyedCallingOnCancel=REBASE(0x4635640);
            const uintptr_t DragDetectorDragContinueReplicateCalling=REBASE(0x4623D20);
            const uintptr_t DragDetectorDragEndBEGIN=REBASE(0x462BC50);
            const uintptr_t DragDetectorDragEndReplicateCallingFireE=REBASE(0x4623F40);
            const uintptr_t DragDetectorDragStartAlreadyDraggingRetu=REBASE(0x46290E0);
            const uintptr_t DragDetectorDragStartReplicateAlreadyDra=REBASE(0x46233D0);
            const uintptr_t DragDetectorEndDragNowAndCancelCallingEn=REBASE(0x4626DA0);
            const uintptr_t DragDetectorFireDragEndRunDuringRestartS=REBASE(0x46282E0);
            const uintptr_t DragDetectorFireDragStartAlreadyDragging=REBASE(0x4626FB0);
            const uintptr_t DragDetectorOnCancel=REBASE(0x4626710);
            const uintptr_t DragDetectorUpdateMouseStateLeftMouseDow=REBASE(0x4624B30);
            const uintptr_t EnabledSetFalseCallingEndDragNow=REBASE(0x462F650);
            const uintptr_t EndDragNowDraggingLocallyInvokedServerCa=REBASE(0x4626960);
            const uintptr_t IsEnabledForPlayerReturningFALSETugWarsP=REBASE(0x4628EC0);
            const uintptr_t MenuOpenedDragDetectorCallingEndDragNowA=REBASE(0x4635320);
            const uintptr_t PlayerRemovingCallingEndDragNow=REBASE(0x4623A20);
            const uintptr_t PlayerShutdownMessageDragDetectorCalling=REBASE(0x4626470);
            const uintptr_t RotateTrackballCursorProjectorProjectToS=REBASE(0x463C12F);
        }
        namespace DynFloodChecker
        {
            const uintptr_t ErrorIncreasingFloodCheckSettingsError=REBASE(0x5BDF820);
            const uintptr_t KeyMissingEmptyEntryFloodChecker=REBASE(0x5BDE6C0);
        }
        namespace DynamicFastVariableReloader
        {
            const uintptr_t CouldnTGetServerTimestampSeconds=REBASE(0x114F3A0);
            const uintptr_t FailedUpdateSettingsUsingDictionaryDisab=REBASE(0x1151D10);
            const uintptr_t FailedWriteDynamicFetchSettingsCache=REBASE(0x11537B0);
            const uintptr_t FlagRolloutTestStaticBool3=REBASE(0x2B9ADEF);
            const uintptr_t FlagRolloutTestStaticString8=REBASE(0x2B9FA63);
            const uintptr_t FlagRolloutTestStaticString9=REBASE(0x2BA0F34);
            const uintptr_t LoadDynamicFlagsUrl=REBASE(0x1150980);
            const uintptr_t ZstdDictionaryFoundDisabling=REBASE(0x114F7B0);
        }
        namespace DynamicTranslation
        {
            const uintptr_t ClientTranslationLRUCacheOnRemoteEventFr=REBASE(0x1380AE0);
            const uintptr_t ErrorSubstitutingParamExpection=REBASE(0x61133F0);
            const uintptr_t SenderFetchTranslationV2ParameterizedSou=REBASE(0x1373CD0);
            const uintptr_t SenderIsEligibleForDynamicTranslationTex=REBASE(0x1373950);
            const uintptr_t SenderTryStartServerPathComplete=REBASE(0x1372B50);
            const uintptr_t ServerProcessorSendEntriesResponseHandle=REBASE(0x1382340);
            const uintptr_t ServerProcessorStartRequestBodyFailedLoc=REBASE(0x13840B0);
            const uintptr_t ServerQueueShouldAddTranslationExistedRC=REBASE(0x1384720);
            const uintptr_t ServerToClientSenderStepDataModelJobTran=REBASE(0x136C0B0);
            const uintptr_t ServerToClientStateOnPlayerAddedFailedAd=REBASE(0x13660E0);
            const uintptr_t ServerToClientStateOnPlayerLocaleChanged=REBASE(0x1367350);
            const uintptr_t ServerToClientStateOnPlayerRemovingFaile=REBASE(0x1366A30);
        }
        namespace EditableServiceLog
        {
            const uintptr_t AmpError=REBASE(0x318EC80);
            const uintptr_t EditableServiceInitialized=REBASE(0x318EF60);
            const uintptr_t MemoryAddTotal=REBASE(0x3191200);
            const uintptr_t MemoryReduceTotal=REBASE(0x3191340);
            const uintptr_t PerformingAMPVerifiedRequest=REBASE(0x318FA70);
            const uintptr_t SkippingEditablePolicyCheckDueFlags=REBASE(0x318FF00);
        }
        namespace Error
        {
            const uintptr_t AccessErrorFileManagerServiceListFilesIn=REBASE(0x6102550);
            const uintptr_t AddSessionInfoFieldOnlySupportedEventIng=REBASE(0x51A09D0);
            const uintptr_t AliveCountUnderflow=REBASE(0x1C98F00);
            const uintptr_t AnalyticsProviderExperienceSignalsIngest=REBASE(0x3B57F00);
            const uintptr_t AnimationLodControllerV2RegisterModelFai=REBASE(0x1A0D430);
            const uintptr_t AnimatorCreateFaceAnimatorTrackerDetecti=REBASE(0x1760340);
            const uintptr_t AssetPublishFlowCreateAssetAndPollAssetI=REBASE(0x335E290);
            const uintptr_t AssetReaderFailedException=REBASE(0x6108440);
            const uintptr_t AssetServiceSendPublishResultToDevDataMo=REBASE(0x335E5F0);
            const uintptr_t AssetServiceSendPublishResultToPlayerDat=REBASE(0x335E8F0);
            const uintptr_t AvatarChatServiceEnableVoiceFailedEnable=REBASE(0x194A260);
            const uintptr_t AvatarChatServiceEnableVoicePlayerLonger=REBASE(0x1949FE0);
            const uintptr_t AvatarChatServiceGetClientFeaturesAsyncS=REBASE(0x194BB10);
            const uintptr_t AvatarChatServicePollClientFeaturesSuppo=REBASE(0xF8D280);
            const uintptr_t AvatarChatServicePollClientFeaturesUserI=REBASE(0x1949B52);
            const uintptr_t AvatarChatServiceProcessRemoteEventFaile=REBASE(0x194A670);
            const uintptr_t AvatarCreationErrorTypeFINALCOUNTIterati=REBASE(0x1BDEA50);
            const uintptr_t Blake2bKeySizeBelowMinimumSize=REBASE(0x4A1C970);
            const uintptr_t Blake3KeySizeMust=REBASE(0x4A1CC30);
            const uintptr_t CacheCleanProcessFailedGetAvailable=REBASE(0x2C64A70);
            const uintptr_t CanSetDeleteIECompatibleVersion=REBASE(0x16BEE80);
            const uintptr_t CouldFindAdPortalTeleportData=REBASE(0x1059210);
            const uintptr_t CouldFindContentInstanceName=REBASE(0x1835620);
            const uintptr_t DebugRenderingTestVideoCaptureFStringDeb=REBASE(0x3099F00);
            const uintptr_t DebugRenderingTestVideoCaptureStartFaile=REBASE(0x309A520);
            const uintptr_t ErrorCompressingMicroprofileJsTemplate=REBASE(0x2A868E0);
            const uintptr_t ErrorMakingAccountSettingsEmailRequestRe=REBASE(0x74B150);
            const uintptr_t ErrorMakingUserAppLaunchInfoRequestRecei=REBASE(0x74AB40);
            const uintptr_t ErrorMakingUserRoleRequestReceivedHTTPEr=REBASE(0x74AF90);
            const uintptr_t ErrorScreenshotNameIdFound=REBASE(0x3486090);
            const uintptr_t ErrorStart=REBASE(0x45B3500);
            const uintptr_t ExceptionCaught=REBASE(0x4195380);
            const uintptr_t ExceptionCaughtDuringDeferredEventDispat=REBASE(0x6215190);
            const uintptr_t ExceptionCaughtDuringModuleScriptReferen=REBASE(0x6211870);
            const uintptr_t ExpectedEditableMeshCageMeshContent=REBASE(0x1AA97A0);
            const uintptr_t ExpectedOnlyOneVideoTrack=REBASE(0x1E24C60);
            const uintptr_t ExternalContentSharingProtocolCopyToClip=REBASE(0x5D11AC0);
            const uintptr_t FACSRigRefusedJointNamesAbove=REBASE(0x49AD920);
            const uintptr_t FModErrorCreateStream=REBASE(0x45B2EF0);
            const uintptr_t FaceAnimatorServiceRunServiceObjectAvail=REBASE(0x1B54FE0);
            const uintptr_t FaceAnimatorServiceSetLodFailedReturned=REBASE(0x1B59270);
            const uintptr_t FaceAnimatorServiceTrackerInitialization=REBASE(0x1B58F30);
            const uintptr_t FaceAnimatorServiceVideoCaptureServiceAv=REBASE(0x1B56890);
            const uintptr_t FailedCloseVideo=REBASE(0x3EC7FF0);
            const uintptr_t FailedDeserializeAvatarModelError=REBASE(0x18365A0);
            const uintptr_t FailedDeserializeHumanoidDescriptionErro=REBASE(0x1836B60);
            const uintptr_t FailedDownloadBundle=REBASE(0x4BC5860);
            const uintptr_t FailedDownloadEagerContent=REBASE(0x4BC4BE0);
            const uintptr_t FailedFlushDiskGetLastError=REBASE(0x2AB8660);
            const uintptr_t FailedFormatContentId=REBASE(0x4BC4610);
            const uintptr_t FailedFunctionMarshallerImplCreateError=REBASE(0x4D5BA30);
            const uintptr_t FailedGetProcessPathError=REBASE(0x29F4D80);
            const uintptr_t FailedIterateBundleEntries=REBASE(0x4BC5A40);
            const uintptr_t FailedOpenMockStreamFormat=REBASE(0x3CCDDF0);
            const uintptr_t FailedOpenVideoDemuxer=REBASE(0x3CABDF0);
            const uintptr_t FailedReadPacket=REBASE(0x3CD0F40);
            const uintptr_t FailedReadSerializedInstance=REBASE(0x61B4F50);
            const uintptr_t FailedResizeMappedFileZuBytes=REBASE(0x2AB84B0);
            const uintptr_t FailedSeekVideoStream=REBASE(0x3CC8DB0);
            const uintptr_t FailedSendSettingsPayload=REBASE(0x61A4200);
            const uintptr_t FailedSerializeHumanoidDescriptionError=REBASE(0x1834ED0);
            const uintptr_t FailedSetFilePointerHANDLEZuBytesGetLast=REBASE(0x2AB7DA0);
            const uintptr_t FailedSetTimePosition=REBASE(0x3EC89E0);
            const uintptr_t FailedStartNewProcessCodeReason=REBASE(0x29F53B0);
            const uintptr_t FailedStepVideo=REBASE(0x3EC9BD0);
            const uintptr_t FirstValueHapticServiceSetMotorValidNumb=REBASE(0x4D7E520);
            const uintptr_t GetTokenDetailsAsyncDataModelNull=REBASE(0x1844940);
            const uintptr_t GetTokenDetailsReturnedNon200=REBASE(0x1845680);
            const uintptr_t GotNullPtrWithinOnReadAudio=REBASE(0x3CC97E0);
            const uintptr_t GroupServicePromptJoinCompletedPromptPro=REBASE(0x3175BF0);
            const uintptr_t H264StreamDidContainAny=REBASE(0x1E4F020);
            const uintptr_t HeapProfileDataTooLargeReplicate=REBASE(0x4204EC0);
            const uintptr_t HttpRequestError=REBASE(0x34A2EF0);
            const uintptr_t HuffmanDecodingGotError=REBASE(0x23D5080);
            const uintptr_t HuffmanEncodingGotError=REBASE(0x23D5030);
            const uintptr_t IXPFailedParseJSONField=REBASE(0x3A502A0);
            const uintptr_t InsertServiceGetLatestAssetVersionSucces=REBASE(0x357DB20);
            const uintptr_t LMSPostAppEventUnsupportedEvent=REBASE(0x10CAEA0);
            const uintptr_t LinkingProtocolGetBoolAttemptedGetBoolJs=REBASE(0x44E0C60);
            const uintptr_t LinkingProtocolGetStringAttemptedGetStri=REBASE(0x44E0AF0);
            const uintptr_t LinkingProtocolImplOpenURLShellExcecuteF=REBASE(0x44F4690);
            const uintptr_t LoadStreamAnimation=REBASE(0x19AF8F0);
            const uintptr_t MarketplaceApiClientFailedParsingError=REBASE(0x610F900);
            const uintptr_t MarketplaceApiClientGamePassPurchasePurc=REBASE(0x12F8040);
            const uintptr_t MergeAndFilterRegionsCregConnectionsInva=REBASE(0x24AFC20);
            const uintptr_t MessageBusReceivedWithoutValidBool=REBASE(0x143EC80);
            const uintptr_t MessageBusReceivedWithoutValidString=REBASE(0x143E910);
            const uintptr_t MessageBusServiceCannotFindCustomTelemet=REBASE(0x143C270);
            const uintptr_t MissingFileHeader=REBASE(0x1189CC0);
            const uintptr_t MultipleRootJointsDetectedFACSRig=REBASE(0x49AC220);
            const uintptr_t NativeAdsGetQueryInfoHandleNull=REBASE(0x514B9F0);
            const uintptr_t NativeAdsIsGmaSdkInstalledHandleNull=REBASE(0x103E5F0);
            const uintptr_t NativeAdsSetAdStringWithDetailedCallback=REBASE(0x514BDC0);
            const uintptr_t NativeAdsShowAdHandleNull=REBASE(0x514C440);
            const uintptr_t OutBoundsTargetFrameIndexTargetTimeFrame=REBASE(0x151DF60);
            const uintptr_t PlayerCalculateNextSpawnLocationPlayerWo=REBASE(0x3DDBFD0);
            const uintptr_t PlayerLoadCharacterPlayerWorld=REBASE(0x3E1BA50);
            const uintptr_t PlayerRespawnTimerElapsedButPlayer=REBASE(0x3DD71B0);
            const uintptr_t PluginScopeForPluginGotEmptyPluginId=REBASE(0x41944C0);
            const uintptr_t ProduceBackgroundFailed=REBASE(0x6126150);
            const uintptr_t ReceivePacket=REBASE(0x6234070);
            const uintptr_t ReceivedHeapProfileDataUnknownRequest=REBASE(0x4205B80);
            const uintptr_t RegisteringAny=REBASE(0x5174340);
            const uintptr_t RemoteAnimationStreamSourceCloseFailedRe=REBASE(0x19AEAD0);
            const uintptr_t RemoteAnimationStreamSourceOpenFailedRes=REBASE(0x19AE410);
            const uintptr_t RequestCharacterCouldResolveRemotePlayer=REBASE(0x47A5FA0);
            const uintptr_t RobloxSerializableInstanceDoesHaveAttrib=REBASE(0x1835FD0);
            const uintptr_t RunClusterSenderHelper=REBASE(0x6231C20);
            const uintptr_t RvSchedulerServicePoolReadyInsideRunCall=REBASE(0x5335430);
            const uintptr_t ScalingUpXXFailed=REBASE(0x5A23AA0);
            const uintptr_t ScopeCheckInitiatedEventNonLocal=REBASE(0x3DE65B0);
            const uintptr_t ScreenProtocolCoreCouldnTParseEdgeInsets=REBASE(0x1437BE6);
            const uintptr_t SerializedOverridesBlobRejectedBytesExce=REBASE(0x2878CD0);
            const uintptr_t SetStateBufferingStatePlaybackStateState=REBASE(0x5C40470);
            const uintptr_t SetStateReadyStatePlaybackStateStatePlay=REBASE(0x5C40000);
            const uintptr_t SettingsFileModifiedWhileBeingRead=REBASE(0x452DB50);
            const uintptr_t SettingsSaveStateCouldRemoveTempSettings=REBASE(0x32139E0);
            const uintptr_t SkippedPerformanceProbeUntrustedDomainUr=REBASE(0x2691AA0);
            const uintptr_t SocialServicePromptRsvpToEventCompletedP=REBASE(0x34C6FF0);
            const uintptr_t StreamDoesContainMagicNumber=REBASE(0x11899B0);
            const uintptr_t TeleportDoesIncludeDestinationPlaceInfo=REBASE(0x100C9B0);
            const uintptr_t TrackerAnimationStreamSourceOpenFailedOp=REBASE(0x19AC1D0);
            const uintptr_t TrackerStatusTelemetryDataNumberStateNam=REBASE(0x191D0E0);
            const uintptr_t TrackerStatusTelemetryDataUpdateCurrentS=REBASE(0x191F640);
            const uintptr_t UGCValidationDidReturnResult=REBASE(0x335AF60);
            const uintptr_t UnableCastRootInstanceMeshPart=REBASE(0x4AB0790);
            const uintptr_t UnableConvertValueJson=REBASE(0x11726C0);
            const uintptr_t UnableGetScriptContext=REBASE(0x320D440);
            const uintptr_t UnableInitializeLibsodium=REBASE(0x5BEEAD0);
            const uintptr_t UnableOpenCameraParamsXFps=REBASE(0x5A22D80);
            const uintptr_t UnexpectedErrorContentReferenceEditableI=REBASE(0x1833250);
            const uintptr_t UnexpectedRealtimeConnectionState=REBASE(0x496F730);
            const uintptr_t UniverseMembersMissingResponse=REBASE(0x34B9AB0);
            const uintptr_t UnknownJavascriptError=REBASE(0x16BF2F0);
            const uintptr_t ValidationFailed=REBASE(0x34D7800);
            const uintptr_t ValidationResponseCannotParsed=REBASE(0x34BCDD0);
            const uintptr_t VideoCacheFileError=REBASE(0x61F1AC0);
            const uintptr_t VideoDeviceInputInitializeVideoCaptureSe=REBASE(0x3CA07A0);
            const uintptr_t VideoDeviceInputRaiseWithDMWriteLockUnab=REBASE(0x3CA1E40);
            const uintptr_t VideoDeviceInputSubscribeUnableSubscribe=REBASE(0x3CA2360);
            const uintptr_t VideoFrameV2CreateVideoInputFormatAsyncF=REBASE(0x3ED0330);
            const uintptr_t VideoFrameVideo2VideoPlaybackControllerC=REBASE(0x3ED0B20);
            const uintptr_t VideoStreamDecodingFailureErrorCode=REBASE(0x3CD1AA0);
            const uintptr_t VideoUsingResolutionSupported=REBASE(0x3D1AC70);
            const uintptr_t WebViewOpenNotificationDataMissingURL=REBASE(0x74D210);
            const uintptr_t WrapLayerContentShouldNoneWhen=REBASE(0x1B40D60);
        }
        namespace ExampleProtocolCore
        {
            const uintptr_t FailedPrintWorldNativeConsole=REBASE(0x5132730);
            const uintptr_t PrintHelloAvailableCurrentPlatform=REBASE(0x5132B70);
            const uintptr_t ReceivedPrintTestNotificationPlatform=REBASE(0x5132E10);
        }
        namespace ExampleV2Handler
        {
            const uintptr_t FailedPrintWorldNativeConsole=REBASE(0x4EAEC50);
            const uintptr_t PrintHelloAvailableCurrentPlatform=REBASE(0x4EAF260);
            const uintptr_t ReceivedPrintTestNotificationPlatform=REBASE(0x4EAEE00);
        }
        namespace ExperienceAuthService
        {
            const uintptr_t CouldFindScopeCheckGuidAfter=REBASE(0x318AE90);
            const uintptr_t ExperienceAuthServiceLongerExists=REBASE(0x3189DB0);
            const uintptr_t ExperienceAuthServiceLongerExistsAfterDa=REBASE(0x318A160);
            const uintptr_t FailedConstructRequestBody=REBASE(0x3189510);
            const uintptr_t ScopeArrayContainsValueInvalidType=REBASE(0x3188AC0);
            const uintptr_t ScopeCheckAsyncShouldOnlyCalledServer=REBASE(0x3186CA0);
        }
        namespace ExperienceContextHolder
        {
            const uintptr_t DMHasBeenInitializedCannotDestroyed=REBASE(0x4D31D90);
            const uintptr_t DMNullCannotPause=REBASE(0x4D31C30);
            const uintptr_t DMNullCannotRun=REBASE(0x4D31A20);
            const uintptr_t ExperienceContextHolderExperienceContext=REBASE(0x4D30C70);
            const uintptr_t UnsafeCallEngineContext=REBASE(0x4D30DA0);
        }
        namespace ExperienceCoordinator
        {
            const uintptr_t AddDataModelJobInvalidDM=REBASE(0x1474190);
            const uintptr_t ExperienceCoordinatorExperienceCoordinat=REBASE(0x1473200);
            const uintptr_t FinalizeAttemptingFinalizeMoreThanOnce=REBASE(0x1473A40);
            const uintptr_t SubmitDataModelTaskInvalidDM=REBASE(0x1473E80);
        }
        namespace ExperienceService
        {
            const uintptr_t ExperienceServiceErrorCallbackPointerMis=REBASE(0x44F7850);
            const uintptr_t ExperienceServiceSuccessCallbackMissingE=REBASE(0x44F6E00);
            const uintptr_t ExperienceServiceSuccessCallbackPointerM=REBASE(0x44F7620);
        }
        namespace ExperienceStateCaptureController
        {
            const uintptr_t CreateCaptureDataModelAndSwitchCaptureDM=REBASE(0x4D910E0);
            const uintptr_t CreateCaptureDataModelAndSwitchDmCapture=REBASE(0x4D93180);
            const uintptr_t CreateCaptureDataModelAndSwitchNullParam=REBASE(0x4D90BF0);
            const uintptr_t CreateCaptureDataModelNullReferencedData=REBASE(0x4D91D10);
            const uintptr_t CreatingNewExperienceStateCaptureControl=REBASE(0x4D90920);
            const uintptr_t DestroyCaptureDataModelIfExistsSkippingD=REBASE(0x4D924A0);
            const uintptr_t OnSwitchBackNullReferencedDataModel=REBASE(0x4D92DB0);
            const uintptr_t OnSwitchNullParameterSDmLoadedState=REBASE(0x4D92A10);
            const uintptr_t PrepareToSwitchNullReferencedDataModel=REBASE(0x4D926F0);
            const uintptr_t SwitchBackAndDestroyCaptureDataModelCapt=REBASE(0x4D932F0);
            const uintptr_t SwitchBackAndDestroyCaptureDataModelDmCa=REBASE(0x4D91740);
            const uintptr_t SwitchBackAndDestroyCaptureDataModelNull=REBASE(0x4D91350);
        }
        namespace ExperienceStateCaptureServiceVerboseDebug
        {
            const uintptr_t FilteringOutNonVisibleUIElement=REBASE(0xE9A220);
        }
        namespace ExperienceStateDeltasVerboseErrors
        {
            const uintptr_t FailedCreateInstanceTypeGuid=REBASE(0xE982D0);
            const uintptr_t FailedParseColorHexValue=REBASE(0xE99EF0);
            const uintptr_t FailedReferencedInstanceApplyRefProp=REBASE(0xE98070);
            const uintptr_t IgnoringInstanceParent=REBASE(0xEA27B0);
        }
        namespace ExperienceStateRecording
        {
            const uintptr_t BatchDiskWriteFailureOpPath=REBASE(0xE84ED0);
            const uintptr_t DataCenterIDBlocklistedSkippingRecorderS=REBASE(0x35A51D0);
            const uintptr_t StaleFileDetectedFileSeqStill=REBASE(0xE8F490);
            const uintptr_t StartedBatchFileRecorderPath=REBASE(0xE943F0);
            const uintptr_t StoppingDMRecorderDataPingMs=REBASE(0xE96090);
        }
        namespace ExperimentationProtocolCore
        {
            const uintptr_t ExperimentationProtocolCoreConstructedAd=REBASE(0x5CCEC10);
            const uintptr_t ExperimentationProtocolCoreDestroyedRemo=REBASE(0x5CCEEB0);
        }
        namespace ExtractPackageDefinition
        {
            const uintptr_t PlaceIdFileDehydratedButExtractPackageDe=REBASE(0x321CB90);
        }
        namespace FMOD
        {
            const uintptr_t FMODAPIErrorFMODRESULTInstance=REBASE(0x2882B50);
            const uintptr_t FMODObjectParentFmodOperationError=REBASE(0x2899B60);
        }
        namespace FRM
        {
            const uintptr_t FRMGatesProfileCloudsSingleTapGateConstF=REBASE(0x49A3B50);
            const uintptr_t FRMQualityLevelFrameTimeState=REBASE(0x3681720);
            const uintptr_t FailedParseFRMLockstepProfileOverrideUsi=REBASE(0x49A0CE0);
            const uintptr_t ProfileOverrideInvalidRange=REBASE(0x623B310);
            const uintptr_t ProfileOverrideNonNumericSSAOValue=REBASE(0x499ED70);
            const uintptr_t ProfileOverrideRangeOutBoundsValid=REBASE(0x499E8A0);
            const uintptr_t ProfileOverrideUnknownFeatureKey=REBASE(0x499F2C0);
            const uintptr_t StartingFRMQualitySettingStartingLevel=REBASE(0x49A26D0);
            const uintptr_t SteppingFRMQualityOldNew=REBASE(0x49A7D4F);
        }
        namespace FaceAnimatorThreadingTrace
        {
            const uintptr_t FaceAnimatorServiceImplOnServiceProvider=REBASE(0x1B55270);
            const uintptr_t FaceAnimatorServiceInitializeInferenceEn=REBASE(0x1B590FF);
            const uintptr_t FaceAnimatorServiceSetVideoAnimationEnab=REBASE(0x1B5A360);
        }
        namespace FaceAnimatorTrace
        {
            const uintptr_t FaceAnimatorServiceA2cEnabled=REBASE(0x1B55E80);
            const uintptr_t FaceAnimatorServiceAudioInitDataModelUna=REBASE(0x1B4DDA0);
            const uintptr_t FaceAnimatorServiceCompletingSDKSetupAud=REBASE(0x1B53700);
            const uintptr_t FaceAnimatorServiceDelayFlagInitializing=REBASE(0x1B4E290);
            const uintptr_t FaceAnimatorServiceDisconnectFromStepSig=REBASE(0x1B54B80);
            const uintptr_t FaceAnimatorServiceDisconnectFromVideoSt=REBASE(0x1B575E0);
            const uintptr_t FaceAnimatorServiceFFlagFinalizingAsyncI=REBASE(0x1B52270);
            const uintptr_t FaceAnimatorServiceFFlagProgressJITModel=REBASE(0x1B5DD10);
            const uintptr_t FaceAnimatorServiceFFlagProgressModelDel=REBASE(0x1B5DB80);
            const uintptr_t FaceAnimatorServiceFailedCreateInitialAu=REBASE(0x1B4E000);
            const uintptr_t FaceAnimatorServiceIsVideoAvailableCamer=REBASE(0x1B570B0);
            const uintptr_t FaceAnimatorServiceSetVideoInputEnabledR=REBASE(0x1B554E0);
            const uintptr_t FaceAnimatorServiceStart=REBASE(0x1B54740);
            const uintptr_t FaceAnimatorServiceTriggeredJustTimeVide=REBASE(0x1B50250);
            const uintptr_t FaceAnimatorServiceUsingExistingContext=REBASE(0x1B5A740);
        }
        namespace FaceChatDebugTrace
        {
            const uintptr_t AnimatorLoadStreamAnimation=REBASE(0x17611A0);
            const uintptr_t AnimatorLoadStreamAnimationDeprecated=REBASE(0x1760650);
            const uintptr_t AnimatorLoadStreamAnimationForSelfieView=REBASE(0x1760BC0);
        }
        namespace FacialAgeEstimationProtocol
        {
            const uintptr_t CallbackReceivedNonexistentInquiryID=REBASE(0x4EAC770);
        }
        namespace FacialAgeEstimationService
        {
            const uintptr_t CallingUpdateConfigurationUserId=REBASE(0x3221E90);
            const uintptr_t ReceivedAgeVerificationStatusChangeEvent=REBASE(0x3221BA0);
        }
        namespace FacialAnimationStreamingServiceV2Verbose
        {
            const uintptr_t FacialAnimationStreamingServiceV2SetStat=REBASE(0x1921970);
        }
        namespace FastLogValueChanged
        {
            const uintptr_t FailedApplyAnyOverride=REBASE(0x4A3B4F0);
        }
        namespace FeatureRestrictionManager
        {
            const uintptr_t FailedCreatePlayersUpdateFeatureTimeoutF=REBASE(0x3181F70);
            const uintptr_t FeatureRestrictionManagerFailedParsingEr=REBASE(0x61AA0F0);
        }
        namespace FileCulling
        {
            const uintptr_t ErrorFileSystem=REBASE(0x617CF40);
        }
        namespace FileMeshDataValidatorLogChannel
        {
            const uintptr_t FileMeshDataValidationPolicyIgnored=REBASE(0x23FFFD0);
        }
        namespace FlagCache
        {
            const uintptr_t CachedExpiryTimeFoundTombstoneSkipping=REBASE(0x452D160);
            const uintptr_t ChannelMismatchPrecheckFailedTombstoneCh=REBASE(0x452D530);
            const uintptr_t FailedBurnAfterReadFailedRename=REBASE(0x452F8C0);
            const uintptr_t FetchAndCacheFlagsFromCdnFetchFlagsFromC=REBASE(0x452AA00);
            const uintptr_t FlagCacheExpiredElapsedSeconds=REBASE(0x452F770);
            const uintptr_t FlagPrefetchTimedOutAfterS=REBASE(0x452B2B0);
            const uintptr_t WriteFlagCacheWroteSignatureLengthSignat=REBASE(0x4530140);
            const uintptr_t WritingPendingFlagCacheDisk=REBASE(0x4525700);
        }
        namespace FlagFetchingStarterModule
        {
            const uintptr_t FailedDownloadApplyCriticalSettingsPleas=REBASE(0x51B16C0);
            const uintptr_t FetchingLoadingFlagsCDN=REBASE(0x51B05F0);
            const uintptr_t FlagCacheLoadFailedFallingBack=REBASE(0x51AF700);
            const uintptr_t PrefetchFlagsCDNSucceededAfterCached=REBASE(0x51AFE20);
            const uintptr_t PrefetchFlagsCDNSucceededLoadingFlags=REBASE(0x51B0270);
            const uintptr_t SuccessfullyLoadedFlags=REBASE(0x51B0F10);
        }
        namespace FontSubsystem
        {
            const uintptr_t CouldRenderGlyphLoadedFontErrorCode=REBASE(0x25A0890);
            const uintptr_t ErrorSetFontPixelSizeLoadedFont=REBASE(0x25A1820);
            const uintptr_t FontFamilyLoadedFaces=REBASE(0x259DC00);
            const uintptr_t FontSubsetFailedLoad=REBASE(0x25A4430);
            const uintptr_t FreeTypeStrokerInitializationFailedError=REBASE(0x259C040);
            const uintptr_t Log=REBASE(0x25A3490);
        }
        namespace FriendServiceCache
        {
            const uintptr_t FriendServiceFriendRequestOnlineLldLld=REBASE(0x2FDE350);
            const uintptr_t FriendServicePlayerRemovingLld=REBASE(0x2FDDB50);
        }
        namespace FriendServiceCallbacks
        {
            const uintptr_t FriendServiceStatusCallbackLldLld=REBASE(0x2FDE510);
        }
        namespace FriendServiceLocalRequests
        {
            const uintptr_t Error=REBASE(0x2FE9050);
            const uintptr_t Failure=REBASE(0x2FD8F50);
            const uintptr_t Success=REBASE(0x2FD9CA0);
        }
        namespace FriendServiceWebRequests
        {
            const uintptr_t GetFriendsWhoPlayedAsyncRequestFailed=REBASE(0x2FE50C0);
        }
        namespace FriendsCallingExperienceController
        {
            const uintptr_t FriendsCallingExperienceControllerFinali=REBASE(0x4D70090);
            const uintptr_t FriendsCallingExperienceControllerInitia=REBASE(0x4D6FDC0);
        }
        namespace FriendsCallingModule
        {
            const uintptr_t FriendsCallingModuleCreatedInstanceCall=REBASE(0x4C7E530);
            const uintptr_t FriendsCallingModuleDroppingCallingState=REBASE(0x4C7D250);
            const uintptr_t FriendsCallingModuleIgnoringIncomingCall=REBASE(0x4C7D8B0);
            const uintptr_t FriendsCallingModuleReleasingInstanceCal=REBASE(0x4C7EBA0);
            const uintptr_t FriendsCallingModuleStartCallCallDMTeari=REBASE(0x4C7C5E0);
            const uintptr_t FriendsCallingProjectedViewCreatedViewCa=REBASE(0x4C85220);
            const uintptr_t FriendsCallingProjectedViewReleasingView=REBASE(0x4C85A10);
        }
        namespace GDKCredentialsProtocol
        {
            const uintptr_t OnGetHeadersRequestUrlMethodAreEmtpy=REBASE(0x776960);
        }
        namespace GDKResourcesManager
        {
            const uintptr_t CouldnTReceiveAuthCodePrivacy=REBASE(0x77CB20);
            const uintptr_t Failed08X=REBASE(0x779190);
            const uintptr_t UserLacksMultiplayerPrivilegesAttempting=REBASE(0x77D310);
            const uintptr_t XUserAddAsyncFailed08X=REBASE(0x77B650);
            const uintptr_t XUserAddResultFailed08X=REBASE(0x77B830);
            const uintptr_t XUserResolvePrivilegeWithUiAsyncFailed08=REBASE(0x77D140);
            const uintptr_t XblContextCreateHandleFailed08X=REBASE(0x77B9B0);
        }
        namespace GDKRobuxUpsell
        {
            const uintptr_t GDKRobuxUpsellDidSuccessfullyComplete=REBASE(0x74E690);
        }
        namespace GDKSessionManager
        {
            const uintptr_t XGameInviteRegisterForEventFailed08X=REBASE(0x780B5A);
            const uintptr_t XTaskQueueDuplicateHandleFailed08X=REBASE(0x77E0D0);
            const uintptr_t XblMultiplayerClearActivityAsyncFailed08=REBASE(0x77F3F0);
            const uintptr_t XblMultiplayerGetSessionByHandleAsyncFai=REBASE(0x77F760);
            const uintptr_t XblMultiplayerSessionCreateHandleFailed=REBASE(0x77E360);
            const uintptr_t XblMultiplayerSessionCurrentUserSetStatu=REBASE(0x77FC90);
            const uintptr_t XblMultiplayerSetActivityAsyncFailed08X=REBASE(0x77F140);
            const uintptr_t XblMultiplayerWriteSessionAsyncFailed08X=REBASE(0x77EB60);
            const uintptr_t XblMultiplayerWriteSessionByHandleAsyncF=REBASE(0x780150);
        }
        namespace GameJoinUtil
        {
            const uintptr_t CreatorBanStartTimeCouldParsed=REBASE(0x624EF80);
            const uintptr_t CreatorBanTextFilterStatusInvalid=REBASE(0x4CCCD00);
            const uintptr_t CreatorExperienceBanMessageUponTeleport=REBASE(0x4CD6600);
            const uintptr_t DecodeTeamTestJoinResponseForTeleportInv=REBASE(0x624F2C0);
            const uintptr_t DecodeTeamTestJoinResponseForTeleportRes=REBASE(0x4CD0BA0);
            const uintptr_t DefaultHandlerTeleportFailedState=REBASE(0x4CE79B0);
            const uintptr_t DefaultHandlerTeleportSucceeded=REBASE(0x4CE78E0);
            const uintptr_t DelayingRequest42fSeconds=REBASE(0x4CC5470);
            const uintptr_t DelayingRequestSeconds=REBASE(0x4CC5D80);
            const uintptr_t ForcedPopAttachedForcedPopJoinGameBody=REBASE(0x4CDF760);
            const uintptr_t GameJoinFailedHereSWhy=REBASE(0x4CE9030);
            const uintptr_t GameJoinSucceeded=REBASE(0x4CCBC70);
            const uintptr_t GameJoinUtilDecodeTeamTestJoinResponseIn=REBASE(0x624F1B0);
            const uintptr_t GameJoinUtilDecodeTeamTestJoinResponseTe=REBASE(0x4CD0300);
            const uintptr_t GameJoinUtilInitiateTeleportToInstanceUR=REBASE(0x4CDC660);
            const uintptr_t GameJoinUtilInitiateTeleportToPlaceURLPO=REBASE(0x4CDD4A0);
            const uintptr_t GameJoinUtilInitiateTeleportToReservedSe=REBASE(0x4CDE440);
            const uintptr_t GameJoinUtilJoinGamePostCrossExpVoiceURL=REBASE(0x4CE67C0);
            const uintptr_t GameJoinUtilJoinGamePostGameInstanceURLB=REBASE(0x4CE0A70);
            const uintptr_t GameJoinUtilJoinGamePostPartyURLBODY=REBASE(0x4CE2EA0);
            const uintptr_t GameJoinUtilJoinGamePostPlayTogetherGame=REBASE(0x4CE17A0);
            const uintptr_t GameJoinUtilJoinGamePostPrivatePartyURLB=REBASE(0x4CE3800);
            const uintptr_t GameJoinUtilJoinGamePostPrivateServerURL=REBASE(0x4CE4E70);
            const uintptr_t GameJoinUtilJoinGamePostReservedServerUR=REBASE(0x4CE5B20);
            const uintptr_t GameJoinUtilJoinGamePostSpecificUserURLB=REBASE(0x4CE2260);
            const uintptr_t GameJoinUtilJoinGamePostStandardURLBODY=REBASE(0x4CDFC00);
            const uintptr_t GameJoinUtilMakePlaceLauncherRequestForT=REBASE(0x4CD9460);
            const uintptr_t GameJoinUtilMakePlaceLauncherRequestRequ=REBASE(0x4CD1050);
            const uintptr_t GameJoinUtilProcessingJoinParameters=REBASE(0x4CC9E40);
            const uintptr_t GameJoinV2StatRandomMetricValue=REBASE(0x4CCDE60);
            const uintptr_t JoinGamePostIsolatedTeamTestURL=REBASE(0x4CE40D0);
            const uintptr_t JoinGamePostTeamTestUniqueGameCode=REBASE(0x4CE4350);
            const uintptr_t PopUdpProbeProbeDataCachedYetSkipping=REBASE(0x4CDF480);
            const uintptr_t SuccessfullyWritingEventId=REBASE(0x4CCA0E0);
            const uintptr_t TeamTestTeleportFailed=REBASE(0x4CD5ED0);
        }
        namespace GameJoinV2
        {
            const uintptr_t CheckingIfUserGameJoinV2AllowlistUserId=REBASE(0x4D418C0);
            const uintptr_t GameJoinV2FinishJoinGamePostV2URLBODY=REBASE(0x4D44530);
            const uintptr_t GameJoinV2FinishTeleportPostV2URLBODY=REBASE(0x4D45350);
            const uintptr_t GameJoinV2OnAcknowledgedAttemptIdRetryMs=REBASE(0x4D43720);
            const uintptr_t GameJoinV2OnResponseReadyStatusJobIdQueu=REBASE(0x4D43B10);
            const uintptr_t GameJoinV2TerminalErrorKindStatusMappedS=REBASE(0x4D43FE0);
        }
        namespace GamePassFreeTrial
        {
            const uintptr_t BatchGetOwnershipRequestPassEsIncludeOve=REBASE(0x1281E80);
            const uintptr_t BatchGetOwnershipResponseHasOwnershipsUs=REBASE(0x1283BA0);
            const uintptr_t CacheHitUserPassOwnedActive=REBASE(0x12850A0);
            const uintptr_t CacheInsertUserPassOwnedActive=REBASE(0x1285590);
            const uintptr_t GamePassFreeTrialRedeemedDroppedOrchestr=REBASE(0x12CC120);
            const uintptr_t GamePassFreeTrialRedeemedPassVerificatio=REBASE(0x12E4290);
            const uintptr_t GamePassFreeTrialRedeemedPassVerifiedRCC=REBASE(0x12CC980);
            const uintptr_t GetPassOwnershipAsyncUserPassOwnedActive=REBASE(0x12CA620);
            const uintptr_t OwnershipsUserPassOwnedActiveEndTime=REBASE(0x1282CB0);
            const uintptr_t RedeemGamePassFreeTrialUserPassApplied=REBASE(0x12CB970);
            const uintptr_t UserOwnsGamePassAsyncUserPassOwnedActive=REBASE(0x12E3FB0);
        }
        namespace GamePassPurchase
        {
            const uintptr_t GetPurchaseBodyJsonPurchasePayloadExceed=REBASE(0x12743D0);
            const uintptr_t GetRequestUrlGamePassPurchaseRequestorOn=REBASE(0x1273550);
            const uintptr_t OrchestrationLayerAvailableMarketplaceSe=REBASE(0x12773D0);
            const uintptr_t ParseResponsesGamePassPurchaseRequestorO=REBASE(0x1273C80);
            const uintptr_t ParseResponsesHTTPRequestFailedErrorCode=REBASE(0x12736A0);
            const uintptr_t RequestorConstructedMaxTimeQueueMs=REBASE(0x1273270);
        }
        namespace GamePassStudioOwnershipCacheFix
        {
            const uintptr_t SetOrchestratedGamePassOwnershipCacheEnt=REBASE(0x12CF4B0);
        }
        namespace GamepadService
        {
            const uintptr_t TabUsedButLayerCollectorDoes=REBASE(0x3BDC550);
        }
        namespace GenerationService
        {
            const uintptr_t AllValidationPassedCreatingMeshSegmentat=REBASE(0x4AD85D0);
            const uintptr_t AllValidationPassedCreatingModelGenerati=REBASE(0x4AC5290);
            const uintptr_t AnimationGenerationJobMotionUpdatePriorJ=REBASE(0x4AEAB20);
            const uintptr_t AssetServiceUnavailableSegmentationPermi=REBASE(0x4AD9470);
            const uintptr_t BeginningDownloadMesh=REBASE(0x4AE43A0);
            const uintptr_t BeginningGLBDownload=REBASE(0x4ACCE30);
            const uintptr_t BeginningRBXMDownload=REBASE(0x4AD0F20);
            const uintptr_t BeginningRBXMDownloadUrl=REBASE(0x4AA25C0);
            const uintptr_t CallerLacksEditPermissionMeshAsset=REBASE(0x4ADAE60);
            const uintptr_t ContentProviderAvailableImageFetch=REBASE(0x4AC8660);
            const uintptr_t CouldWriteByteSOutputFile=REBASE(0x4AE48A0);
            const uintptr_t CreatingRuntimeContentMODELGENERATIONID=REBASE(0x4ACF190);
            const uintptr_t DataModelLostDuringImageFetchCallback=REBASE(0x4AC8AE0);
            const uintptr_t DataModelLostDuringImageFetchError=REBASE(0x4AC9BB0);
            const uintptr_t EditableModelConversionCompletedSuccessf=REBASE(0x4ACFF90);
            const uintptr_t EditableModelConversionFailed=REBASE(0x4AD0770);
            const uintptr_t ErrorInvokingProgressCallback=REBASE(0x6244540);
            const uintptr_t ExceptionDuringConversionCallback=REBASE(0x6244AC0);
            const uintptr_t ExceptionDuringErrorCallback=REBASE(0x6244DC0);
            const uintptr_t ExceptionGLBImportCompletionCallback=REBASE(0x62459C0);
            const uintptr_t ExceptionGLBImportErrorCallbackTask=REBASE(0x6246100);
            const uintptr_t FailedConvert=REBASE(0x4AC0C30);
            const uintptr_t FailedCreateAnimationGenerationJob=REBASE(0x4AA9C50);
            const uintptr_t FailedCreateMeshSegmentationJob=REBASE(0x4AA4E70);
            const uintptr_t FailedCreateModelGenerationJob=REBASE(0x4AA4180);
            const uintptr_t FailedReportErrorExceptionGLBImport=REBASE(0x6245900);
            const uintptr_t FailedReportErrorUnknownExceptionGLB=REBASE(0x6245CA0);
            const uintptr_t GLBDownloadSuccessfulBytes=REBASE(0x4ACD3A0);
            const uintptr_t GLBImportFailed=REBASE(0x4AD09B0);
            const uintptr_t ImageDecodeEncodeFailed=REBASE(0x62455D0);
            const uintptr_t IndividualConversionCompletedPendingConv=REBASE(0x4ABFFE0);
            const uintptr_t InvalidResultGenerateMeshAsync=REBASE(0x4AA9460);
            const uintptr_t KeyMappedOptions=REBASE(0x4ADF050);
            const uintptr_t MeshExportSegmentationFailed=REBASE(0x4ADC110);
            const uintptr_t MeshImportedSuccessfully=REBASE(0x4AAB110);
            const uintptr_t MeshPartConversionCompletedConversionsRe=REBASE(0x4ABFC4E);
            const uintptr_t MeshPartDoesHaveEditableContentSkipping=REBASE(0x4ABF8E0);
            const uintptr_t MeshPartWasDestroyedBeforeConversionComp=REBASE(0x4AC0280);
            const uintptr_t MeshSegmentationCompletedDownloadingSegm=REBASE(0x4ADC470);
            const uintptr_t MeshSegmentationJobConstructedPreValidat=REBASE(0x4AD8C00);
            const uintptr_t MeshSegmentationJobRequestUrl=REBASE(0x4AD8FE0);
            const uintptr_t MeshSegmentationPermissionCheckFailed=REBASE(0x4ADB3A0);
            const uintptr_t MetadataMappingWasUnableParsed=REBASE(0x4AE6FA0);
            const uintptr_t ModelGenerationCompletedButValidGLB=REBASE(0x4ACBE90);
            const uintptr_t ModelGenerationJobConstructedPreValidate=REBASE(0x4AC5EC0);
            const uintptr_t ModelGenerationOptionsDepthExceededMax=REBASE(0x4AD66D0);
            const uintptr_t ModelInstanceFoundUsingOriginalRootModel=REBASE(0x4AC0F10);
            const uintptr_t OutMemoryDuringImageDecodeEncode=REBASE(0x62456E0);
            const uintptr_t PollingGeneratedMeshJobId=REBASE(0x4AE2E00);
            const uintptr_t PollingGeneratedModelFailed=REBASE(0x4AD60A0);
            const uintptr_t PollingGeneratedModelJobId=REBASE(0x4AD5CE0);
            const uintptr_t ProcessRemoteEvent=REBASE(0x4AA1420);
            const uintptr_t RBXMContainedRootInstancesExpected1=REBASE(0x4AA2E60);
            const uintptr_t RBXMDeserializeReturnedInstancesExpected=REBASE(0x4AD1ED0);
            const uintptr_t RBXMDeserializeThrew=REBASE(0x6244190);
            const uintptr_t RBXMDownloadSuccessfulBytes=REBASE(0x4AD1470);
            const uintptr_t ReplicatingRequestGenerationReplicationE=REBASE(0x4AA9780);
            const uintptr_t ReplicationRequestEventTriggeredServer=REBASE(0x4AAB530);
            const uintptr_t ResponseBodyWasUnableParsed=REBASE(0x4ADA120);
            const uintptr_t RunningGenerationJobPreValidatedParamete=REBASE(0x4AD47D0);
            const uintptr_t RunningMeshGenerationJobUserIdUniverseId=REBASE(0x4AA7980);
            const uintptr_t SegmentedRBXMDeserializeReturnedInstance=REBASE(0x4ADD0B0);
            const uintptr_t SendingRequestStartMeshGeneration=REBASE(0x4AE1230);
            const uintptr_t SendingRequestStartMeshSegmentation=REBASE(0x4AD9E00);
            const uintptr_t StartingContentConversionUsingAssetServi=REBASE(0x4ABDD50);
            const uintptr_t StartingConversionEditableModelRuntimeCo=REBASE(0x4AC1650);
            const uintptr_t UnableCreateGenerationService=REBASE(0x4AE56E0);
            const uintptr_t UnableCreateGenerationServiceGLBImport=REBASE(0x4ACE460);
            const uintptr_t UnableGenerateIntermediateResult=REBASE(0x4AB4890);
            const uintptr_t UnableGenerateMeshJobId=REBASE(0x4AA8DD0);
            const uintptr_t UnableLockIntermediateResultCallback=REBASE(0x4AA8740);
            const uintptr_t UnableSnapshotMeshSegmentationExport=REBASE(0x6246600);
            const uintptr_t UnknownExceptionDuringConversionCallback=REBASE(0x6244CC0);
            const uintptr_t UnknownExceptionDuringErrorCallback=REBASE(0x6244EF0);
            const uintptr_t UnknownExceptionGLBImportCompletionCallb=REBASE(0x6245D60);
            const uintptr_t UnknownExceptionGLBImportErrorCallbackTa=REBASE(0x62461F0);
            const uintptr_t VideoGenGetTriggersFailed=REBASE(0x4ABD830);
            const uintptr_t VideoGenGetTriggersFailedParseResponse=REBASE(0x4ABBA60);
            const uintptr_t VideoGenIceServersFailed=REBASE(0x4ABCF40);
            const uintptr_t VideoGenIceServersFailedParseResponse=REBASE(0x4AB7790);
            const uintptr_t VideoGenOfferFailed=REBASE(0x4ABD100);
            const uintptr_t VideoGenOfferFailedParseResponse=REBASE(0x4AB8DD0);
            const uintptr_t VideoGenReleaseFailed=REBASE(0x4ABDB10);
            const uintptr_t VideoGenReserveFailed=REBASE(0x4ABCD80);
            const uintptr_t VideoGenReserveFailedParseResponse=REBASE(0x4AB69B0);
            const uintptr_t VideoGenSessionIdCollisionReleasingPrior=REBASE(0x4AAC4A0);
            const uintptr_t VideoGenSessionReleased=REBASE(0x4ABD9E0);
            const uintptr_t VideoGenStartFailed=REBASE(0x4ABD310);
            const uintptr_t VideoGenUpdatePromptFailed=REBASE(0x4ABD4C0);
            const uintptr_t VideoGenUpdateTriggersFailed=REBASE(0x4ABD670);
        }
        namespace GetUsersPriceLevels
        {
            const uintptr_t HandleGetUsersPriceLevelsResponseErrorFa=REBASE(0x12CFBB0);
            const uintptr_t HandleGetUsersPriceLevelsResponseSuccess=REBASE(0x12CF940);
        }
        namespace GfxClusters
        {
            const uintptr_t AfterInitialBindAddedParts=REBASE(0x37481E0);
            const uintptr_t FastClustersCheckBreakNonStationary=REBASE(0x3753680);
            const uintptr_t InvalidatingFastClustersPriorityInvalida=REBASE(0x374DCA0);
            const uintptr_t ProcessingNewMegaClusters=REBASE(0x37502A0);
            const uintptr_t SceneUpdaterUpdateCycleCurrentFrame=REBASE(0x3751C30);
            const uintptr_t WaitingPartsPassBegin=REBASE(0x374CCD0);
        }
        namespace GfxClustersFull
        {
            const uintptr_t FrameAddingMegaclusterQueue=REBASE(0x374A4F0);
            const uintptr_t FrameQueueInvalidateFastCluster=REBASE(0x374B260);
            const uintptr_t FrameQueueInvalidatePart=REBASE(0x374B190);
            const uintptr_t FrameQueuePriorityInvalidateFastCluster=REBASE(0x374B410);
            const uintptr_t PartAlreadyHasBindingSkippingAdd=REBASE(0x3755750);
            const uintptr_t PartRemovedWorkspaceBeforeWeCould=REBASE(0x3750EA0);
            const uintptr_t UpdatingEntityPartCluster=REBASE(0x374BB80);
        }
        namespace GlyphProviderCreation
        {
            const uintptr_t CreatedNewGlyphProviderIndexFont=REBASE(0x16290A0);
            const uintptr_t InvalidTypesetterIdOutRangeSize=REBASE(0x3680380);
        }
        namespace GlyphRenderer
        {
            const uintptr_t CannotCreateFontStrokerMemory=REBASE(0x37BCBB0);
            const uintptr_t CannotSetFreeTypeTruetypeInterpreterVers=REBASE(0x37BC550);
        }
        namespace GoogleAnalyticsTracking
        {
            const uintptr_t CouldSetGoogleAnalyticsReporterUninitial=REBASE(0x10CC240);
            const uintptr_t GoogleAnalyticsAlreadyInitialized=REBASE(0x10CC140);
            const uintptr_t GoogleAnalyticsLotteryNumber=REBASE(0x10CD080);
        }
        namespace Graphics
        {
            const uintptr_t AbandoningTexturePackBecauseSolidTexture=REBASE(0x399B810);
            const uintptr_t ActiveNonSimStepParticleIdsEmitterErasin=REBASE(0x3810CF0);
            const uintptr_t ActiveNonSimStepParticleIdsEmitterReserv=REBASE(0x3813640);
            const uintptr_t AllocatingUBO=REBASE(0x59D01B0);
            const uintptr_t CapsASTCSupportProfileLDRSliced=REBASE(0x59CA980);
            const uintptr_t CapsVAOTexStorageMapBufferMapBufferRange=REBASE(0x59CBF20);
            const uintptr_t CloudsAreDisabled=REBASE(0x3777EB0);
            const uintptr_t CloudsFailedDownloadCoverTexture=REBASE(0x377A419);
            const uintptr_t CompiledShadersMsMultiThreadedLoading=REBASE(0x3800460);
            const uintptr_t ConstantBufferCountExtraExceedsDevice=REBASE(0x5A11B40);
            const uintptr_t CopyPhysicalBlocksUnableIgnoreSrcAlphaSi=REBASE(0x399D060);
            const uintptr_t CopyRepeatPixelsSourceDestinationFormats=REBASE(0x399D926);
            const uintptr_t CouldCreateDeviceDueEINVALIDARG=REBASE(0x27C2410);
            const uintptr_t CouldEnableRobustBufferAccessBecause=REBASE(0x59E7C30);
            const uintptr_t D3D11ConstantBufferAllocPageCreateBuffer=REBASE(0x27D2CC0);
            const uintptr_t D3D11FATALERRORCouldCreateConstant=REBASE(0x27CC280);
            const uintptr_t D3D11FutureRenderingDisabledPattern=REBASE(0x27C7DC0);
            const uintptr_t D3D11GfxCardNameGfxCardVendorGfxFeatureL=REBASE(0x27C58D0);
            const uintptr_t DRSDrawportXFramebufferXAreaScale=REBASE(0x36A9650);
            const uintptr_t DRSInitDeviceKeyDeviceDeniedFullSizeFram=REBASE(0x36A60A0);
            const uintptr_t DRSPlaceOverridePlaceIdPlaceDeniedDenied=REBASE(0x36A9097);
            const uintptr_t DRSStateQlModeMsaaHalved=REBASE(0x36B33F0);
            const uintptr_t DTMHarmonyV3TunableAllowlistedEditableIm=REBASE(0x3728AA0);
            const uintptr_t DispatchSceneCreatedUsing=REBASE(0x37C4FB0);
            const uintptr_t DispatchSceneNumHiQualBatchesNumBatchesC=REBASE(0x37C3D10);
            const uintptr_t ERRORComputeStateObjectCreationFailed=REBASE(0x5A0BE10);
            const uintptr_t ERRORPipelineStateObjectCreationFailed=REBASE(0x5A0B2B0);
            const uintptr_t ERRORResourcesAreDestroyed=REBASE(0x27BCFF0);
            const uintptr_t EditableImageRenderingDisabledFastFlag=REBASE(0x37289B0);
            const uintptr_t EditableMeshRenderingDisabledFastFlag=REBASE(0xD8B700);
            const uintptr_t EnableTexturePackGeneratorOnClientTrueBu=REBASE(0x3714D90);
            const uintptr_t ErrorCreatingTextureDownloadResourceX=REBASE(0x61CA4E0);
            const uintptr_t ErrorDonTKnowFlag=REBASE(0x37FF520);
            const uintptr_t ErrorFailedCreateShader=REBASE(0x61D4F10);
            const uintptr_t ErrorFailedLinkShaderProgram=REBASE(0x61D4D70);
            const uintptr_t ErrorInitializingFlattenedXRayAdorn=REBASE(0x61CD2A0);
            const uintptr_t ErrorInitializingUIStencilBuffer=REBASE(0x61CC1C0);
            const uintptr_t FailedAttachColorTextureFramebuffer=REBASE(0x59D8D19);
            const uintptr_t FailedCreateTextureHResultWas=REBASE(0x27D7940);
            const uintptr_t FailedCreateThumbnailTexture=REBASE(0x3660CA0);
            const uintptr_t FailedCreateVRDebugStereoTexture=REBASE(0x36552F0);
            const uintptr_t FailedCreateVRDebugTexture=REBASE(0x36545A0);
            const uintptr_t FailedLoadImageInstance=REBASE(0x623BDA0);
            const uintptr_t FailedLoadUpdateTextureLayerReason=REBASE(0x399C7A0);
            const uintptr_t FailedLockBufferSize=REBASE(0x27DA510);
            const uintptr_t FailedLockTexture=REBASE(0x27D8A60);
            const uintptr_t FailedOpenSharedResourceRenderingGPU=REBASE(0x27CBCC0);
            const uintptr_t FailedParseTunablesJSONUsingFallback=REBASE(0x3687C50);
            const uintptr_t FailsafeGeometryVerticesIndices=REBASE(0x61DD3D0);
            const uintptr_t FutureBright=REBASE(0x367EF10);
            const uintptr_t GLDebug=REBASE(0x59CBBD0);
            const uintptr_t GeometrySolidVerticesWaterVertices=REBASE(0x61D96A0);
            const uintptr_t GradientCacheFailedCreateAtlasTextureX=REBASE(0x3AC3C80);
            const uintptr_t GridNEWReadSubmittedVJMReadAsync=REBASE(0x4BCE810);
            const uintptr_t GridReadJobSetupLockedBuiltChunkListChun=REBASE(0x4C66140);
            const uintptr_t GridReadJobWorkProcessingChunkTotal=REBASE(0x4C66440);
            const uintptr_t IDXGIAdapterNullDeviceCreationWillUse=REBASE(0x27C1CD0);
            const uintptr_t LQMTunablesQLPrioritizedShadowDistanceLi=REBASE(0x3650060);
            const uintptr_t LayeredClothingModeUpdatedLCHSR=REBASE(0x367EDA0);
            const uintptr_t MainFrameBufferColorFormatSupported=REBASE(0x3653600);
            const uintptr_t MultipleVisualEnginesActive=REBASE(0x3676CC0);
            const uintptr_t NOTEGlobalInstancingSupportedDevice=REBASE(0x378F3A0);
            const uintptr_t ObtainedRuntimeTerrainTextureCache=REBASE(0x39990E0);
            const uintptr_t OnDrawFinishedCalledWhileCaptureDownload=REBASE(0x3662D60);
            const uintptr_t PixelFormatHasStencilBits8=REBASE(0x59D6670);
            const uintptr_t RTPoolWidthHeightMiplevelsFormatCount=REBASE(0x61CB9F0);
            const uintptr_t RenderFixShadowOnMeshStreamInMeshReadyBu=REBASE(0x382465B);
            const uintptr_t RenderViewCreated=REBASE(0x36401F0);
            const uintptr_t RenderViewDestroyedAppExiting=REBASE(0x36493E0);
            const uintptr_t ResidualRefcountsAfterTeardownDeviceCont=REBASE(0x27C74F0);
            const uintptr_t ResizingDueDifferentWidthHeightCurrent=REBASE(0x59F7610);
            const uintptr_t ResolutionX=REBASE(0x61CC2C0);
            const uintptr_t SceneManagerMainTargetsModeSamplesHighli=REBASE(0x36A2930);
            const uintptr_t SchedulingChunkUpdateChunkPriority=REBASE(0x386F880);
            const uintptr_t ShaderHasNonEmptyInfologLength=REBASE(0x59DC680);
            const uintptr_t ShuttingDownThread=REBASE(0x4C597B0);
            const uintptr_t SmoothClusterSchedulingGenerationChunkXY=REBASE(0x38700F0);
            const uintptr_t SolidTexturesProcessUsedMaterialChangesS=REBASE(0x399A12A);
            const uintptr_t SpaceFittingVertexIndexIntoVBPool=REBASE(0x368E0E0);
            const uintptr_t Spawning=REBASE(0x4C58300);
            const uintptr_t TM2MaxCloudAssetDimension=REBASE(0x3703C50);
            const uintptr_t TextureDownloadResourceAsyncDownloadFail=REBASE(0x3666C20);
            const uintptr_t TextureDownloadResourceCouldnTCreateReso=REBASE(0x3666420);
            const uintptr_t TextureDownloadResourceSkippingZeroSized=REBASE(0x3667720);
            const uintptr_t UnableCreateRuntimeTerrainTexture=REBASE(0x61DC900);
            const uintptr_t UnableFitTerrainLayersTextureAtlas=REBASE(0x3998390);
            const uintptr_t UsingTexturePackGenerator=REBASE(0x3715190);
            const uintptr_t VRAMLocalBudgetBytesCurrentUsageBytes=REBASE(0x27C1ADE);
            const uintptr_t VRAMNonLocalBudgetBytesCurrentUsage=REBASE(0x27C1BAC);
            const uintptr_t VULKAN=REBASE(0x59E5E10);
            const uintptr_t VULKANRECOVERYDeviceLostSetDeviceLost=REBASE(0x59F8E80);
            const uintptr_t VULKANUnifiedMemoryDeviceMemoryZuHost=REBASE(0x59E34E0);
            const uintptr_t VoxelJobManagerRunning=REBASE(0x4C59360);
            const uintptr_t VulkanDeviceIncompatibleSkipping=REBASE(0x59E2ED0);
            const uintptr_t VulkanSavedPipelineCacheBytesHash=REBASE(0x5A09FF0);
            const uintptr_t VulkanSkippingFramebufferCreationInvalid=REBASE(0x59F73B0);
            const uintptr_t VulkanSkippingPipelineCacheBytesSince=REBASE(0x5A09660);
            const uintptr_t WARNINGD3DFrameQueryTimedOut=REBASE(0x27C9A12);
        }
        namespace GuiTargetLifetime
        {
            const uintptr_t BasePlayerGuiCreated=REBASE(0x3F5C820);
            const uintptr_t BasePlayerGuiDestroyed=REBASE(0x3F5CA10);
            const uintptr_t GuiItemCreated=REBASE(0x4068940);
            const uintptr_t GuiItemDestroyed=REBASE(0x4068A30);
            const uintptr_t GuiLayerCollectorCreated=REBASE(0x3F8F510);
            const uintptr_t GuiLayerCollectorDestroyed=REBASE(0x3F8F830);
            const uintptr_t WorkspaceCreated=REBASE(0x33FD9D0);
            const uintptr_t WorkspaceDestroyed=REBASE(0x33FFAC0);
        }
        namespace H3Connection
        {
            const uintptr_t ConnSeqErrorParsingDatagramContextID=REBASE(0x21545A0);
            const uintptr_t ConnSeqH3BodyWriterReadDataCbFailedBodyW=REBASE(0x215F440);
            const uintptr_t ConnSeqH3ClientConnectionSendRequestFail=REBASE(0x2159700);
            const uintptr_t ConnSeqH3ConnectionOnQuicStreamReadFaile=REBASE(0x2152DA0);
            const uintptr_t ConnSeqH3ConnectionOpenCustomUniStreamFa=REBASE(0x2150E50);
            const uintptr_t ConnSeqH3ConnectionOpenH3BidiStreamFaile=REBASE(0x2151310);
            const uintptr_t ConnSeqH3ConnectionReportConnectionClose=REBASE(0x2153660);
            const uintptr_t ConnSeqH3ConnectionSendDatagramFailedDat=REBASE(0x2151F30);
            const uintptr_t ConnSeqH3ConnectionShutdownStreamWriteSt=REBASE(0x2151DA0);
            const uintptr_t ConnSeqH3ServerConnectionSendRejectedInv=REBASE(0x215C810);
            const uintptr_t ConnSeqPeerClosedLocalHTTP3=REBASE(0x21532E0);
            const uintptr_t H3ClientConnectionCreateH3ConnFailed=REBASE(0x215A0F0);
            const uintptr_t H3ServerConnectionCreateH3ConnFailed=REBASE(0x215D300);
        }
        namespace HangDetectionJob
        {
            const uintptr_t HangDetectionJobStartedTimeoutMs=REBASE(0x5A3A380);
            const uintptr_t TaskSchedulerHangDetectedGetBlockingThre=REBASE(0x5A39890);
        }
        namespace HangMonitor
        {
            const uintptr_t MoreHangsResolvedThanThereAre=REBASE(0x5D14530);
        }
        namespace HeartBeatFailure
        {
            const uintptr_t HeartbeatStepping=REBASE(0x3512C70);
        }
        namespace HeatmapBackendClient
        {
            const uintptr_t FetchingHeatmapTypeName=REBASE(0x3BC2820);
            const uintptr_t ParsedEnvelopeHeatmapTypeHeatmapNameBinC=REBASE(0x3BC0A20);
        }
        namespace HeatmapQueryService
        {
            const uintptr_t LoadDebugHeatmapFromCsvLoadedZuChunks=REBASE(0x3BBBE30);
        }
        namespace HitchRateLog
        {
            const uintptr_t HitchrateMsSecFrameTimeTargetMSsecMsRamT=REBASE(0x20C70D0);
        }
        namespace HttpClientStatsReporterTrace
        {
            const uintptr_t BlockingSendHttpDownloadBandwidthV2=REBASE(0x1130F80);
        }
        namespace HttpCookieProtocol
        {
            const uintptr_t FailSCookieSErrorS=REBASE(0x2C911D0);
            const uintptr_t SCookiesSSProhibited=REBASE(0x2C91460);
        }
        namespace HttpOpenTelemetryTracing
        {
            const uintptr_t AddingRbxRotraceRunIdHeaders=REBASE(0x4EC44E0);
            const uintptr_t ExceptionWhileEndingAPISpan=REBASE(0x6257790);
            const uintptr_t ExceptionWhileEndingSpan=REBASE(0x6257850);
            const uintptr_t SpanEndedSuccessfully=REBASE(0x4EC4C20);
        }
        namespace HttpRbxApiBudget
        {
            const uintptr_t ExecutingRetryRequestsSizeBudget=REBASE(0x3C444D0);
            const uintptr_t ExecutingThrottledRequestsSizeBudget=REBASE(0x3C44BF0);
            const uintptr_t ThrottlingBudget=REBASE(0x3C45290);
        }
        namespace HttpRetryOverrides
        {
            const uintptr_t InsertCodeRangeStrategyIntervalMax=REBASE(0x2CAB350);
        }
        namespace HttpService
        {
            const uintptr_t HttpServiceInvocationUrlRequestBodyStack=REBASE(0x3C14050);
        }
        namespace HttpServiceOpenCloud
        {
            const uintptr_t EncounteredInvalidUniverseIDWhenParsing=REBASE(0x61EA750);
        }
        namespace HttpTrace
        {
            const uintptr_t HttpRequestAbortState=REBASE(0x2C78230);
            const uintptr_t HttpRequestOldStateNewState=REBASE(0x2C61BC0);
            const uintptr_t HttpRequestRoundtripsLdDelayMsLd=REBASE(0x2C61980);
            const uintptr_t HttpRequestSetIfModifiedSinceRevalidatio=REBASE(0x2CB4FE0);
            const uintptr_t HttpRetryManagerProcessingRetryQueue=REBASE(0x2CAE390);
        }
        namespace HttpTraceError
        {
            const uintptr_t CurlConnectFailedCurrentFileDescriptor=REBASE(0x2CA06F0);
            const uintptr_t DebugHttpForceIpv6OnlyIPV6V6ONLYFailedRe=REBASE(0x2CA37C0);
            const uintptr_t DebugHttpForceIpv6OnlyIPv4MappedCandidat=REBASE(0x2CA5EB0);
            const uintptr_t ExceptionMessageRbxStorageEnabledTargetU=REBASE(0x6189010);
            const uintptr_t FailedAllocateEmbeddedCACertificateStore=REBASE(0x2CBA520);
            const uintptr_t FailedCacheResultUpdateCacheUrlExternal=REBASE(0x2CB5280);
            const uintptr_t FailedLoadEmbeddedCACertificates=REBASE(0x2CBA6A8);
            const uintptr_t FailedUpdateCookieCouldnTInitialize=REBASE(0x2CBE510);
            const uintptr_t HttpClientCacheCleanupError=REBASE(0x61882B0);
            const uintptr_t ReadISequentialStreamintoStringException=REBASE(0x618A540);
            const uintptr_t ReadISequentialStreamintoStringOutMemory=REBASE(0x618A480);
            const uintptr_t RequestUrlInvalidHttp=REBASE(0x2C791D0);
            const uintptr_t UnknownRequestType=REBASE(0x2C57210);
            const uintptr_t VerifyCbSSLCertificateDistrusted=REBASE(0x2C9E7C3);
            const uintptr_t VerifyCbSSLCertificateNull=REBASE(0x2C9E610);
        }
        namespace HttpTraceLight
        {
            const uintptr_t AsyncWriteCacheSkippedAccumulatedBytes=REBASE(0x2C84930);
            const uintptr_t AttemptingCallHttpClientSendDuringGlobal=REBASE(0x2C54730);
            const uintptr_t FixedBackoffProcessingEndpointRetryTime=REBASE(0x2CB1590);
            const uintptr_t HttpClientDestroyBegin=REBASE(0x2C528C0);
            const uintptr_t HttpRequestCurlIsExternalRequestIsExtern=REBASE(0x2CA3910);
            const uintptr_t HttpRequestPendingCacheEntryWasRevalidat=REBASE(0x2C5C8A0);
            const uintptr_t HttpRequestUrlPostSizeZuCachePolicyExter=REBASE(0x2C53310);
            const uintptr_t RequestUrlWillThrottledLocallyEndpoint=REBASE(0x2CB0BE0);
            const uintptr_t ThrottlingForcedPermanentAddDomainEndpoi=REBASE(0x2CB1030);
            const uintptr_t ThrottlingForcedPermanentRemoveDomainEnd=REBASE(0x2CB1390);
            const uintptr_t UpdatedHttpLatencyClientPopPopDc=REBASE(0x4CC0C00);
        }
        namespace HttpTraceNew
        {
            const uintptr_t CallbackHandlerHttpResponseUrlCallbackTi=REBASE(0x2C7DB40);
            const uintptr_t ConntrackDISCONNECTConnIdHostHttp=REBASE(0x2CA6410);
            const uintptr_t DeferringConnectivityUpdateWorkerThreadR=REBASE(0x2C667E0);
            const uintptr_t DeferringNetworkChangeWorkerThreadReason=REBASE(0x2C665C0);
            const uintptr_t HttpRequest416ReqRangeBodySizeRangePast=REBASE(0x2C5D040);
            const uintptr_t WarningWillUseHttpRequestWhileDefault=REBASE(0x2C76450);
            const uintptr_t WorkerThreadProcessNetworkChangeProcessi=REBASE(0x2C5BC10);
        }
        namespace HugeHugePersistentLog
        {
            const uintptr_t PartTooLargeTreatingPersistent=REBASE(0x4876090);
        }
        namespace HumanoidFloorProcess
        {
            const uintptr_t DisconnectingLastFloor=REBASE(0x1917090);
            const uintptr_t FloorMovementTooSmall=REBASE(0x180106A);
            const uintptr_t PlatformSubscribed=REBASE(0x1916EB1);
        }
        namespace HumanoidPlatformsLog
        {
            const uintptr_t FailedTransitionRemoteBasisRemoteBasis=REBASE(0x151BFEA);
            const uintptr_t RemoteBasisBasisFallbackModeTransitionMi=REBASE(0x151C450);
            const uintptr_t RemoteBasisRemoteBasisFallbackModeTransi=REBASE(0x151B830);
        }
        namespace ISRIncomingOutgoingAttributes
        {
            const uintptr_t InstanceStateSenderWriteInstanceStatePac=REBASE(0x3A9EFF0);
            const uintptr_t InstanceStateSerializationManagerSeriali=REBASE(0x48F24A0);
        }
        namespace ISRTimestampOffsets
        {
            const uintptr_t ISRShortServerStallBoostingConvergence=REBASE(0x3A75A6B);
        }
        namespace ISteppedLifetime
        {
            const uintptr_t AnimatorCreated=REBASE(0x175E330);
            const uintptr_t AnimatorDestroyed=REBASE(0x175EEC0);
            const uintptr_t ControllerCreated=REBASE(0x3007410);
            const uintptr_t ControllerDestroyed=REBASE(0x3007530);
            const uintptr_t ExplosionCreated=REBASE(0xDB1520);
            const uintptr_t ExplosionDestroyed=REBASE(0xDB17B0);
            const uintptr_t FlagStandServiceCreated=REBASE(0x3D50F50);
            const uintptr_t FlagStandServiceDestroyed=REBASE(0x3D51190);
            const uintptr_t HumanoidDestroyed=REBASE(0x17D32A0);
            const uintptr_t RocketCreated=REBASE(0x3D56660);
            const uintptr_t RocketDestroyed=REBASE(0x3D56860);
            const uintptr_t SubscribedIStepped=REBASE(0x24A7A00);
        }
        namespace IXPService
        {
            const uintptr_t IXPServiceConstructedAddedChangedListene=REBASE(0x3153CB0);
            const uintptr_t IXPServiceDestroyedRemovedChangedListene=REBASE(0x3154170);
            const uintptr_t IXPServiceDmTaskSignalBrowserTracker=REBASE(0x3154CA0);
            const uintptr_t IXPServiceDmTaskSignalUserIXPLoadingStat=REBASE(0x31550E0);
            const uintptr_t IXPServiceSignallingLuaCreatorIXPLoading=REBASE(0x3155570);
            const uintptr_t IXPServiceSubmittingDmTaskSignalCreator=REBASE(0x31552E0);
        }
        namespace IdempotentDevProductPurchasing
        {
            const uintptr_t GetPurchaseBodyJsonPurchasePayloadExceed=REBASE(0x128ADE0);
            const uintptr_t GetRequestUrlDevProductPurchaseRequestor=REBASE(0x128A010);
            const uintptr_t OrchestrationLayerAvailableMarketplaceSe=REBASE(0x128CF20);
            const uintptr_t ParseResponsesDevProductPurchaseRequesto=REBASE(0x128A740);
            const uintptr_t ParseResponsesHTTPRequestFailedErrorCode=REBASE(0x128A160);
            const uintptr_t RequestorConstructedMaxTimeQueueMs=REBASE(0x1289D30);
        }
        namespace ImmHandler
        {
            const uintptr_t IMNSETOPENSTATUSIsOpenShouldBeOpen=REBASE(0x16DF2A0);
            const uintptr_t KeyboardLayout=REBASE(0x16DEA10);
            const uintptr_t RIMTYPEKEYBOARDShouldSinkKeyboardReturne=REBASE(0x16D7170);
            const uintptr_t SettingUpImmHandler=REBASE(0x16DE400);
        }
        namespace ImmersiveBrandedAdsServer
        {
            const uintptr_t ErrorMessageTooLong=REBASE(0x101ADF0);
        }
        namespace InExperienceAvatarCreation
        {
            const uintptr_t AvatarCreationServiceFailedFindGuidUgcVa=REBASE(0x184AE50);
            const uintptr_t AvatarCreationServiceOnCreateAvatarAsset=REBASE(0x1869930);
            const uintptr_t AvatarCreationServiceOnCreateAvatarAutho=REBASE(0x1866D30);
            const uintptr_t OnCreateAvatarAssetAuthorizationComplete=REBASE(0x1868200);
            const uintptr_t OnCreateAvatarAuthorizationCompleteDataM=REBASE(0x18658A0);
            const uintptr_t PromptCreateAvatarAssetAsyncError=REBASE(0x182B3C0);
            const uintptr_t PromptCreateAvatarAsyncError=REBASE(0x1829F20);
            const uintptr_t PropertyDescriptorFound=REBASE(0x184A300);
        }
        namespace InExperienceCreation
        {
            const uintptr_t FailedDeserializeInstance=REBASE(0x335EE90);
            const uintptr_t PromptCreatePlatformContentAsyncFailedCl=REBASE(0x3356770);
            const uintptr_t PromptImportAnimationClipFromVideoAsyncA=REBASE(0x336B490);
            const uintptr_t PromptImportAnimationClipFromVideoAsyncC=REBASE(0x336A620);
            const uintptr_t PromptImportAnimationClipFromVideoAsyncD=REBASE(0x336ACB0);
            const uintptr_t PromptImportAnimationClipFromVideoAsyncO=REBASE(0x336A030);
            const uintptr_t PromptPublishAssetAsyncRobloxServerStora=REBASE(0x33589E0);
            const uintptr_t UnexpectedError=REBASE(0x3354790);
        }
        namespace IncomingDataLog
        {
            const uintptr_t PhysicsSenderStaleFrameGuidBlockingTimes=REBASE(0x4846600);
            const uintptr_t PutFrameInBufferCalledGuidTLastTime=REBASE(0x151AC70);
        }
        namespace InferredCrash
        {
            const uintptr_t BatteryLevel=REBASE(0x2A0A0F0);
            const uintptr_t ExitReason=REBASE(0x2A07F80);
            const uintptr_t FailedRemoveSnapshotFile=REBASE(0x2A14530);
            const uintptr_t FailedRemoveStaleSnapshot=REBASE(0x2A14950);
            const uintptr_t SessionResultV2=REBASE(0x2A16D10);
            const uintptr_t SnapshotCleanupFailed=REBASE(0x617BA80);
            const uintptr_t SnapshotFileMissingPlaySessionIdRemoving=REBASE(0x2A13650);
            const uintptr_t SnapshotLimitReachedSkippingSnapshotPlay=REBASE(0x2A14090);
            const uintptr_t ThermalStatus=REBASE(0x2A09F90);
        }
        namespace InferredCrashBacktraceReportLog
        {
            const uintptr_t CreatedInferredCrashBacktraceReporter=REBASE(0x4D62D30);
            const uintptr_t CreatedInferredCrashBacktraceReporterIns=REBASE(0x4D644D0);
            const uintptr_t ReportingInferredCrashDataBacktrace=REBASE(0x4D63BC0);
        }
        namespace InfluxTrace
        {
            const uintptr_t AccumulatorUnknownException=REBASE(0x617BD10);
            const uintptr_t PointsReporterUnknownException=REBASE(0x617BD80);
            const uintptr_t RejectedInvalidKeyName=REBASE(0x2A1F440);
            const uintptr_t ReportToV2AdapterCreateRobloxTelemetryEv=REBASE(0x2A1E380);
        }
        namespace InputRecorder
        {
            const uintptr_t Log=REBASE(0xE81B50);
            const uintptr_t SessionInfoGuid=REBASE(0xE834F0);
        }
        namespace InstanceStitchingLog
        {
            const uintptr_t AssignedDeterministicGUIDSpeculativeInst=REBASE(0x32424C0);
            const uintptr_t ClientRecyclingRolledBackSpeculativeInst=REBASE(0x3241750);
            const uintptr_t ClientSpeculativeInstanceTypeGUIDPeer=REBASE(0x3241400);
            const uintptr_t ClientStitchedInstanceGUID=REBASE(0x32429A0);
            const uintptr_t ClientTrackingSpeculativeInstanceGUIDFra=REBASE(0x32427C0);
            const uintptr_t GeneratedGUIDInstanceTypeTime=REBASE(0x3241A80);
            const uintptr_t RollingBackFrame=REBASE(0x3243490);
        }
        namespace InstanceTreeManipulation
        {
            const uintptr_t InstanceSettingParentOldParent=REBASE(0x1C9F520);
        }
        namespace InternalMessagingService
        {
            const uintptr_t CSMEventException=REBASE(0x61A8C10);
            const uintptr_t ConnectingCallbackSubscriptionKeyNumSubs=REBASE(0x3143760);
            const uintptr_t FailedGetDataModelCreateSubscriptionInfo=REBASE(0x3142070);
            const uintptr_t FailedGetDataModelGenerateArgsForChannel=REBASE(0x3144770);
            const uintptr_t FailedGetDataModelInitiateBackendSubscri=REBASE(0x3145080);
            const uintptr_t IgnoringMessageFailedParseCSMEvent=REBASE(0x3141090);
            const uintptr_t InternalMessagingServiceInitializeConnec=REBASE(0x31407E0);
            const uintptr_t InternalMessagingServiceLockDataModelHel=REBASE(0x313F480);
            const uintptr_t InternalMessagingServiceOnReconnectedCSM=REBASE(0x314B4A0);
            const uintptr_t InternalMessagingServiceRestoreBackendCh=REBASE(0x3145D10);
            const uintptr_t InternalMessagingServiceUnsubscribeRPCFa=REBASE(0x3149050);
            const uintptr_t LastCallbackDisconnectedSubscriptionKeyU=REBASE(0x3143DA0);
            const uintptr_t ReceivedMessageUnknownSubscriptionKeyCha=REBASE(0x31466D0);
            const uintptr_t UnknownInternalMessagingScope=REBASE(0x3144F30);
        }
        namespace InternalMessagingServiceVerifier
        {
            const uintptr_t FailedGetInternalMessagingService=REBASE(0x313E3E0);
            const uintptr_t ReceivedCustomChannelMessage=REBASE(0x313F210);
            const uintptr_t ReceivedPlaceVersionMessage=REBASE(0x313EF70);
            const uintptr_t ReceivedRccMessage=REBASE(0x313F0C0);
            const uintptr_t ReceivedUniverseMessage=REBASE(0x313EE20);
        }
        namespace IxpController
        {
            const uintptr_t AddingChangedListener=REBASE(0x3A58F40);
            const uintptr_t FetchingLayersSubjectID=REBASE(0x3A58960);
            const uintptr_t GettingExperimentInfoLayer=REBASE(0x3A59D80);
            const uintptr_t IXPLayerTypeAttemptLogExposure=REBASE(0x3A59A50);
            const uintptr_t IXPLayerTypeInitHttpRequest=REBASE(0x3A56D00);
            const uintptr_t IXPLayerTypeInitializeLayersSucceededSet=REBASE(0x3A52A70);
            const uintptr_t IXPLayerTypeInvalidCreatorIdCreator=REBASE(0x3A52E70);
            const uintptr_t IXPLayerTypeSettingLoadingStatus=REBASE(0x3A52090);
            const uintptr_t IXPLayerTypeWARNINGAccessingLayer=REBASE(0x3A541C0);
            const uintptr_t IXPLayerTypeWARNINGRegisteringLayer=REBASE(0x3A51B40);
            const uintptr_t LocalLayerVariablesJsonErrorCheckingLoca=REBASE(0x3A61640);
            const uintptr_t LocalLayerVariablesJsonLayerCouldConvert=REBASE(0x61E0740);
            const uintptr_t LocalLayerVariablesJsonUnknownSectionIgn=REBASE(0x3A60C80);
            const uintptr_t LocalLayerVariablesParseErrorLocalIXPOve=REBASE(0x3A61050);
            const uintptr_t RegisteringLayer=REBASE(0x3A58750);
            const uintptr_t RemovingChangedListener=REBASE(0x3A59190);
        }
        namespace IxpFlagLinkedExperimentRegister
        {
            const uintptr_t Log=REBASE(0x62CE9C0);
            const uintptr_t UnableGetFilepathIXPCache=REBASE(0x5CD3970);
        }
        namespace IxpLayers
        {
            const uintptr_t DynamicLayerRegistration=REBASE(0x4D07630);
        }
        namespace IxpParsingWarning
        {
            const uintptr_t CouldnTFindVariableApplyIXP=REBASE(0x4A364B0);
        }
        namespace IxpStorageManager
        {
            const uintptr_t ExceptionWhileLoadingCacheFile=REBASE(0x61E0390);
            const uintptr_t ExceptionWhileLoadingInstanceIDFile=REBASE(0x61E05C0);
            const uintptr_t ExceptionWhileSavingRandomIDFile=REBASE(0x61E0440);
            const uintptr_t GeneratedNewRandomID=REBASE(0x3A5C170);
            const uintptr_t HashComputeDurationUserIdBucketXxhash32=REBASE(0x3A5F8B0);
            const uintptr_t LoadCacheFileLocalStorageManagerAvailabl=REBASE(0x3A5CF80);
            const uintptr_t LoadInstanceIdFromFileLocalStorageManage=REBASE(0x3A5EE00);
            const uintptr_t SaveInstanceIdToFileLocalStorageManagerA=REBASE(0x3A5E890);
            const uintptr_t SendingDeferredEventUserIdUserIdSending=REBASE(0x3A5C800);
        }
        namespace JointLifetime
        {
            const uintptr_t JointCreatedEmptyPrimitives=REBASE(0x1536F00);
            const uintptr_t JointDestroyed=REBASE(0x1537040);
        }
        namespace KeyRing
        {
            const uintptr_t ApplicationRevertVersionVersions=REBASE(0x2BA9520);
        }
        namespace LBFGS
        {
            const uintptr_t LBFGS=REBASE(0x2E702D0);
        }
        namespace LargeReplicatorTrace
        {
            const uintptr_t AssetRemovedTypeHandleVersion=REBASE(0x3A8BF20);
            const uintptr_t AssignAssetSkippedButForcedReAdd=REBASE(0x3AA56C0);
            const uintptr_t CancelReceivedStreamGuidVersion=REBASE(0x3AA31B0);
            const uintptr_t DeltaSourceVersionFoundPublishedUnblocki=REBASE(0x3A6D920);
            const uintptr_t FailedAssetChecksumCompareTypeFlags=REBASE(0x3AA7340);
            const uintptr_t LargeReplicatorActiveReceiverStreamId=REBASE(0x3AA5570);
            const uintptr_t ManuallyDecrementingNetworkRefTypeHandle=REBASE(0x3A6FB00);
            const uintptr_t ManuallyIncrementingNetworkRefTypeHandle=REBASE(0x3A8B120);
            const uintptr_t ProcessedAddsRemoves=REBASE(0x3A6BAF0);
            const uintptr_t ReceivedDeltaGuidVersionAdditional=REBASE(0x3AA40B0);
            const uintptr_t ReceivedEndGuidVersionFrameId=REBASE(0x3AA3BE0);
            const uintptr_t ReceivedHeaderTypeAdditionalGuidVersion=REBASE(0x3AA6D70);
            const uintptr_t RegisterCachedAssetInReceiverAttemptingG=REBASE(0x3A8C805);
            const uintptr_t RegisterCachedAssetInReceiverSkippedAlre=REBASE(0x3A8C940);
            const uintptr_t RemovingPartialDeltaEntryGuidVersion=REBASE(0x3AA3700);
            const uintptr_t ResettingStaleDeltaStateGuidVersion=REBASE(0x3AA29C0);
            const uintptr_t SendingEndGuidVersionTypeFrame=REBASE(0x3A86B10);
            const uintptr_t SendingHeaderTypeAdditionalGuidVersion=REBASE(0x3A86490);
            const uintptr_t SendingRemoveStaleDeltaStateCleanup=REBASE(0x3A6C620);
        }
        namespace LayeredClothingWrapDeformedBundleId
        {
            const uintptr_t LCWRAPDEFORMEDBUNDLEOwnerPathOwner=REBASE(0x1B38D50);
        }
        namespace LibWebrtcImpl
        {
            const uintptr_t AddAudioTrackEmptyCodecPreferenceList=REBASE(0x52BDC80);
            const uintptr_t AddVideoTrackEmptyCodecPreferenceList=REBASE(0x52BD100);
            const uintptr_t CreateDataChannelOrErrorFailed=REBASE(0x52BCC70);
            const uintptr_t CreatePeerConnectionOrErrorFailed=REBASE(0x52BC0D0);
            const uintptr_t FailedParseICECandidate=REBASE(0x52BF470);
            const uintptr_t FailedParseRemoteSDP=REBASE(0x52BEF60);
            const uintptr_t SDPCreateOperationTimedOutAfter=REBASE(0x52BA1A0);
            const uintptr_t SDPSetOperationTimedOutAfter=REBASE(0x52BA470);
            const uintptr_t SendFrameSupportedTransceiver=REBASE(0x52B9620);
            const uintptr_t SetCodecPreferencesFailed=REBASE(0x52B8410);
            const uintptr_t SetLocalDescriptionEmptyCouldParseGenera=REBASE(0x52BEC30);
            const uintptr_t TWCCDIAGReceiverHeaderExtensionsCount=REBASE(0x52BAA20);
        }
        namespace LmsClient
        {
            const uintptr_t LMSGetLmsUrlUrl=REBASE(0x10C71F0);
            const uintptr_t LMSGetRecipe=REBASE(0x10C5030);
            const uintptr_t LMSGetRecipeFailedGetRecipe=REBASE(0x10C52F0);
            const uintptr_t LMSParseRecipeInputStringWas=REBASE(0x10C7BD0);
            const uintptr_t LMSProcessRecipeZeroPulsesStop=REBASE(0x10C55E0);
            const uintptr_t LMSPulseResponseGETReturnedError=REBASE(0x10C5D30);
            const uintptr_t LMSSendPulsePulse=REBASE(0x10C59E0);
            const uintptr_t LMSSubmitReportFailureUrlErr=REBASE(0x10C7A10);
            const uintptr_t LMSSubmitReportSkippingReportUpload=REBASE(0x10C6A80);
        }
        namespace LoadSettingsZstdDictionary
        {
            const uintptr_t CouldDecompressBecauseDictionaryWasNull=REBASE(0x451D3F0);
            const uintptr_t DictionaryFoundDisablingClientSettings=REBASE(0x451CF90);
            const uintptr_t ExceptionWhileGettingDictionaryPath=REBASE(0x6220880);
            const uintptr_t FailedReadDictionaryFile=REBASE(0x451DE20);
            const uintptr_t PlatformAssetsPathSetDictionaryLoading=REBASE(0x451C530);
        }
        namespace LoadTesting
        {
            const uintptr_t CancelEnqueuedTestCalledWithoutEnqueuedT=REBASE(0x13128B0);
            const uintptr_t CheckIfEnqueuedTestNeedsToBeCanceledEnqu=REBASE(0x1310450);
            const uintptr_t CheckIfPublishedTestNeedsToBeEnqueuedDat=REBASE(0x1313CC0);
            const uintptr_t CheckIfPublishedTestNeedsToBeEnqueuedFou=REBASE(0x130E7C0);
            const uintptr_t EnqueuePublishedTestDataModelInstanceLon=REBASE(0x130FA20);
            const uintptr_t ExecuteEnqueuedTestEnqueuedTestParameter=REBASE(0x13100C0);
            const uintptr_t ExecuteEnqueuedTestEnqueuedTestStartingS=REBASE(0x13108F0);
            const uintptr_t ExecuteEnqueuedTestLoadTestExecutorTestF=REBASE(0x1311470);
            const uintptr_t InitializeLoadTestCoordinatorLoadTestCoo=REBASE(0x12D1C60);
            const uintptr_t LoadTestCoordinatorConstructorCalled=REBASE(0x130D6F0);
            const uintptr_t LoadTestCoordinatorCreateDatamodelSUnive=REBASE(0x130CF50);
            const uintptr_t LoadTestCoordinatorDestructorCalled=REBASE(0x130DAA0);
            const uintptr_t LoadTestCoordinatorStartDataModelInstanc=REBASE(0x130DD10);
            const uintptr_t LoadTestCoordinatorStepTimerInstanceLong=REBASE(0x130E340);
            const uintptr_t LoadTestCoordinatorStepTimerTaskUnableLo=REBASE(0x1313AD0);
            const uintptr_t MarketplaceServiceInitializeOnGameLoadAw=REBASE(0x12BEE40);
            const uintptr_t MarketplaceServiceInitializeOnGameLoadCa=REBASE(0x12BF220);
            const uintptr_t StepTestCurrentlyStartingExecutingIgnori=REBASE(0x1312B80);
        }
        namespace LocalStorage
        {
            const uintptr_t LocalStorageFailedOpenFileFlushing=REBASE(0x29B97C0);
            const uintptr_t LocalStorageFlushEntriesBytesJSONBytes=REBASE(0x29B7BE0);
            const uintptr_t LocalStorageFlushFailedFlushingDisabled=REBASE(0x29B8300);
            const uintptr_t LocalStorageFlushing=REBASE(0x29B5E10);
            const uintptr_t LocalStorageFlushingBlockingFailedFlushi=REBASE(0x29B6B40);
            const uintptr_t LocalStorageInvalidJsonObject=REBASE(0x29B87A0);
            const uintptr_t LocalStorageWroteZuBytesDisk=REBASE(0x29B92B0);
        }
        namespace LocalizationServiceVerbose
        {
            const uintptr_t AddUntranslatedParameterStringOriginalCo=REBASE(0x13DF470);
            const uintptr_t AttemptLocalizationForInstanceContextTex=REBASE(0x13D99B0);
            const uintptr_t ErrorManifestLoad=REBASE(0x13FCB30);
            const uintptr_t InvalidSystemLocaleIdProvided=REBASE(0x13D16D0);
            const uintptr_t IsLoadingInternalTranslationsSettingChan=REBASE(0x13D2C80);
            const uintptr_t LocaleIdStringToLanguageParseErrorUnable=REBASE(0x13B4940);
            const uintptr_t LocalizationTableProcessContentTakesLfMs=REBASE(0x13B7550);
            const uintptr_t SetLocaleManifest=REBASE(0x13DB3D0);
            const uintptr_t SourceLanguageCodeFieldTypeStringManifes=REBASE(0x13FD790);
            const uintptr_t TextScraperOnTranslationAttemptOriginalC=REBASE(0x13DE520);
        }
        namespace LogStepTimeAndNetworkUsage
        {
            const uintptr_t GameJoin=REBASE(0x465B3F0);
            const uintptr_t GameLoaded=REBASE(0x4650DB0);
            const uintptr_t ReceivedGlobals=REBASE(0x4650A90);
        }
        namespace LogWin32BTId
        {
            const uintptr_t LogWin32BTIdAppInstallerLaunchWebBtid=REBASE(0x74B7D0);
            const uintptr_t LogWin32BTIdAppInternalBrowserSessionEnd=REBASE(0x742DB0);
            const uintptr_t LogWin32BTIdAppLogoutSyncCookieNative=REBASE(0x76CD40);
            const uintptr_t LogWin32BTIdErrorStollAppWebLaunch=REBASE(0x606ADE0);
        }
        namespace LoggingProtocolCore
        {
            const uintptr_t SendingRobloxTelemetryEphemeralCounterEv=REBASE(0x44E4200);
            const uintptr_t SendingRobloxTelemetryEphemeralStatEvent=REBASE(0x44E46A0);
        }
        namespace LoomTrackerEngineTrace
        {
            const uintptr_t DestroyedLoomContext=REBASE(0x19B68D0);
            const uintptr_t DetectedLowCameraFpsFPSForcing=REBASE(0x19B61A0);
            const uintptr_t FailedCreateLoomSession=REBASE(0x19B4B30);
            const uintptr_t GetUnsupportedSetting=REBASE(0x19B37A0);
            const uintptr_t LoomSDK=REBASE(0x1B6F1A0);
            const uintptr_t SettingKeyValue=REBASE(0x19B3590);
            const uintptr_t ShuttingDown=REBASE(0x19B3410);
            const uintptr_t SubmittingAudioInferenceFailedReturned=REBASE(0x19B3C10);
            const uintptr_t SubmittingVideoInferenceFailedReturned=REBASE(0x19B4120);
            const uintptr_t SyncAudioInferenceLodA2cEnabled=REBASE(0x19B38E0);
            const uintptr_t SyncVideoInferenceLodV2cEnabled=REBASE(0x19B3A60);
            const uintptr_t TrackingEngineInitializedAudioVideoLod=REBASE(0x19B28E0);
        }
        namespace LowMemoryWarning
        {
            const uintptr_t LowMemoryWarningReceivedTelemetryWill=REBASE(0x4D8EDE0);
        }
        namespace LuaAppExperienceController
        {
            const uintptr_t GCGoalRestoredReason=REBASE(0x4D382D0);
            const uintptr_t GCGoalSetStartup=REBASE(0x4D38420);
            const uintptr_t LuaAppExperienceControllerEnableLuaAppSc=REBASE(0x4D3DD40);
            const uintptr_t LuaAppExperienceControllerFinalizeDidFin=REBASE(0x4D3BBB0);
            const uintptr_t LuaAppExperienceControllerInitializeInva=REBASE(0x4D39420);
            const uintptr_t LuaAppExperienceControllerLuaAppExperien=REBASE(0x4D39190);
            const uintptr_t LuaAppExperienceControllerOnLowMemoryWar=REBASE(0x4D3E360);
            const uintptr_t LuaAppExperienceControllerOnNavigationEv=REBASE(0x4D3EBB0);
            const uintptr_t LuaAppExperienceControllerOnSendOnExperi=REBASE(0x4D3E9A0);
            const uintptr_t LuaAppExperienceControllerOnSendOnFeatur=REBASE(0x4D3E630);
            const uintptr_t LuaAppExperienceControllerOnUserLogout=REBASE(0x4D39FC0);
            const uintptr_t LuaAppExperienceControllerPauseDidPauseD=REBASE(0x4D3C0B0);
            const uintptr_t LuaAppExperienceControllerReceivedScript=REBASE(0x4D3DFE0);
            const uintptr_t LuaAppExperienceControllerStartDidStartD=REBASE(0x4D3BDC0);
            const uintptr_t LuaAppExperienceControllerStopPreEmptive=REBASE(0x4D3F5C0);
            const uintptr_t LuaAppInteractiveSignalPerformDeferredSi=REBASE(0x4D3A840);
            const uintptr_t ProcessLowMemoryWarningLowMemorySendingL=REBASE(0x4D3F990);
        }
        namespace LuaHangedScript
        {
            const uintptr_t HangStackTrace=REBASE(0x4332500);
        }
        namespace LuauGcFixpoint
        {
            const uintptr_t SignalHandlerCollectedWhileOwnerStill=REBASE(0x4194FC0);
        }
        namespace MLPostProcess
        {
            const uintptr_t FirstFrameXFmtModelX=REBASE(0x4AF51D0);
            const uintptr_t ProcessPixelsException=REBASE(0x6246F00);
            const uintptr_t ProcessPixelsUnknownException=REBASE(0x6247010);
            const uintptr_t SessionSetModelInputXCh=REBASE(0x4AF5C10);
            const uintptr_t SetEnabledWas=REBASE(0x4AF5AE0);
            const uintptr_t UnsupportedModelZeroDimensionsXOut=REBASE(0x4AF4B40);
        }
        namespace MLService
        {
            const uintptr_t FailedCreateSessionDownloadedBundle=REBASE(0x141D5A0);
            const uintptr_t FailedEarlyInputShapeValidationExpected=REBASE(0x1418AB0);
            const uintptr_t MLSessionForwardAsyncDataModelValid=REBASE(0x141AED0);
            const uintptr_t MLSessionForwardAsyncMLSessionValid=REBASE(0x141C330);
            const uintptr_t ModelFetchFailed=REBASE(0x141F6B0);
        }
        namespace MachineIdUploader
        {
            const uintptr_t MachineBanned=REBASE(0x1114600);
        }
        namespace Macroprofile
        {
            const uintptr_t ProfilerDumpLastFramesDumped=REBASE(0x29E1900);
            const uintptr_t ProfilerRawDumpLastFramesDumped=REBASE(0x29E0A00);
        }
        namespace MarketplaceRecommendationsApi
        {
            const uintptr_t CacheDisabledRankProductsCacheGet=REBASE(0x1242750);
            const uintptr_t CacheEnabledRankProductsCacheInsert=REBASE(0x12428F0);
            const uintptr_t ConstructedURLRankProducts=REBASE(0x123B150);
            const uintptr_t ConstructedURLTopRecommendedProducts=REBASE(0x1237D10);
            const uintptr_t HttpRequestBodyRankProducts=REBASE(0x123BC30);
            const uintptr_t HttpRequestBodyRecommendTopProducts=REBASE(0x12382B0);
            const uintptr_t InitiateRankProductsAsyncIsEnabled=REBASE(0x12D2E10);
            const uintptr_t InitiateRecommendTopProductsAsyncIsEnabl=REBASE(0x12D26A0);
            const uintptr_t InvokeIsRecommendationsApiEligible=REBASE(0x1296380);
            const uintptr_t ParsedResultSuccess=REBASE(0x123BF60);
            const uintptr_t RankProductsCheckIfThrottleLimitPer=REBASE(0x129F210);
            const uintptr_t RecommendProductsCheckIfThrottleLimitPer=REBASE(0x129DF80);
            const uintptr_t SuccessfullyParsedValidProductIdentifier=REBASE(0x1297260);
            const uintptr_t SuccessfullyRetrievedProductInfoIndex=REBASE(0x1299020);
            const uintptr_t TryGetRankProductsModuleDatamodel=REBASE(0x12D2A80);
            const uintptr_t TryGetRecommendTopProductsModuleDatamode=REBASE(0x12D2310);
            const uintptr_t ValidatedProductIdentifierIndex=REBASE(0x12966A0);
            const uintptr_t WaitingRecommendTopProductsResponse=REBASE(0x129A860);
        }
        namespace MarketplaceShopApi
        {
            const uintptr_t InitiatingOpenShopRequestedSignal=REBASE(0x12352B0);
            const uintptr_t OpenShopSuccessIsClient=REBASE(0x12D3CE0);
            const uintptr_t ShopModuleOpenShopDataModelLongerAvailab=REBASE(0x1234C60);
            const uintptr_t TryGetShopModuleDatamodel=REBASE(0x12D3720);
        }
        namespace MatchmakingService
        {
            const uintptr_t FailedSendServerAttributesUpdateError=REBASE(0x3138460);
            const uintptr_t SendServerAttributesUpdateExitWithoutCha=REBASE(0x3137790);
            const uintptr_t ServerAttributesUpdateInProgress=REBASE(0x3137560);
        }
        namespace MediaCodecDriver
        {
            const uintptr_t CloseCalledCodecAttached=REBASE(0x3D28B10);
            const uintptr_t CodecUnexpectedlyReturnedEOFSettingStrea=REBASE(0x3D29350);
            const uintptr_t DroppingFramePtsDueSeek=REBASE(0x3D290D0);
        }
        namespace MegaClusterInit
        {
            const uintptr_t ClearingTerrainClientReplicator=REBASE(0x3402A9E);
            const uintptr_t DestroyingVoxelJobManager=REBASE(0x3456B40);
            const uintptr_t MegaClusterCreated=REBASE(0x3455E10);
            const uintptr_t OnServiceProviderOldProviderNewParent=REBASE(0x3457E00);
            const uintptr_t TerrainAlreadyExistsReplaceExistingOne=REBASE(0x34583E0);
            const uintptr_t TerrainDoesnTExistCreatingTerrain=REBASE(0x34027C0);
        }
        namespace MegaClusterNetwork
        {
            const uintptr_t SendClusterPacketJobRun=REBASE(0x46D52F0);
        }
        namespace MegaClusterNetworkInit
        {
            const uintptr_t AddingMegaClusterReplicationData=REBASE(0x46C4040);
        }
        namespace MegaReplicatorLogDisconnectCleanUpLog
        {
            const uintptr_t DestroyingMegaReplicator=REBASE(0x4765C50);
        }
        namespace MemoryHeapWalk
        {
            const uintptr_t HeapWalkInLaunchDurationMs2f=REBASE(0x4A02DFE);
        }
        namespace MemoryPrioritization
        {
            const uintptr_t CommitTotalBytesCommitLimitBytes=REBASE(0x2A4AB80);
            const uintptr_t FreeMBDeltaPctUsedMBDeltaPct=REBASE(0x2A497E0);
            const uintptr_t MemoryPressureResetLastLevelFreeMBUsedMB=REBASE(0x146B420);
        }
        namespace MemoryStore
        {
            const uintptr_t AddingHeaderBypassUniverseRateLimit=REBASE(0x110D500);
            const uintptr_t AddingInitialThrottlingBudgets=REBASE(0x310C950);
            const uintptr_t AddingLocalThrottlingBudgetPlayersTimeDe=REBASE(0x310CFC0);
        }
        namespace MemoryStoreService
        {
            const uintptr_t CursorValueString=REBASE(0x3123130);
            const uintptr_t DataKeyFoundBackendResponse=REBASE(0x310DF50);
            const uintptr_t EmptyQueueReadRemainingWaitTimeout=REBASE(0x31117E0);
            const uintptr_t FailedParseJson=REBASE(0x110F630);
            const uintptr_t FailedParseResponseJsonError=REBASE(0x110F9C0);
            const uintptr_t FailedParseSortKeyType=REBASE(0x3E9BB40);
            const uintptr_t InvalidCombinationBoundsProvided=REBASE(0x3EA70D0);
            const uintptr_t ItemsValueArray=REBASE(0x3114D50);
            const uintptr_t KeyValueString=REBASE(0x3E9D780);
            const uintptr_t QueueNull=REBASE(0x3110B50);
            const uintptr_t SendingHTTPErrorInfoUnknownErrors=REBASE(0x110DFB0);
            const uintptr_t SendingHTTPResponseUnknownErrors=REBASE(0x110DE00);
            const uintptr_t UnknownMemoryStoreErrorType=REBASE(0x110EEC0);
            const uintptr_t UnknownMemoryStoreErrorTypeEnum=REBASE(0x110AE60);
            const uintptr_t UnknownMemoryStoreStatusCode=REBASE(0x110A460);
        }
        namespace MeshCompressionLog
        {
            const uintptr_t CompressedDracoMeshExceedsMetadataFace=REBASE(0x2405370);
            const uintptr_t DecodedDracoMeshMissingHasMalformed=REBASE(0x24047E7);
            const uintptr_t FailedConvertMeshDracoMesh=REBASE(0x2404C90);
            const uintptr_t WriteUncompressedFileMeshData=REBASE(0x23F8160);
        }
        namespace MeshLODDetails
        {
            const uintptr_t SkinningValidationVertexHasOutRange=REBASE(0x2BE803D);
        }
        namespace MessageBus
        {
            const uintptr_t DestroyingConnectionInstance=REBASE(0x143AD30);
            const uintptr_t MessageBusReceivedWithoutValidNumber=REBASE(0x143EA90);
            const uintptr_t MessageBusServiceGetLastFailedDecodeJSON=REBASE(0x611BC90);
            const uintptr_t MessageBusServiceMakeRequestFailedDecode=REBASE(0x611BE90);
            const uintptr_t MessageBusServiceSetRequestHandlerFailed=REBASE(0x611C060);
            const uintptr_t MessageBusServiceSubscribeInternalFailed=REBASE(0x611BAD0);
            const uintptr_t Received=REBASE(0x1442120);
            const uintptr_t ReceivedProtocolMethodResponseWithoutReq=REBASE(0x1443810);
        }
        namespace MessagingService
        {
            const uintptr_t CSMEvent0JsonArraySize=REBASE(0x30FF260);
            const uintptr_t CSMEventException=REBASE(0x61A6A90);
            const uintptr_t MessagingServiceHandleMessageTopicSignal=REBASE(0x30FE410);
            const uintptr_t MessagingServiceInitializeConnectionCSM=REBASE(0x30FED30);
            const uintptr_t MessagingServiceLockDataModelHelperWeakD=REBASE(0x30FB3C0);
            const uintptr_t MessagingServiceOnCsmReconnectedResubscr=REBASE(0x3100B30);
            const uintptr_t MessagingServiceUnSubscribeUnsubscribeTo=REBASE(0x31097E0);
        }
        namespace Mimalloc
        {
            const uintptr_t Log=REBASE(0x4A01BB0);
            const uintptr_t MimallocIntegrationDetectedSettings=REBASE(0x49FC430);
        }
        namespace MissingDataPing
        {
            const uintptr_t TimeSinceLastDataPingReceived=REBASE(0x46E0BD0);
        }
        namespace ModelBundleTrace
        {
            const uintptr_t UnexpectedMagicWhilstDeserializingModelB=REBASE(0x2229DF0);
        }
        namespace ModelDeliveryTrace
        {
            const uintptr_t AssetDownloadSizeBufferSize=REBASE(0x833270);
            const uintptr_t ModelDeliveryTraceFailedModelRequestProc=REBASE(0x834CB0);
            const uintptr_t ModelDeliveryTraceMLModelDeliveryService=REBASE(0x835B60);
            const uintptr_t ModelDeliveryTraceModelRequestIdHasConte=REBASE(0x836330);
            const uintptr_t PriorityListSizeButExpectedSize=REBASE(0x837C20);
            const uintptr_t SizeVariantDoesMatchTotalSize=REBASE(0x82D840);
            const uintptr_t WeakDataModelCouldLocked=REBASE(0x831130);
        }
        namespace ModelLod
        {
            const uintptr_t ModelLodLoadingModelMeshZuBytes=REBASE(0x3606100);
        }
        namespace ModelSkinningTransformsView
        {
            const uintptr_t ModelSkinningTransformsViewSkeletonCreat=REBASE(0x52FE9C0);
            const uintptr_t ModelSkinningTransformsViewUnableGenerat=REBASE(0x52FC790);
            const uintptr_t ModelSkinningTransformsViewUpdateTransfo=REBASE(0x52FE330);
        }
        namespace ModelTranscoder
        {
            const uintptr_t AddingNewJoint=REBASE(0x44C78B0);
            const uintptr_t AssetFetchFailedContentId=REBASE(0x5BC5F30);
            const uintptr_t AssetFetchFailedContentIdError=REBASE(0x629C1B0);
            const uintptr_t AssetIDRecognizedFormat=REBASE(0x446CBD0);
            const uintptr_t CouldCreateSLIMResourceOBJDirectory=REBASE(0x448E360);
            const uintptr_t CouldMeasureInputFileSize=REBASE(0x621C0E0);
            const uintptr_t DerivedSLIMTranscoderResourcePathDoes=REBASE(0x4463F60);
            const uintptr_t ErrorCouldOpenFmdListFile=REBASE(0x446E940);
            const uintptr_t ErrorReadingPropertySetFile=REBASE(0x4495EF0);
            const uintptr_t FFlagFoundSetting=REBASE(0x4469BA0);
            const uintptr_t FailedDecodeCSGMeshMeshData2=REBASE(0x44A6D40);
            const uintptr_t FailedGenerateFileMeshDataPrimitive=REBASE(0x4476400);
            const uintptr_t FailedReadFileMeshData=REBASE(0x621DEF0);
            const uintptr_t FailedWriteLODMetadataFidelity=REBASE(0x448DB50);
            const uintptr_t FileFound=REBASE(0x446C520);
            const uintptr_t FlagNameFoundFlagBank=REBASE(0x4499040);
            const uintptr_t InstancesFoundPropertySetFile=REBASE(0x44961D0);
            const uintptr_t LoadFlagsSettingTranscoderOverrideFlags=REBASE(0x44653E0);
            const uintptr_t MissingVisualTrussStylePropertyTrussInst=REBASE(0x4472770);
            const uintptr_t MultiMaterialMeshHasJointsTimesVertices=REBASE(0x4486A50);
            const uintptr_t MultiSurfaceAppearanceMeshGeometryHasSur=REBASE(0x44741D0);
            const uintptr_t MultiSurfaceAppearanceMeshSurfaceSlotOut=REBASE(0x4473F80);
            const uintptr_t OnTranscodingEndWasNeverCalledTranscoder=REBASE(0x446B4C0);
            const uintptr_t PathDirectoryDoesExist=REBASE(0x4496D20);
            const uintptr_t ReadFileMeshData=REBASE(0x44A4BF0);
            const uintptr_t ResourceFileCannotWritten=REBASE(0x4490240);
            const uintptr_t TranscoderMetricsFailedLog=REBASE(0x621C020);
            const uintptr_t TranscoderRegistrySettingFlags=REBASE(0x44698C0);
            const uintptr_t WildMeshSimplifierFailedErrorCodeWhenPro=REBASE(0x4484710);
            const uintptr_t WrapDeformerPartInstanceHasBoneSkeleton=REBASE(0x44A23C0);
        }
        namespace ModerationService
        {
            const uintptr_t FailedDeleteReviewableContentEvent=REBASE(0x30F81B0);
            const uintptr_t HTTPStatusOKUploadingScreenshot=REBASE(0x30F2D30);
            const uintptr_t IECSafetyCallbackFailedDecodeProto=REBASE(0x30F4DC0);
            const uintptr_t IECSafetyCallbackMessageMissingScreensho=REBASE(0x30F43E0);
            const uintptr_t InternalMessagingServiceLoadedCannotSubs=REBASE(0x30F4110);
            const uintptr_t ReceivedTriggeredCaptureUploadSignalWith=REBASE(0x30F1A40);
            const uintptr_t ReceivedTriggeredCaptureUploadWithoutCap=REBASE(0x30F2190);
            const uintptr_t RecievedOKStatusLeaseReviewableContentEv=REBASE(0x30EE8F0);
            const uintptr_t UpdatingReviewableContentEventPollingInt=REBASE(0x30E8FA0);
            const uintptr_t ViolationProcessorBoundDroppingViolation=REBASE(0x30F3950);
        }
        namespace MomentsService
        {
            const uintptr_t MomentsServiceCheckMomentTextStatusAsync=REBASE(0x3F8CF80);
            const uintptr_t MomentsServiceCreatePostAsyncDispatching=REBASE(0x3F8A2E0);
            const uintptr_t MomentsServiceFetchPostAsyncDispatchingA=REBASE(0x3F8D530);
            const uintptr_t MomentsServiceGenerateMomentTextAsyncDis=REBASE(0x3F8C500);
        }
        namespace MouseCommandLifetime
        {
            const uintptr_t CloneToolCreated=REBASE(0xCEDD40);
            const uintptr_t CloneToolDestroyed=REBASE(0xCEDE20);
            const uintptr_t GameToolCreated=REBASE(0xCE5E60);
            const uintptr_t GameToolDestroyed=REBASE(0xCE5F50);
            const uintptr_t GrabToolCreated=REBASE(0xCE5290);
            const uintptr_t GrabToolDestroyed=REBASE(0xCE53D0);
            const uintptr_t HammerToolCreated=REBASE(0xCE4AB0);
            const uintptr_t HammerToolDestroyed=REBASE(0xCE4B90);
            const uintptr_t LuaDragToolCreated=REBASE(0xCDCE20);
            const uintptr_t LuaDragToolDestroyed=REBASE(0xCDD2D0);
            const uintptr_t PartDragToolCreated=REBASE(0xCD4FF0);
            const uintptr_t PartDragToolDestroyed=REBASE(0xCD52D0);
            const uintptr_t PartToolCreated=REBASE(0x3BA8680);
            const uintptr_t PartToolDestroyed=REBASE(0x3BA8830);
            const uintptr_t ScriptMouseCommandCreated=REBASE(0x3C0C590);
            const uintptr_t ScriptMouseCommandDestroyed=REBASE(0x3C0C810);
        }
        namespace MultiFilterWarning
        {
            const uintptr_t AnomalousConfigurationMultipleUniverseFi=REBASE(0x4A2F8C4);
        }
        namespace NCNNBackendTrace
        {
            const uintptr_t UnableParseInputShapeIndex=REBASE(0x222CF50);
            const uintptr_t UnableParseInputTensorName=REBASE(0x222C2A0);
        }
        namespace NativeAdsCore
        {
            const uintptr_t CallingPlatformImplOnServeInterstitialAd=REBASE(0x5144020);
            const uintptr_t HandleOnInterstitialLoadAdResultTakeRequ=REBASE(0x5145470);
            const uintptr_t PreServeTook3fMs=REBASE(0x51429F0);
            const uintptr_t ServingRequestWasFilled=REBASE(0x51398C0);
            const uintptr_t ServingRequestWasUnfilled=REBASE(0x5139A00);
        }
        namespace Navigation
        {
            const uintptr_t NavMeshAddTilePolyVertOffmesh=REBASE(0x24AA4A0);
            const uintptr_t NavMeshRemoveTilePolyVertOffmesh=REBASE(0x24AA010);
            const uintptr_t NavigationPathResultStartFinishAgentRadi=REBASE(0x85C110);
            const uintptr_t PartExceedsTileHeightCapacitySome=REBASE(0x86EA00);
            const uintptr_t PathfindingHeightfieldMemoryExceededMB=REBASE(0x84ACE0);
            const uintptr_t ProcessingRequestTilesQueueSize=REBASE(0x84BA90);
            const uintptr_t RcBuildContoursOutMemoryHolesMax=REBASE(0x24B3FC0);
            const uintptr_t UsedTerrainMemoryExccedLimitTileMemoryUs=REBASE(0x875D00);
            const uintptr_t VeryLargeTileMemoryUsedMBHeightfield=REBASE(0x8764B0);
        }
        namespace NavigationDetail
        {
            const uintptr_t AddClimbableLinkTopBottom=REBASE(0x84EAB0);
            const uintptr_t AddSpanIdxMaxMinXY=REBASE(0x24C2000);
            const uintptr_t JumpLinkAdded=REBASE(0x24ADE90);
        }
        namespace Network
        {
            const uintptr_t AckTimeoutLastPacketReceivedTimeMs=REBASE(0x2847E70);
            const uintptr_t ConfigDebugRepo=REBASE(0x49DFA40);
            const uintptr_t ConnectionLostConnectModeTimeMSLluConnec=REBASE(0x28296C0);
            const uintptr_t Disconnect=REBASE(0x46F64B0);
            const uintptr_t DisconnectReasonReceived=REBASE(0x2826A20);
            const uintptr_t DisconnectingDueExceedingMaximumSendSize=REBASE(0x48B4B30);
            const uintptr_t DuplicatePlayerIdJoinQueueRemoving=REBASE(0x4773770);
            const uintptr_t ErrorDecompressingPacketClientOnReceive=REBASE(0x4802140);
            const uintptr_t ExceptionDuringDataOutStepRequest=REBASE(0x622B250);
            const uintptr_t JoinSnapshotTimer=REBASE(0x4707890);
            const uintptr_t Log=REBASE(0x48A3B40);
            const uintptr_t LostConnectionReason=REBASE(0x46F6320);
            const uintptr_t MessageError=REBASE(0x6231AC0);
            const uintptr_t NetworkClientCreate=REBASE(0x47F2240);
            const uintptr_t NetworkClientRemove=REBASE(0x47F28D0);
            const uintptr_t NetworkServerCreate=REBASE(0x4818550);
            const uintptr_t NetworkServerDestroy=REBASE(0x4818E90);
            const uintptr_t PlayerLuaLoadCharacter=REBASE(0x3DDA310);
            const uintptr_t PlayerLuaLoadCharacterWithAvatarRules=REBASE(0x3DDB420);
            const uintptr_t PlayerLuaLoadCharacterWithHumanoidDescri=REBASE(0x3DDA630);
            const uintptr_t PlayersServiceRequestsPlayerDisconnect=REBASE(0x4764690);
            const uintptr_t RakNetFailedSetSendTimeoutSocket=REBASE(0x28118E0);
            const uintptr_t RefEdgeScratchLeaseReentrantScratchUseUs=REBASE(0x475C650);
            const uintptr_t ReplicatorCreated=REBASE(0x46B50E0);
            const uintptr_t ReplicatorDestroyed=REBASE(0x46B8FD0);
            const uintptr_t ReplicatorReadMarkerId=REBASE(0x48B94D0);
            const uintptr_t ReplicatorSendMarkerId=REBASE(0x46D43E0);
            const uintptr_t RxOrderedHeapStallTimeoutChannel=REBASE(0x2846750);
            const uintptr_t RxPeerExceededBufferedCompleteDatagram=REBASE(0x281FF40);
            const uintptr_t SendingDisconnectReason=REBASE(0x281BE80);
            const uintptr_t SerializingInstancesPreparingBlobsJoinDa=REBASE(0x4773AF0);
            const uintptr_t ServerDroppedRakNetRouteRakNetPeer=REBASE(0x481FF40);
            const uintptr_t ServerOnReceiveIDNEWINCOMINGCONNECTION=REBASE(0x481CAA0);
            const uintptr_t SetsockoptIPV6V6ONLYFailedErrnoErrString=REBASE(0x283E050);
            const uintptr_t ShardingCreateBoundSocketForcePortPortLo=REBASE(0x283E6B0);
            const uintptr_t TimedOutFailedGracefullyEndReceive=REBASE(0x28144C0);
            const uintptr_t TimedOutSendPacketsToSelfToUnblockSocket=REBASE(0x28143FC);
            const uintptr_t TooManyPacketsDroppedMs=REBASE(0x282A9A0);
            const uintptr_t UDMUXAddressPortRCCServerAddress=REBASE(0x4805370);
            const uintptr_t UnableAccessDataModelWhenCheckingIXP=REBASE(0x47F2D40);
            const uintptr_t WARNINGSkippingTopReplicationContainerBe=REBASE(0x4827FB0);
        }
        namespace NetworkAudit
        {
            const uintptr_t RakNetDisconnectClosingConnection=REBASE(0x281E110);
            const uintptr_t RakNetSocketClose=REBASE(0x283A820);
        }
        namespace NetworkBandwidthManagerTrace
        {
            const uintptr_t NetworkBandwdithManagerCalculateBandwidt=REBASE(0x47D6AE0);
        }
        namespace NetworkClient
        {
            const uintptr_t ClientDisconnect=REBASE(0x47F95D0);
            const uintptr_t RbxTransportClientWillConnectWithoutRupp=REBASE(0x47F54E0);
            const uintptr_t RbxTransportDummyClientWillConnectWithou=REBASE(0x47F8270);
            const uintptr_t RbxTransportRccAddrParseError=REBASE(0x47F77A0);
            const uintptr_t TransportSelectionUseRbxTransportEnabled=REBASE(0x47F4050);
        }
        namespace NetworkCluster
        {
            const uintptr_t ClusterDeserializeIsEmptyMaskCount=REBASE(0x48C4260);
            const uintptr_t ClusterInitialCacheLineCreatedLod=REBASE(0x48A9E10);
            const uintptr_t SkippingClusterChunkDebounceSizeHasOutgo=REBASE(0x48C3780);
            const uintptr_t SkippingClusterPacketIllegalTerrainRecei=REBASE(0x48C4970);
            const uintptr_t WroteJoinDataItemMegacluster=REBASE(0x4857CB0);
        }
        namespace NetworkDataAssertData
        {
            const uintptr_t NetworkDataAssert=REBASE(0x5326B90);
        }
        namespace NetworkEmulationUdpSocket
        {
            const uintptr_t NetworkEmulationUdpSocketUpdatedConfigur=REBASE(0x2178590);
            const uintptr_t SendsDroppedTotalSendsSendDropPercentage=REBASE(0x217AC80);
        }
        namespace NetworkEmulationUpdater
        {
            const uintptr_t ApplyingNetworkEmulationConfigOverrideNe=REBASE(0x4807570);
            const uintptr_t IgnoringCoreNetworkSettingsChangeDueActi=REBASE(0x48E9FD0);
            const uintptr_t ResettingNetworkEmulationConfigOverrideN=REBASE(0x48EA290);
            const uintptr_t UsingNetworkEmulationConfigCoreNetworkSe=REBASE(0x48E9AD0);
        }
        namespace NetworkInstances
        {
            const uintptr_t DestroyReplicationCleaningUpReplicationD=REBASE(0x48EED90);
            const uintptr_t ReplicatingUnparentingInstance=REBASE(0x48B7A30);
        }
        namespace NetworkItemQueueDtor
        {
            const uintptr_t ItemsQueuedDestruction=REBASE(0x485695A);
        }
        namespace NetworkIxp
        {
            const uintptr_t SetIXPParamsLayerLoadedSignal=REBASE(0x4805160);
            const uintptr_t SetLatencyIxpLiveResponseAfter=REBASE(0x47F3240);
            const uintptr_t SettingLatencyIxpTxRx=REBASE(0x281CEC0);
        }
        namespace NetworkJoin
        {
            const uintptr_t HandledZuInstancesOverInvocationsMs=REBASE(0x48575D0);
            const uintptr_t ServerJoinSnapshotTimer=REBASE(0x479CF10);
        }
        namespace NetworkPauseLogging
        {
            const uintptr_t CharacterOutsideStreamedAreaChangedFalse=REBASE(0x47C15B0);
            const uintptr_t GCJobDeleteRegionReplicationFocusOutside=REBASE(0x47C0A20);
            const uintptr_t GCJobUpdateReplicationFocusTrackingFallB=REBASE(0x47BB589);
            const uintptr_t StillPausedStateOutsideStreamedRadius=REBASE(0x47B8200);
        }
        namespace NetworkProfilerChannel
        {
            const uintptr_t L6fPeerLocalRemote=REBASE(0x53271C3);
        }
        namespace NetworkReadItem
        {
            const uintptr_t ReadItemWireTypeBitStreamOffsetBytes=REBASE(0x46DD320);
            const uintptr_t ReplicatorProcessDeserializedJoinDataIte=REBASE(0x46E6080);
        }
        namespace NetworkSenderStallTracking
        {
            const uintptr_t ByteBudgetFrames=REBASE(0x48906F0);
            const uintptr_t Frames=REBASE(0x4890470);
            const uintptr_t TransportLevelPushBackFrames=REBASE(0x4890960);
        }
        namespace NetworkSharedQueue
        {
            const uintptr_t CleaningSharedQueueAfterCleanLowestValid=REBASE(0x476EC60);
        }
        namespace NetworkSocketReceiveError
        {
            const uintptr_t PollFailedErrno=REBASE(0x283E9C0);
        }
        namespace NetworkStatsReport
        {
            const uintptr_t ReportingACTUALBYTESRECEIVED=REBASE(0x46F7920);
            const uintptr_t UpdateStatsJobRakStatsACTUALBYTESRECEIVE=REBASE(0x489A000);
            const uintptr_t UpdatingStatsReplicatorOnStatisticsChang=REBASE(0x46C3AD0);
        }
        namespace NetworkStepsMultipliers
        {
            const uintptr_t PingElapsedTime=REBASE(0x46DEC70);
            const uintptr_t ProcessPacketsJobRunning=REBASE(0x48A7730);
        }
        namespace NetworkStreaming
        {
            const uintptr_t SendingItemInstancesEvaluatingNewlyAdded=REBASE(0x468B5B0);
            const uintptr_t SendingItemInstancesEvaluatingRequiredSe=REBASE(0x468AABF);
            const uintptr_t SendingMetaUpdateCenterRadius=REBASE(0x4692820);
            const uintptr_t SendingPrefetchMetaUpdateCenterRadius=REBASE(0x4692C50);
            const uintptr_t SendingRegion0InstancesPrimitiveCallback=REBASE(0x4698D90);
            const uintptr_t SendingRegionClusterLodInstances=REBASE(0x4697F10);
            const uintptr_t SendingRegionInstances=REBASE(0x4694230);
        }
        namespace NetworkStreamingExpandedShapeQuery
        {
            const uintptr_t AddingTestFrustumQuery=REBASE(0x468BE90);
            const uintptr_t ClientFrustumProgressHorizontalAngleMax=REBASE(0x47BC5A0);
            const uintptr_t CollectedInstances=REBASE(0x4695B4B);
            const uintptr_t CollectedLodInstances=REBASE(0x4695190);
            const uintptr_t CreateItemCalledBeforeViewWasSet=REBASE(0x4826590);
            const uintptr_t DynamicSubdivisionsDimQueriedTotalInstan=REBASE(0x4826AB2);
            const uintptr_t FinalizedRegions=REBASE(0x4696110);
            const uintptr_t FoundTerrainS=REBASE(0x4695D6B);
            const uintptr_t QueryCanceledBecauseWeAreRestricted=REBASE(0x46809BF);
            const uintptr_t QueryLodStartedBecauseWeWere=REBASE(0x4680380);
            const uintptr_t QueryStartedBecauseWeWereOutdated=REBASE(0x4695530);
        }
        namespace NetworkTrace
        {
            const uintptr_t DidAddPacketTxDelayQueue=REBASE(0x283EC60);
            const uintptr_t GetConnectedServerReturning=REBASE(0x4803E50);
            const uintptr_t NoViableConnectionsLeftScStateReturningF=REBASE(0x48E6150);
            const uintptr_t ReportPerServerMetricScStateReturningFal=REBASE(0x48E61E0);
            const uintptr_t ReportingNetworkMetricDiagTimeSince=REBASE(0x48E6900);
            const uintptr_t ReportingPerServerMetricInflux=REBASE(0x48E7E50);
            const uintptr_t SendtoFailedCodeMsgLenErrno=REBASE(0x283EF20);
        }
        namespace NewWebView2Browser
        {
            const uintptr_t CannotCreateRebar=REBASE(0x16D1150);
            const uintptr_t CannotCreateToolbar=REBASE(0x16D0B10);
            const uintptr_t DesignFoundationsApplyingTokenColor06XCo=REBASE(0x16CDC10);
            const uintptr_t GamepadNavigationCommandJSONInvalid=REBASE(0x16D1940);
            const uintptr_t GotRequestButDeferredRequestAlready=REBASE(0x16C7E70);
            const uintptr_t WebView2BrowserCloseEmbeddedWindowWebVie=REBASE(0x16CED70);
            const uintptr_t WebView2BrowserContentLoadingDeepLinking=REBASE(0x16C6B70);
            const uintptr_t WebView2BrowserErrorSource=REBASE(0x16C8FD0);
            const uintptr_t WebView2BrowserExecuteScript=REBASE(0x16D4790);
            const uintptr_t WebView2BrowserLaunching=REBASE(0x16C3AD0);
            const uintptr_t WebView2BrowserLogWin32BTIdRBXEventTrack=REBASE(0x16CB620);
            const uintptr_t WebView2BrowserStopContentWebviewInvalid=REBASE(0x16D2440);
            const uintptr_t WebView2BrowserTabNavStartingUrlBlocked=REBASE(0x16C5A70);
            const uintptr_t WebView2DeepLinkingNewWindowRequestedHan=REBASE(0x16CD3F0);
            const uintptr_t WebView2RuntimeInstalled=REBASE(0x16A9590);
        }
        namespace NotificationLogs
        {
            const uintptr_t DisplayedNonexistentNotificationId=REBASE(0x3EFE720);
            const uintptr_t TriedDismissNonexistentNotificationId=REBASE(0x3EFDDA0);
            const uintptr_t TriedInteractNonexistentNotificationId=REBASE(0x3EFE3C0);
        }
        namespace NotificationService
        {
            const uintptr_t ConnectToRelaySignalsSuccessfullyConnect=REBASE(0x30DF9A0);
            const uintptr_t HandleRccRelayConnectionStateChangedName=REBASE(0x30E4530);
            const uintptr_t HandleRccRelayMessageNamespaceDetailType=REBASE(0x30E4120);
            const uintptr_t NotificationServiceGetOrCreateRccRealtim=REBASE(0x30DFED0);
            const uintptr_t NotificationServiceOnServiceProviderUniv=REBASE(0x30DE5A0);
            const uintptr_t NotificationServiceReceivedMessageRelayN=REBASE(0x30E6900);
            const uintptr_t SetupBackendMessageSubscriptionRccRealti=REBASE(0x30E1C10);
            const uintptr_t SetupRccRealtimeRelayIfReadyUniverseIdNo=REBASE(0x30DF150);
            const uintptr_t SubscribeToRccEventNamespaceEventNamespa=REBASE(0x30E0960);
            const uintptr_t SubscribeToTopicTokenCannotEmpty=REBASE(0x30E0AA0);
            const uintptr_t TrySubscribeInternalMessagingServiceSubs=REBASE(0x30E04C0);
            const uintptr_t UnsubscribeFromTopicTokenCannotEmpty=REBASE(0x30E1380);
        }
        namespace OPENXR
        {
            const uintptr_t CheckHapticsXrResultValueSetResult=REBASE(0x27E1040);
            const uintptr_t Error=REBASE(0x27DB160);
            const uintptr_t HandleSessionStateChangedReceivedSession=REBASE(0x27DFD40);
            const uintptr_t OpenXrDeviceSetRefreshRateTargetRefreshR=REBASE(0x27E0B60);
        }
        namespace OPENXRHaptics
        {
            const uintptr_t SetHapticsStateValue=REBASE(0x27E1160);
        }
        namespace OnScreenKeyboardController
        {
            const uintptr_t OpeningScreenKeyboardInputType=REBASE(0x787FE0);
        }
        namespace OnScreenKeyboardListener
        {
            const uintptr_t UnableRegisterCallbackHandlerFrameworkIn=REBASE(0x78A0D0);
        }
        namespace OnScreenKeyboardWindowDelegate
        {
            const uintptr_t CouldConvertClientScreenPoint=REBASE(0x78B890);
            const uintptr_t DoNeedResetWindowPositionPosition=REBASE(0x78B5A0);
            const uintptr_t UnableChangePositionWindow=REBASE(0x78B390);
            const uintptr_t UnableGetMonitorInfo=REBASE(0x78B760);
        }
        namespace OpenCloudService
        {
            const uintptr_t FailedLockOpenCloudCoreScript=REBASE(0x30D6440);
            const uintptr_t OpenCloudScriptFailed=REBASE(0x30DA860);
            const uintptr_t RegisterOpenCloudShouldOnlyCalledServer=REBASE(0x30D7280);
            const uintptr_t UnexpectedReturnValueTable=REBASE(0x30D7020);
        }
        namespace Output
        {
            const uintptr_t AppNoReloadHandlerLocalAppResuming=REBASE(0x719060);
            const uintptr_t BackupOTAUpdateRequested=REBASE(0x15B9A60);
            const uintptr_t BuildSystemId2=REBASE(0x4CB0190);
            const uintptr_t CSGPropertyDataGetStringValue=REBASE(0xE33070);
            const uintptr_t CSGPropertyDataReadvalue=REBASE(0xE32E60);
            const uintptr_t CSGPropertyDataSetStringValue=REBASE(0xE33020);
            const uintptr_t CSGPropertyDataWritevalue=REBASE(0xE32E10);
            const uintptr_t CallingGetRegistryChannelBeforeAppPtrVal=REBASE(0x71C2E0);
            const uintptr_t CallingMiCollect=REBASE(0x4A04CE0);
            const uintptr_t CanTFindSecretKey=REBASE(0x3C1BBE0);
            const uintptr_t ClosingFmodMlSl=REBASE(0x453C260);
            const uintptr_t ConnectingUDMUXServerRCCServer=REBASE(0x49048F0);
            const uintptr_t CouldFindSoundServiceAudioPlayer=REBASE(0x45F3490);
            const uintptr_t DebugRenderingTestVideoCaptureStopSucces=REBASE(0x309A740);
            const uintptr_t DumpedRawDataKBStringsKB=REBASE(0x2A80970);
            const uintptr_t ERRORGetAdapterDescFailedGetGetDescInfo=REBASE(0x29F20E6);
            const uintptr_t ERRORGetAdapterDescGetFactoryFailedResul=REBASE(0x29F1FD4);
            const uintptr_t ESGamePerfMonitorGPUDedicatedVidMemLluDe=REBASE(0x29F2520);
            const uintptr_t EditableMeshPublishSuccess=REBASE(0x3B8DB60);
            const uintptr_t EngineContextInExperienceLocaleSet=REBASE(0x13D0CB0);
            const uintptr_t ErrorParsingExperimentFString=REBASE(0x617B5F0);
            const uintptr_t ErrorStandardMessageOutSetIncorrect=REBASE(0x4267530);
            const uintptr_t ErrorWhileCleaningSoundCache=REBASE(0x6221C90);
            const uintptr_t EvaluatingDeferredInferredCrashes=REBASE(0x2A0DBB0);
            const uintptr_t ExecutingMicroProfilerScreenshotCallback=REBASE(0x2A87730);
            const uintptr_t FailedCreateTracerProvider=REBASE(0x4EC4F80);
            const uintptr_t FailedRegisterHapticEffect=REBASE(0x3C059E0);
            const uintptr_t FailedRemoveStreamCacheFileSound=REBASE(0x453B9A0);
            const uintptr_t FailedUnregisterHapticEffect=REBASE(0x3C05C30);
            const uintptr_t FailedUpdateAdornsAfterPhysicsSettings=REBASE(0x33FF520);
            const uintptr_t FastFlagConfigForcingINTERNALTESTINGFlag=REBASE(0x5C03850);
            const uintptr_t FreeErr=REBASE(0x2C9EA70);
            const uintptr_t HSRDataHasUploadedHsrIdPlease=REBASE(0x1B09460);
            const uintptr_t HashingBTIDValueRangeIsTreatment=REBASE(0x2A06EA0);
            const uintptr_t HelloWorldGNDMRX78CLI=REBASE(0x5BCDD20);
            const uintptr_t HttpRequestStreamingCallbackError=REBASE(0x61EAF60);
            const uintptr_t ImplementationFoundContentIdFormatterEng=REBASE(0x1C52980);
            const uintptr_t ImplementationFoundCreatorConfigEngineMo=REBASE(0x1C527E0);
            const uintptr_t ImplementationFoundEditableTelemetryModu=REBASE(0x1C52B20);
            const uintptr_t ImplementationFoundEngineApiMetricsModul=REBASE(0x1C52A50);
            const uintptr_t ImplementationFoundFriendsCallingModule=REBASE(0x1C52BF0);
            const uintptr_t ImplementationFoundInstanceStitchingHand=REBASE(0x1C52710);
            const uintptr_t ImplementationFoundStreamingEngineModule=REBASE(0x1C52640);
            const uintptr_t ImplementationFoundTextEngineModule=REBASE(0x1C528B0);
            const uintptr_t InferredCrashSystemFoundUniqueId=REBASE(0x2A12690);
            const uintptr_t LaunchtimeArgumentLoggingExperienceLaunc=REBASE(0x44EB8D0);
            const uintptr_t MicroProfilerStreamCouldPublishedSlot=REBASE(0x2A7C2B0);
            const uintptr_t MicroProfilerStreamStoppedRequestedPaylo=REBASE(0x2AAF400);
            const uintptr_t MockVideoLengthMsTotalMemory=REBASE(0x5A21630);
            const uintptr_t OTAUpdateRequested=REBASE(0x15B9D70);
            const uintptr_t ParsingV5BucketSettingsMinRangeMaxRange=REBASE(0x2A061A0);
            const uintptr_t ProductionSampler=REBASE(0x5A34A40);
            const uintptr_t ProtectedMemoryResourceAllocateFailed=REBASE(0x28ADFC0);
            const uintptr_t RBXFileSystemCopyFileFailedUnknownExcept=REBASE(0x623EF90);
            const uintptr_t ReportingSuccessErrorOperation=REBASE(0x50C0D40);
            const uintptr_t Screenshot=REBASE(0x3BD4C80);
            const uintptr_t ScriptScopeTokenPoolStatsPerFramesHotPat=REBASE(0x5A36CB0);
            const uintptr_t SessionTransitionFSMErrorOccurred=REBASE(0x2A4D8A0);
            const uintptr_t SetAssetFolder=REBASE(0x113A0B0);
            const uintptr_t SetExtraAssetFolder=REBASE(0x1139AE0);
            const uintptr_t SetLocalAssetFolder=REBASE(0x1139D10);
            const uintptr_t SetStudioAssetFolder=REBASE(0x1139840);
            const uintptr_t SettingsDateFoundInvalidUsingLocal=REBASE(0x4532440);
            const uintptr_t SpatialHashStats=REBASE(0x2E1EAB0);
            const uintptr_t SubmitAndValidateForUTPTestServiceFoundS=REBASE(0x3097340);
            const uintptr_t SubmittingSaveTaskTaskScheduler=REBASE(0x4D03440);
            const uintptr_t SubmittingScreenshotTaskTaskScheduler=REBASE(0x4D032D0);
            const uintptr_t Subtracting=REBASE(0x5C99470);
            const uintptr_t SwitchingAllowlistBasedLogFilteringCurre=REBASE(0x4520C70);
            const uintptr_t ThirdPartyUserDoesHoldNecessary=REBASE(0x749CF0);
            const uintptr_t TrayNoReloadHandlerLocalAppResuming=REBASE(0x7A1190);
            const uintptr_t UnknownJointFoundTargetMesh=REBASE(0x1D3B290);
            const uintptr_t UnrecognizedProtocolArg=REBASE(0x773440);
            const uintptr_t ValidationError=REBASE(0x3098670);
            const uintptr_t ValidationPSNR2fSSIM4f=REBASE(0x30988D0);
            const uintptr_t VideoApiEnabledUniversalAppLuaContextUni=REBASE(0x3D1CB10);
            const uintptr_t WebClickELTShouldRunWhenLaunchWeb=REBASE(0x748930);
            const uintptr_t WrapDeformerBeginSkinningTransferResulte=REBASE(0x18BFD00);
            const uintptr_t WrapDeformerFetchingMeshesResultFinish=REBASE(0x18BFB20);
            const uintptr_t WrapDeformerFetchingMeshesResultedError=REBASE(0x18BF820);
            const uintptr_t WrapDeformerFetchingSkinnedMeshesResult=REBASE(0x18DC5A0);
        }
        namespace PPJProgressHalt
        {
            const uintptr_t QueueHasBeenEmptyFrames=REBASE(0x488F8B0);
            const uintptr_t StuckProcessingPacketIdFrames=REBASE(0x488FB30);
            const uintptr_t UnablePopLatestPacketQueueFrames=REBASE(0x4890070);
        }
        namespace Package
        {
            const uintptr_t FailedReadOverridesCarriedNewDefinition=REBASE(0x3D76B40);
            const uintptr_t MakeInstancePatchViewBeforeAfterHaveMism=REBASE(0x5BD2780);
            const uintptr_t PackageRequestResultPackageLliV=REBASE(0x3D68860);
            const uintptr_t RequestWebCopyPackageLldVersion=REBASE(0x3D6EF90);
            const uintptr_t RevertOverridesNestedReferenceChangedWhi=REBASE(0x3D60880);
            const uintptr_t RevertOverridesSkippingNestedReferencePa=REBASE(0x3D5F960);
        }
        namespace PackageLink
        {
            const uintptr_t ErrorWhileSettingOverride=REBASE(0x3D73370);
            const uintptr_t FailedRevert=REBASE(0x61F45B0);
            const uintptr_t FailedRevertAttributes=REBASE(0x61F4760);
            const uintptr_t FailedRevertParent=REBASE(0x61F4470);
            const uintptr_t FailedSerializePackageOverrides=REBASE(0x3D7F250);
            const uintptr_t OverridesBlobNamesPropertyWhichDoes=REBASE(0x5BD9540);
            const uintptr_t PublishFilterFailedReSerializeReach=REBASE(0x61F3DE0);
            const uintptr_t PublishFilterFailedReadOverrides=REBASE(0x3D7EB20);
            const uintptr_t ReHomeOverridesNestedRootFound=REBASE(0x3D81F60);
        }
        namespace PageMilestoneRegistry
        {
            const uintptr_t SubscriberCallbackThrew=REBASE(0x62CE540);
            const uintptr_t SubscriberCallbackThrewNonStdException=REBASE(0x62CE640);
        }
        namespace ParameterizeHandler
        {
            const uintptr_t WrongParameterFormat=REBASE(0x13A21A0);
        }
        namespace PartInstanceLifetime
        {
            const uintptr_t BasePartDestroyedPrimitive=REBASE(0xDCB550);
            const uintptr_t Name=REBASE(0xDCBAD0);
        }
        namespace PartStreamingRequests
        {
            const uintptr_t CenterPosition=REBASE(0x4670B5A);
            const uintptr_t ChangedStreamedRadiusBasedServerMetadata=REBASE(0x47B9BA0);
            const uintptr_t CollectedInstances=REBASE(0x4693D60);
            const uintptr_t DeletedRegionGcdistCurrentRad=REBASE(0x47B15E0);
            const uintptr_t ReceivedNewClientInstanceQuotaMax=REBASE(0x4675B20);
            const uintptr_t ShrankCurrentStreamedRadiusFocusRegions=REBASE(0x47B0C10);
            const uintptr_t StreamMaxDistanceExceededLongestDistance=REBASE(0x47BD6E0);
        }
        namespace PaymentsProtocol
        {
            const uintptr_t PerformSubscriptionPurchaseStartProductT=REBASE(0x5194B90);
        }
        namespace PaymentsProtocolImpl
        {
            const uintptr_t GetMicrosoftCollectionsAccessTokenProduc=REBASE(0x51985C0);
            const uintptr_t GetSecondaryAuthTokenStarted=REBASE(0x51966B0);
            const uintptr_t GrantRobuxFailureUserCollectionIdFound=REBASE(0x5196BA0);
            const uintptr_t InvokeStoreFailureUserCollectionId=REBASE(0x5197E80);
            const uintptr_t PreparePaymentProductFailed=REBASE(0x5199270);
            const uintptr_t XStoreEnumerateProductsQueryStarted=REBASE(0x5196450);
            const uintptr_t XStoreGetUserCollectionsIdResultSizeFail=REBASE(0x5199740);
            const uintptr_t XTaskQueueCreateFailed08X=REBASE(0x5196A40);
        }
        namespace PeerMonotonicClock
        {
            const uintptr_t PeerMonotonicClockNowCalledBeforeInitial=REBASE(0x59C485A);
        }
        namespace PercentileReportStats
        {
            const uintptr_t DFStringPerfRunTeamCityId=REBASE(0x2AA3230);
            const uintptr_t PhasePercentileAggregateP0P5P10=REBASE(0x2AA7470);
            const uintptr_t PhaseReportCurrentCycleCountLd=REBASE(0x2AA5B50);
            const uintptr_t PhaseSkippingFrameLdDurationMs=REBASE(0x2AA40D0);
        }
        namespace PerformanceControlExecution
        {
            const uintptr_t RequestingChangeTunable=REBASE(0x20AFFB0);
            const uintptr_t TunableCurrentValTargetValDeltaMemBytes=REBASE(0x20DD810);
            const uintptr_t TunableTimeCompleteUs=REBASE(0x20AB3B0);
        }
        namespace PerformanceControlHarmonyComputeCoordinator
        {
            const uintptr_t ComputeTunableEnabledCheckFStringPerform=REBASE(0x20852D0);
            const uintptr_t TargetFrameTimeIncreased=REBASE(0x209B7B0);
        }
        namespace PerformanceControlIXP
        {
            const uintptr_t DeferringHarmonyExposureEnrollmentPerExp=REBASE(0x4D13100);
            const uintptr_t DeviceExposedExperiments=REBASE(0x4D15C50);
            const uintptr_t HarmonyExposureLayerInitializedEnrolling=REBASE(0x4D16380);
            const uintptr_t TrimMemoryEnabled=REBASE(0x58D4BE0);
            const uintptr_t UniverseIdPlaceIdAreBothAbsentAllowlist=REBASE(0x4D15EF0);
        }
        namespace PerformanceControlMemoryBudget
        {
            const uintptr_t HarmonyMemoryMBFreeOs1fCritBuf=REBASE(0x20CD240);
        }
        namespace PerformanceControlService
        {
            const uintptr_t UnsupportedCrossExperienceType=REBASE(0x5D0F910);
        }
        namespace PerformanceControlThermalThrottle
        {
            const uintptr_t PerformanceControlThermalThrottlingTherm=REBASE(0x2089BE0);
        }
        namespace PerformanceControlUtil
        {
            const uintptr_t PerformanceControlUtilLaunchCrossExpVoic=REBASE(0x4D150C0);
            const uintptr_t PerformanceControlUtilRegisteredContinue=REBASE(0x4D14A60);
            const uintptr_t PerformanceControlUtilRegisteredLaunchCr=REBASE(0x4D14400);
            const uintptr_t PerformanceControlUtilRegisteredSingleSu=REBASE(0x4D13A00);
            const uintptr_t PerformanceControlUtilRemovedContinueCro=REBASE(0x4D15A60);
            const uintptr_t PerformanceControlUtilSubmittedContinueC=REBASE(0x4D15440);
        }
        namespace PerformanceTelemetry
        {
            const uintptr_t CountMinP001P01P05=REBASE(0x35FEDC0);
            const uintptr_t ReportingAggregationsTelemetry=REBASE(0x35FFBD0);
            const uintptr_t ShuttingDownSubsystem=REBASE(0x359B2D0);
            const uintptr_t ThrottledCreatingSubsystemThrottledPerfo=REBASE(0x35FD950);
        }
        namespace Photo2Avatar
        {
            const uintptr_t AddAccessory=REBASE(0x1AAE570);
            const uintptr_t AddAvatarGenerationJobJobAlreadyExistsPl=REBASE(0x1AB7970);
            const uintptr_t AddCompletedAvatarPreviewJobJobAlreadyEx=REBASE(0x1AB7BB0);
            const uintptr_t CancelAllPlayerGenerationJobsPlayerNull=REBASE(0x1AB9010);
            const uintptr_t CancelJobFailedID=REBASE(0x1C18AF0);
            const uintptr_t CancelJobSucceededID=REBASE(0x1C18A00);
            const uintptr_t CancelQRTokenFailedTokenIDHttpResponse=REBASE(0x1AD47C2);
            const uintptr_t CancelQRTokenSucceededTokenID=REBASE(0x1AD4690);
            const uintptr_t CreateAvatarGenerationJobURL=REBASE(0x1C164E0);
            const uintptr_t CreateFromImageContentAsyncFailed=REBASE(0x1AD48F0);
            const uintptr_t DecodedNestedJSONBlob=REBASE(0x1C186E0);
            const uintptr_t FailedDelete3DGenerationResultError=REBASE(0x1BE49C0);
            const uintptr_t GetAvatarGenerationIdForPlayerError=REBASE(0x1AB7700);
            const uintptr_t GetAvatarGenerationIdForPlayerFailedGetI=REBASE(0x1AB71D0);
            const uintptr_t GetPreviewJobByIdJobFoundPlayer=REBASE(0x1AB97D4);
            const uintptr_t GetPreviewJobByIdPlayerFound=REBASE(0x1AB96A0);
            const uintptr_t HandleJobDoneUrl=REBASE(0x1C17D90);
            const uintptr_t HandleSelfieQRResultQRSelfiesYetEnabled=REBASE(0x1AC8B30);
            const uintptr_t HeadInstanceMeshPartGeneratedAvatar=REBASE(0x1AB1970);
            const uintptr_t JobCompletedSuccessfullyID=REBASE(0x1C15C10);
            const uintptr_t MediaPickerProtocolAvailablePlatform=REBASE(0x1ACCFF0);
            const uintptr_t MediaPickerProtocolIsAvailableFailed=REBASE(0x1ACE210);
            const uintptr_t ParentAttachmentBasePart=REBASE(0x1AB124E);
            const uintptr_t ParentJointAttachmentBasePart=REBASE(0x1AB11B3);
            const uintptr_t Photo2AvatarJob2DOutputDataDoesIncludePr=REBASE(0x1BDD2A0);
            const uintptr_t Photo2AvatarJob3DSaveResultSuccessfullyW=REBASE(0x1BE4F40);
            const uintptr_t Photo2AvatarJobRunFailed=REBASE(0x1C162A0);
            const uintptr_t PollForResultStatus=REBASE(0x1C17720);
            const uintptr_t PreviewJobDidResolveTemplateHair=REBASE(0x1BE1740);
            const uintptr_t PromptSelectAvatarGenerationImageAsyncDa=REBASE(0x1AC04A0);
            const uintptr_t QRTokenGenerationSucceededTokenID=REBASE(0x1ACBF70);
            const uintptr_t RemovePendingAvatarGenerationJobJobFound=REBASE(0x1AB81B0);
            const uintptr_t ReplicateAvatarGenerationImageIdEventSho=REBASE(0x1ABEE80);
            const uintptr_t ReplicationAvatarModelShouldOnlyHappen=REBASE(0x1ABA190);
            const uintptr_t RequestAvatarGenerationImageEventShouldO=REBASE(0x1ABEAB0);
            const uintptr_t RequestAvatarPreviewUrlEventShouldOnlySe=REBASE(0x1ABDCE0);
            const uintptr_t RequestAvatarTempAssetIdsEventShouldOnly=REBASE(0x1ABC1E0);
            const uintptr_t SendOpenQRCodeEventError=REBASE(0x1ACB140);
            const uintptr_t SendOpenQRCodeEventErrorPlayersNull=REBASE(0x1ACA970);
            const uintptr_t SessionUserMapFoundSessionMap=REBASE(0x1AC22E0);
            const uintptr_t SkippingGeneratedAccessoryUnknownType=REBASE(0x1AB0350);
            const uintptr_t StoredPreviewURLValidURL=REBASE(0x1ABF930);
            const uintptr_t StoringAvatarModelShouldOnlyHappen=REBASE(0x1ABBB70);
            const uintptr_t StoringAvatarPreviewShouldOnlyHappen=REBASE(0x1ABB710);
            const uintptr_t TakeAvatarGenerationPhotoOnClientFailed=REBASE(0x1ACDD80);
            const uintptr_t TakeAvatarGenerationPhotoOnClientImageNu=REBASE(0x1ACD6C0);
            const uintptr_t UnexpectedErrorFailedCreateHairAccessory=REBASE(0x1AB3300);
            const uintptr_t UnexpectedErrorMissingHair=REBASE(0x1AB0A40);
            const uintptr_t UnexpectedErrorMissingMeshpart=REBASE(0x1AAD5F0);
            const uintptr_t UnexpectedErrorMissingMeshpartHead=REBASE(0x1AB0780);
            const uintptr_t UnexpectedErrorShouldCalledClient=REBASE(0x1AC8490);
            const uintptr_t UnexpectedPartNull=REBASE(0x1AB12F0);
        }
        namespace Physics
        {
            const uintptr_t FailedApplyDeltaConvexDecompHolder=REBASE(0xD3D780);
            const uintptr_t FailedGenerateClosedVoxelFallingBackVoxe=REBASE(0x60C5FC0);
            const uintptr_t RemoveBulletDispatcher=REBASE(0x1488850);
            const uintptr_t SetBulletDispatcher=REBASE(0x1487470);
        }
        namespace PhysicsMeshCompression
        {
            const uintptr_t PhysicsMeshDecoderFailedParseOldMeshData=REBASE(0x2ADDB90);
        }
        namespace PhysicsNetwork
        {
            const uintptr_t IgnoreNullRootPartFilteredGrounded=REBASE(0x4669C90);
        }
        namespace PinShortcutCore
        {
            const uintptr_t PinExperienceAvailableCurrentPlatform=REBASE(0x5158170);
            const uintptr_t RevealPinnedExperienceAvailableCurrentPl=REBASE(0x5158050);
        }
        namespace PlaceAssetIdsService
        {
            const uintptr_t PublishBatchingEvents=REBASE(0x3B37B90);
            const uintptr_t PublishError=REBASE(0x3B389B0);
        }
        namespace PlayerCharacterLoadingLog
        {
            const uintptr_t PlayerCharacterLoadingLogAssetIdLldDidRe=REBASE(0x3E0D0F0);
            const uintptr_t PlayerCharacterLoadingLogBackEndProcessi=REBASE(0x3E16980);
            const uintptr_t PlayerCharacterLoadingLogUnableParseAvat=REBASE(0x3E22610);
            const uintptr_t R6CharacterAppearanceLoadingFailed=REBASE(0x3E286A0);
        }
        namespace PlayerData
        {
            const uintptr_t UnknownPlayerDataAPIType=REBASE(0x11002C0);
        }
        namespace PlayerDeviceTrust
        {
            const uintptr_t UserIdDisconnectedConnectionError=REBASE(0x3151280);
            const uintptr_t UserIdEvaluatePlayerDeviceTrustAfter0fMs=REBASE(0x314FEE0);
            const uintptr_t UserIdEvaluatePlayerDeviceTrustTimedOutA=REBASE(0x31505C0);
            const uintptr_t UserIdEvaluationDisabledStayingPending=REBASE(0x314F2D0);
            const uintptr_t UserIdRejectionMessageFilterTimedOut=REBASE(0x31510B0);
        }
        namespace PlayerFeedbackPromptLog
        {
            const uintptr_t PlayerFeedbackEligibilityGETError=REBASE(0x34CDC60);
            const uintptr_t PlayerFeedbackEligibilityGETUrlPlaceIdAs=REBASE(0x34CC470);
            const uintptr_t PlayerFeedbackFlightResumingImmediately=REBASE(0x34C9980);
            const uintptr_t PlayerFeedbackGamesV1RootPlaceIdParseFai=REBASE(0x61BCD50);
            const uintptr_t PlayerFeedbackGamesV1RootPlaceIdRequestF=REBASE(0x34CE540);
            const uintptr_t PlayerFeedbackJSONParseException=REBASE(0x61BCC30);
            const uintptr_t PlayerFeedbackPOSTFailure=REBASE(0x34D0360);
            const uintptr_t PlayerFeedbackPOSTSuccess=REBASE(0x34CFDF0);
            const uintptr_t PlayerFeedbackParseFailedDefaultingUnava=REBASE(0x34CC890);
            const uintptr_t PlayerFeedbackPermissionDenied=REBASE(0x34D3C50);
            const uintptr_t PlayerFeedbackPlayerSupportDescriptionTo=REBASE(0x34CE8B0);
            const uintptr_t PlayerFeedbackPlayerSupportEligibility2x=REBASE(0x34CAD50);
            const uintptr_t PlayerFeedbackPlayerSupportEligibilityGE=REBASE(0x34CB930);
            const uintptr_t PlayerFeedbackStartingPOSTSubmissionFeed=REBASE(0x34CEF50);
            const uintptr_t PlayerFeedbackWatchdogTimeoutResuming=REBASE(0x34D868F);
        }
        namespace PlayerGui
        {
            const uintptr_t OnServiceProviderScreenOrientation=REBASE(0x3F61E40);
        }
        namespace PlayerHydrationService
        {
            const uintptr_t AttemptingHydratePlayerCachedAttributes=REBASE(0x3DAA530);
            const uintptr_t AttemptingHydratePlayerReplicatedCachedA=REBASE(0x3B3BF90);
            const uintptr_t HydratingPlayerFailed=REBASE(0x3B3BBB0);
            const uintptr_t HydratingPlayerPulledAttributes=REBASE(0x3B3DEF0);
            const uintptr_t HydratingPlayerReceivedAttributes=REBASE(0x3B3CDE0);
            const uintptr_t PlayerAttributesFoundAppStorageAre=REBASE(0x3B3A7F0);
        }
        namespace PlayerLocaleIdVerbose
        {
            const uintptr_t SuccessfullySetEventIdUserJoinData=REBASE(0x3DDF250);
            const uintptr_t UpdatedPlayerSChatLocaleId=REBASE(0x3DE48A0);
            const uintptr_t UpdatedPlayerSLocaleId=REBASE(0x3DE4530);
        }
        namespace PlayerViewServiceTrace
        {
            const uintptr_t OnCameraCFrameReplicationRequest=REBASE(0x3DF4890);
            const uintptr_t SubscribeToTrackerData=REBASE(0x3DF4930);
            const uintptr_t UnsubscribeFromTrackerData=REBASE(0x3DF2580);
        }
        namespace PolicyService
        {
            const uintptr_t VTRiskAssessmentError=REBASE(0x139E6E0);
        }
        namespace PopLatencyService
        {
            const uintptr_t EnablePopLatencyProbeWentFalseMidSession=REBASE(0x142E080);
            const uintptr_t IPv6ProbeSeededDebugVIPS=REBASE(0x142D2F0);
            const uintptr_t RejectedMalformedForcedPoPCodeBytes=REBASE(0x142F0F0);
            const uintptr_t WarmUpOnlyProbeCompletePublished=REBASE(0x142E4F0);
        }
        namespace PostUploader
        {
            const uintptr_t CompletePostFailedStatus=REBASE(0x40BD740);
            const uintptr_t CreatePostFailedStatusErr=REBASE(0x40BA260);
            const uintptr_t S3PUTFailedStatusErr=REBASE(0x40BB1B0);
            const uintptr_t SkippingTextToSpeechEntryMissingInvalidV=REBASE(0x40B7540);
        }
        namespace PowerTraceModule
        {
            const uintptr_t CheckingIsUserEnrolledForCurrentInterval=REBASE(0x511BF40);
            const uintptr_t PerformedHashingUserHashUserIdEnrolled=REBASE(0x511BA00);
            const uintptr_t TimeWindow1SecondUsedPowerTraceModule=REBASE(0x511B740);
        }
        namespace PrefetchProtocol
        {
            const uintptr_t ConcatString=REBASE(0x3C60B90);
            const uintptr_t ErrorKeyFoundDeviceInfoPayload=REBASE(0x5C80AA0);
            const uintptr_t ErrorUnusedResponseFoundAfter120s=REBASE(0x3C61F70);
            const uintptr_t OmniRecommendationsServiceClearSessionId=REBASE(0x5C83320);
            const uintptr_t OmniRecommendationsServiceGetSessionId=REBASE(0x5C83170);
            const uintptr_t OmniRecommendationsServiceMakeRequest=REBASE(0x5C82CE0);
            const uintptr_t PrefetchBlockedHasBeenHandledBefore=REBASE(0x3C5FED0);
            const uintptr_t PrefetchProtocolBankExpiredLongerAcceptN=REBASE(0x3C60610);
            const uintptr_t PrefetchProtocolCoreMakePrefetchSyntheti=REBASE(0x5C800D0);
            const uintptr_t PrefetchProtocolCoreMakePrefetchWaitingN=REBASE(0x5C7F190);
            const uintptr_t ResponseReceivedTriggerCallback=REBASE(0x3C5F8D0);
            const uintptr_t SDUICapabilityDescriptorValidJSONUsing=REBASE(0x5C84340);
            const uintptr_t SDUICollectionLayoutDescriptorValidJSON=REBASE(0x5C85A20);
        }
        namespace PreloadLinkedScriptsTiming
        {
            const uintptr_t DonePreloadingLinkedScriptsId=REBASE(0x4203B70);
        }
        namespace Preloaded
        {
            const uintptr_t ExceptionDuringPreloadLoading=REBASE(0x60DBB30);
            const uintptr_t LoadFromBufferSkippedServerWillReplicate=REBASE(0xEAEAF0);
        }
        namespace PreloadedCacheManager
        {
            const uintptr_t DebugPreloadLocalRbxmPathReadFailedPlace=REBASE(0xEACD60);
            const uintptr_t PreloadFetchFailedPlaceId=REBASE(0xEAD740);
        }
        namespace PreloadedCacheVerifier
        {
            const uintptr_t PreloadVerificationKeyFoundKeyRing=REBASE(0xEA8A40);
        }
        namespace PresetChatManager
        {
            const uintptr_t ExpressionTrayOptionsRequestFailedStatus=REBASE(0x4A9AA70);
            const uintptr_t FailedParseExpressionTrayOptionsResponse=REBASE(0x4A99030);
            const uintptr_t FailedParsePresetOptionsResponse=REBASE(0x4A95CD0);
            const uintptr_t MalformedPresetConfigResponseBody=REBASE(0x4A94590);
            const uintptr_t PresetChatInfoEligibilityCriteriaBlocked=REBASE(0x4A9CBD0);
            const uintptr_t PresetChatManagerFetchErrorStatus=REBASE(0x4A93F60);
            const uintptr_t SkippingExpressionTrayPresetWithoutPrese=REBASE(0x4A98A50);
        }
        namespace PrimalObjective
        {
            const uintptr_t EquilibriumSolveIslandStageDualDual=REBASE(0x4E703E0);
            const uintptr_t PlainAlSolveIslandStageDual=REBASE(0x4E6FAF0);
        }
        namespace PrimitiveLifetime
        {
            const uintptr_t OwnerSetPrimitive=REBASE(0xDCA6B0);
            const uintptr_t PrimitiveCreated=REBASE(0x14FD890);
            const uintptr_t PrimitiveDestroyed=REBASE(0x14FDB60);
        }
        namespace PrimitiveMidPhaseExtentsMap
        {
            const uintptr_t AssemblyPrimitiveTraversalVisitedPrimiti=REBASE(0x1577FC0);
            const uintptr_t BVHPrimitiveWasAbsentAssemblyTraversal=REBASE(0x1577D00);
        }
        namespace ProfileTelemetry
        {
            const uintptr_t FailedSendPerfDataEventIngest=REBASE(0x2A400F0);
            const uintptr_t FailedSendPerfDataPoints=REBASE(0x2A40260);
            const uintptr_t SendingPerfDataEventIngestViaRobloxTelem=REBASE(0x2A376A0);
            const uintptr_t SkippingPerfDataStatsReportDueMissing=REBASE(0x2A38E10);
        }
        namespace PropertySet
        {
            const uintptr_t FailedGetHeader=REBASE(0x61DDC20);
        }
        namespace R15Character
        {
            const uintptr_t DataModelRequestUniverseConfigurationSet=REBASE(0x3C3D610);
            const uintptr_t DataModelRequestUniverseConfigurationUni=REBASE(0x40F8120);
            const uintptr_t DataModelSetUniverseIdLld=REBASE(0x40F8630);
            const uintptr_t DataModelUniverseConfigurationLoadedErro=REBASE(0x40F7D90);
            const uintptr_t DataModelUniverseConfigurationLoadedSucc=REBASE(0x40F78A0);
        }
        namespace RTAnimationTrackerTrace
        {
            const uintptr_t AddingConsumer=REBASE(0x16F0C30);
            const uintptr_t AncestorChanged=REBASE(0x16F11A0);
            const uintptr_t Connect=REBASE(0x16F07B0);
            const uintptr_t CreatingInputProcessorFailedStreamType=REBASE(0x16F1490);
            const uintptr_t Disconnect=REBASE(0x16F09D0);
            const uintptr_t FailedCreateTrackerEngineUnsupportedTrac=REBASE(0x16F3160);
            const uintptr_t HandlingActiveChanged=REBASE(0x16EFD10);
            const uintptr_t HandlingEnableFallbackAudioInputChanged=REBASE(0x16EFE00);
            const uintptr_t HandlingTrackerTypeChanged=REBASE(0x16EFFC0);
            const uintptr_t NotifyingTrackerError=REBASE(0x16F1D40);
            const uintptr_t NotifyingTrackerModeChanged=REBASE(0x16F2310);
            const uintptr_t NotifyingTrackerPrompt=REBASE(0x16F2880);
            const uintptr_t RTAnimationTrackerConstructed=REBASE(0x16EF840);
            const uintptr_t RemovingConsumer=REBASE(0x16F0EC0);
            const uintptr_t RunServiceAvailableConnecting=REBASE(0x16F2DC0);
            const uintptr_t ShuttingDown=REBASE(0x16F05E0);
            const uintptr_t StartingTracking=REBASE(0x16F0152);
            const uintptr_t StoppingTracking=REBASE(0x16F03E0);
            const uintptr_t UpdatingInputConnectionStreamType=REBASE(0x16F2A60);
        }
        namespace RVideoBufferPool
        {
            const uintptr_t ResizeZu=REBASE(0x1E192A0);
        }
        namespace RVideoTrace
        {
            const uintptr_t CurrentSegmentIndexBehindMediaSequence=REBASE(0x1E0CCE0);
            const uintptr_t FormatSupportedHLSMediaSegment=REBASE(0x1E0C8F0);
            const uintptr_t I420Buffer=REBASE(0x1E6E250);
            const uintptr_t MediaFoundationCodecReceiveFrameSetSampl=REBASE(0x1E5B960);
            const uintptr_t MediaFoundationCodecSendFrameInternalSet=REBASE(0x1E5D760);
            const uintptr_t MediaFoundationCodecSendPacketSetSampleT=REBASE(0x1E5A390);
            const uintptr_t MockInputFormatReadPacket=REBASE(0x1E36A60);
            const uintptr_t MockInputFormatSeek=REBASE(0x1E36BB0);
            const uintptr_t Mp4InputFormatCreate=REBASE(0x1E248F0);
            const uintptr_t MpegTsInputFormatFailedFindPATPMTPAT=REBASE(0x1E224F0);
            const uintptr_t MpegTsInputFormatFindStreamInfo=REBASE(0x1E21F90);
            const uintptr_t MpegTsInputFormatOpenedSuccessfullyVideo=REBASE(0x1E21730);
            const uintptr_t MpegTsInputFormatParsedSPSPPSXExtradata=REBASE(0x1E23560);
            const uintptr_t MpegTsInputFormatSeek=REBASE(0x1E22300);
            const uintptr_t NeedsSetMockInputFormat=REBASE(0x1E35D10);
            const uintptr_t OpeningVPXEncoderWidthHeightBitrate=REBASE(0x1E43490);
            const uintptr_t OpusSoftwareCodecClose=REBASE(0x1E48740);
            const uintptr_t OpusSoftwareCodecOpenInternal=REBASE(0x1E48290);
            const uintptr_t OpusSoftwareCodecReceiveFrameInternalPts=REBASE(0x1E48AF0);
            const uintptr_t OpusSoftwareCodecReceivePacketInternalPt=REBASE(0x1E494A0);
            const uintptr_t OpusSoftwareCodecSendFrameInternalPtsLld=REBASE(0x1E49300);
            const uintptr_t OpusSoftwareCodecSendPacketInternalPts=REBASE(0x1E48900);
            const uintptr_t RvDebugMemoryNumAllocations=REBASE(0x1E0A8E0);
            const uintptr_t RvFlvFormatWritePacketPtsF=REBASE(0x1E39FE0);
            const uintptr_t RvSchedulerServiceConnectScoped=REBASE(0x5335970);
            const uintptr_t RvSchedulerServiceRunAsyncThread=REBASE(0x53351C0);
            const uintptr_t RvSchedulerServiceSchedule=REBASE(0x53358B0);
            const uintptr_t RvSubsystemRvDeviceSystem=REBASE(0x37B6D30);
            const uintptr_t SizeCmcdVisibilityHeaderTooLarge=REBASE(0x1E08630);
            const uintptr_t StreamChangeSegment=REBASE(0x1E0BDC0);
            const uintptr_t VorbisSoftwareCodecClose=REBASE(0x1E4AFB0);
            const uintptr_t VorbisSoftwareCodecOpenInternal=REBASE(0x1E4AB50);
            const uintptr_t VorbisSoftwareCodecReceiveFrameInternal=REBASE(0x1E4B3F0);
            const uintptr_t VorbisSoftwareCodecReceivePacketInternal=REBASE(0x1E4BB20);
            const uintptr_t VorbisSoftwareCodecSendFrameInternalPts=REBASE(0x1E4B8A0);
            const uintptr_t VorbisSoftwareCodecSendPacketInternalPts=REBASE(0x1E4B170);
            const uintptr_t VpxCodecEncConfigSetFailed=REBASE(0x1E443AA);
            const uintptr_t VpxSoftwareCodecClose=REBASE(0x1E44210);
            const uintptr_t VpxSoftwareCodecFlush=REBASE(0x1E47730);
            const uintptr_t VpxSoftwareCodecGetVpxImageSupportNonCon=REBASE(0x1E45C10);
            const uintptr_t VpxSoftwareCodecOpenInternal=REBASE(0x1E43120);
            const uintptr_t VpxSoftwareCodecReceiveFrameInternalPts=REBASE(0x1E44DE0);
            const uintptr_t VpxSoftwareCodecReceivePacketInternalPts=REBASE(0x1E474F0);
            const uintptr_t VpxSoftwareCodecSendFrameInternalPts=REBASE(0x1E45EE0);
            const uintptr_t VpxSoftwareCodecSendPacketInternalPts=REBASE(0x1E444F0);
            const uintptr_t WebmInputFormatOpen=REBASE(0x1E1E140);
            const uintptr_t WebmInputFormatSeek=REBASE(0x1E1F590);
        }
        namespace RVideoWarning
        {
            const uintptr_t UnknownTag=REBASE(0x1DF4D40);
        }
        namespace RaknetJoinOrDisconnectRequest
        {
            const uintptr_t RakNetReceivingPacket=REBASE(0x2815BEA);
        }
        namespace RbxFiberSpanProcessor
        {
            const uintptr_t SpanQueueFullDroppingSpan=REBASE(0x4EC8D00);
        }
        namespace RbxOtlpHttpExporter
        {
            const uintptr_t ExceptionDuringOTLPExport=REBASE(0x6257AB0);
            const uintptr_t OTLPExportConcurrencyCapDroppingBatch=REBASE(0x4EC9A30);
        }
        namespace RbxStorage
        {
            const uintptr_t ClientStorageInterfaceGetRejectedStorage=REBASE(0x4462CA0);
            const uintptr_t ClientStorageInterfaceRemoveRejectedKeyL=REBASE(0x4463060);
            const uintptr_t ClientStorageInterfaceRemoveRejectedStor=REBASE(0x44631FE);
            const uintptr_t ClientStorageInterfaceSetRejectedValueSi=REBASE(0x44628A0);
            const uintptr_t ErrorParsingFileNamePidPath=REBASE(0x616F560);
            const uintptr_t FailedGetAppDataDirectory=REBASE(0x616F2D0);
            const uintptr_t FailedGetAvailableDiskSpacePath=REBASE(0x26D4130);
            const uintptr_t FailedGetCacheDirectory=REBASE(0x616F3E0);
            const uintptr_t FailedGetFileSizePath=REBASE(0x26D3E60);
            const uintptr_t FailedGetOldCacheDirectory=REBASE(0x616F1C0);
            const uintptr_t FailedInitializeCacheDatabaseRemovingDat=REBASE(0x26B5860);
            const uintptr_t FailedWriteIdFile=REBASE(0x26BEA80);
            const uintptr_t FileCacheCleanupCAPACITYBytes=REBASE(0x26EA0D0);
            const uintptr_t FileCacheClearERRORFailedCreateSubdirect=REBASE(0x26DFB20);
            const uintptr_t FileCacheClearPATH=REBASE(0x26E9850);
            const uintptr_t FileCacheCreateFileDirectoriesERRORFaile=REBASE(0x26E17C0);
            const uintptr_t FileCacheFileCacheNAMEPATHTEMPPERM=REBASE(0x26E1060);
            const uintptr_t FileCacheFileCacheNamePath=REBASE(0x26E15D0);
            const uintptr_t FileCacheGetERRORFailedAllocateString=REBASE(0x26E37A0);
            const uintptr_t FileCacheGetPATHBUFFER=REBASE(0x26E3C60);
            const uintptr_t FileCacheGetPATHMMAP=REBASE(0x26E34E0);
            const uintptr_t FileCacheKeysERRORKeysStorageCategorySup=REBASE(0x26EC460);
            const uintptr_t FileCacheReloadStatsSKIPLastReloadWas=REBASE(0x26EC680);
            const uintptr_t FileCacheRemoveERRORFailedRemoveFile=REBASE(0x26E92C0);
            const uintptr_t FileCacheRenameFileFailedRenameFileFirst=REBASE(0x26E4460);
            const uintptr_t FileCacheSelfTestERRORTestValueMismatch=REBASE(0x26EA7E0);
            const uintptr_t FileCacheSetFromFileERRORFailedGetFile=REBASE(0x26E5090);
            const uintptr_t FileCacheSetKEYSIZE=REBASE(0x26E5890);
            const uintptr_t FileCacheSetKEYVECTORSIZE=REBASE(0x26E7480);
            const uintptr_t FinishedRemovingTempFilesSubdirectory02x=REBASE(0x26D4E80);
            const uintptr_t GetSubDirFileNamesERRORFailedRemoveInval=REBASE(0x26EB420);
            const uintptr_t GetSubDirSizeERRORFailedRemoveInvalidFil=REBASE(0x26E0400);
            const uintptr_t MemCacheCleanupFAILEDTotalSizeCapacity=REBASE(0x26EF050);
            const uintptr_t MemCacheGetInternalFoundInL1=REBASE(0x26ED7A0);
            const uintptr_t MemCacheMemCachePending=REBASE(0x26ED590);
            const uintptr_t MemCacheProcessPendingWritesPendingTotal=REBASE(0x26EFB30);
            const uintptr_t MemCacheRemove=REBASE(0x26EEAF0);
            const uintptr_t MemCacheSetERRORValueNull=REBASE(0x26EDB90);
            const uintptr_t MemCacheSetFromFileERRORFailedReadFile=REBASE(0x26EE130);
            const uintptr_t MockStorageInterfaceSetFromFileFailedRem=REBASE(0x26D6C90);
            const uintptr_t NullCacheSetFromFileFailedRemoveFileErro=REBASE(0x26D32D0);
            const uintptr_t OldCacheDirectoryPathDoesExist=REBASE(0x26D53C0);
            const uintptr_t RbxStorageCleanupOnceSTARTCurrentSizeAva=REBASE(0x26BBCE0);
            const uintptr_t RbxStorageCleanupThreadFuncAvailableSpac=REBASE(0x26BB180);
            const uintptr_t RbxStorageCleanupThreadStdStopped=REBASE(0x26BB9B0);
            const uintptr_t RbxStorageCleanupThreadStopped=REBASE(0x26C153E);
            const uintptr_t RbxStorageDestroyedFlagDestructorCalledS=REBASE(0x6399600);
            const uintptr_t RbxStorageFillCacheDONEItemsElapsed3f=REBASE(0x26BEF90);
            const uintptr_t RbxStorageGetStorageInterfaceRemovingAll=REBASE(0x26B3870);
            const uintptr_t RbxStorageInitDONENameDuration3f=REBASE(0x26B6000);
            const uintptr_t RbxStorageInitFailedInitializeFileCache=REBASE(0x26B5350);
            const uintptr_t RbxStorageInitINITUserAvailableDiskSpace=REBASE(0x26B7E20);
            const uintptr_t RbxStorageRbxStorageDroppingCacheDueToo=REBASE(0x26B4870);
            const uintptr_t RbxStorageRollingTelemetryTRIGGERED=REBASE(0x26BD200);
            const uintptr_t RemoveOldCacheCacheDirectoryPathTooShort=REBASE(0x26D3740);
            const uintptr_t RemoveTempFilesERRORDirectory=REBASE(0x26DF130);
            const uintptr_t RemovingLargeWalFileDbSize=REBASE(0x26BA730);
            const uintptr_t SafeIntToStorageCategoryInvalidCategory=REBASE(0x2E778C0);
            const uintptr_t SqliteCacheCleanupBadPolicy=REBASE(0x26CD650);
            const uintptr_t SqliteCacheCleanupPolicyPriorityScalarAT=REBASE(0x26CD7D0);
            const uintptr_t SqliteCacheContainsFailedPrepareStatemen=REBASE(0x26C9200);
            const uintptr_t SqliteCacheEvictKeyKeySizeExternalHits=REBASE(0x26CA7F0);
            const uintptr_t SqliteCacheGetRollingStatsFailedPrepareS=REBASE(0x26CE390);
            const uintptr_t SqliteCacheGetSizeMismatchBetweenDb=REBASE(0x26C6D30);
            const uintptr_t SqliteCacheIncrementOpenCountFailedIncre=REBASE(0x26CCD40);
            const uintptr_t SqliteCacheKeysExternalFailedCreateIndex=REBASE(0x26CF930);
            const uintptr_t SqliteCacheProcessHitListSizeGreaterThan=REBASE(0x26D0D00);
            const uintptr_t SqliteCacheRemoveExternalKeysElapsed3f=REBASE(0x26C9EB0);
            const uintptr_t SqliteCacheRemoveFailedDeleteKey=REBASE(0x26C9A60);
            const uintptr_t SqliteCacheSelfTestFailedSmallValue=REBASE(0x26CBB60);
            const uintptr_t SqliteCacheSelfTestValueMismatchExpected=REBASE(0x26CC640);
            const uintptr_t SqliteCacheSetFailedInsertMetadataInto=REBASE(0x26C8810);
            const uintptr_t SqliteCacheSetFailedPrepareStatement=REBASE(0x26C8C90);
            const uintptr_t SqliteCacheSetFromFileFailedInsertMetada=REBASE(0x26C7F50);
            const uintptr_t SqliteCacheSqliteCacheCreateTableFailedB=REBASE(0x26C5770);
            const uintptr_t SqliteCacheSqliteCacheMedianSizeNumAsset=REBASE(0x26C6830);
            const uintptr_t StorageInterfaceRemoveCategoryCountDurat=REBASE(0x26D2900);
            const uintptr_t TelemetryCacheCreatedWithoutStatsReporte=REBASE(0x26C1A40);
            const uintptr_t TelemetryCacheGetBufferInternalArtificia=REBASE(0x26C28E0);
            const uintptr_t TelemetryCacheGetBufferInternalOffsetArt=REBASE(0x26C2D60);
            const uintptr_t TelemetryCacheGetInternalArtificiallySlo=REBASE(0x26C1F30);
            const uintptr_t TelemetryCacheGetInternalOffsetArtificia=REBASE(0x26C23D0);
            const uintptr_t UtilsCleanUpSessionScopedDataSafeSkipOrp=REBASE(0x26D6040);
        }
        namespace RbxTelemetryBatch
        {
            const uintptr_t ReportingBatchReports=REBASE(0x2EB45E0);
        }
        namespace RbxTransportChannelTracker
        {
            const uintptr_t DiscardingExpiredFragmentDatagramChannel=REBASE(0x21A5970);
            const uintptr_t FragmentIDAlreadyExistsPossibleDuplicate=REBASE(0x21A6AF0);
            const uintptr_t ReceivedACKUnknownFragmentId=REBASE(0x21A7060);
            const uintptr_t UnreliableFragmentsSizeExceedClaimedData=REBASE(0x21D4FC0);
            const uintptr_t UnreliableReassemblyBudgetExceededBytesD=REBASE(0x21A5878);
        }
        namespace RbxTransportClientLog
        {
            const uintptr_t FailedStartBaseClientConfiguration=REBASE(0x5CFB570);
            const uintptr_t MessageQueuedChannelYetOpenQueueSize=REBASE(0x5CFB950);
            const uintptr_t RbxTransportClientACKReceiveChannelOpene=REBASE(0x5CFD190);
            const uintptr_t RbxTransportClientDisconnectedServerReas=REBASE(0x5CFE1D0);
            const uintptr_t RbxTransportClientFailedEstablishConnect=REBASE(0x5CFD9D0);
            const uintptr_t RbxTransportClientMessageSent=REBASE(0x5CFBB20);
        }
        namespace RbxTransportControlNetStreams
        {
            const uintptr_t InvalidOpenUnreliableChannelControlWireI=REBASE(0x22299F0);
        }
        namespace RbxTransportDummyClient
        {
            const uintptr_t ConnectionAttemptTimedOutAfterMs=REBASE(0x4933B30);
            const uintptr_t DisconnectedServerReason=REBASE(0x4935D70);
            const uintptr_t FailedEstablishConnectionServerReason=REBASE(0x4933E90);
            const uintptr_t FailedSendTimeSyncRequest=REBASE(0x49381F0);
            const uintptr_t PerformanceTestDisabledBuildConfiguratio=REBASE(0x4937290);
            const uintptr_t PingThreadExiting=REBASE(0x4936DB0);
            const uintptr_t StartedPingThreadIntervalMsPayload=REBASE(0x49367C0);
            const uintptr_t StoppedPingThread=REBASE(0x4937110);
            const uintptr_t StoppedTimeSyncThread=REBASE(0x4937FF0);
            const uintptr_t UpdateMonotonicClockDifferentialFunction=REBASE(0x4937840);
        }
        namespace RbxTransportDummyServer
        {
            const uintptr_t ServerStoppedReason=REBASE(0x4939890);
        }
        namespace RbxTransportIntegration
        {
            const uintptr_t AssigningCapabilitiesReplicator=REBASE(0x481B280);
            const uintptr_t SendEarlyAuthDataFailedBecauseEarlyAuthD=REBASE(0x4800220);
        }
        namespace RbxTransportIoLibContext
        {
            const uintptr_t RbxTransportIOBackendChosen=REBASE(0x21726E0);
        }
        namespace RbxTransportNgtcp2
        {
            const uintptr_t ConnSeqNgtcp2=REBASE(0x21A9970);
        }
        namespace RbxTransportQuicConnection
        {
            const uintptr_t ConnSeqCALLBACKAckDatagramCbDatagramId=REBASE(0x21B6620);
            const uintptr_t ConnSeqCALLBACKAckedStreamDataOffsetCbSt=REBASE(0x21B47C0);
            const uintptr_t ConnSeqCALLBACKExtendMaxLocalStreamsBidi=REBASE(0x21B6A90);
            const uintptr_t ConnSeqCALLBACKExtendMaxLocalStreamsUniC=REBASE(0x21B6BA0);
            const uintptr_t ConnSeqCALLBACKGetNewConnectionIdCbNewCo=REBASE(0x21B4350);
            const uintptr_t ConnSeqCALLBACKHandshakeCompletedCb=REBASE(0x21B6120);
            const uintptr_t ConnSeqCALLBACKHandshakeConfirmedCb=REBASE(0x21B6290);
            const uintptr_t ConnSeqCALLBACKLostDatagramCbDatagramId=REBASE(0x21B6770);
            const uintptr_t ConnSeqCALLBACKRecvDatagramCbDatalen=REBASE(0x21B63E0);
            const uintptr_t ConnSeqCALLBACKRecvRxKeyCbLevel=REBASE(0x21B5C00);
            const uintptr_t ConnSeqCALLBACKRecvStreamDataCbUnknownSt=REBASE(0x21B3CC0);
            const uintptr_t ConnSeqCALLBACKRemoteStreamOpenCbStreamI=REBASE(0x21B4A10);
            const uintptr_t ConnSeqCALLBACKRemoveConnectionIdCbCid=REBASE(0x21B4650);
            const uintptr_t ConnSeqCALLBACKStatelessResetCb=REBASE(0x21B68D0);
            const uintptr_t ConnSeqCALLBACKStreamCloseCbStreamId=REBASE(0x21B4E70);
            const uintptr_t ConnSeqCALLBACKStreamResetCbStreamIdFina=REBASE(0x21B56AA);
            const uintptr_t ConnSeqCALLBACKTlsEarlyDataRejectedCb=REBASE(0x21B6EB0);
            const uintptr_t ConnSeqCALLBACKVersionNegotiationCb=REBASE(0x21B6D80);
            const uintptr_t ConnSeqCouldSetSendBufferSize=REBASE(0x21B79F0);
            const uintptr_t ConnSeqERRCRYPTOTlsAlertTls=REBASE(0x21AED80);
            const uintptr_t ConnSeqOnConnectionTimerHandshakeTimeout=REBASE(0x21B16B0);
            const uintptr_t ConnSeqProcessPendingTxTransientErrorAwa=REBASE(0x21B8D80);
            const uintptr_t ConnSeqQuicClientConnectionInitializeLoc=REBASE(0x21B9250);
            const uintptr_t ConnSeqQuicServerConnectionCloseRemoteAd=REBASE(0x21BA790);
            const uintptr_t ConnSeqQuicServerConnectionReplacedIniti=REBASE(0x21BC9B0);
            const uintptr_t ConnSeqQuicServerConnectionSrcConnIdOrig=REBASE(0x21BA090);
            const uintptr_t ConnSeqRejectingQUICConnectionInitialTLS=REBASE(0x21BACE0);
            const uintptr_t ConnSeqRetrySendIfNeededScheduleSendFail=REBASE(0x21AFC50);
            const uintptr_t ConnSeqSendCurrentPacketWithRetrySchedul=REBASE(0x21B1190);
            const uintptr_t ConnSeqStartReadingStreamStreamId=REBASE(0x21C7B40);
            const uintptr_t ConnSeqStopReadingStreamStreamId=REBASE(0x21AD400);
            const uintptr_t ConnSeqUpdateConnectionTimerDelayUsRound=REBASE(0x21B14A8);
            const uintptr_t FailedSendCurrentPacketBeforeSending=REBASE(0x21ABBF0);
            const uintptr_t SendPendingDataDroppingOversizedDatagram=REBASE(0x21B28A0);
        }
        namespace RbxTransportQuicPacker
        {
            const uintptr_t CouldParseTxPrefixDestination=REBASE(0x21D73B0);
            const uintptr_t Ngtcp2ConnWriteConnectionCloseReported=REBASE(0x21D70E0);
            const uintptr_t Ngtcp2ConnWritevDatagramDgIdTotalDataSiz=REBASE(0x21D6DD0);
            const uintptr_t RewrittenTxPrefixHasWrongSize=REBASE(0x21D7A80);
        }
        namespace RbxTransportQuicPacketSender
        {
            const uintptr_t PacketSendSchedulerTrySendTxQueueFull=REBASE(0x21CB940);
            const uintptr_t UDPDatagramTXQueueFlushSent=REBASE(0x21CBF20);
        }
        namespace RbxTransportQuicServerSocket
        {
            const uintptr_t CouldSetDFBitServerSocket=REBASE(0x21BE520);
            const uintptr_t QuicServerSocketBindAddr=REBASE(0x21BE300);
            const uintptr_t QuicServerSocketOnHandshakeDoneHandshake=REBASE(0x21C0F10);
            const uintptr_t QuicServerSocketProcessUdpPacketInitialP=REBASE(0x21BF7B0);
            const uintptr_t QuicServerSocketSendRetryPacketClientAdd=REBASE(0x21C06C0);
            const uintptr_t QuicServerSocketStartAccepting=REBASE(0x21BEB20);
            const uintptr_t QuicServerSocketTokenRetrySendingRetry=REBASE(0x21BF030);
            const uintptr_t QuicUdpChannelOnRecvRecvErrorRestarting=REBASE(0x21CAC50);
        }
        namespace RbxTransportRnaExp
        {
            const uintptr_t CreatingConnection=REBASE(0x20EB1B0);
            const uintptr_t InitializedRtcIoRnaEventLoopThreads=REBASE(0x20EA7E0);
            const uintptr_t RefusingCreateConnectionReservedApplicat=REBASE(0x20EAD60);
            const uintptr_t RefusingCreateListenerReservedApplicatio=REBASE(0x20EAEC0);
            const uintptr_t SharedConnectionRegistryTeardownComplete=REBASE(0x20EDB10);
        }
        namespace RbxTransportRnaExpConnection
        {
            const uintptr_t AbortFromEventLoop=REBASE(0x20F7BC0);
            const uintptr_t ChannelInitializedYet=REBASE(0x20FDD20);
            const uintptr_t CloseCompletedReportingCompletion=REBASE(0x210F260);
            const uintptr_t CloseReceiveChannelChannelIdReason=REBASE(0x20FA8B0);
            const uintptr_t CloseSendChannelAppChannelIdReason=REBASE(0x20FA350);
            const uintptr_t ClosingAlreadyClosedConnection=REBASE(0x20FC160);
            const uintptr_t CompatControlReceivedOpenUnreliableChann=REBASE(0x20FB560);
            const uintptr_t ConnectionClosedWithoutAnyPathRecording=REBASE(0x20F5BA0);
            const uintptr_t ConnectionCompletedSuccessfully=REBASE(0x2106840);
            const uintptr_t ConnectionWasClosedAsynchronouslyReporti=REBASE(0x20FC4B0);
            const uintptr_t ErrorDelayedOpeningChannelApp=REBASE(0x21060F0);
            const uintptr_t ErrorOpeningChannelApp=REBASE(0x20F8AD0);
            const uintptr_t ErrorResolvingAddr=REBASE(0x2104BF0);
            const uintptr_t ExportKeyingMaterialReturnedNulloptLiveC=REBASE(0x2128870);
            const uintptr_t FailedInitializeRUPPWTConnectionInit=REBASE(0x2107D90);
            const uintptr_t FailedInitializeRuppConnectionInitReturn=REBASE(0x2107330);
            const uintptr_t FailedSendOpenUnreliableChannelControlMe=REBASE(0x2121610);
            const uintptr_t GetCapabilities=REBASE(0x20F8130);
            const uintptr_t GetChannelStats=REBASE(0x20F8350);
            const uintptr_t GetConnectionEvents=REBASE(0x211D200);
            const uintptr_t GetConnectionStats=REBASE(0x20F64B0);
            const uintptr_t OnDatagramReceivedReceiveBytesFailedWire=REBASE(0x21031E0);
            const uintptr_t OnRecvCompletionStreamIdChannelOpened=REBASE(0x2100700);
            const uintptr_t OnRecvCompletionStreamIdChannelRecvBytes=REBASE(0x2101A10);
            const uintptr_t OpeningSendChannelAppChannelIdReliabilit=REBASE(0x20F8610);
            const uintptr_t QUICConnectionClosedReason=REBASE(0x20FD4B0);
            const uintptr_t QUICStreamAcceptedResult=REBASE(0x20FCBD0);
            const uintptr_t QUICStreamAckedDataStreamIdOffset=REBASE(0x20FE1B0);
            const uintptr_t QUICStreamClosedStreamIdAppErrorCode=REBASE(0x20FD9E0);
            const uintptr_t ReceivePopChannelIdBytesReadBytesRemaini=REBASE(0x211E890);
            const uintptr_t ReceivePopMaxBytesChannelIdMaxBytesBytes=REBASE(0x211F140);
            const uintptr_t ReceivedTooLargeChannelIdValueStreamId=REBASE(0x2101CC0);
            const uintptr_t RefusingRequestOpenUnreliableChannelApp=REBASE(0x2122490);
            const uintptr_t RejectingSendChannelOpenFailedConnection=REBASE(0x21059E0);
            const uintptr_t ResumeStreamRecvChannelStillBackpressure=REBASE(0x21002B0);
            const uintptr_t RtcAppConnectionMissingReceiveQueueAppCh=REBASE(0x211FB20);
            const uintptr_t SendChannelIdSize=REBASE(0x20F93D0);
            const uintptr_t UnreliableDatagramDroppedRecvQueueFull=REBASE(0x2120E80);
            const uintptr_t UnreliableRecvChannelCreatedWireId=REBASE(0x20FABA0);
            const uintptr_t UnreliableSendChannelOpenedWireId=REBASE(0x21026C0);
            const uintptr_t WebTransportClientWasInitializedProperly=REBASE(0x21080B0);
            const uintptr_t WebTransportSessionCompleted=REBASE(0x2108730);
        }
        namespace RbxTransportRnaExpListener
        {
            const uintptr_t AcceptedNewConnectionClientHelloSNIALPN=REBASE(0x2135BE0);
            const uintptr_t AcceptedNewH3ConnectionALPN=REBASE(0x2137960);
            const uintptr_t BoundPortRangeAttempts=REBASE(0x2132740);
            const uintptr_t ClosingWTSessionMissingValidCapabilities=REBASE(0x2137C30);
            const uintptr_t ConnectionAcceptError=REBASE(0x21354A0);
            const uintptr_t ErrorStartingListenerShardPort=REBASE(0x2117140);
            const uintptr_t ListenerRegisteredAppIgnoringAppOpen=REBASE(0x21368C0);
            const uintptr_t OnAcceptedConnClosedPendingErasingPendin=REBASE(0x2136D30);
            const uintptr_t OnAcceptedConnCompatConnectedFiringNewCo=REBASE(0x2137030);
            const uintptr_t OnAcceptedConnectionPendingConnsClaimedC=REBASE(0x21364E0);
            const uintptr_t PortRangeSmallMayCauseBind=REBASE(0x2132B00);
            const uintptr_t PrepareDirectServerReturnRespondingSrcIP=REBASE(0x2137200);
            const uintptr_t ReadPktInfoSocketOptionSupportedCurrentP=REBASE(0x2135130);
            const uintptr_t RtcIoCertificateRotationInitializationFa=REBASE(0x2112DB0);
            const uintptr_t RtcIoCertificateRotationInitializedCertH=REBASE(0x213A3D0);
            const uintptr_t RtcIoCertificateRotationPendingCertHashe=REBASE(0x213B540);
            const uintptr_t RtcIoCertificateRotationPromotedCertHash=REBASE(0x213B8A0);
        }
        namespace RbxTransportRnaExpSlot
        {
            const uintptr_t RtcIoSharedConnectionSlotFailedInitializ=REBASE(0x2117E30);
        }
        namespace RbxTransportRnaPrefixProcessor
        {
            const uintptr_t PrepareTxUdpAttrsRespondingSrcIPPKTINFOD=REBASE(0x212D7F0);
            const uintptr_t RtcIoServerPrefixProcessorDroppedInitial=REBASE(0x212EC30);
        }
        namespace RbxTransportStunPopProbe
        {
            const uintptr_t BindFailedSkippingBurstRetryingNext=REBASE(0x4B04BF0);
            const uintptr_t BurstSentFailedFirstError=REBASE(0x4B067D0);
            const uintptr_t BurstSkippedTickMsPastIts=REBASE(0x4B058E0);
            const uintptr_t TURNSeedPoPsCarriedFresh=REBASE(0x4B04440);
            const uintptr_t WarmUpCompleteAfterBurstsParking=REBASE(0x4B05B31);
        }
        namespace RbxTransportTimepointTracker
        {
            const uintptr_t QUICHandshakeRetryEventButCLIENT=REBASE(0x22146A0);
            const uintptr_t QUICHandshakeTrackerDebugInfo=REBASE(0x2213050);
        }
        namespace RbxTransportTls
        {
            const uintptr_t CalledGetCipherNameBeforeSSLInitialized=REBASE(0x21D34C0);
            const uintptr_t CannotApplyCryptoIdentityNullSSL=REBASE(0x21D0D90);
            const uintptr_t FailedDerivePublicKeyPrivateKey=REBASE(0x21CE2B0);
            const uintptr_t InvalidPrivateKeySizeExpectedGot=REBASE(0x21CDED0);
            const uintptr_t InvalidPublicKeySizeExpectedGot=REBASE(0x21CE0C0);
            const uintptr_t LoadingServerCertificatePrivateKey=REBASE(0x21CFDF0);
            const uintptr_t LoadingTrustedCACertificate=REBASE(0x21CF5E0);
            const uintptr_t Ngtcp2CryptoOsslInitFailed=REBASE(0x21D25E0);
            const uintptr_t PublicKeyDoesMatchPrivateKey=REBASE(0x21D2E00);
            const uintptr_t RejectingClientHelloTLSServerCryptoIdent=REBASE(0x21D13F0);
            const uintptr_t SSLCTXDaneEnableFailed=REBASE(0x21CF810);
            const uintptr_t SSLCTXNewClient=REBASE(0x21CF4C0);
            const uintptr_t SSLCTXSet1ServerCertType=REBASE(0x21D0B20);
            const uintptr_t SSLCTXSetMinProtoVersion=REBASE(0x21CF200);
            const uintptr_t SSLSet1ClientCertTypeFailed=REBASE(0x21D29D0);
            const uintptr_t SSLSetAlpnProtosFailed=REBASE(0x21D3BE0);
            const uintptr_t ServerCertificatePEMOverrideDoesContain=REBASE(0x21D00F0);
            const uintptr_t ServerTLSSessionCustomExtensionCallback=REBASE(0x21CED20);
            const uintptr_t ServerTLSSessionCustomExtensionParse=REBASE(0x21CF043);
            const uintptr_t TLSCustomExtensionDataExceedsMaximum=REBASE(0x21CE800);
            const uintptr_t TLSCustomExtensionParseCallbackConfigure=REBASE(0x21CEBCC);
            const uintptr_t TLSServerMethod=REBASE(0x21CF940);
        }
        namespace RbxmFileManager
        {
            const uintptr_t ErrorDecompressedSizeDoesMatchChunk=REBASE(0x15ACC20);
            const uintptr_t ErrorFailedReadChunkHeaderBeforeReach=REBASE(0x15ACF00);
            const uintptr_t FailedCreateDirectoryDirectoryAlreadyExi=REBASE(0x15AFC10);
            const uintptr_t MemoryAllocationFailed=REBASE(0x6123980);
            const uintptr_t RBXMChecksumCacheFileChecksumHave=REBASE(0x15AB820);
            const uintptr_t RBXMFinishedWritingChecksumCachedChecksu=REBASE(0x15AE780);
            const uintptr_t ReadingCachedRBXMFile=REBASE(0x15AEB00);
            const uintptr_t RunTransformRbxmToCacheJobsStart=REBASE(0x15AF680);
            const uintptr_t StartSavingRBXMDecompressedChunksContent=REBASE(0x15AF070);
            const uintptr_t UnknownError=REBASE(0x6123AC0);
        }
        namespace RccRealtimeRelay
        {
            const uintptr_t BackendConnectionStateChangedConnected=REBASE(0x49741E0);
            const uintptr_t BackendMessageReceivedLength=REBASE(0x4975FE0);
            const uintptr_t ConnectToNamespaceConnectingNamespace=REBASE(0x4973940);
            const uintptr_t CouldParseDetailType=REBASE(0x623A4C0);
            const uintptr_t ParseMessageMessageFieldMissingFallingBa=REBASE(0x49743E0);
            const uintptr_t RccRealtimeRelayCreatedReadySignalConnec=REBASE(0x4975600);
            const uintptr_t RccRealtimeRelayDestroyed=REBASE(0x4975C30);
            const uintptr_t RccRealtimeRelayOnConnectionStateChanged=REBASE(0x4973550);
            const uintptr_t RccRealtimeRelayOnMessageParsedNamespace=REBASE(0x4972B80);
            const uintptr_t RccRealtimeRelayParseMessageException=REBASE(0x623A5D0);
            const uintptr_t RccRealtimeRelayParseMessageUnknownExcep=REBASE(0x623A6D0);
            const uintptr_t RccRealtimeRelaySetupBackendSubscription=REBASE(0x4973CE0);
        }
        namespace RccSoundLength
        {
            const uintptr_t SoundConstructGetSoundLengthUrlAssetIdEm=REBASE(0x454D2F0);
            const uintptr_t SoundServiceLoadSoundLengthForServerLeng=REBASE(0x454B5B0);
            const uintptr_t SoundServiceLoadSoundLengthForServerUnex=REBASE(0x454BB40);
            const uintptr_t SoundServiceParseSoundLengthResponseLeng=REBASE(0x454C8F0);
        }
        namespace RealtimeCoreNotification
        {
            const uintptr_t CannotSubscribeTopicBecauseRealtimeConne=REBASE(0x4970590);
            const uintptr_t DurableReplayUpdatingSequenceNumbersName=REBASE(0x49850B0);
            const uintptr_t FailedSubscribeTopic=REBASE(0x4970DA0);
            const uintptr_t FailedUnsubscribeTopic=REBASE(0x49718D0);
            const uintptr_t RealtimeNetworkHandlerReset=REBASE(0x49703D0);
            const uintptr_t RealtimeNotificationEventSizeHasUnsuppor=REBASE(0x496A810);
            const uintptr_t RealtimeSubscriptionStatusRecognized=REBASE(0x496EA20);
            const uintptr_t RealtimeTopicNotificationEventSizeHas=REBASE(0x496B270);
            const uintptr_t RealtimeTopicSubscriptionErrorHasUnexpec=REBASE(0x496BE00);
            const uintptr_t RealtimeTopicTokenExpiryHasUnexpectedSha=REBASE(0x496CC10);
            const uintptr_t SeqNumMapAfterSignalRNotificationNs=REBASE(0x4969F60);
            const uintptr_t TailLossPollingLiveNotificationOrder=REBASE(0x4985A80);
            const uintptr_t TailLossPollingPollTimerFired=REBASE(0x4986990);
            const uintptr_t TailLossPollingSchedulingNextPoll=REBASE(0x4986660);
            const uintptr_t TailLossPollingStartingBaseInterval=REBASE(0x497D3D0);
            const uintptr_t TailLossPollingStopping=REBASE(0x49861C0);
            const uintptr_t TailLossPollingTargetsAccumulatedDuring=REBASE(0x4986BD0);
            const uintptr_t TailLossRetryReEnqueuedNs=REBASE(0x4986390);
        }
        namespace RealtimeMedia
        {
            const uintptr_t AppHiddenSkipAudioPacket=REBASE(0x3C79920);
            const uintptr_t AppHiddenSkipVideoPacket=REBASE(0x3C78DF0);
            const uintptr_t ConnectAsyncFailedCreateRvInputFormatErr=REBASE(0x3C70770);
            const uintptr_t FailedSubmitWeakConnectionTask=REBASE(0x3C75DD0);
            const uintptr_t HandleSetUserSettingExceptionSettingProp=REBASE(0x61ED150);
            const uintptr_t HandleSetUserSettingRejectedValuePropert=REBASE(0x3C6C560);
            const uintptr_t OnAppHidePausingStreaming=REBASE(0x3C76950);
            const uintptr_t OnAppUnhideResumingStreaming=REBASE(0x3C76EC0);
            const uintptr_t RealtimeMediaDisconnectedReasonExpected=REBASE(0x3C737F0);
            const uintptr_t RealtimeMediaWeakConnectionStateTrueRtt=REBASE(0x3CFC634);
            const uintptr_t RenderFramePts=REBASE(0x3C686C0);
            const uintptr_t StratusEligibilityConnectEligiblePopLate=REBASE(0x3CF56F0);
            const uintptr_t StratusEligibilityConnectStratusSingleCa=REBASE(0x3CF8EB0);
            const uintptr_t StratusEligibilityUsingCachedPoPLatencyS=REBASE(0x3CF66A0);
        }
        namespace RealtimeMediaTelemetry
        {
            const uintptr_t FlowMilestoneFailureElapsedMs=REBASE(0x3CEC6C0);
            const uintptr_t PeriodicStatsThreadStartedIntervalS=REBASE(0x3CEC3B0);
            const uintptr_t SessionStatsDurationMsReasonVideo=REBASE(0x3CF1150);
            const uintptr_t SessionStopResultElapsedMs=REBASE(0x3CED310);
            const uintptr_t StratusSessionQualityRecordedRttMsJitter=REBASE(0x3CE9050);
            const uintptr_t VideoRTPPacketsRecvLostJitter=REBASE(0x3CEDA70);
        }
        namespace RealtimeProtocol
        {
            const uintptr_t AppResume=REBASE(0x519B180);
            const uintptr_t AppStop=REBASE(0x519B2A0);
            const uintptr_t CallEnded=REBASE(0x519EB50);
            const uintptr_t CallStarted=REBASE(0x519B590);
            const uintptr_t CallingActiveDroppingStaleVersion=REBASE(0x519B6B0);
            const uintptr_t DecidedStartRealtime=REBASE(0x519C050);
            const uintptr_t IncomingTopicMessage=REBASE(0x519C770);
            const uintptr_t UserLoggedIn=REBASE(0x519B420);
        }
        namespace RealtimeReliabilityMeasurement
        {
            const uintptr_t FailedTriggerRealtimeReliabilityMessage=REBASE(0x4988480);
            const uintptr_t IntialDelayRealtimeReliabilityMeasuremen=REBASE(0x49700E0);
            const uintptr_t TriggerNewRealtimeReliabilityMeasurement=REBASE(0x4988690);
        }
        namespace RecommendationSystem
        {
            const uintptr_t BatchRegistrationEndpointError=REBASE(0x4914C80);
            const uintptr_t FailedFetchRecommendationItems=REBASE(0x491B0B0);
            const uintptr_t FailedGetItem=REBASE(0x4915540);
            const uintptr_t FailedParseRegisterRecommendationItemRes=REBASE(0x490E140);
            const uintptr_t FailedRegisterRecommendationItemsFailedR=REBASE(0x49102D0);
            const uintptr_t FailedRemoveItem=REBASE(0x4915210);
            const uintptr_t FailedUpdateRecommendationItemsFailedRes=REBASE(0x4910C90);
            const uintptr_t GetRecommendationItemResponse=REBASE(0x49153C0);
            const uintptr_t RemoveRecommendationItemResponse=REBASE(0x4915070);
            const uintptr_t UpdateItemEndpointError=REBASE(0x4914EC0);
        }
        namespace ReconcileChatAccess
        {
            const uintptr_t AMPExperienceChatAvailabilityStatusChang=REBASE(0x2F9B900);
            const uintptr_t StartingPlayer=REBASE(0x2F9C210);
        }
        namespace ReduceMeshDebugLog
        {
            const uintptr_t StartingBluenoiseMeshSamplingSamples=REBASE(0x2E3E3D0);
            const uintptr_t StartingUniformMeshSamplingSamples=REBASE(0x2E3E0B0);
            const uintptr_t UniformMeshSamplingDone=REBASE(0x2E3E2F4);
        }
        namespace RegisterBacktraceReporterCallback
        {
            const uintptr_t RegisteringInferredCrashBacktraceReporte=REBASE(0x4D103D0);
        }
        namespace RenderAdvSkyGroup
        {
            const uintptr_t AdvSkyComputeProcessingComplete=REBASE(0x378D7C0);
            const uintptr_t AdvSkyCreated=REBASE(0x3787E40);
            const uintptr_t AdvSkyDestroyed=REBASE(0x37887A0);
            const uintptr_t AdvSkyKComputeWaitReadyUploadingVB=REBASE(0x378ADB0);
        }
        namespace RenderEnvMapPBR
        {
            const uintptr_t EnvMapPBRCancelTask=REBASE(0x3769A7B);
            const uintptr_t EnvMapPBRIndoor=REBASE(0x376BBC0);
            const uintptr_t EnvMapPBROutdoor=REBASE(0x376BC60);
            const uintptr_t EnvMapPBRSpecularFastConvDownsampleIndoo=REBASE(0x376BE60);
            const uintptr_t EnvMapPBRSpecularFastConvDownsampleOutdo=REBASE(0x376BF00);
            const uintptr_t EnvMapPBRSpecularFastConvDownsampleViewp=REBASE(0x376BFA0);
            const uintptr_t EnvMapPBRSpecularFastConvIndoorStep=REBASE(0x376C380);
            const uintptr_t EnvMapPBRSpecularFastConvOutdoorStep=REBASE(0x376C450);
            const uintptr_t EnvMapPBRSpecularFastConvViewportFrameEn=REBASE(0x376C520);
            const uintptr_t EnvMapPBRViewportFrame=REBASE(0x376D980);
        }
        namespace RenderFastCluster
        {
            const uintptr_t FastClusterBoundPartBindingConnections=REBASE(0x39AC720);
            const uintptr_t FastClusterCreateGridXXFlags=REBASE(0x3909460);
            const uintptr_t FastClusterInvalidateSkeletonInvalidDirt=REBASE(0x3912E60);
            const uintptr_t FastClusterPartBindingRequestsAdornmentC=REBASE(0x39ACF10);
            const uintptr_t FastClusterPartBindingRequestsCastShadow=REBASE(0x39ACDF0);
            const uintptr_t FastClusterPartBindingRequestsCoordinate=REBASE(0x39ACC20);
            const uintptr_t FastClusterPartBindingRequestsInvalidate=REBASE(0x39ACB90);
            const uintptr_t FastClusterPartBindingRequestsMeshChange=REBASE(0x39ACF80);
            const uintptr_t FastClusterPartBindingRequestsSizeChange=REBASE(0x39ACCD0);
            const uintptr_t FastClusterPartBindingRequestsSpecialSha=REBASE(0x39ACE80);
            const uintptr_t FastClusterPartBindingRequestsTransparen=REBASE(0x39ACD70);
            const uintptr_t FastClusterPartChangedClusterID=REBASE(0x390A310);
            const uintptr_t FastClusterPartChangedSpatialIndexX=REBASE(0x3909BC0);
            const uintptr_t FastClusterQueueEntityUpdateInvalidateTy=REBASE(0x390A130);
            const uintptr_t FastClusterSettingProceduralAvatarGroup=REBASE(0x390A9B0);
        }
        namespace RenderInstanceGlob
        {
            const uintptr_t InstanceGlobResizingHandleBuffer=REBASE(0x3792A80);
            const uintptr_t InstanceGlobResizingMain=REBASE(0x37933C0);
        }
        namespace RenderInstancedCluster2
        {
            const uintptr_t Binding0x=REBASE(0x381F0B0);
            const uintptr_t Binding0x0xDies=REBASE(0x381E8E0);
            const uintptr_t Binding0x0xSpawns=REBASE(0x381E230);
            const uintptr_t Binding0x0xTransfer0x0x=REBASE(0x381D1D0);
            const uintptr_t Binding0xCframe=REBASE(0x38279CA);
            const uintptr_t BindingDecal0xSpawns=REBASE(0x381E720);
            const uintptr_t Buffer0xReUploadedInstances=REBASE(0x3819A90);
            const uintptr_t Cluster0xEntity0xGotMesh=REBASE(0x3835850);
            const uintptr_t Cluster0xEvicted0x0x=REBASE(0x381EB20);
            const uintptr_t Cluster0xRebuiltEntityListEntries=REBASE(0x381D580);
            const uintptr_t Cluster0xRemove0x0x=REBASE(0x381AC3A);
            const uintptr_t Cluster0xSpawns=REBASE(0x381A080);
            const uintptr_t Cluster0xStillHasEntities=REBASE(0x381A390);
            const uintptr_t Entity0xAdded0x=REBASE(0x381FB10);
            const uintptr_t Entity0xKeyTypeContentid=REBASE(0x381F3F0);
            const uintptr_t Entity0xPurged=REBASE(0x38208F0);
            const uintptr_t Entity0xRemoved0x=REBASE(0x3820875);
            const uintptr_t Entity0xSyncingShadowBuffers=REBASE(0x3820C8D);
            const uintptr_t WARNDeletingNonEmptyEntityBindings=REBASE(0x381F880);
        }
        namespace RenderLightGrid
        {
            const uintptr_t FailedCreateCopyTextureUploaderLightGrid=REBASE(0x39440A0);
            const uintptr_t LightGridChangingLightDirection=REBASE(0x394E1F0);
            const uintptr_t UploadChunkCountExceededPerFrame=REBASE(0x3952DF0);
            const uintptr_t WaitingLightGridCompletedChunkContexts=REBASE(0x394FEE0);
        }
        namespace RenderMeshManager
        {
            const uintptr_t CpGetContentIDCpPrioRequestType=REBASE(0x360A6A0);
            const uintptr_t MeshManagerDecodedLodHxVersion=REBASE(0x360C110);
            const uintptr_t MeshManagerDecodedModelMesh=REBASE(0x36098E0);
            const uintptr_t MeshManagerDecodedStudioCSG=REBASE(0x3608C00);
            const uintptr_t MeshManagerEmptyGeomLODsSkipping=REBASE(0x36123A0);
            const uintptr_t MeshManagerGeneratedPartType=REBASE(0x3607860);
            const uintptr_t MeshManagerRequestedTFRequested=REBASE(0x3691320);
            const uintptr_t MeshManagerScheduledDecode=REBASE(0x360BC80);
            const uintptr_t MeshManagerUploadMsCountSize=REBASE(0x3613E50);
        }
        namespace RenderPipeline
        {
            const uintptr_t FetcherFrontendReroutingPart=REBASE(0x3A0EAD0);
            const uintptr_t MeshFetcherOnPropertyChanged=REBASE(0x3A29DCA);
            const uintptr_t MeshFetcherOnSpecialMeshPropertyChanged=REBASE(0x3A2B200);
            const uintptr_t MeshUpdaterPartMarkedRemovalRemoving=REBASE(0x3A3D160);
            const uintptr_t RemovingDecal=REBASE(0x3A23B80);
            const uintptr_t ShapeFetcherAddPart=REBASE(0x3A24320);
            const uintptr_t ShapeFetcherOnPropertyChanged=REBASE(0x3A25220);
            const uintptr_t ShapeFetcherRemovePart=REBASE(0x3A24750);
            const uintptr_t ShapeUpdaterAddPart=REBASE(0x3A374B0);
            const uintptr_t SkinningRootLoaderCouldCreateInputConfig=REBASE(0x3A44650);
            const uintptr_t ValidSkeletonRootInstance=REBASE(0x3A320E0);
        }
        namespace RenderTest
        {
            const uintptr_t DeterministicCaptureAlreadyActiveCannotS=REBASE(0x3643770);
            const uintptr_t DeterministicCaptureCancelledRequestId=REBASE(0x366CA20);
            const uintptr_t DeterministicCaptureRenderingTestOriginB=REBASE(0x3643EE0);
            const uintptr_t DeterministicCaptureStartedRequestIdQual=REBASE(0x3643960);
            const uintptr_t PostFXGlowTemporalResetCounterWas=REBASE(0x36CAED0);
            const uintptr_t RenderingTestCaptureSSAOFrameIndex=REBASE(0x36458A0);
            const uintptr_t RenderingTestFinished=REBASE(0x366CE20);
            const uintptr_t RenderingTestStarted=REBASE(0x3643170);
            const uintptr_t SSAOTemporalResetConsumedFrameIndexWas=REBASE(0x37752C0);
            const uintptr_t SubmitTestTimeoutPayload=REBASE(0x3645AC0);
            const uintptr_t WaitingMeshContentProviderRequestQueue=REBASE(0x36469A0);
            const uintptr_t WaitingTextureManager2StreamingDone100=REBASE(0x36451B0);
        }
        namespace RenderTextureCompositor
        {
            const uintptr_t TCCreateTexture=REBASE(0x3744D90);
            const uintptr_t TCJobAttachInstance=REBASE(0x37404B0);
            const uintptr_t TCJobDetachInstance=REBASE(0x3740CC0);
            const uintptr_t TCJobQueueing=REBASE(0x3741DF0);
            const uintptr_t TCJobQueueingDownsample=REBASE(0x3741360);
            const uintptr_t TCJobQueueingExternalRequest=REBASE(0x373F6E0);
            const uintptr_t TCJobStorePreviousTextureOrphaned=REBASE(0x37443C0);
            const uintptr_t TCJobTextureBlitWidthFailed=REBASE(0x61CFA70);
            const uintptr_t TextureCompositorLayerTextureFailedLoad=REBASE(0x373E330);
        }
        namespace ReplicationDataCaching
        {
            const uintptr_t DiscardingJoinInstanceDueNullLocal=REBASE(0x4892FE0);
            const uintptr_t ExpectingInvalidMetaDataBlob=REBASE(0x4895CCC);
            const uintptr_t InvalidOffsetLength=REBASE(0x4895DEE);
            const uintptr_t InvalidatingInstanceBlobOffsetLength=REBASE(0x48DB6C0);
            const uintptr_t ReplicationDataCacheFinalizeBlob=REBASE(0x48DA9F0);
            const uintptr_t ReplicationDataCacheNumInvalidatedCacheB=REBASE(0x4892000);
            const uintptr_t ReplicationDataCacheOpenBlob=REBASE(0x48DA020);
            const uintptr_t ShufflingInstancesBeforeSerializing=REBASE(0x48D8DA0);
            const uintptr_t SkippingOffsetLength=REBASE(0x4896760);
            const uintptr_t TotalUncompressedUsedBytes=REBASE(0x48DB675);
        }
        namespace ReplicationDataLifetime
        {
            const uintptr_t AddChildSubtreeRecursivelyAddingMRDInsta=REBASE(0x31D9EC0);
            const uintptr_t ParentChangedNULLInstance=REBASE(0x46C4A80);
        }
        namespace ReplicationJoinBatchLog
        {
            const uintptr_t ProcessJoinsDoneBatchZuStill=REBASE(0x4771070);
        }
        namespace ResetFilters
        {
            const uintptr_t ApplyFilteredVariablesResetting=REBASE(0x4A377A0);
            const uintptr_t ParseAndSetFilterValueSaving=REBASE(0x4A34010);
        }
        namespace RewardedVideo
        {
            const uintptr_t AdServiceDoAdAvailabilityRequestIneligib=REBASE(0x1062790);
            const uintptr_t AdServiceGetAdAvailabilityNowAsyncReturn=REBASE(0x10639C0);
            const uintptr_t AdServiceHandleOnDemandAdPlayAtClientAdC=REBASE(0x1067240);
            const uintptr_t AdServiceHasSufficientMemoryForRewardedV=REBASE(0x1053AE0);
            const uintptr_t AdServiceIsAdLoadedReturningFalseAdForma=REBASE(0x1064FB0);
            const uintptr_t AdServiceOnDemandVideoPlayInUI=REBASE(0x1067D60);
            const uintptr_t AdServiceOnPlayWithRewardResult=REBASE(0x1066CE0);
            const uintptr_t AdServiceOnPlayWithRewardResultRewardGra=REBASE(0x1066F70);
            const uintptr_t AdServiceShowRewardedVideoAdAsyncPlayerA=REBASE(0x105F260);
            const uintptr_t AdServiceShowRewardedVideoAdAsyncPlayerN=REBASE(0x105FFF0);
            const uintptr_t AdServiceShowRewardedVideoAdAtClientAsyn=REBASE(0x1060950);
            const uintptr_t AdUtilsGmaEligibilityCheckForcingEnabled=REBASE(0x104DB10);
            const uintptr_t AdUtilsGmaEligibilityCheckGmaEligibility=REBASE(0x104E300);
            const uintptr_t AdUtilsSendGmaEligibilityRequestForcingE=REBASE(0x103DA00);
            const uintptr_t AdUtilsSendGmaEligibilityRequestGmaEligi=REBASE(0x103D460);
            const uintptr_t AdsLifecycleManagerGetOnDemandAdsProvide=REBASE(0x103E9E0);
            const uintptr_t DefaultNativeAdsProtocolGetQueryInfoRece=REBASE(0x514EB30);
            const uintptr_t DefaultNativeAdsProtocolGetQueryInfoSend=REBASE(0x514E160);
            const uintptr_t DefaultNativeAdsProtocolShowAdReceivedSh=REBASE(0x5151000);
            const uintptr_t DefaultNativeAdsProtocolShowAdSendingSho=REBASE(0x51506F0);
            const uintptr_t FailedGrantAdRewardFutureCanceled=REBASE(0x1066630);
            const uintptr_t GetAdAvailabilityCacheAttemptToCacheUniv=REBASE(0x10334C0);
            const uintptr_t GetAdAvailabilityCacheValidateAndGetCach=REBASE(0x10331E0);
            const uintptr_t NativeAdsCoreCleanupAdPlatformImplNullpt=REBASE(0x513CE20);
            const uintptr_t NativeAdsCoreGetQueryInfoPlatformImplNul=REBASE(0x513B8D0);
            const uintptr_t NativeAdsCoreHandleAdProgressEventAdProg=REBASE(0x5141230);
            const uintptr_t NativeAdsCoreHandleCtaClickEventCtaClick=REBASE(0x51416C0);
            const uintptr_t NativeAdsCoreHandleGetQueryInfoCompleted=REBASE(0x513F8D0);
            const uintptr_t NativeAdsCoreHandleInitializeCompleted=REBASE(0x513F3F0);
            const uintptr_t NativeAdsCoreHandleOnInitializeSdkFailed=REBASE(0x5142110);
            const uintptr_t NativeAdsCoreHandleOnInitializeSdkSucces=REBASE(0x51418F0);
            const uintptr_t NativeAdsCoreHandleReportAdEventReportAd=REBASE(0x5141490);
            const uintptr_t NativeAdsCoreHandleSetAdStringCompleted=REBASE(0x513FFC0);
            const uintptr_t NativeAdsCoreHandleShowAdCompleted=REBASE(0x5140AE0);
            const uintptr_t NativeAdsCoreNativeAdsCoreSetAdStringPla=REBASE(0x513BDE0);
            const uintptr_t NativeAdsCorePlatformImplInitialize=REBASE(0x513B490);
            const uintptr_t NativeAdsCoreRegisterForAdProgress=REBASE(0x513D060);
            const uintptr_t NativeAdsCoreRegisterForCtaClick=REBASE(0x513D400);
            const uintptr_t NativeAdsCoreRegisterForReportAd=REBASE(0x513D230);
            const uintptr_t NativeAdsCoreShowAdPlatformImplNullptr=REBASE(0x513C900);
            const uintptr_t OnDemandAdsProviderClearAdStateClearingR=REBASE(0x100E740);
            const uintptr_t OnDemandAdsProviderConsumeReadyAdForRead=REBASE(0x100E920);
            const uintptr_t OnDemandAdsProviderFetchAdIgnoredStaleFa=REBASE(0x100FE10);
            const uintptr_t OnDemandAdsProviderFetchAdMakingBackendA=REBASE(0x100EEE0);
            const uintptr_t OnDemandAdsProviderFetchAdReceivingBacke=REBASE(0x1010E40);
            const uintptr_t OnDemandAdsProviderFetchAdStoredSharedOn=REBASE(0x1010720);
            const uintptr_t OnDemandAdsProviderFetchAdSuccessfullyFe=REBASE(0x1012D60);
            const uintptr_t OnDemandAdsProviderGetAdAvailabilityOrFe=REBASE(0x1015060);
            const uintptr_t OnDemandAdsProviderMarkPlayingAdAsConsum=REBASE(0x1016010);
            const uintptr_t OnDemandAdsProviderOnDemandAdsProviderCo=REBASE(0x100E1E0);
            const uintptr_t OnDemandAdsProviderSwapAdReadyAdNewAd=REBASE(0x100E390);
            const uintptr_t RewardedVideoApiClientSendGrantAdRewardR=REBASE(0x1007F40);
            const uintptr_t RewardedVideoTraceDesyncCounterOriginTra=REBASE(0x16B4100);
            const uintptr_t SetGoogleAdFormat=REBASE(0x1006440);
            const uintptr_t UnrecognizedIneligibleReasonDefaultingPl=REBASE(0x1047790);
        }
        namespace RobloxLuaOTA
        {
            const uintptr_t UsingCVServiceLuaAppOTA=REBASE(0x11DB9F0);
        }
        namespace RobloxStarter
        {
            const uintptr_t AllPreDMModulesCompleted=REBASE(0x51AC400);
            const uintptr_t InvalidStageTransitionPreFlag=REBASE(0x51AAEF0);
            const uintptr_t RobloxStarterDestroyed=REBASE(0x51ACA30);
        }
        namespace RobloxStarterNetworkStarterModule
        {
            const uintptr_t UserAgent=REBASE(0x51B2990);
        }
        namespace RobloxTelemetry
        {
            const uintptr_t AppBuildVariantEmptyWhenAdding=REBASE(0x2EAEFA0);
            const uintptr_t CalledSetValueWhenHistogramAlreadyBucket=REBASE(0x2E7EAB0);
            const uintptr_t DualSendingEphemeralCounterV2Counter=REBASE(0x2E97B70);
            const uintptr_t ExcludingEphemeralStatLegacyECS=REBASE(0x2E967F0);
            const uintptr_t HistogramValuesValidCount0=REBASE(0x2E7EF00);
            const uintptr_t InferredCrashCallbackBlockingWaitTimedOu=REBASE(0x4D0F440);
            const uintptr_t InvalidStringValidationRegex=REBASE(0x618CA20);
            const uintptr_t InvalidTelemetryFieldDoubleValueKey=REBASE(0x2E932E0);
            const uintptr_t InvalidTelemetryFieldEmptyValueKey=REBASE(0x2E92FA0);
            const uintptr_t InvalidTelemetryFieldKeyExceedsMax=REBASE(0x2E93490);
            const uintptr_t InvalidTelemetryFieldValueExceedingMax=REBASE(0x2E93101);
            const uintptr_t InvalidTelemetrySampleRateExpectedFinite=REBASE(0x2E89A20);
            const uintptr_t OnDynamicFlagsUpdatedCalledButBatchManag=REBASE(0x2EB0200);
            const uintptr_t OnFlagsLoadedCalledWithoutInitializedTel=REBASE(0x2E993A0);
            const uintptr_t RobloxTelemetryImplOnFlagsLoadedInvoked=REBASE(0x2EB0100);
            const uintptr_t SendEventIngestThrottledEventEventIngest=REBASE(0x2EA6E60);
            const uintptr_t SendPointThrottledEventPointsThrottle=REBASE(0x2EAF220);
            const uintptr_t Sending=REBASE(0x2E805D0);
            const uintptr_t ShutdownRobloxTelemetryCalled=REBASE(0x2B80E40);
            const uintptr_t StartupRobloxTelemetryCalled=REBASE(0x2E99190);
            const uintptr_t ThrottledTelemetrySampleRate=REBASE(0x2EA97F0);
        }
        namespace RobloxWndInit
        {
            const uintptr_t AltEnterFullscreenIgnoringViewAware=REBASE(0x16BD520);
            const uintptr_t BtidFoundSendingClientStatusSet=REBASE(0x71D8E0);
            const uintptr_t ChangedScreenResolutionX=REBASE(0x16BD5C0);
            const uintptr_t EnteringFullscreenResolution=REBASE(0x16BD430);
            const uintptr_t ErrorDuringInitializationUserMessage=REBASE(0x6068E80);
            const uintptr_t FailedRemoveExistingVersions=REBASE(0x6069230);
            const uintptr_t FailedRemoveExistingVersionsNonStandard=REBASE(0x6069320);
            const uintptr_t OldVersionDeletionThreadCompleted=REBASE(0x723A90);
            const uintptr_t ResponseSettingClientStatusExpectTrue=REBASE(0x7305A0);
            const uintptr_t UnknownExceptionSetCookieHandler=REBASE(0x6069020);
            const uintptr_t UpdateAvailableButSkippingUpdateBecause=REBASE(0x71E690);
            const uintptr_t UpdaterLaunchedDrainReportingQuit=REBASE(0x71E250);
        }
        namespace RobuxTransfers
        {
            const uintptr_t CanUsersTransferRobuxAsyncCouldDetermine=REBASE(0x12EF170);
            const uintptr_t ConstructedInitiateRobuxTransferURL=REBASE(0x12A74C0);
            const uintptr_t ConstructedRobuxTransferEligibilityURL=REBASE(0x12A77F0);
            const uintptr_t ErrorOccurredDuringRobuxTransferHTTP=REBASE(0x12FF0D0);
            const uintptr_t InitiateCanUsersTransferRobuxAsync=REBASE(0x12EAE10);
            const uintptr_t InitiatingRobuxTransferUserUserAmount=REBASE(0x12FE6C0);
            const uintptr_t MarketplaceServiceBatchReceiptsResponseR=REBASE(0x12C2450);
            const uintptr_t MarketplaceServiceReceiptPollPeriodRebui=REBASE(0x12ED100);
            const uintptr_t MarketplaceServiceReceiptPollingStartupJ=REBASE(0x12ECD00);
            const uintptr_t MarketplaceServiceThrottledRobuxTransfer=REBASE(0x12EC5E0);
            const uintptr_t ProcessReceiptMissingInvalidPurchaseIdRe=REBASE(0x12A0090);
            const uintptr_t ReplicatingResponseSender=REBASE(0x12E9C20);
            const uintptr_t RobuxTransferInitiatedSuccessfullyTransf=REBASE(0x12FF770);
            const uintptr_t RobuxTransferRequiresPlusSubscriptionPro=REBASE(0x12E9E80);
            const uintptr_t RobuxTransferRequiresPlusSubscriptionTri=REBASE(0x12F2FA0);
            const uintptr_t WaitingSubscriptionPurchaseCompletionRet=REBASE(0x12EA3D0);
        }
        namespace RolloutWarning
        {
            const uintptr_t SetRolloutValueCalledFlagType=REBASE(0x4A33780);
        }
        namespace RomarkScreenshot
        {
            const uintptr_t ExecutingSaveScreenshotThreadTaskTaskSch=REBASE(0x3662AC0);
            const uintptr_t GetEncodedJpegBufferEncodeThrew=REBASE(0x61CA240);
            const uintptr_t PreciseScreenshotCaptureBufferAllocation=REBASE(0x363DC60);
            const uintptr_t SaveScreenshotThreadStartedTimestampMsTy=REBASE(0x36632E0);
            const uintptr_t TryingCopyTextureDownloadResourceOntoFra=REBASE(0x3661F30);
        }
        namespace RtcIoDefaultInterface
        {
            const uintptr_t InterfaceMonitorStaleDuplicateGeneration=REBASE(0x213C770);
            const uintptr_t InterfaceMonitorSubscribingConnectivityV=REBASE(0x213C2E0);
        }
        namespace RuntimeContentLog
        {
            const uintptr_t AddingPendingDeserializationB=REBASE(0x32D7050);
            const uintptr_t AlsoUnableFallBackBaseAsset=REBASE(0x34E6EE0);
            const uintptr_t AssetServiceCreateDataModelContentAsyncF=REBASE(0x3502C90);
            const uintptr_t CaughtExceptionWhileTryingTranscode=REBASE(0x61BDB10);
            const uintptr_t CaughtExceptionWhileTryingTranscodeImage=REBASE(0x61BDC30);
            const uintptr_t CaughtExceptionWhileTryingTranscodeMesh=REBASE(0x61BDDB0);
            const uintptr_t CaughtExceptionWhileTryingTranscodeTextu=REBASE(0x61BDF30);
            const uintptr_t ClearAllContentDatamodelDmType=REBASE(0x34E1B60);
            const uintptr_t ClearingAllRuntimeContentPendingDeserial=REBASE(0x32D4E50);
            const uintptr_t CouldnTFindData=REBASE(0x34F5C10);
            const uintptr_t CreateInternalRuntimeContentAsync=REBASE(0x3501BA0);
            const uintptr_t CreateMeshPartAsyncUnableRetrieveDataMod=REBASE(0xD926D0);
            const uintptr_t CreateTexturePackRuntimeContentAsync=REBASE(0x3506DD0);
            const uintptr_t CreateTexturePackRuntimeContentAsyncErro=REBASE(0x3505D40);
            const uintptr_t CreatingMeshTranscoder=REBASE(0x3501050);
            const uintptr_t CreatingTexturePackTranscoder=REBASE(0x3504510);
            const uintptr_t CreatingTranscoder=REBASE(0x34FDBC0);
            const uintptr_t DataModelContentDeserializingB=REBASE(0x3507D60);
            const uintptr_t DestructingRuntimeContentHandle=REBASE(0x32D41A0);
            const uintptr_t DispatchingCallbacksAcrKey=REBASE(0x34E0A00);
            const uintptr_t EnqueuingTranscodingJob=REBASE(0x34F7B80);
            const uintptr_t ErasingData=REBASE(0x34F0D70);
            const uintptr_t ExceptionWhileRespondingRuntimeContentQu=REBASE(0x61BD4E0);
            const uintptr_t FailedDecodeTexturePackPbrMap=REBASE(0x61BE410);
            const uintptr_t OnAllTpMapsSyncedErrorGettingDataModelLo=REBASE(0x35068E0);
            const uintptr_t ProcessingDeserializationLoadTimeB=REBASE(0x32D5780);
            const uintptr_t ProcessingPendingDeserializationsAsyncPe=REBASE(0x32D72C0);
            const uintptr_t ProcessingRemoteEventContentShare=REBASE(0x34E5870);
            const uintptr_t QueueEstimate2fSItems=REBASE(0x34DFAE0);
            const uintptr_t RbxStorageInitializedCannotAccessStorage=REBASE(0x34E8110);
            const uintptr_t RecordedTranscodeTimeKey2fS=REBASE(0x34DF816);
            const uintptr_t RemovingRuntimeContentHandle=REBASE(0x32D4B40);
            const uintptr_t ReturningExistingRuntimeContentHandle=REBASE(0x32D5390);
            const uintptr_t RuntimeContentServiceOnServiceProviderDa=REBASE(0x34E2AA0);
            const uintptr_t SendingNetAssetViaInterface=REBASE(0x34E3A90);
            const uintptr_t SkippedRecordingEmptyTranscodeTimeKey=REBASE(0x34DF700);
            const uintptr_t StorageResult=REBASE(0x34EDAE0);
            const uintptr_t StorageTypeImageBaseBytes=REBASE(0x34E8700);
            const uintptr_t StoreData=REBASE(0x34EE240);
            const uintptr_t StoreDataAsync=REBASE(0x34ED0A0);
            const uintptr_t StoringIntoRbxStorage=REBASE(0x34E8DC0);
            const uintptr_t StoringOntoRbxStorageAsync=REBASE(0x34EA830);
            const uintptr_t SuitableACRAlreadyAvailableCheckingIf=REBASE(0x34F62A0);
            const uintptr_t SyncRuntimeData=REBASE(0x34EF820);
            const uintptr_t SyncRuntimeDataAsync=REBASE(0x34ED650);
            const uintptr_t TextureStreamingTranscodeProducedOutputs=REBASE(0x34F8D70);
            const uintptr_t TranscodeImageSuccessful=REBASE(0x34FDF80);
            const uintptr_t TranscodeImageSuccessfulOutputs=REBASE(0x34FF460);
            const uintptr_t TranscodeMeshSuccessfulOutputs=REBASE(0x35012B0);
            const uintptr_t TranscodeTexturePackSuccessfulOutputs=REBASE(0x35048A0);
            const uintptr_t TranscodingJobFinishedResult=REBASE(0x34FD000);
            const uintptr_t UnableGetRuntimeContentLocalPlayer=REBASE(0x34E3620);
            const uintptr_t UnableGetRuntimeContentNetAssetTypeRef=REBASE(0x34E4730);
            const uintptr_t UnableGetRuntimeContentPlayer=REBASE(0x34E30E0);
            const uintptr_t WhenRequestingDataDataWasFound=REBASE(0x34F2290);
        }
        namespace RuntimeInjector
        {
            const uintptr_t BindingFactoryReturnedNullptrAfterMs=REBASE(0x1DE5690);
            const uintptr_t InjectorConstructedBindings=REBASE(0x1DE2770);
            const uintptr_t InjectorCreateAllCreatedBindings1fMs=REBASE(0x1DE63A0);
            const uintptr_t InjectorTearingDownBindingsCreationOrder=REBASE(0x1DE2E10);
        }
        namespace Rupp
        {
            const uintptr_t AssigningAddressReverseEndpoint=REBASE(0x281C320);
            const uintptr_t ClientFailedRuppSetup=REBASE(0x4904680);
            const uintptr_t ClientOptReceivingRuppHeaders=REBASE(0x282D442);
            const uintptr_t ClientOptedReceivingRuppHeadersSending=REBASE(0x282D7A0);
            const uintptr_t InvalidRuppHeaderLengthBytesRead=REBASE(0x2820D70);
            const uintptr_t OfflineRuppLength=REBASE(0x2835A40);
            const uintptr_t StartOfflineBitStreamReverseSerializatio=REBASE(0x2835600);
        }
        namespace RuppTokenClientLog2
        {
            const uintptr_t GeneratingNewRuppToken=REBASE(0x2221800);
            const uintptr_t UpdatingRuppTokenHeader=REBASE(0x2222166);
        }
        namespace RuppTokenLog
        {
            const uintptr_t GetaddrinfoHasDifferentFamilyResultVs=REBASE(0x283C260);
            const uintptr_t SwitchingNewTTTokenReceivedRCC=REBASE(0x221DCA0);
        }
        namespace SQLite
        {
            const uintptr_t DatabaseBeginTransactionMutexLockElapsed=REBASE(0x26DE690);
            const uintptr_t DatabaseDatabase=REBASE(0x26DC340);
            const uintptr_t DatabaseExec=REBASE(0x26DC430);
            const uintptr_t DatabaseExecInt=REBASE(0x26DC6B0);
            const uintptr_t DatabaseWalCheckpointRcLogCkptElapsed=REBASE(0x26DCB40);
            const uintptr_t ExecSQLElapsed3fMs=REBASE(0x26D8770);
            const uintptr_t MemMethodsInit=REBASE(0x26F49E0);
            const uintptr_t MemMethodsMallocOutMemory=REBASE(0x26F46D0);
            const uintptr_t MemMethodsShutdown=REBASE(0x26F4AC0);
            const uintptr_t SetupDatabaseERRORFailedSetLockingMode=REBASE(0x26D8ED0);
            const uintptr_t Sqlite3ErrorLog=REBASE(0x26DA910);
            const uintptr_t Sqlite3GlobalInitENDElapsed3f=REBASE(0x26DB5E0);
            const uintptr_t StatementFinalizeERRORRcErrorElapsed=REBASE(0x26F3D80);
            const uintptr_t StatementStepDoneERROR=REBASE(0x26F3A10);
            const uintptr_t StatementStepRowERRORSQL=REBASE(0x26F3810);
        }
        namespace SafeAreaInsetChanges
        {
            const uintptr_t NewSafeAreaInsetsLeftTop=REBASE(0x3EFB2D0);
        }
        namespace Safety
        {
            const uintptr_t ARVideoFeasibilityPredictionValue=REBASE(0x4346610);
            const uintptr_t BuildUIClosed=REBASE(0x4352C80);
            const uintptr_t BuildUIOpened=REBASE(0x4352B90);
            const uintptr_t CannotStartARVideoRecordingDue=REBASE(0x4350F50);
            const uintptr_t CaptureAvatarMovementFrameFailedObtainWo=REBASE(0x436E7D0);
            const uintptr_t CaptureServiceRequestVideoReportRecordin=REBASE(0x43517B0);
            const uintptr_t CapturesUIClosed=REBASE(0x43526E0);
            const uintptr_t CapturesUIOpened=REBASE(0x43525F0);
            const uintptr_t ChatLineReportingClosed=REBASE(0x4352AA0);
            const uintptr_t ChatLineReportingOpened=REBASE(0x43529B0);
            const uintptr_t ChatSuspensionDialogClosed=REBASE(0x43528C0);
            const uintptr_t ChatSuspensionDialogOpened=REBASE(0x43527D0);
            const uintptr_t CreatedSafetyService=REBASE(0x4338150);
            const uintptr_t DataModelARVideoRecordingFinalizationRem=REBASE(0x4351D80);
            const uintptr_t DecodeAvatarMovementProtoSupportedClient=REBASE(0x4353DE0);
            const uintptr_t FailedReadVideoFile=REBASE(0x43481F0);
            const uintptr_t GetVisibleAvatarsFailedObtainWorkspaceCa=REBASE(0x436A6E0);
            const uintptr_t HandleForcedScreenshotEventAtClientFaile=REBASE(0x434F1D0);
            const uintptr_t IllegalRequestArgumentsAreMalformedMissi=REBASE(0x434E6C0);
            const uintptr_t MenuClosed=REBASE(0x4352310);
            const uintptr_t PartyChatWindowClosed=REBASE(0x4352500);
            const uintptr_t PartyChatWindowOpened=REBASE(0x4352410);
            const uintptr_t ProcessRemoteEventFailedObtainDataModel=REBASE(0x4350B90);
            const uintptr_t RegisteredAbuseReportVideoTunableId=REBASE(0x4347AB0);
            const uintptr_t RemovedAbuseReportVideoTunableId=REBASE(0x4347810);
            const uintptr_t ResizeEncodeWithParamsInvalidZeroValueHe=REBASE(0x433CBC0);
            const uintptr_t RespondingRequestStopARVideo=REBASE(0x43480B0);
            const uintptr_t SafetyServiceLongerValidHandlingPlayerLe=REBASE(0x4339500);
            const uintptr_t SafetyServiceLongerValidHandlingToggleCa=REBASE(0x4356ED0);
            const uintptr_t SafetyServiceReceiveVideoCaptureStartAtt=REBASE(0x4351A60);
            const uintptr_t SceneCaptureFailedWrite=REBASE(0x433E0A0);
            const uintptr_t SceneSnapshotPruneCountBudgetDistCullCha=REBASE(0x435A4E0);
            const uintptr_t ScreenshotReadyTaskDataModelGone=REBASE(0x433F340);
            const uintptr_t ScreenshotResizeEncodeInvalidZeroValueHe=REBASE(0x433BB50);
            const uintptr_t ScreenshotSendAbortedStageReasonAllocati=REBASE(0x433DDA0);
            const uintptr_t SkippingAvatarIDSinceAvatarIdentificatio=REBASE(0x4340320);
            const uintptr_t SkippingPreciseScreenshotMemoryPressureT=REBASE(0x433B4A0);
            const uintptr_t StartingUploadAsyncTaskReportID=REBASE(0x4353630);
            const uintptr_t StudioT0UploadDroppedAuthenticatedStudio=REBASE(0x4349FA0);
            const uintptr_t SubmittedAbuseReportV2ID=REBASE(0x3223CD0);
            const uintptr_t SubmittedAbuseReportV3ID=REBASE(0x32247D0);
            const uintptr_t SubmittedAbuseReportVideoTunableId=REBASE(0x4346970);
            const uintptr_t UploadCompleteFiringTransitionTask=REBASE(0x43565C0);
            const uintptr_t UploadCompleteIDWillTransitionVia=REBASE(0x4353A90);
            const uintptr_t UploadingScreenshotAMCMetadataReasonCont=REBASE(0x4344900);
            const uintptr_t VideoUploadSuccessfulID=REBASE(0x43494E0);
            const uintptr_t WeAreOnVideoRecorderFinalizedGotFilePath=REBASE(0x4352D70);
        }
        namespace SamplingProfiler
        {
            const uintptr_t CanTKickNewSampleWorker=REBASE(0x2AA0CE0);
            const uintptr_t EnumProcessModulesFailed=REBASE(0x2A9E490);
            const uintptr_t FailedGetProfileTelemetrySubsystem=REBASE(0x2AA08A0);
            const uintptr_t WorkerLoopExitingModuleInformation=REBASE(0x2AA0F10);
        }
        namespace ScreenProtocolCore
        {
            const uintptr_t ReceivedSafeAreaInsets=REBASE(0x1437CB0);
        }
        namespace ScreenTime
        {
            const uintptr_t ScreenTimeEndSessionRequestResponse=REBASE(0x4D56630);
            const uintptr_t ScreenTimeEndSessionRequestTimestamp=REBASE(0x4D558F0);
            const uintptr_t ScreenTimeHeartbeatSessionRequestTimesta=REBASE(0x4D55010);
            const uintptr_t ScreenTimeManagerInitByGuacResponseCodeB=REBASE(0x4CED230);
            const uintptr_t ScreenTimeManagerStartCheckingCompliance=REBASE(0x4CEC6E0);
            const uintptr_t ScreenTimeStatusWarningLockout=REBASE(0x4D59130);
        }
        namespace ScriptContextAdd
        {
            const uintptr_t LoaderFacetAddScript=REBASE(0x427BFF0);
        }
        namespace ScriptContextClose
        {
            const uintptr_t VmCollectionFacetVmCollectionFacetStateT=REBASE(0x424D080);
        }
        namespace ScriptContextRemove
        {
            const uintptr_t LoaderFacetRemoveScript=REBASE(0x427C3A0);
        }
        namespace Serialization
        {
            const uintptr_t HitExceptionHSRPublishProcess=REBASE(0x3539EA0);
            const uintptr_t InstanceVectorEmpty=REBASE(0x3539A10);
            const uintptr_t UnknownException=REBASE(0x61C00E0);
        }
        namespace SerializationTrace
        {
            const uintptr_t TriedDeserializeEmptyBytes=REBASE(0x222B50D);
            const uintptr_t TriedDeserializeModelBundleMappedData=REBASE(0x222BA40);
            const uintptr_t TriedDeserializeModelBundleMetadataParam=REBASE(0x222B6F0);
            const uintptr_t TriedDeserializeSizePrefixInvalidStream=REBASE(0x222BF10);
            const uintptr_t TriedDeserializeStringSizeMaxAllowed=REBASE(0x222B180);
        }
        namespace Serializer
        {
            const uintptr_t StringViewProvidedChunkDataCompressed=REBASE(0x4B874C0);
            const uintptr_t UnknownReflectionTypeSerializerPugiReadP=REBASE(0x4BBA410);
        }
        namespace ServerRuppGenerator
        {
            const uintptr_t UpdatingPeer=REBASE(0x2222E20);
        }
        namespace SessionAuthObserver
        {
            const uintptr_t SessionManagerSessionAuthObserverSetAuth=REBASE(0x51CC730);
        }
        namespace SessionCrypto
        {
            const uintptr_t RbxOpenReply2EncryptFailed=REBASE(0x2831040);
            const uintptr_t RbxOpenRequest2Invalid=REBASE(0x2833FF0);
            const uintptr_t RbxOpenRequest2UsingEncryption=REBASE(0x282E240);
        }
        namespace SessionIdleController
        {
            const uintptr_t SessionIdleControllerOnTimerUserFoundIdl=REBASE(0x51CBA10);
            const uintptr_t SessionIdleControllerOnUserActiveLastAct=REBASE(0x51CB910);
            const uintptr_t SessionIdleControllerStopTimer=REBASE(0x51CB7E0);
        }
        namespace SessionL2ValidationHelper
        {
            const uintptr_t OnSessionChangeScCountShCountCur=REBASE(0x51BC170);
            const uintptr_t OnSessionHeartbeatScCountShCountCur=REBASE(0x51BDA70);
        }
        namespace SessionService
        {
            const uintptr_t L2SessionContextManagerAcquireContextFoc=REBASE(0x51C1D50);
            const uintptr_t L2SessionContextManagerReleaseContextFoc=REBASE(0x51C21F0);
            const uintptr_t SessionChangedEvent=REBASE(0x51C35C0);
            const uintptr_t SessionManagerReleaseContextFocusRemoveR=REBASE(0x51C1860);
            const uintptr_t SessionManagerReplaceSessionCurL2Context=REBASE(0x51B8660);
            const uintptr_t SessionManagerSetSessionInternalCurL2Con=REBASE(0x51B9710);
        }
        namespace SessionSubscriberEventLog
        {
            const uintptr_t SessionSubscriberDispatchSessionChangedE=REBASE(0x51C7300);
        }
        namespace SessionSystrayObserver
        {
            const uintptr_t SessionSystrayObserverOnEnterSystraySett=REBASE(0x51B5B20);
        }
        namespace SessionTransitionFSM
        {
            const uintptr_t DetectedApplicationForegrounding=REBASE(0x2A4EA90);
            const uintptr_t EnteredAppSession=REBASE(0x2A4C910);
            const uintptr_t EnteredPlaySession=REBASE(0x2A4C1B0);
            const uintptr_t Initialized=REBASE(0x2A4BD80);
            const uintptr_t SentAppSessionSuccess=REBASE(0x2A4DF50);
            const uintptr_t SentPlaySessionSuccess=REBASE(0x2A4DD70);
            const uintptr_t TearingDown=REBASE(0x2A4E400);
            const uintptr_t Teleported=REBASE(0x2A4E790);
        }
        namespace ShapeFit
        {
            const uintptr_t AlternatingMinimizerLDLTFactorizationFai=REBASE(0x1D8CDD0);
            const uintptr_t DeformationGradientFormVerticesHaveWeigh=REBASE(0x1D994B0);
            const uintptr_t GridCageAltGridReducedDOFs=REBASE(0x1D7D110);
            const uintptr_t GridCageAltLSInitX=REBASE(0x1D7E250);
            const uintptr_t GridCageAltMinimizerDidConverge=REBASE(0x1D7F370);
            const uintptr_t GridCageAutoCellSize4fAvgCageEdge=REBASE(0x1D859C6);
            const uintptr_t GridToMeshBuildJacobianForPointsFloatQue=REBASE(0x1D87800);
            const uintptr_t GridToMeshCompressToActiveNodesFloatNode=REBASE(0x1D87E60);
            const uintptr_t GridToMeshLinearGridXXNodes=REBASE(0x1D86EE0);
            const uintptr_t MergedCoincidentCageVertices=REBASE(0x1D97660);
            const uintptr_t ProperArapFormConstantHessianNnz=REBASE(0x1D8F730);
            const uintptr_t ShapeFitMemoryPhaseLsFactorizedFactorL=REBASE(0x1D89A00);
            const uintptr_t ShapeFitMultiLayerCascadedAvatarCage=REBASE(0x1D777D0);
            const uintptr_t ShapeFitMultiLayerLayerThrewSkipping=REBASE(0x61575F0);
            const uintptr_t TotalFreeInnerCageVerticesOuter=REBASE(0x1D83930);
        }
        namespace ShareLinkHandler
        {
            const uintptr_t ShareLinkV2ResolvedResponse=REBASE(0x5187540);
        }
        namespace SharedStringCacheInfo
        {
            const uintptr_t LoadingSharedStringCacheExitedEarly=REBASE(0x48BC840);
            const uintptr_t UpdatedSharedStringCacheAddingEntries=REBASE(0x48C05C0);
        }
        namespace SharedWebViewProtocol
        {
            const uintptr_t WebViewImplOpenBrowserDefaultHandlerDrop=REBASE(0x5164A00);
            const uintptr_t WebViewProtocolCloseBrowser=REBASE(0x5164CD0);
            const uintptr_t WebViewProtocolHandleWindowClose=REBASE(0x51646C0);
            const uintptr_t WebViewProtocolMutateBrowser=REBASE(0x51640E0);
            const uintptr_t WebViewProtocolOpenBrowser=REBASE(0x5163460);
        }
        namespace ShipsInNightGarbageCollection
        {
            const uintptr_t INFOREDUCERegionRadiusVersionWas=REBASE(0x474AFA0);
        }
        namespace SignalRCore
        {
            const uintptr_t AttemptingReconnectMs=REBASE(0x498F410);
            const uintptr_t ReceivedIncompleteMessage=REBASE(0x498D5E0);
            const uintptr_t StopIgnoredBecauseAlreadyDisconnected=REBASE(0x498BEE0);
        }
        namespace SignalRCoreError
        {
            const uintptr_t ActionEventHasAlreadyBeenRegistered=REBASE(0x498B9E0);
            const uintptr_t CannotInvokeWhenConnectedCurrentState=REBASE(0x498FF70);
            const uintptr_t IDDisconnected=REBASE(0x498FB40);
            const uintptr_t SignalRCoreCannotStartUnlessHub=REBASE(0x498BCB0);
        }
        namespace SignalRCoreNetworkHandler
        {
            const uintptr_t SignalRCoreCannotInvokeWhenConnectedCurr=REBASE(0x497C710);
        }
        namespace SingleSurfaceApp
        {
            const uintptr_t ApplyLocale=REBASE(0x1461370);
            const uintptr_t DeferredRbxmAbandoningOwedSwapStoppingGa=REBASE(0x1468520);
            const uintptr_t DeferredRbxmDownloadFailedStayingLuaAppJ=REBASE(0x146FAC0);
            const uintptr_t DeferredRbxmFlowImplementationSingleSurf=REBASE(0x145F170);
            const uintptr_t DeferredRbxmGameDataModelClosedBeforeLoa=REBASE(0x146F2A0);
            const uintptr_t DeferredRbxmGameDataModelLoadedSwappingS=REBASE(0x1468710);
            const uintptr_t DeferredRbxmHoldingSurfaceSwapUntilGame=REBASE(0x1469340);
            const uintptr_t DeferredRbxmIdleLeaveAbandoningParkedJoi=REBASE(0x146AFD0);
            const uintptr_t DeferredRbxmJoinOutcome=REBASE(0x1466920);
            const uintptr_t DeferredRbxmLaunchUGCGameInternalDeferri=REBASE(0x1466DF0);
            const uintptr_t DeferredRbxmPreGameAppliedJoiningPlaceId=REBASE(0x1467490);
            const uintptr_t DeferredRbxmResumingUGCJoinAfterDownload=REBASE(0x1467F10);
            const uintptr_t DeferredRbxmStatusPublished=REBASE(0x146FE90);
            const uintptr_t DestroyLuaAppStageFinishedDestroyingLuaA=REBASE(0x1463CD0);
            const uintptr_t ErrorForceOTAUpdateAvailableSignalButUpd=REBASE(0x146CE50);
            const uintptr_t HandleGameWillClose=REBASE(0x1465480);
            const uintptr_t HandleLowMemoryWarningForRenderViewSessi=REBASE(0x145E3A9);
            const uintptr_t InitializeLuaAppLoggedUserOp=REBASE(0x1461540);
            const uintptr_t InitializeSingleton=REBASE(0x145ED60);
            const uintptr_t InitializeWithAppStarter=REBASE(0x145CF20);
            const uintptr_t LaunchUGCGameInternalRestoreRenderingFre=REBASE(0x1468B30);
            const uintptr_t LaunchUGCGameInternalUserCancelledSkippi=REBASE(0x1467B10);
            const uintptr_t MemoryPrioritizationCallbackLevel=REBASE(0x146C860);
            const uintptr_t PauseLuaAppAndDestroyIfNeededStageDestro=REBASE(0x1464120);
            const uintptr_t PauseLuaAppSingleSurfaceAppIntialized=REBASE(0x14635C0);
            const uintptr_t PauseUGCGameStageDestroySurfaceView=REBASE(0x146A1F0);
            const uintptr_t PerformanceControlCallbackLevel=REBASE(0x146C540);
            const uintptr_t ProcessLowMemoryWarningLowMemoryDestroyi=REBASE(0x146AD50);
            const uintptr_t ReducePatchCacheMemory=REBASE(0x1470C20);
            const uintptr_t RegisterForForceOTAUpdateAvailableConnec=REBASE(0x146CC20);
            const uintptr_t RegisterRenderingFrequencyDuringStartup=REBASE(0x1461AE0);
            const uintptr_t ReplaceCurrentDataModelAppStage=REBASE(0x14610F0);
            const uintptr_t ReplaceForegroundDataModelAppStage=REBASE(0x1460D30);
            const uintptr_t RestoringRenderingFrequencyNormal=REBASE(0x1470920);
            const uintptr_t ResumeUGCGameStage=REBASE(0x146A420);
            const uintptr_t ResumeUGCGameStagePauseBeforeResumeDestr=REBASE(0x146A6F0);
            const uintptr_t ReturnToLuaAppInternalAppYetInitializedR=REBASE(0x14626C0);
            const uintptr_t ReturnToLuaAppLuaAppStageResumeApp=REBASE(0x1462050);
            const uintptr_t SetLocale=REBASE(0x1460A40);
            const uintptr_t SetStageStage=REBASE(0x146BFA0);
            const uintptr_t ShutDownStage=REBASE(0x1465050);
            const uintptr_t StartLuaAppStage=REBASE(0x14633E0);
            const uintptr_t UnregisterMemoryPrioritizationCallback=REBASE(0x145E190);
            const uintptr_t UpdateSurfaceLuaAppStage=REBASE(0x14639B0);
            const uintptr_t UpdateSurfaceUGCGameStage=REBASE(0x146AAE0);
            const uintptr_t UserDidLogin=REBASE(0x145D700);
        }
        namespace SkinMorph
        {
            const uintptr_t HasInfluenceSkipping=REBASE(0x1DA4710);
            const uintptr_t SourceDestinationVertexCountsDonT=REBASE(0x1DA34A0);
            const uintptr_t SourceJointHierarchyHasCycleAbove=REBASE(0x1DA36A0);
        }
        namespace SkinningSubsets
        {
            const uintptr_t BuiltSkinningSubsetsFacesJoints=REBASE(0x23E43C0);
        }
        namespace SlimLoader
        {
            const uintptr_t ACRRequestPriorityTryMadeResource=REBASE(0x39D01E0);
            const uintptr_t ACRResponseTryReceivedResource=REBASE(0x39C9E50);
            const uintptr_t FailedReadFileMeshDataSlimDataChunk=REBASE(0x39D1F40);
            const uintptr_t LODGenerationJobLODCreated=REBASE(0x39CD1F0);
            const uintptr_t LODGenerationJobThreadLODStatus=REBASE(0x39CE63F);
            const uintptr_t ManifestStatusChanged=REBASE(0x39CBE80);
            const uintptr_t RequestLODCreated=REBASE(0x39C92F0);
            const uintptr_t RequestLODNeeds=REBASE(0x39CC240);
            const uintptr_t RequestLODTookSeconds=REBASE(0x39CA570);
        }
        namespace SlimPropertySetLog
        {
            const uintptr_t FailedReadSlimPropertySetHeader=REBASE(0x44BEE80);
        }
        namespace SlimRenderer
        {
            const uintptr_t SlimTelemetryInitializationBlocked=REBASE(0x39C5DF0);
            const uintptr_t SlimTelemetryInitialized=REBASE(0x39C5A70);
            const uintptr_t SlimTelemetrySubmittedSlimControllerACRR=REBASE(0x39C6420);
            const uintptr_t SlimTelemetrySubmittedSlimForceExperimen=REBASE(0x39C6950);
            const uintptr_t SlimTelemetrySuppressedSlimControllerACR=REBASE(0x39C5F40);
        }
        namespace SlimRendererAnimation
        {
            const uintptr_t CreateStreamKeyHadStreamCreatedAnimation=REBASE(0x38ADB90);
            const uintptr_t UpdateSlimAnimationHandleDoesHaveAnimati=REBASE(0x38A4CB0);
            const uintptr_t UpdatingAnimationStreamBonesEntityHandle=REBASE(0x38A6030);
            const uintptr_t UpdatingAnimationStreamBonesSourceKey=REBASE(0x38AE790);
        }
        namespace SlimReplicationLog
        {
            const uintptr_t ModelHasBonesWhichExceedsMaximum=REBASE(0x30787D0);
            const uintptr_t ModelHasEmptySkeletonSkipSnapshot=REBASE(0x307A630);
            const uintptr_t ModelInstanceSetSlimInstanceHashesHashes=REBASE(0x342C380);
            const uintptr_t ReceivedEntityArrayDoesAlignCFrame=REBASE(0x3075650);
            const uintptr_t SlimAnimationDataEntityAttemptSetInvalid=REBASE(0x3085120);
            const uintptr_t SlimAnimationDataEntityNumberParentIndic=REBASE(0x3085800);
            const uintptr_t SlimAnimationSmoothingErrorSource=REBASE(0x30849D0);
            const uintptr_t SlimReplicationDataCanOnlyReplicateUpBon=REBASE(0x3246B50);
        }
        namespace SlimServiceLog
        {
            const uintptr_t AttachedStringValueModelJsonSize=REBASE(0x3066B60);
            const uintptr_t Log=REBASE(0x30682C0);
            const uintptr_t SLIMShadowUploadModelAssetHash=REBASE(0x306D190);
            const uintptr_t SLIMUploadFlowBasePartAssetHash=REBASE(0x3068570);
            const uintptr_t SlimHashChanged=REBASE(0x3427490);
            const uintptr_t SuccessfullyUploadedPropertySet=REBASE(0x3070F70);
        }
        namespace SlowHttpRequest
        {
            const uintptr_t SlowHttpRequest=REBASE(0x11D1B20);
        }
        namespace SocialAmpFeatureEvaluationManager
        {
            const uintptr_t AMPFeatureEvaluationError=REBASE(0x4A735E0);
            const uintptr_t AMPFeatureReturnedErrorValueMay=REBASE(0x4A747C0);
            const uintptr_t DisconnectingPlayerSignals=REBASE(0x4A79440);
            const uintptr_t FailedParseAMPResponse=REBASE(0x62431A0);
            const uintptr_t HandlingAMPFeatureEvaluationResponse=REBASE(0x4A74C30);
            const uintptr_t PurgingAMPFeatureEvaluationCachePlayer=REBASE(0x4A78EF0);
            const uintptr_t RefetchForPlayerRateLimitedUserId=REBASE(0x4A769A0);
            const uintptr_t SendingAMPFeatureEvaluationRequestPlayer=REBASE(0x4A76D00);
        }
        namespace SocialCounterpartyManager
        {
            const uintptr_t AMPAgeCheckEvaluationError=REBASE(0x4A7CB50);
            const uintptr_t AMPEvaluationError=REBASE(0x4A7C9A0);
            const uintptr_t CompatibilityTokenResponse=REBASE(0x4A81900);
            const uintptr_t FailedFindChatService=REBASE(0x4A84C90);
            const uintptr_t FailedParseUserBlockingData=REBASE(0x6243C30);
            const uintptr_t FetchMissingBlockingDataTriggeringInitia=REBASE(0x4A8C9D0);
            const uintptr_t FetchingUserBlockingDataPlayer=REBASE(0x4A8B140);
            const uintptr_t HandlingAgeGroupAMPResponse=REBASE(0x4A7EA70);
            const uintptr_t HandlingBatchCheckReciprocalBlockRespons=REBASE(0x4A8EE00);
            const uintptr_t HandlingCompatibilityTokenAMPResponse=REBASE(0x4A7F820);
            const uintptr_t HasCommunicationAccessStatus=REBASE(0x4A7D5F0);
            const uintptr_t MakeBatchCheckReciprocalBlockRequestUser=REBASE(0x4A8C570);
            const uintptr_t PlayerAddedUserIdBranchEmptyCache=REBASE(0x4A86C30);
            const uintptr_t PlayerLeaving=REBASE(0x4A87740);
            const uintptr_t PopulatingSocialCounterpartiesPlayerOthe=REBASE(0x4A827C0);
            const uintptr_t PurgingAgeGroupPlayer=REBASE(0x4A81EE0);
            const uintptr_t PurgingCompatibilityTokensPlayer=REBASE(0x4A82300);
            const uintptr_t PurgingSocialCounterpartiesPlayer=REBASE(0x4A834A0);
            const uintptr_t PurgingUserBlockingDataPlayer=REBASE(0x4A8C1D0);
            const uintptr_t SkippingAgeGroupPopulationPlayer=REBASE(0x4A80400);
            const uintptr_t SkippingCompatibilityTokenPopulationPlay=REBASE(0x4A81230);
            const uintptr_t SocialCounterpartyManagerFailedAgeGroupP=REBASE(0x62433E0);
            const uintptr_t SocialCounterpartyManagerFailedCompatibi=REBASE(0x6243590);
            const uintptr_t SocialCounterpartyManagerFailedParsingEr=REBASE(0x6243780);
            const uintptr_t SubscribingPlayerAddedPlayerRemovingSign=REBASE(0x4A86580);
            const uintptr_t UpdateBlockStatusBlockerIdBlockeeIdBlock=REBASE(0x4A8F980);
            const uintptr_t UserBlockStateChangeHandlerException=REBASE(0x6243910);
            const uintptr_t UserBlockingAPIError=REBASE(0x4A7CD00);
            const uintptr_t UserBlockingDataCachedUserIdPairsBlocked=REBASE(0x4A89920);
            const uintptr_t UserBlockingDataRequestFailedUserIdErrSt=REBASE(0x4A8B7D0);
            const uintptr_t UserIdCanCommunicateUserId=REBASE(0x4A841C0);
        }
        namespace Sound
        {
            const uintptr_t FmodFailedLoadSound=REBASE(0x454F920);
            const uintptr_t ReleasingFMOD=REBASE(0x2882A00);
            const uintptr_t SubtractorDspOverrunRemove=REBASE(0x45F6CB0);
            const uintptr_t SubtractorDspResyncDiscardedReferenceSam=REBASE(0x45F73A0);
            const uintptr_t SubtractorDspUnderrunProcess=REBASE(0x45F6570);
            const uintptr_t TTSLength=REBASE(0xFAE9E0);
            const uintptr_t UnsupportedDeviceListChangeType=REBASE(0x455B520);
            const uintptr_t VolumetricSoundProducedNaNEmitterListene=REBASE(0x45D4B70);
        }
        namespace SoundTrace
        {
            const uintptr_t CreatingFMODChannelBecauseSoundBad=REBASE(0x5A266D0);
            const uintptr_t FMODBADDSPCONNECTIONSrcDst=REBASE(0x2883780);
            const uintptr_t FMODPlaybackChannelUpdateSyncTimePositio=REBASE(0x5A28BF4);
            const uintptr_t FMODPlaybackDSPReleaseFmodDspResult=REBASE(0x28914BB);
            const uintptr_t FmodAudioDeviceSetInputDeviceDeviceIndex=REBASE(0x28A11C0);
            const uintptr_t FmodManagerInitializeOnce=REBASE(0x28873B0);
            const uintptr_t FmodRecordingStopDriver=REBASE(0x28B7140);
            const uintptr_t LegacySoundEffectImplOnOpenFmod=REBASE(0x45DCE20);
            const uintptr_t LegacySoundEffectImplSynchronizeParentDS=REBASE(0x45DD2C0);
            const uintptr_t LegacySoundGroupImplOnAncestorChangedCha=REBASE(0x45E3BD0);
            const uintptr_t LegacySoundImplLoadSoundWithContextCould=REBASE(0x45D3CE0);
            const uintptr_t LegacySoundImplOnChildAddedFmodChannel=REBASE(0x45D1B00);
            const uintptr_t LegacySoundImplOnChildRemovedFmodChannel=REBASE(0x45D1C50);
            const uintptr_t LegacySoundImplOnClosingFmodFmodChannel=REBASE(0x45D2250);
            const uintptr_t LegacySoundImplOnOpenFmodFmodChannel=REBASE(0x45D2130);
            const uintptr_t LegacySoundImplOnServiceProviderNewProvi=REBASE(0x45D1DA0);
            const uintptr_t LegacySoundImplSetSuccessfullyLoadedSoun=REBASE(0x45D2FA0);
            const uintptr_t NBFSLFmodCallbackReturningDmSoundResult=REBASE(0x28A5A30);
            const uintptr_t NonBlockingFmodSoundLoader=REBASE(0x28A5FE0);
            const uintptr_t NonBlockingFmodSoundLoaderCreatedFromDis=REBASE(0x28A6D80);
            const uintptr_t NonBlockingFmodSoundLoaderCreatedFromMem=REBASE(0x28A66A0);
            const uintptr_t ShimSoundEffectImplSynchronizeParentDSPs=REBASE(0x45DF4C0);
            const uintptr_t SoundReleaseFmodSound=REBASE(0x28B54C0);
            const uintptr_t SoundServiceMuteAllChannelsMute=REBASE(0x4547450);
            const uintptr_t SoundServiceOnServiceProvider=REBASE(0x4540C70);
            const uintptr_t SoundServiceOpenFmod=REBASE(0x453A540);
            const uintptr_t SoundServiceSetAmbientReverb=REBASE(0x453F840);
            const uintptr_t SoundServiceSetVolumetricMode=REBASE(0x453F9D0);
        }
        namespace SpatialFilterSanity
        {
            const uintptr_t ServerSpatialFilterReturningAssemblySimS=REBASE(0x14B6FC0);
            const uintptr_t SpatialFilterFilteringIncorrectAssemblyF=REBASE(0x14B7F70);
        }
        namespace SpeechToText
        {
            const uintptr_t ReceivedResponse=REBASE(0x5BEA420);
            const uintptr_t SpeechTextWonTWorkIf=REBASE(0x5BEBA20);
            const uintptr_t SpeechToTextRequestFailed=REBASE(0x5BE9D50);
        }
        namespace SpeechToTextServiceLog
        {
            const uintptr_t SoundServiceRequestSttPlatformTokenSent=REBASE(0x4553F80);
            const uintptr_t SoundServiceSttPlatformTokenReceivedTtl=REBASE(0x4553D00);
        }
        namespace SseClient
        {
            const uintptr_t SseClientFrameBufferExceededCapAborting=REBASE(0x2C9BDF0);
            const uintptr_t SseClientSendCompletionDroppedCallerDid=REBASE(0x2C9BB40);
            const uintptr_t SseClientStreamingChunkDroppedCallerDid=REBASE(0x2C9B910);
        }
        namespace StartupController
        {
            const uintptr_t BrowserTrackerIdRequestAppStorageGetItem=REBASE(0x4D5B5D0);
            const uintptr_t BrowserTrackerIdRequestBrowserTrackerIdR=REBASE(0x4D5AF70);
            const uintptr_t BrowserTrackerIdRequestCookieDoesExistUs=REBASE(0x4D59DB0);
            const uintptr_t BrowserTrackerIdRequestDestructor=REBASE(0x4D59A90);
            const uintptr_t BrowserTrackerIdTaskDestructor=REBASE(0x4D0B100);
            const uintptr_t BrowserTrackerIdTaskRequestFailedError=REBASE(0x4D0B420);
            const uintptr_t BrowserTrackerIdTaskWebBrowserTrackerIdL=REBASE(0x4D0B1E0);
            const uintptr_t CheckAppVersionRequestCallbackErrorStatu=REBASE(0x4D5DB40);
            const uintptr_t CheckAppVersionRequestDestructor=REBASE(0x4CFB540);
            const uintptr_t CheckAppVersionRequestLoadAsyncURL=REBASE(0x4D5D3D0);
            const uintptr_t CheckAppVersionTaskDestructor=REBASE(0x4D0BE40);
            const uintptr_t CheckAppVersionTaskGotUpgradeStatus=REBASE(0x4D0BC80);
            const uintptr_t CheckAppVersionTaskStart=REBASE(0x4D0BA70);
            const uintptr_t DeferredRbxmResolvedVariantFirstEnrollme=REBASE(0x4D5CE10);
            const uintptr_t DeferredRbxmRestoredPersistedVariant=REBASE(0x4D5CA60);
            const uintptr_t DeviceInitTaskGroupDestructor=REBASE(0x4D0C6C0);
            const uintptr_t DeviceInitTaskGroupDoAllTasksComplete=REBASE(0x4D0CE80);
            const uintptr_t DeviceInitTaskGroupFetchingUserLayers=REBASE(0x4D0B600);
            const uintptr_t DeviceInitTaskGroupWebBrowserTrackerIdLl=REBASE(0x4D0C7A0);
            const uintptr_t LaunchOriginEligiblePrefetchingSkipping=REBASE(0x4D0C0B0);
            const uintptr_t PerformDeviceInitSettingBtidPriorDeviceI=REBASE(0x4CF74A0);
            const uintptr_t PlatformNativeAdsProtocolInitialized=REBASE(0x4CF6000);
            const uintptr_t PrefetchAppContentTaskDestructor=REBASE(0x4D0C450);
            const uintptr_t ReportAnalyticsAppQuit=REBASE(0x4CF8ED0);
            const uintptr_t ReportAnalyticsDeviceInfoSubmitTaskColle=REBASE(0x4CF7240);
            const uintptr_t StartupControllerInitializationMustProgr=REBASE(0x4CF6E10);
            const uintptr_t StartupControllerSetBrowserTrackerIdCall=REBASE(0x51B3010);
            const uintptr_t StartupControllerStartupController=REBASE(0x4CF5CB0);
        }
        namespace StatusFileManagerLogV2
        {
            const uintptr_t InvalidInstallerStatus=REBASE(0x5119E30);
        }
        namespace StratusSession
        {
            const uintptr_t ActivateOnGameLoadingComplete=REBASE(0x3CDE2E0);
            const uintptr_t ControlAudioDeviceSelectionCallbackSet=REBASE(0x3CE2EE0);
            const uintptr_t InputCaptureSetUpWithoutCallback=REBASE(0x3CE43F0);
            const uintptr_t InputCaptureTornDown=REBASE(0x3CE50F0);
            const uintptr_t PopUdpProbeCachedReportMalformedSkipping=REBASE(0x3CDB7B0);
            const uintptr_t PopUdpProbeProbeDataCachedYetSkipping=REBASE(0x3CDF6C0);
            const uintptr_t PreActivateStratusSessionId=REBASE(0x3CDDD80);
            const uintptr_t RequestingFrameRateChangeFps=REBASE(0x3CE6790);
            const uintptr_t ResolutionDisplayDpXRenderViewX=REBASE(0x3CDCEC0);
        }
        namespace StratusSessionHistory
        {
            const uintptr_t DeserializeFailed=REBASE(0x3D2A5D0);
        }
        namespace StratusWebView
        {
            const uintptr_t UnrecognizedWebviewMessageType=REBASE(0x5168440);
            const uintptr_t WebViewBridgeActivated=REBASE(0x51666F0);
            const uintptr_t WebViewMessageMissingUrl=REBASE(0x5165E20);
        }
        namespace StreamMRF
        {
            const uintptr_t ReceivedTemporaryReplicationFocusRequest=REBASE(0x467A090);
            const uintptr_t ReplicationFocusAddedCenter=REBASE(0x4679F00);
            const uintptr_t ReplicationFocusAddedPart=REBASE(0x4679820);
            const uintptr_t ReplicationFocusRemovedCenter=REBASE(0x467A350);
            const uintptr_t ReplicationFocusRemovedPart=REBASE(0x4679C50);
            const uintptr_t ServerReplicationFocusRemoval=REBASE(0x48694BB);
            const uintptr_t ServerReplicationFocusRequestFocusIdComp=REBASE(0x474B2C0);
            const uintptr_t ServerReplicationFrustumFocusRequest=REBASE(0x474B420);
            const uintptr_t StreamMRFRequestsDeferredNotifyFocusIdCo=REBASE(0x4680FB0);
        }
        namespace StreamPrefetch
        {
            const uintptr_t ProtectPrefetch=REBASE(0x47BD430);
            const uintptr_t ReleasePrefetchRemainingCellsZu=REBASE(0x47CB1B0);
            const uintptr_t ServerPrefetchRequest=REBASE(0x4868C89);
            const uintptr_t ValidatePrefetch=REBASE(0x47C1A40);
        }
        namespace StreamingObserverDetailed
        {
            const uintptr_t SkippingDisconnectCompactionReplicatorSi=REBASE(0x4865740);
            const uintptr_t SkippingSubscriptionAccessReplicatorIdxS=REBASE(0x4862570);
            const uintptr_t StepResizeJobCapThresholdReps=REBASE(0x4862230);
        }
        namespace Styling
        {
            const uintptr_t FailedDeserializeStyleRulePropertyTransi=REBASE(0x612A680);
            const uintptr_t FailedSerializeStyleRulePropertyTransiti=REBASE(0x612A500);
        }
        namespace StylingPropertiesPanel
        {
            const uintptr_t SettingStyleRuleOverrideInstanceFailedEx=REBASE(0x612A1B0);
        }
        namespace SubscriptionDataParsing
        {
            const uintptr_t FailedParseAvailableSubscriptionProducts=REBASE(0x1213C60);
            const uintptr_t FailedParseLocalizedPriceNonObject=REBASE(0x1210B20);
            const uintptr_t FailedParseProductKeyNonObject=REBASE(0x1210750);
            const uintptr_t FailedParseSubscriptionProductOffersNon=REBASE(0x1212650);
            const uintptr_t FailedParseSubscriptionProductTypeDetail=REBASE(0x1212F50);
            const uintptr_t FailedParseVirtualTransactionDiscountsNo=REBASE(0x1210EA0);
        }
        namespace SubscriptionPurchase
        {
            const uintptr_t CheckingWhetherPlayerHasRobloxSubscripti=REBASE(0x121DDB0);
            const uintptr_t HandlingCheckPlayerHasRobloxSubscription=REBASE(0x121D937);
            const uintptr_t HandlingConfirmPlayerHasRobloxSubscripti=REBASE(0x121DB70);
            const uintptr_t PerformSubscriptionPurchaseV3AsyncFailur=REBASE(0x121B360);
            const uintptr_t PerformSubscriptionPurchaseV3AsyncStartP=REBASE(0x121A250);
            const uintptr_t StoredPromptFinishedTimestampPendingRobu=REBASE(0x121EE10);
            const uintptr_t UserMetPromptFinishedSubscriptionChanged=REBASE(0x1220E00);
        }
        namespace SubscriptionPurchaseCallback
        {
            const uintptr_t MarketplaceServiceWasDeallocated=REBASE(0x122CCD0);
            const uintptr_t PerformSubscriptionPurchaseV3AsyncFailed=REBASE(0x122CBE0);
        }
        namespace SurfaceController
        {
            const uintptr_t DataModelWasNullDuringSurfaceController=REBASE(0x14575D0);
            const uintptr_t ModeFailed=REBASE(0x611CFD0);
            const uintptr_t RenderViewNULL=REBASE(0x14593C0);
            const uintptr_t ReplaceDataModelStageWindowTid08x=REBASE(0x1458930);
            const uintptr_t SurfaceControllerInitialize=REBASE(0x1456CE0);
            const uintptr_t SurfaceControllerPauseRenderJobWasNull=REBASE(0x1457BE0);
            const uintptr_t SurfaceControllerRenderJobScheduleRender=REBASE(0x1454A10);
            const uintptr_t SurfaceControllerRenderJobStepDataModelJ=REBASE(0x14552E0);
            const uintptr_t SurfaceControllerResumeDataModel=REBASE(0x1457FD0);
            const uintptr_t SurfaceControllerSetStartupThrottlePreRe=REBASE(0x1453D60);
            const uintptr_t SurfaceControllerSetStartupThrottleRende=REBASE(0x1458D60);
            const uintptr_t SurfaceControllerStartDataModel=REBASE(0x1456FB0);
            const uintptr_t SurfaceControllerUpdate=REBASE(0x1458370);
        }
        namespace SurfaceControllerDebug
        {
            const uintptr_t DrainRenderingJobsRemoveAllRenderingJobs=REBASE(0x1459B10);
            const uintptr_t SurfaceControllerStop=REBASE(0x1458590);
        }
        namespace SystemDialogHandler
        {
            const uintptr_t AnotherDialogAlreadyActiveFirstCancel=REBASE(0x5CE72D0);
            const uintptr_t DismissAllAvailableCurrentPlatform=REBASE(0x5CE6590);
            const uintptr_t DismissAvailableCurrentPlatform=REBASE(0x5CE6490);
            const uintptr_t DismissBlockingDialog=REBASE(0x5CE6DA0);
            const uintptr_t HandlerCallDismiss=REBASE(0x5CE7600);
            const uintptr_t HandlerCallDismissAll=REBASE(0x5CE7770);
            const uintptr_t OpenAvailableCurrentPlatform=REBASE(0x5CE6390);
            const uintptr_t PlatformHandlerWasDestroyed=REBASE(0x5CE71B0);
            const uintptr_t PlatformHandlerWasInstanced=REBASE(0x5CE7900);
        }
        namespace SystemUtil
        {
            const uintptr_t ErrorAllocationFailure=REBASE(0x2A8D3AC);
            const uintptr_t GetLogicalProcessorInformationSupported=REBASE(0x2A8D020);
        }
        namespace Systray
        {
            const uintptr_t AutoStartupDisabled=REBASE(0x798AF0);
            const uintptr_t CannotPostNotificationAPINotificationId=REBASE(0x78D7B0);
            const uintptr_t ChannelDidChangeStillBound=REBASE(0x79A380);
            const uintptr_t CheckForUpdateTimerFired=REBASE(0x79A1C0);
            const uintptr_t ErrorInitializingWinToastInstanceError=REBASE(0x78CF30);
            const uintptr_t ErrorShowingNotificationToast=REBASE(0x78D2C0);
            const uintptr_t FailedCreateSystemTrayContextMenu=REBASE(0x79C740);
            const uintptr_t FailedFetchConnectionsCount=REBASE(0x79E4D0);
            const uintptr_t FailedFetchNotificationCount=REBASE(0x791970);
            const uintptr_t FailedFetchThumbnail=REBASE(0x78E440);
            const uintptr_t FailedLoadBuilderSansFont=REBASE(0x78BFA0);
            const uintptr_t FailedShowDesktopNotification=REBASE(0x78CD20);
            const uintptr_t IgnoringDesktopNotificationBecauseAppAct=REBASE(0x78F9F0);
            const uintptr_t MainThreadReceivedActivateMainWindow=REBASE(0x796A10);
            const uintptr_t NewVersionAvailableCurrentVersionChannel=REBASE(0x79B1A0);
            const uintptr_t NotificationHasThumbnail=REBASE(0x78E1A0);
            const uintptr_t SetAutoStartRegistryFailed=REBASE(0x7984F0);
            const uintptr_t SetPriorityClassIDLEPRIORITYCLASSFailed=REBASE(0x794280);
            const uintptr_t SetPriorityClassNORMALPRIORITYCLASSFaile=REBASE(0x794890);
            const uintptr_t ShellNotifyIconWFailed=REBASE(0x7A02B0);
            const uintptr_t ShellNotifyIconWNIMMODIFYFailed=REBASE(0x7A0E30);
            const uintptr_t ShowWarmStartInfoNIMMODIFYFailed=REBASE(0x7A0870);
            const uintptr_t StartingBackgroundUpdateTimers=REBASE(0x799CE0);
            const uintptr_t StartingSignalRConnectionBecauseUserId=REBASE(0x606E2D0);
            const uintptr_t StoppingAllBackgroundUpdateTimers=REBASE(0x799360);
            const uintptr_t SuccessfullyLaunchedNewProcessSystrayMod=REBASE(0x797AD0);
            const uintptr_t SuccessfullySentNotificationApiPath=REBASE(0x78F140);
            const uintptr_t SystrayCheckInternetFail=REBASE(0x79B9A0);
            const uintptr_t SystrayInitializedAsyncMode=REBASE(0x7963F0);
            const uintptr_t SystrayMenuItemAvatarClicked=REBASE(0x79ED30);
            const uintptr_t SystrayMenuItemChartsClicked=REBASE(0x79EB10);
            const uintptr_t SystrayMenuItemConnectionsClicked=REBASE(0x79F390);
            const uintptr_t SystrayMenuItemExitClicked=REBASE(0x79D8D0);
            const uintptr_t SystrayMenuItemHomeClicked=REBASE(0x79E8F0);
            const uintptr_t SystrayMenuItemNotificationsClicked=REBASE(0x79F170);
            const uintptr_t SystrayMenuItemPartyClicked=REBASE(0x79EF50);
            const uintptr_t SystrayThreadProcError=REBASE(0x606E7F0);
            const uintptr_t TrayEmptyWhenRemovingIcon=REBASE(0x7982C0);
            const uintptr_t TrayEmptyWhenShowingIcon=REBASE(0x798080);
            const uintptr_t UnsupportedActionType=REBASE(0x78C4D0);
            const uintptr_t UserExitAppStayTrayMode=REBASE(0x795270);
            const uintptr_t UserOpenMainWindowStayTray=REBASE(0x794C60);
        }
        namespace TDigest
        {
            const uintptr_t QuantilesMustSortedIncreasingOrder=REBASE(0x2A9BF80);
            const uintptr_t SpecifiedBufferSizeTooSmall=REBASE(0x2A9B410);
            const uintptr_t TryingAddNaNInfTDigest=REBASE(0x2A9BD60);
        }
        namespace TabTipKeyboard
        {
            const uintptr_t FailedGetProgramFilesKnownFolder=REBASE(0x78ABA0);
            const uintptr_t FailedStartTabTip=REBASE(0x78A9E0);
            const uintptr_t FoundTabTipWindowButCouldPost=REBASE(0x7884A0);
        }
        namespace TaskSchedulerInit
        {
            const uintptr_t JobCreatedArbiter=REBASE(0x2A2A6F0);
            const uintptr_t JobDestroyed=REBASE(0x2A2ACF0);
        }
        namespace TaskSchedulerRun
        {
            const uintptr_t JobStartArbiterTime=REBASE(0x2A31060);
        }
        namespace TeamCreateServerScriptChanges
        {
            const uintptr_t UIDLldScriptBeingSetDefault=REBASE(0x46D8EE0);
        }
        namespace TelemetryBatchManager
        {
            const uintptr_t BatchManagerCanRequestBeQueuedMaxRetryAt=REBASE(0x2EA2650);
            const uintptr_t BatchManagerErasePendingRequestPendingRe=REBASE(0x2EA0860);
            const uintptr_t BatchManagerFreeRetrySlotConcurrentRetri=REBASE(0x2EA21F0);
            const uintptr_t BatchManagerGetPendingRequestRequestFoun=REBASE(0x2EA0CD0);
            const uintptr_t BatchManagerHttpCallbackCalledErrStatusC=REBASE(0x2EA1180);
            const uintptr_t BatchManagerReportSendResultToUserCallba=REBASE(0x2EA1B80);
            const uintptr_t BatchManagerRetryRequestRetryingRequest=REBASE(0x2EA2ED0);
            const uintptr_t BatchManagerRetryRequestShuttingDownRetr=REBASE(0x2EA2840);
            const uintptr_t BatchManagerShouldRetryRequestErrStatusC=REBASE(0x2EA2400);
            const uintptr_t ExceptionReportingEvent=REBASE(0x618D300);
            const uintptr_t ExceptionReportingEventIngestEvent=REBASE(0x618D170);
            const uintptr_t ExceptionReportingV2CounterStat=REBASE(0x618D400);
            const uintptr_t ExceptionReportingV2Point=REBASE(0x618D590);
            const uintptr_t ExceptionShutdown=REBASE(0x618DAA0);
            const uintptr_t FlushingAllTelemetryBatches=REBASE(0x2E9FF30);
            const uintptr_t TryCutAndSendBatchBatchCutUnsuccessfulTi=REBASE(0x2E9EBE0);
        }
        namespace TelemetryProtocol
        {
            const uintptr_t CLogEventFromLuaEventType=REBASE(0x51A2D10);
            const uintptr_t SendingRobloxTelemetryEphemeralCounterEv=REBASE(0x51A0010);
            const uintptr_t SendingRobloxTelemetryEphemeralStatEvent=REBASE(0x51A04E0);
        }
        namespace TelemetryReliabilityCounters
        {
            const uintptr_t AtomicBoolGuardingWriteBeforeRead=REBASE(0x2EBF140);
            const uintptr_t TriedWriteReliabilityCountersBeforeReadi=REBASE(0x2EC01E0);
            const uintptr_t UnderscoreWasFoundEventName=REBASE(0x2EBDFA0);
        }
        namespace TelemetryService
        {
            const uintptr_t LegacyOverrideTargetForEventIngestFieldO=REBASE(0x4EB9120);
        }
        namespace Teleport
        {
            const uintptr_t AttemptingFallbackTeleportPlaceAfterTele=REBASE(0x34ABD20);
            const uintptr_t FailedFetchStarterPlaceIdGamejoin=REBASE(0x34AB120);
            const uintptr_t FailedFindJoinDataKey=REBASE(0x34430F0);
            const uintptr_t FallbackTeleportPlaceFailed=REBASE(0x34AAEA0);
            const uintptr_t GroupTeleportAnalyticsDataModelNull=REBASE(0x343D580);
            const uintptr_t GroupTeleportAnalyticsRemovedParty=REBASE(0x343CDE0);
            const uintptr_t GroupTeleportAnalyticsStartTimeError=REBASE(0x343D050);
            const uintptr_t GuidMissingCannotRecordGroupTeleport=REBASE(0x343C820);
            const uintptr_t OnUserJoinCorruptedAuthToken=REBASE(0x343BB70);
            const uintptr_t PlayTestTeleportDestinationLookupFailed=REBASE(0x450F6F0);
            const uintptr_t ReservedServerResultsNull=REBASE(0x4500620);
            const uintptr_t TeleportCompletedLldMs=REBASE(0x3438B40);
            const uintptr_t TeleportPlayersNull=REBASE(0x44FE0A0);
            const uintptr_t TeleportServicePromptExperienceDetailsCo=REBASE(0x3441950);
        }
        namespace TestCaseAssertions
        {
            const uintptr_t CheckOperandShownTypeVariantConversion=REBASE(0x61A1490);
            const uintptr_t TestCaseCheckIgnoredTestCurrentlyExecuti=REBASE(0x3044CF0);
            const uintptr_t TestCaseRequireIgnoredTestCurrentlyExecu=REBASE(0x3045030);
        }
        namespace TestServiceConnectionManager
        {
            const uintptr_t AutoReconnecting=REBASE(0x35A90A0);
            const uintptr_t CaughtExceptionWhileDestroyingTestServic=REBASE(0x61C4360);
            const uintptr_t CaughtExceptionWhileDisconnectingWebSock=REBASE(0x61C4440);
            const uintptr_t DataModelExpiredWhileCreatingWebSocketCl=REBASE(0x35A8540);
            const uintptr_t HandlerRegisteredMessageType=REBASE(0x35A9330);
            const uintptr_t OutboundEncodeFailedIgnoredMessageType=REBASE(0x35AA0D0);
            const uintptr_t OutboxFullMsgsDroppingOutboundType=REBASE(0x35ABD90);
            const uintptr_t ProtoToJsonFailedMessageType=REBASE(0x35A7C40);
            const uintptr_t SendHandshakeExecutionId=REBASE(0x35ACBF0);
            const uintptr_t TimerServiceUnavailableCannotScheduleRec=REBASE(0x35A9B60);
            const uintptr_t VideoBinaryTransferAbortedChunk=REBASE(0x35AD870);
            const uintptr_t WebSocketAlreadyOpenConnectCaughtRace=REBASE(0x35A96E0);
            const uintptr_t WebSocketOpened=REBASE(0x35AE6C0);
        }
        namespace TestServiceLog
        {
            const uintptr_t CaptureScreenshotCompleteRequestIdArtifa=REBASE(0x3491140);
            const uintptr_t CaptureScreenshotDeterministicRequestIdA=REBASE(0x34921A0);
            const uintptr_t FailedEnqueueResultOutboxFullLauncher=REBASE(0x3483BC0);
            const uintptr_t FailedEnqueueTestRunSummarySerializableO=REBASE(0x348E410);
            const uintptr_t FailedEnqueueTestsListOutboxFull=REBASE(0x348DDD0);
            const uintptr_t FailedSendPONGResponsePING=REBASE(0x34A3800);
            const uintptr_t FetchTestControlsPendingCallbackRequestI=REBASE(0x3490BB0);
            const uintptr_t FetchTestControlsStoredPendingRequestReq=REBASE(0x349A710);
            const uintptr_t FetchTestControlsUnsupportedValueTypeKey=REBASE(0x349B580);
            const uintptr_t HandshakeAckProtoParseErrorPayloadPrefix=REBASE(0x34902F0);
            const uintptr_t InitConnectionManagerHasManagerUriIsStud=REBASE(0x348F700);
            const uintptr_t InstallInboundHandlersConnectionManager=REBASE(0x348FC50);
            const uintptr_t LegacyUTSTestFoundSuiteTestCase=REBASE(0x348D3B0);
            const uintptr_t Log=REBASE(0x347F2F0);
            const uintptr_t OnServiceProviderDmWsOptInIsStudioIsServ=REBASE(0x348EA40);
            const uintptr_t OnTestCaseEndConnectionManagerSkippingSe=REBASE(0x3489F10);
            const uintptr_t RequestValidationSTOREDCallbackRequestId=REBASE(0x3497030);
            const uintptr_t RequestValidationUsingDeprecatedValidati=REBASE(0x3497CD0);
            const uintptr_t SignalProfilingCaptureConnectionManagerS=REBASE(0x3499C10);
            const uintptr_t SignalProfilingStartConnectionManagerSki=REBASE(0x34998E0);
            const uintptr_t TestCaseTimedOutAfterSeconds=REBASE(0x3485710);
            const uintptr_t TestServiceTakeSnapshotCalledButDataMode=REBASE(0x3485A00);
            const uintptr_t ValidationResultMessageReceivedConnectio=REBASE(0x34906D0);
            const uintptr_t WSConnectedAwaitingHandshakeAck=REBASE(0x34A3630);
            const uintptr_t WSDisconnected=REBASE(0x34A3700);
            const uintptr_t WSEndSessionMessageReceivedClosing=REBASE(0x34A3930);
            const uintptr_t WSImageSendSkippedWSConnection=REBASE(0x34A2BB0);
        }
        namespace Text
        {
            const uintptr_t ERRORFailedMapFontFile=REBASE(0x1635E80);
            const uintptr_t FoundMatchWhileTryingAddFont=REBASE(0x1627A40);
            const uintptr_t InitializedTextEngineModuleMs=REBASE(0x161D8F0);
            const uintptr_t LayoutNonrichText=REBASE(0x160E6F0);
            const uintptr_t LayoutRichText=REBASE(0x160D5B0);
            const uintptr_t LoadingFaceFailed=REBASE(0x1629C00);
            const uintptr_t RegisteredFamilyFacesSetLoaded=REBASE(0x162A2C0);
            const uintptr_t RichTextTypesetterLayoutThisLineStartIdx=REBASE(0x160CFE0);
            const uintptr_t SetFaceWaiting=REBASE(0x162E9E0);
            const uintptr_t SetFamilyWaiting=REBASE(0x1627C80);
            const uintptr_t UsingFontSubsystem=REBASE(0x161CD10);
        }
        namespace TextChannelWindow
        {
            const uintptr_t CheckProtectedChatEnabledDebugModeForced=REBASE(0x4B4DA00);
            const uintptr_t UpdateProtectedChatCachePhaseEnabled=REBASE(0x4B4D770);
        }
        namespace TextChatFiltering
        {
            const uintptr_t ChatEnableButtonClicked=REBASE(0x4B15D10);
            const uintptr_t ChatEnableButtonShown=REBASE(0x4B15B30);
            const uintptr_t ErrorOccurredRephraseSettingAvailable=REBASE(0x4B35550);
            const uintptr_t ExpectedTextFilterTranslatedResultInstan=REBASE(0x4B27C70);
            const uintptr_t FailedParseFilterResult=REBASE(0x4B46A90);
            const uintptr_t OnUserChatSettingUpdateHTTPErrorStatusFe=REBASE(0x4B49CA0);
            const uintptr_t ParseGetActionsResponseJSONParseFailed=REBASE(0x4B3CC20);
            const uintptr_t PlayersServiceFound=REBASE(0x4B3D6E0);
            const uintptr_t SendUniverseChatPresetAsyncFiringSending=REBASE(0x4B43BE0);
            const uintptr_t ServerReceivedUniverseChatPresetV2=REBASE(0x4B337F0);
            const uintptr_t SkippingTextChannelHistoryEntry=REBASE(0x4B54C70);
        }
        namespace TextChatSummary
        {
            const uintptr_t MakeGetActionsRequestFailedParseResponse=REBASE(0x4B70240);
            const uintptr_t MakeGetActionsRequestSubmitTaskTextChatS=REBASE(0x4B70890);
            const uintptr_t TextChannelPollingTextChannelUnderTextCh=REBASE(0x4B6EC50);
        }
        namespace TextSafetyAnalyticsSender
        {
            const uintptr_t TextSafetyAnalyticsSenderAddingEntryBatc=REBASE(0x1354D30);
            const uintptr_t TextSafetyAnalyticsSenderDispatchingBatc=REBASE(0x1354B80);
            const uintptr_t TextSafetyAnalyticsSenderSentServer=REBASE(0x1355330);
        }
        namespace TextToSpeech
        {
            const uintptr_t MakePlatformPreviewRequestBodyInvalidVoi=REBASE(0x5BB4C10);
            const uintptr_t SoundServiceLoadTextCallbackLengthZero=REBASE(0x5BB3420);
            const uintptr_t SoundServiceLoadTextRequest=REBASE(0x5BB4420);
            const uintptr_t SoundServiceLoadTextRequestFailed=REBASE(0x5BB3240);
            const uintptr_t TTSOpenCloudGeneratingSpeechAssetUrl=REBASE(0x5BB8090);
            const uintptr_t TTSOpenCloudRequestFailedHTTPBody=REBASE(0x5BB8990);
            const uintptr_t TTSPublishGenerateAudioAssetFailedHTTP=REBASE(0x5BB9E60);
            const uintptr_t TTSPublishGeneratingAudioAssetUrl=REBASE(0x5BB9470);
            const uintptr_t TTSPublishGenerationFailedErrHTTPMsg=REBASE(0x5BB79E0);
            const uintptr_t TTSPublishUploadResponseMissingId=REBASE(0x5BB6F00);
            const uintptr_t TTSPublishUploadingAsset=REBASE(0x5BB67E0);
            const uintptr_t TTSPublishUsingCachedAudioSkippingGenera=REBASE(0x5BB6110);
        }
        namespace TextureCageProjection
        {
            const uintptr_t TextureCageProjectionFailed=REBASE(0x1B34AD0);
        }
        namespace TextureManager2
        {
            const uintptr_t BaselineFetchKeyStoreKey=REBASE(0x3906830);
            const uintptr_t ImageDimensionsXFormatScaledX=REBASE(0x37373F0);
            const uintptr_t ImageFailedLoad=REBASE(0x3737860);
            const uintptr_t ItemOnEraseItemIdFetchKeyStoreKey=REBASE(0x371F930);
            const uintptr_t JoiningButJustDetachingAsyncRequests=REBASE(0x3904BF0);
            const uintptr_t NewManagedTexturePriorityItemIdFetchKeyS=REBASE(0x3706D00);
            const uintptr_t ProcessPendingImagesImageLoadedFetchKeyS=REBASE(0x370EBD0);
            const uintptr_t StartAsyncLoadFailedFetchKeyStoreKey=REBASE(0x3707C70);
            const uintptr_t TPFailedRetryFetchkeyStoreKey=REBASE(0x3712340);
            const uintptr_t TextureManager2Constructed=REBASE(0x370B400);
            const uintptr_t TextureManager2Destroyed=REBASE(0x370C1B0);
            const uintptr_t TextureManager2TpUtilPendingTexturePackC=REBASE(0x373C540);
            const uintptr_t TexturePackFetching=REBASE(0x3739D70);
            const uintptr_t TexturePackImageLoaded=REBASE(0x373A800);
        }
        namespace TextureManager2Priority
        {
            const uintptr_t BindMeshCreateMaterialPriorityKey=REBASE(0x381C920);
            const uintptr_t StartAsyncLoadPriorityIdTypeFetchKeyStor=REBASE(0x39072D0);
        }
        namespace TextureManager2Residency
        {
            const uintptr_t LoadingFinishedBytesFreedDeferredFetchKe=REBASE(0x370AFE8);
            const uintptr_t LoadingStartedBytesItemidFetchKeyStoreKe=REBASE(0x370AD40);
            const uintptr_t SetResidencyResMinMipReqMinMipPriorityFe=REBASE(0x3705BF0);
        }
        namespace ThirdPartyUserService
        {
            const uintptr_t DefaultLocaleIdObtainedLocalizationServi=REBASE(0x3B61270);
            const uintptr_t DefaultingEmptyString=REBASE(0x3B619D0);
            const uintptr_t GetHasActiveUserAndSyncValueTrueSyncingB=REBASE(0x3B60BD0);
            const uintptr_t GetTextChatRestrictionStatusUsingPlatfor=REBASE(0x3B620D0);
            const uintptr_t GetVoiceChatRestrictionStatusFromImpleme=REBASE(0x3B628E0);
            const uintptr_t HaveActiveUserTrueNeedSync=REBASE(0x3B61BF0);
            const uintptr_t IsAccountSwitchingSupportedUsingPlatform=REBASE(0x3B626E0);
            const uintptr_t IsChatRestrictionSupportedUsingPlatformA=REBASE(0x3B622E0);
            const uintptr_t IsSingleSignOnSupportedUsingPlatformAPIS=REBASE(0x3B624E0);
            const uintptr_t SetHasActiveUserAndSyncSyncingAppStorage=REBASE(0x3B60E30);
            const uintptr_t ShowAccountPicker=REBASE(0x3B61F10);
            const uintptr_t SyncingAppStorageSupplantingUserInfoDue=REBASE(0x3B5FB30);
        }
        namespace ThumbnailPlayerCharacterLoadingLog
        {
            const uintptr_t ApplyCharacterAppearanceAssetsFinishedEq=REBASE(0x3E0B030);
            const uintptr_t FinishCharacterLoadingComplete=REBASE(0x3E07A60);
            const uintptr_t LoadCharacterAppearanceAssetsCollectAsse=REBASE(0x3E18940);
            const uintptr_t UnexpectedErrorAssetDownload=REBASE(0x3E06590);
        }
        namespace ThumbnailRender
        {
            const uintptr_t AfterRenderProvidersRequestsEmptyContent=REBASE(0x36602D0);
            const uintptr_t BestEffortRenderLoadTimedOut=REBASE(0x365F2E0);
        }
        namespace ThumbnailVideoStreamTrace
        {
            const uintptr_t Close=REBASE(0xFFB8D0);
            const uintptr_t ConnectToServiceServiceProvider=REBASE(0xFFD160);
            const uintptr_t ConnectToServiceVideoService=REBASE(0xFFD2C2);
            const uintptr_t Ctor=REBASE(0xFFA500);
            const uintptr_t DisconnectFromServiceServiceProvider=REBASE(0xFFD570);
            const uintptr_t Dtor=REBASE(0xFFA8D0);
            const uintptr_t OnHeartBeatVideoService=REBASE(0xFFAD47);
            const uintptr_t OnServiceProvider=REBASE(0x108A350);
            const uintptr_t Open=REBASE(0xFFAFE0);
            const uintptr_t Pause=REBASE(0xFFC5D0);
            const uintptr_t PlayServiceProvider=REBASE(0xFFBAF0);
            const uintptr_t RenderIsVideoTextureUpdatedVideoStreamIs=REBASE(0xFFC9A0);
        }
        namespace TombstoneCache
        {
            const uintptr_t FailedSeekHoldoutByteTombstoneFile=REBASE(0x4528A00);
            const uintptr_t SettingHoldoutExperimentState=REBASE(0x45287E0);
            const uintptr_t TombstoneCheckFailedMinimumValueAllowed=REBASE(0x4527610);
            const uintptr_t TombstoneExpiryTimeHoldoutChannelWritten=REBASE(0x45277D0);
            const uintptr_t UnexpectedHoldoutByteValueOffset8=REBASE(0x4529260);
        }
        namespace Tool
        {
            const uintptr_t ToolSetBackendToolStateCurrentStateNewSt=REBASE(0x302AED0);
        }
        namespace TouchInputServiceGesture
        {
            const uintptr_t PanGestureTranslationVelocityState=REBASE(0x3BF4930);
            const uintptr_t PinchGestureScaleVelocityState=REBASE(0x3BF52E0);
            const uintptr_t RotateGestureRotationVelocityState=REBASE(0x3BF59D0);
            const uintptr_t TapGestureDetectedTouchesFirstTouch=REBASE(0x3BF3EC0);
        }
        namespace TraceDebugLog
        {
            const uintptr_t NetworkTracerAddingCheckpointTracerIdPee=REBASE(0x3AA92F3);
            const uintptr_t NetworkTracerCreationStreamTrackerIdAlre=REBASE(0x3AA86C0);
            const uintptr_t NetworkTracerCreationTrackerNameAlreadyE=REBASE(0x3AA8420);
            const uintptr_t NetworkTracerDeleteTracerNumberTracersLe=REBASE(0x3AA8CF0);
            const uintptr_t NetworkTracerFindingCheckpointTracerId=REBASE(0x3AA9090);
            const uintptr_t NetworkTracerSerializingTracerObjectInpl=REBASE(0x3AA8F80);
            const uintptr_t NetworkTracerTracerExistsId=REBASE(0x3AA943A);
        }
        namespace TrackHttpRequest
        {
            const uintptr_t HttpRequestCurlWsCallingReAbort=REBASE(0x2CB9B90);
            const uintptr_t HttptrackAddResReqAbortedRequests=REBASE(0x2C58320);
            const uintptr_t HttptrackHttpRequest=REBASE(0x2C77470);
            const uintptr_t HttptrackNewPriorityReq=REBASE(0x2C62260);
            const uintptr_t HttptrackWebSocketCurlReq=REBASE(0x2CB6AC0);
            const uintptr_t WstrackWsClient=REBASE(0x2C67230);
        }
        namespace TrackerAnimationStreamSourceTrace
        {
            const uintptr_t Close=REBASE(0x19AC8B0);
        }
        namespace TrackerLodControllerTrace
        {
            const uintptr_t LODProcessingTimeFrameRateRunningVoteLod=REBASE(0x1908930);
        }
        namespace TrackerStreamAnimationTrace
        {
            const uintptr_t OnDisconnect=REBASE(0x16E7A40);
            const uintptr_t SetProducer=REBASE(0x16E76F0);
            const uintptr_t SetStreamSource=REBASE(0x16E7440);
            const uintptr_t Stop=REBASE(0x16E63C0);
        }
        namespace Transcoder
        {
            const uintptr_t HasInvalidPercentage=REBASE(0x49D0870);
        }
        namespace TransitionType
        {
            const uintptr_t TransitionTypeSendingEvent=REBASE(0x4CC6690);
            const uintptr_t TransitionTypeSettingTeleportTarget=REBASE(0x4CC6C50);
        }
        namespace TranslationLocaleIdVerbose
        {
            const uintptr_t ErrorUpdatingLocaleId=REBASE(0x1385F10);
        }
        namespace TtiTelemetryIntegrationCheck
        {
            const uintptr_t ConfirmEventSentErrorCode=REBASE(0x3C665E0);
            const uintptr_t RandomID=REBASE(0x3C65940);
            const uintptr_t TelemetryEventASendErrorCode=REBASE(0x3C65B70);
        }
        namespace UIDragDetectorLog
        {
            const uintptr_t DragDisabledEndingDrag=REBASE(0x461D870);
            const uintptr_t MenuOpenedUIDragDetectorCallingEndDragNo=REBASE(0x4621290);
            const uintptr_t UIDragDetectorAncestryChangedCallingOnCa=REBASE(0x46213D0);
            const uintptr_t UIDragDetectorDestroyedCallingOnCancel=REBASE(0x46215A0);
            const uintptr_t UIDragDetectorDragContinueDraggingReturn=REBASE(0x4615240);
            const uintptr_t UIDragDetectorDragEndEnabledReturningFal=REBASE(0x4617D40);
            const uintptr_t UIDragDetectorDragStartEnabledReturningF=REBASE(0x4614800);
        }
        namespace UIOcclusionMetrics
        {
            const uintptr_t UIOcclusionMetricsRegionStringHasError=REBASE(0x406C850);
        }
        namespace US14116
        {
            const uintptr_t SendingDisplayStatsLld=REBASE(0x3DB6250);
        }
        namespace UgcExperienceController
        {
            const uintptr_t CannotInitializePlayerHostedServerContex=REBASE(0x4D4A9D0);
            const uintptr_t GameShutdownSignalFailedLock=REBASE(0x4D53ED0);
            const uintptr_t GameShutdownSignalSignalToObserversFaile=REBASE(0x4D4C970);
            const uintptr_t PlayerHostedServerContextNullCannot=REBASE(0x4D51AD0);
            const uintptr_t PlayerHostedServerDMNullCannotDestroyed=REBASE(0x4D47EB0);
            const uintptr_t SignalToObserversFailedGetDataModel=REBASE(0x4D521C0);
            const uintptr_t TeamTestTeleportTeleportInfoMissingRequi=REBASE(0x4D498B0);
            const uintptr_t UgcExperienceControllerDoTeleportJoinScr=REBASE(0x4D4EEC0);
            const uintptr_t UgcExperienceControllerExitExperienceSta=REBASE(0x4D53630);
            const uintptr_t UgcExperienceControllerFinalizeDidFinali=REBASE(0x4D4B460);
            const uintptr_t UgcExperienceControllerFinishTeleportWit=REBASE(0x4D4E970);
            const uintptr_t UgcExperienceControllerInitializeDidInit=REBASE(0x4D4AF10);
            const uintptr_t UgcExperienceControllerJoinInitializedDm=REBASE(0x4D4FC50);
            const uintptr_t UgcExperienceControllerSendAnalyticsBefo=REBASE(0x4D493D0);
            const uintptr_t UgcExperienceControllerStartDidStartDueS=REBASE(0x4D4B650);
            const uintptr_t UgcExperienceControllerStopBeginBlocking=REBASE(0x4D4BA00);
            const uintptr_t UgcExperienceControllerSubmitStartGameTa=REBASE(0x4D505D0);
            const uintptr_t UgcExperienceControllerSwitchToExperienc=REBASE(0x4D50C00);
            const uintptr_t UgcExperienceControllerUgcExperienceCont=REBASE(0x4D4A780);
            const uintptr_t UgcExperienceControllerUpdateServerTypeA=REBASE(0x4D48FF0);
        }
        namespace UnexpectedServiceInstanceCountsLog
        {
            const uintptr_t DMIntentStudioServerPlayClient=REBASE(0x351ECF0);
        }
        namespace UniverseChatChannelMonitorLog
        {
            const uintptr_t ExceptionParsingHeartbeatV2Response=REBASE(0x62D0410);
            const uintptr_t HeartbeatV2RegroupedNewChannelGroup=REBASE(0x5D08D10);
            const uintptr_t HeartbeatV2ResultChannelGroupOk=REBASE(0x5D0A3D0);
            const uintptr_t HeartbeatV2ResultChannelGroupReassigned=REBASE(0x5D076C0);
            const uintptr_t ReassignedActionChannelMissingChannelIdT=REBASE(0x5D05730);
            const uintptr_t SendingHeartbeatRequestBody=REBASE(0x5D03A20);
            const uintptr_t StartingUniverseChatChannelMonitor=REBASE(0x4B30440);
            const uintptr_t UniverseChatChannelMonitorPulsePlaceId=REBASE(0x5D01510);
            const uintptr_t UniverseChatMessageManagerAvailableSkipp=REBASE(0x5D01A90);
        }
        namespace UniverseChatMessageManager
        {
            const uintptr_t CSMMessageMissingSenderUserIdMessageId=REBASE(0x4A54530);
            const uintptr_t ExceptionWhileParsingAllocateChannelResp=REBASE(0x6242A50);
            const uintptr_t ExceptionWhileParsingAllocateChannelV2=REBASE(0x6242BA0);
            const uintptr_t ExceptionWhileParsingGetMessagesResponse=REBASE(0x6242DA0);
            const uintptr_t ExceptionWhileParsingIngestMessageRespon=REBASE(0x6242FB0);
            const uintptr_t InvalidPermissionsCheckResponse=REBASE(0x4A57EC0);
            const uintptr_t MakeGetActionsRequestHTTPErrorStatus=REBASE(0x4A575F0);
            const uintptr_t MissingInvalidResultsArrayAllocateChanne=REBASE(0x4A5F670);
            const uintptr_t MissingInvalidResultsArrayGetMessages=REBASE(0x4A65B20);
            const uintptr_t MissingRequiredFieldsIngestMessageResult=REBASE(0x4A6A880);
            const uintptr_t ParsedAllocateChannelResponseUserChannel=REBASE(0x4A5E300);
            const uintptr_t ReassigningChannelChannelTopicNewChannel=REBASE(0x4A618E0);
            const uintptr_t ReassigningGroupChannelTopic=REBASE(0x4A62D00);
        }
        namespace UnreliableItems
        {
            const uintptr_t OversizedUnreliableItemDroppedItemSize=REBASE(0x48B50D0);
            const uintptr_t UnreliableEventReceivedBeforeObjectHas=REBASE(0x48AE690);
        }
        namespace UpdateController
        {
            const uintptr_t CheckingIfUpdaterExistsReturning=REBASE(0x784F40);
            const uintptr_t FailedParseJson=REBASE(0x4EE5C40);
            const uintptr_t NetworkCheckFinishedWhileReadingCache=REBASE(0x4EE37C0);
            const uintptr_t RbxStorageUnavailableCannotBurnUpdateCon=REBASE(0x4EE4CA0);
            const uintptr_t RbxStorageUnavailableCannotReadUpdateCon=REBASE(0x4EE39E0);
            const uintptr_t UnauthorizedAccess401VersionURLExpected=REBASE(0x4EE54F0);
            const uintptr_t UpdateCheckThreadUpdateRequired=REBASE(0x4EE5F20);
            const uintptr_t UpdateControllerVersionQueryUrl=REBASE(0x4EE2EC0);
            const uintptr_t UpdateModeChosenTelemetrySent=REBASE(0x4EE6240);
            const uintptr_t UsingCachedUpdateCheckValues=REBASE(0x4EE5080);
            const uintptr_t WindowsUpdateControllerUpdaterFullPath=REBASE(0x7837E0);
            const uintptr_t WroteUpdateControllerCacheAppStorageJson=REBASE(0x4EE4680);
        }
        namespace UserAgentHelper
        {
            const uintptr_t MainWindowEmptyWebview2Installed=REBASE(0x16BE140);
        }
        namespace UserController
        {
            const uintptr_t UserControllerDidLoginStage=REBASE(0x4D2FE00);
            const uintptr_t UserControllerDidLogoutStage=REBASE(0x4D2FF60);
        }
        namespace UserInputProfile
        {
            const uintptr_t ChangingHumanoidStateOldNew=REBASE(0x1917C80);
            const uintptr_t HandingGUITargetX=REBASE(0x3BD2340);
            const uintptr_t HandingWorkspaceEarlyBecauseEventGrabbed=REBASE(0x3BCEEF0);
            const uintptr_t MovingVelocity10f10f10f=REBASE(0x17E16A1);
            const uintptr_t PassingTouchEndUpProcessingCommand=REBASE(0x3411EB0);
            const uintptr_t SettingLuaMoveDirection10f10f=REBASE(0x17E2870);
            const uintptr_t ToolActivate=REBASE(0x3C09740);
        }
        namespace VCS
        {
            const uintptr_t ErrorAppylingPatch=REBASE(0x5BD4AB0);
        }
        namespace VIPTeleport
        {
            const uintptr_t CalledInitiateTeleportToPrivateServer=REBASE(0x4CD4EB0);
            const uintptr_t CreateTeleportImplValuesAreNull=REBASE(0x3435610);
            const uintptr_t CreateWeWereAbleGetVip=REBASE(0x344FFC0);
            const uintptr_t MadeInsideGameLoadedSignalWithoutTelepor=REBASE(0x344FA50);
            const uintptr_t NewDMAfterGameLoadedSignalConnect=REBASE(0x3444940);
            const uintptr_t ReportTeleportOnGameLoadedGotValuesTelep=REBASE(0x3445370);
            const uintptr_t TeleportDataValueTableData=REBASE(0x3443C60);
        }
        namespace Verbs
        {
            const uintptr_t GuiRenderStats=REBASE(0x402AD10);
        }
        namespace VersionHistory
        {
            const uintptr_t CommitFailureAssetMapingsAvailable=REBASE(0x32383F0);
            const uintptr_t CommitFailureCanTParseJSON=REBASE(0x3236090);
            const uintptr_t CommitFailureCommitGuidProvided=REBASE(0x3237110);
            const uintptr_t CommitFailureHttpTransportError=REBASE(0x32355F0);
            const uintptr_t CommitFailureUnexpectedScriptGuid=REBASE(0x323A110);
            const uintptr_t CommitFailureVersionHistoryCommitCoordin=REBASE(0x3234D40);
            const uintptr_t Int64TConversionFailureValidNumber=REBASE(0x3237730);
        }
        namespace Video
        {
            const uintptr_t CreateFenceFailed0x08xHWColor=REBASE(0x3B15800);
            const uintptr_t CreateVideoProcessorInputViewFailed0x08x=REBASE(0x3B16D30);
            const uintptr_t DXGIAdapterMatchedRendererLUID=REBASE(0x3B007D0);
            const uintptr_t DownloadingDataLoadHttpRequestSucceededI=REBASE(0x5C7AB60);
            const uintptr_t DownloadingDataLoadLoadStateUnloadedStar=REBASE(0x5C79D50);
            const uintptr_t DownloadingDataUnloadAbortingExistingHtt=REBASE(0x5C7B6D0);
            const uintptr_t FailedGetIMFDXGIBufferDXVASample0x=REBASE(0x3B16B30);
            const uintptr_t MFTEnumExFailedFindDecoder=REBASE(0x3B13650);
            const uintptr_t MMFAudioDecoderProcessOutputFailed0x08x=REBASE(0x3B1A060);
            const uintptr_t MMFAudioDecoderSetOutputTypeFailed0x08x=REBASE(0x3B19930);
            const uintptr_t OpusDecodeFailed=REBASE(0x3B1AAF0);
            const uintptr_t OpusDecoderCreationFailed=REBASE(0x3B1C8A0);
            const uintptr_t OpusEncodeFailed=REBASE(0x3B1B790);
            const uintptr_t OpusEncoderCreationFailed=REBASE(0x3B1B300);
            const uintptr_t ProcessOutputFailed0x08x=REBASE(0x3B18260);
            const uintptr_t RawInputFormatCouldParseWAVHeader=REBASE(0x5C54480);
            const uintptr_t RawInputFormatInvalidY4MDimensionsX=REBASE(0x5C54397);
            const uintptr_t RawInputFormatInvalidY4MHeader=REBASE(0x5C54160);
            const uintptr_t RenderFrameWithCustomShaderCreateTexture=REBASE(0x3AF7980);
            const uintptr_t RenderFrameWithFullSoftwareConvertFrameT=REBASE(0x3AF5A80);
            const uintptr_t RenderFrameWithImmutableSamplerCreateTex=REBASE(0x3AF6F40);
            const uintptr_t SizeCmcdVisibilityHeaderTooLarge=REBASE(0x5C45C10);
            const uintptr_t SlewingClockSnapClockDiffUsExceeds250ms=REBASE(0x5C32020);
            const uintptr_t StreamChangeCouldFindMatchingOutput=REBASE(0x3B19210);
            const uintptr_t SubdemuxerReturnedAudioPacketButAudio=REBASE(0x5C6A4B0);
            const uintptr_t Time=REBASE(0x5C42930);
            const uintptr_t TriedIncrementVideoAnalyticsEventDoes=REBASE(0x3B05950);
            const uintptr_t TriedReadNumericValueNonNumeric=REBASE(0x3B07F50);
            const uintptr_t UnexpectedPacketStreamIndexSubDemuxer=REBASE(0x5C66C90);
            const uintptr_t UploadPlaneFailedLockPlane=REBASE(0x3AF6CC0);
            const uintptr_t UserAgent=REBASE(0x5C45680);
            const uintptr_t VideoPlaybackControllerVideoBufferingDue=REBASE(0x5C33BA0);
            const uintptr_t VideoPlaybackControllerVideoStreamDeacti=REBASE(0x5C38640);
            const uintptr_t VideoProcessorInitFailedHardwareFrames=REBASE(0x3B142F0);
            const uintptr_t VideoProcessorReconfigureFailedHardwareF=REBASE(0x3B16960);
            const uintptr_t VideoSubsystemTelemetryRefusingRegisterV=REBASE(0x3B0D6C0);
            const uintptr_t VorbisHeaderParseFailed=REBASE(0x3B1CAF0);
        }
        namespace VideoAdaption
        {
            const uintptr_t AbrSelectorConfigInvalidJSONMissingStart=REBASE(0x1E11150);
            const uintptr_t AbrSelectorConfigUnknownSelectorReturnin=REBASE(0x1E10B30);
            const uintptr_t AdaptionLogicDecidedVideoShouldPlayed=REBASE(0x3CCB5C0);
            const uintptr_t ForcingHighestResolutionAsset=REBASE(0x3CCD900);
            const uintptr_t GettingCurrentScreenDensity=REBASE(0x1E1CB50);
            const uintptr_t NextVariantChosen=REBASE(0x3CD7850);
            const uintptr_t StartingVariantChosen=REBASE(0x3CD7A30);
        }
        namespace VideoAnalytics
        {
            const uintptr_t MetricValueExceedsUpperBound=REBASE(0x3B06565);
        }
        namespace VideoCodec
        {
            const uintptr_t EncoderAcceptingInputSampleCachingFrame=REBASE(0x1E74C70);
            const uintptr_t EnoughMemoryStartSoftwareVideoEncoder=REBASE(0x1E5CA00);
            const uintptr_t ErrorCreatingTextureHardwareEncoderAvail=REBASE(0x1E5FC70);
            const uintptr_t FailedCreateTexture=REBASE(0x1E70340);
            const uintptr_t FailedGetFileVersionSizeDLL=REBASE(0x1E6B1F0);
            const uintptr_t FailedSetMFLOWLATENCY=REBASE(0x1E72130);
            const uintptr_t FailedStartMediaFoundation=REBASE(0x1E698B0);
            const uintptr_t FirstOutputFrameKeyFrameMay=REBASE(0x1E77350);
            const uintptr_t HardwareEncoderInitializedSuccessfullyIs=REBASE(0x1E64140);
            const uintptr_t HwEncoderReturnedErrorWhenReceiving=REBASE(0x1E5F360);
            const uintptr_t IncorrectNumberPlanesCreateRGBATexture=REBASE(0x1E7BB00);
            const uintptr_t InvalidCodecParametersVideoEncoder=REBASE(0x1E7A1C0);
            const uintptr_t MediaFoundationCodecReceivePacketInterna=REBASE(0x1E85D70);
            const uintptr_t MediaFoundationCodecSendPacketVideoSetSa=REBASE(0x1E88840);
            const uintptr_t MissingCodecWhenCreatingHardwareBuffer=REBASE(0x1E58CD0);
            const uintptr_t SampleTrackerReleasingOldSample=REBASE(0x1E96D60);
            const uintptr_t WindowsHardwareMFTVideoEncoderAdapter=REBASE(0x1E63920);
            const uintptr_t WindowsMFTVideoEncoderStartedIsVideo=REBASE(0x1E66630);
        }
        namespace VideoDeviceInputTrace
        {
            const uintptr_t VideoDeviceInputSetActiveActive=REBASE(0x3CA19D0);
            const uintptr_t VideoDeviceInputSetCameraIdId=REBASE(0x3CA1C20);
            const uintptr_t VideoDeviceInputSetCaptureQualityQuality=REBASE(0x3CA1AD0);
            const uintptr_t VideoDeviceInputShutdown=REBASE(0x3CA18C0);
        }
        namespace VideoFeatureControlTrace
        {
            const uintptr_t VideoFeatureControlReportVideoStatsRebuf=REBASE(0x3D278A0);
            const uintptr_t VideoFeatureControlSave=REBASE(0x3D27BB0);
            const uintptr_t VideoStatsCacheDeserialize=REBASE(0x3D271A0);
        }
        namespace VideoFrame
        {
            const uintptr_t VideoFrameSetPlaybackStateNew=REBASE(0x3ECE6F0);
        }
        namespace VideoInputProcessorTrace
        {
            const uintptr_t Activating=REBASE(0x19B7A20);
            const uintptr_t AlreadySubscribedVideoDeviceProducerSubs=REBASE(0x19B7DA0);
            const uintptr_t StartingProcessing=REBASE(0x19B8E30);
            const uintptr_t StoppingProcessing=REBASE(0x19B9050);
            const uintptr_t StreamDeviceIDNullDevice=REBASE(0x19B82C0);
            const uintptr_t VideoErrorCode=REBASE(0x19B86F0);
            const uintptr_t VideoStopping=REBASE(0x19B8590);
        }
        namespace VideoMemoryPool
        {
            const uintptr_t VideoSVideoBipBufferHasRings=REBASE(0x1E1B820);
        }
        namespace VideoPlaybackManagerTrace
        {
            const uintptr_t RequestingSeek=REBASE(0x3CA42E0);
            const uintptr_t SetStream=REBASE(0x3CA4169);
            const uintptr_t SettingLoadAllowed=REBASE(0x3C98350);
            const uintptr_t SettingPlay=REBASE(0x3CA4420);
        }
        namespace VideoPlayer
        {
            const uintptr_t FailedOpenVideo=REBASE(0x3C98540);
            const uintptr_t FailedSetTimePosition=REBASE(0x3C97520);
            const uintptr_t VideoPlayerV2InputFormatError=REBASE(0x3C99A40);
            const uintptr_t VideoPlayerV2VPCClosedError=REBASE(0x3C9BCC0);
            const uintptr_t VideoPlayerV2VPCCreateFailed=REBASE(0x3C9ACB0);
        }
        namespace VideoPlaylistSelector
        {
            const uintptr_t DisplaySizeUnknownAssumingBigDisplay=REBASE(0x1E157D0);
            const uintptr_t EstimatedCodecTextureMemoryUsageVariant=REBASE(0x1E148A0);
            const uintptr_t HarmonyStartingSelectorWorstIndex=REBASE(0x1E145C0);
            const uintptr_t PlayingMomentsCaptureSelectingHighestPos=REBASE(0x1E15DD0);
            const uintptr_t PlentyMemoryPlayVideoForcingHighest=REBASE(0x1E15520);
            const uintptr_t TotalMemoryLowForcingLowestResolution=REBASE(0x1E15FD0);
        }
        namespace VideoScreenCaptureService
        {
            const uintptr_t CaptureSucceededDurationMs=REBASE(0x3C8B7D0);
            const uintptr_t CheckingGPUAgainstBlacklistMomentsCaptur=REBASE(0x3C8D004);
            const uintptr_t CheckingGPUAgainstGraphicsAPIBlacklist=REBASE(0x3C8D300);
            const uintptr_t CleanupVideoCapture=REBASE(0x3C89610);
            const uintptr_t CurrentVideoCaptureTriggerDoesMatch=REBASE(0x3C8C160);
            const uintptr_t FailedGetGraphicBufferSourceWhenCaptureA=REBASE(0x3C8BB70);
            const uintptr_t FailedRemoveSelfTestFile=REBASE(0x3C8A1A0);
            const uintptr_t LoadSelfTestResult=REBASE(0x3C8DB20);
            const uintptr_t LoadSettings=REBASE(0x3C8E3B0);
            const uintptr_t OnStartedVideoCaptureStartedResult=REBASE(0x3C8ED60);
            const uintptr_t PreventingPendingRequestStarting=REBASE(0x3C8CE60);
            const uintptr_t PromotingPendingRequestCurrentRequest=REBASE(0x3C8CC60);
            const uintptr_t SaveSelfTestResult=REBASE(0x3C8D650);
            const uintptr_t SaveSettingsUseHardware=REBASE(0x3C8DEE0);
            const uintptr_t SendingCurrentRequestTriggerCaptureEngin=REBASE(0x3C8AB10);
            const uintptr_t StartFailed=REBASE(0x3C8BFB0);
            const uintptr_t StartScreenCaptureAsyncTrigger=REBASE(0x3C89120);
            const uintptr_t StartingRequestTriggerDirectly=REBASE(0x3C89A90);
            const uintptr_t StartingSelfTestThenRequestTrigger=REBASE(0x3C89CF0);
            const uintptr_t StopAllRequests=REBASE(0x3C8C540);
            const uintptr_t StopScreenCaptureExpectedTriggerCurrentT=REBASE(0x3C893A0);
        }
        namespace VideoSelfTest
        {
            const uintptr_t CloseDecoder=REBASE(0x533A7B0);
            const uintptr_t SelfTestRvsScaleFailed=REBASE(0x53399A0);
            const uintptr_t SendPacketTimedOutAfterMsecAttempts=REBASE(0x533A9E0);
            const uintptr_t ValidateSelfTestVideoIndexAVCHEVCVideo=REBASE(0x533ADB0);
        }
        namespace VideoServer
        {
            const uintptr_t CancelReservationAsyncNon2xxErrorHttpCod=REBASE(0x3D35F40);
            const uintptr_t CloudClientServiceFailedSubmitReservatio=REBASE(0x4A4CA90);
            const uintptr_t PostConnectAsyncConnectServedStratusSing=REBASE(0x3D30040);
            const uintptr_t PostOfferAsyncFailedStatusHttpCodeBody=REBASE(0x3D31500);
            const uintptr_t ReserveAsyncResponseHadNeitherReservatio=REBASE(0x3D32700);
            const uintptr_t ReserveTtlMsLeavesTimeRedeemReleasing=REBASE(0x3D34640);
        }
        namespace VideoService
        {
            const uintptr_t ClientAddedVideoServiceClientsIndexIsNew=REBASE(0x3EC0A70);
            const uintptr_t RegisteringClientHasPendingRemoveRemovin=REBASE(0x3EBAA50);
            const uintptr_t UnregisteringClientHasPendingAddRemoving=REBASE(0x3EBAE90);
        }
        namespace VideoServiceClient
        {
            const uintptr_t AccumulatedPreviousBufferingStatsVideoSt=REBASE(0x3CAF26D);
            const uintptr_t NewAccumulatedBufferingStats=REBASE(0x3CAF471);
            const uintptr_t SendingSmoothnessCounterPlayMsRebufferin=REBASE(0x3CAF620);
        }
        namespace VideoStream
        {
            const uintptr_t VideoStreamCheckIfVideoTypeIsValidInvali=REBASE(0x3CCCA90);
            const uintptr_t VideoStreamUpdateContextVideoTypeValidCu=REBASE(0x3CD3DB0);
        }
        namespace VideoThumbnailGeneratorTrace
        {
            const uintptr_t GenerateAndInsertTextureIdFrameBuffer=REBASE(0x5CA0A80);
            const uintptr_t GetThumbnailTextureId=REBASE(0x5CA00F0);
            const uintptr_t OnHeartBeat=REBASE(0x3EBCA60);
            const uintptr_t RequestThumbnailThumbnailRequestDropped=REBASE(0x5C9FB60);
            const uintptr_t TryFinishingCurrentJob=REBASE(0x5CA0740);
            const uintptr_t TryStartingNextJobNothingProcess=REBASE(0x5CA03B0);
        }
        namespace VideoTrace
        {
            const uintptr_t VideoFrameSamplerCloseCodecs=REBASE(0x3D1B153);
            const uintptr_t VideoFrameSamplerOpen=REBASE(0x3D163A0);
            const uintptr_t VideoStreamClose=REBASE(0x3CC7BA0);
            const uintptr_t VideoStreamCloseCodecs=REBASE(0x3CCF3C0);
            const uintptr_t VideoStreamOpenConstStdStringVideoUrl=REBASE(0x3CC7790);
            const uintptr_t VideoStreamOpenFailOnLowResource=REBASE(0x3CC7980);
        }
        namespace ViewRbxBase
        {
            const uintptr_t DirectVideoCaptureSourceInjected=REBASE(0x3666260);
            const uintptr_t RenderPerformEndDeltaTotalPresent=REBASE(0x365ACB0);
            const uintptr_t WaitVRWaitedMs=REBASE(0x364BDD0);
        }
        namespace ViewRbxInit
        {
            const uintptr_t BindWorkspaceNewDatamodelOldDatamodel=REBASE(0x36472E0);
            const uintptr_t RenderViewAdditionalCreated=REBASE(0x3642140);
            const uintptr_t RenderViewSubViewCreated=REBASE(0x3642620);
        }
        namespace VoiceChatLogs
        {
            const uintptr_t AsyncInitRTCThreadsAndAudioDeviceENTRYSe=REBASE(0x52C9BB0);
            const uintptr_t AttemptingUpdateSubscriptionsButPeerConn=REBASE(0x52086B0);
            const uintptr_t AudioDeviceManagerInit=REBASE(0x5285E30);
            const uintptr_t AudioDeviceManagerInitPlayout=REBASE(0x52865D0);
            const uintptr_t AudioDeviceManagerInitRecording=REBASE(0x5286800);
            const uintptr_t AudioDeviceManagerStartPlayout=REBASE(0x52869F0);
            const uintptr_t AudioDeviceManagerStartRecordingHasPermi=REBASE(0x5286D20);
            const uintptr_t AudioDeviceManagerStopPlayout=REBASE(0x5286B60);
            const uintptr_t AudioDeviceManagerTerminate=REBASE(0x5286110);
            const uintptr_t AudioFormatChangedReInitializingRecordin=REBASE(0x528B890);
            const uintptr_t AudioQualityEncoderFailedCreateOGGContai=REBASE(0x52426A0);
            const uintptr_t AudioQualityEncoderFailedWriteOGGTrailer=REBASE(0x52433B0);
            const uintptr_t CannotFindUserCurrentUserToMidMapAbandon=REBASE(0x52326F0);
            const uintptr_t ClientContextParsingStateTryUpdateQueued=REBASE(0x51F2A10);
            const uintptr_t ClientICETrickleOperationCollectICECandi=REBASE(0x52385F0);
            const uintptr_t ClientICETrickleOperationConstructed=REBASE(0x5237EF0);
            const uintptr_t ClientICETrickleOperationInitializeState=REBASE(0x52383B0);
            const uintptr_t ClientICETrickleOperationSendICECandidat=REBASE(0x52391C0);
            const uintptr_t ClientJoinOperationSkippedPlaySoloMode=REBASE(0x52155E0);
            const uintptr_t ClientJoinOperationWaitForJoinedVoiceSta=REBASE(0x52163D0);
            const uintptr_t ClientLeaveOperationConstructed=REBASE(0x520E960);
            const uintptr_t ClientLeaveOperationDisconnectPeerConnec=REBASE(0x520EDB0);
            const uintptr_t ClientLeaveOperationDuplicateLeaveCleanu=REBASE(0x52100E0);
            const uintptr_t ClientLeaveOperationWaitForWebrtcShutDow=REBASE(0x52106E0);
            const uintptr_t ClientMuteUnmuteOperationConstructedStat=REBASE(0x521BF90);
            const uintptr_t ClientOperationCollectionEnqueueClientMu=REBASE(0x4C8F1F0);
            const uintptr_t ClientOperationCollectionRunSendSessionE=REBASE(0x51EFE90);
            const uintptr_t ClientPeerLocalMuteUnmuteOperationConstr=REBASE(0x522BEF0);
            const uintptr_t ClientPeerRemoteMuteUnmuteOperationConst=REBASE(0x5231F30);
            const uintptr_t ClientPublishInitializeStateAbandoningPu=REBASE(0x5220BB0);
            const uintptr_t ClientPublishOperationClientPublishAband=REBASE(0x52201E0);
            const uintptr_t ClientPublishOperationClientPublishFailS=REBASE(0x5220000);
            const uintptr_t ClientPublishOperationClientPublishRepub=REBASE(0x5221080);
            const uintptr_t ClientPublishOperationClientPublishSucce=REBASE(0x521FC60);
            const uintptr_t ClientPublishOperationConstructed=REBASE(0x5220300);
            const uintptr_t ClientPublishOperationHaltedVoiceSetupFa=REBASE(0x5223040);
            const uintptr_t ClientPublishOperationTimedOut=REBASE(0x5220900);
            const uintptr_t ClientPublishSetupPeerConnectionStateFai=REBASE(0x5221C30);
            const uintptr_t ClientPublishWaitForAnswerStateTooManyPu=REBASE(0x5223510);
            const uintptr_t ClientPublishWaitForCompleteStateTooMany=REBASE(0x5224110);
            const uintptr_t ClientPublishWaitForOfferStateFailedGetO=REBASE(0x52227C0);
            const uintptr_t ClientPublishWaitForSetupPeerConnectionC=REBASE(0x5222310);
            const uintptr_t ClientRebootInitializeState=REBASE(0x521B040);
            const uintptr_t ClientSubscribeOperationConstructedSessi=REBASE(0x5201FD0);
            const uintptr_t ClientSubscribeOperationNewConnectionDet=REBASE(0x5202D40);
            const uintptr_t ClientSubscriberAudioQualityAwaitPristin=REBASE(0x5227680);
            const uintptr_t ClientSubscriberAudioQualityEncodeAndUpl=REBASE(0x5228090);
            const uintptr_t ClientSubscriberAudioQualityOperationTim=REBASE(0x5226970);
            const uintptr_t ClientSubscriberAudioQualitySelectAndAtt=REBASE(0x5226B40);
            const uintptr_t ClientSubscriptionsUpdateOnCompletedStat=REBASE(0x520A370);
            const uintptr_t ClientSubscriptionsUpdateOperationFailed=REBASE(0x5202AF0);
            const uintptr_t ClientSubscriptionsUpdateSendAckedEventS=REBASE(0x5209580);
            const uintptr_t ClientSubscriptionsUpdateSignalParticipa=REBASE(0x5206A90);
            const uintptr_t ClientSubscriptionsUpdateWaitForSubCompl=REBASE(0x5209F90);
            const uintptr_t ClientTurnAuthOperationConstructed=REBASE(0x52196A0);
            const uintptr_t ClientVoiceRtcStatsOperationSkippingStat=REBASE(0x5234DA0);
            const uintptr_t ClientVoiceRtcStatsOperationTimedOut=REBASE(0x5234A78);
            const uintptr_t CloseConnectionsAudioDeviceModuleWrapper=REBASE(0x52A7CF0);
            const uintptr_t CloseConnectionsENTRYSession=REBASE(0x52CA490);
            const uintptr_t CloseConnectionsEarlyReturnPeerConnectio=REBASE(0x52A6C70);
            const uintptr_t CloseConnectionsStoppingAudioPlayoutReco=REBASE(0x52A73C0);
            const uintptr_t ConnectOperationConnectAbandonedState=REBASE(0x523E310);
            const uintptr_t ConnectOperationDataChannelRemoteAnswerR=REBASE(0x5240BF0);
            const uintptr_t ConnectOperationFailed=REBASE(0x523E0A0);
            const uintptr_t ConnectOperationFailedInitializePeerConn=REBASE(0x523EBB0);
            const uintptr_t ConnectOperationMissingConnectBlob=REBASE(0x523E690);
            const uintptr_t ConnectOperationReceivedDataChannelAnswe=REBASE(0x30FA290);
            const uintptr_t ConnectionApiCullingStateUpdateListenerO=REBASE(0x5293060);
            const uintptr_t ConnectionApiPublishSetRemoteDescription=REBASE(0x52A3700);
            const uintptr_t ConnectionApiRELAYCandidateIpPort=REBASE(0x52A5990);
            const uintptr_t ContextParsingOperationSendPublisherSign=REBASE(0x51F2190);
            const uintptr_t CreateSessionWebRTCConnectionBuiltProces=REBASE(0x52C4BC0);
            const uintptr_t CreateWebRTCConnectionFFlagVoiceUseWebRT=REBASE(0x5292DB0);
            const uintptr_t CullingPassSummaryActiveCulledMuted=REBASE(0x522A790);
            const uintptr_t CustomAudioDeviceModuleBuiltInAECIsAvail=REBASE(0x5279470);
            const uintptr_t CustomAudioDeviceModuleEnableBuiltInAECI=REBASE(0x5279620);
            const uintptr_t CustomAudioDeviceModuleInitPlayoutResult=REBASE(0x5279910);
            const uintptr_t CustomAudioDeviceModuleInitRecordingResu=REBASE(0x5279C50);
            const uintptr_t CustomAudioMixerAddSourceSourceAlreadyPr=REBASE(0x5D17BE0);
            const uintptr_t CustomAudioMixerCustomAudioMixer=REBASE(0x5D1B5D0);
            const uintptr_t CustomAudioMixerRemoveSourceSsrc=REBASE(0x5D182E0);
            const uintptr_t CustomAudioMixerUpdateSourcesUpdatedPubl=REBASE(0x5D19D30);
            const uintptr_t CustomAudioProcessingCustomAudioProcessi=REBASE(0x5D1D150);
            const uintptr_t DeallocatePeerConnectionFactoryENTRYSess=REBASE(0x52CA630);
            const uintptr_t DebugFriendsCallSubscribeOperationFailed=REBASE(0x5230C20);
            const uintptr_t DebugFriendsCallSubscribeOperationRegist=REBASE(0x5230050);
            const uintptr_t EmittedVoiceRtcStatsEventSuperSetEventIn=REBASE(0x5CF2D20);
            const uintptr_t EmittedVoiceRtcStatsSessionSummaryEventS=REBASE(0x5CF7EB0);
            const uintptr_t ErrorRetryAllowedDueRetryLimit=REBASE(0x521B2D0);
            const uintptr_t FeedReferenceIdUserAudioMidMappingFound=REBASE(0x5205570);
            const uintptr_t FlushSessionTrackingTalkSecListenSecAvgR=REBASE(0x52479F0);
            const uintptr_t InitPeerConnectionFactoryENTRYSession=REBASE(0x52C9CB0);
            const uintptr_t LeavingAbandoningClientTurnAuthOperation=REBASE(0x52199B0);
            const uintptr_t MetricsGuiModelICECandidatesTruncatedEnt=REBASE(0x4CA2D00);
            const uintptr_t MetricsGuiModelUserToMidMapTruncatedEntr=REBASE(0x4CA3010);
            const uintptr_t MuteMicrophoneENTRYMuteSession=REBASE(0x52CC280);
            const uintptr_t MuteStateDidChangeAbandoningClient=REBASE(0x521C720);
            const uintptr_t PeerConnectionStateChangedFailed=REBASE(0x5211440);
            const uintptr_t PlayoutDeviceNameTooLongWill=REBASE(0x5288260);
            const uintptr_t PollingMessages=REBASE(0x5240470);
            const uintptr_t PublishCreateSdpOfferENTRYSession=REBASE(0x52CA900);
            const uintptr_t PublishOperationFailedInitializePeerConn=REBASE(0x52218E0);
            const uintptr_t PublishSetRemoteDescriptionENTRYSessionS=REBASE(0x52CAAF0);
            const uintptr_t QueueStreamTransactionQueueErrorMaxQueue=REBASE(0x52A54A0);
            const uintptr_t ReceivedEventVoiceMigrationReason=REBASE(0x4C906A0);
            const uintptr_t ReceivedSubscriptionHandshakeAckedWithCo=REBASE(0x4C8E280);
            const uintptr_t RecordingDeviceManagerInitRecording=REBASE(0x528A710);
            const uintptr_t RecordingDeviceManagerInitRecordingInput=REBASE(0x528B620);
            const uintptr_t RecordingDeviceManagerRecordingDeviceMan=REBASE(0x528A340);
            const uintptr_t RecordingDeviceManagerSetMicrophoneMute=REBASE(0x528B1E0);
            const uintptr_t RecordingDeviceManagerStartRecording=REBASE(0x528A9A0);
            const uintptr_t RecordingDeviceManagerStopRecording=REBASE(0x528AC70);
            const uintptr_t RecordingDeviceNameTooLongWill=REBASE(0x528AEE0);
            const uintptr_t RecordingDevicePermissionsRequestMicroph=REBASE(0x5288D60);
            const uintptr_t RobloxAudioDeviceForcingShutdownActively=REBASE(0x5282B10);
            const uintptr_t RobloxAudioDeviceInit=REBASE(0x5281750);
            const uintptr_t RobloxAudioDeviceInitPlayout=REBASE(0x5281EF0);
            const uintptr_t RobloxAudioDeviceInitRecording=REBASE(0x5282230);
            const uintptr_t RobloxAudioDeviceInitRecordingInputAudio=REBASE(0x52804B0);
            const uintptr_t RobloxAudioDeviceModuleFailedCreatePlatf=REBASE(0x5277D30);
            const uintptr_t RobloxAudioDeviceRequestMicrophonePermis=REBASE(0x5284630);
            const uintptr_t RobloxAudioDeviceSetMicrophoneMuteFalse=REBASE(0x5283D20);
            const uintptr_t RobloxAudioDeviceStartDeviceRecordingHas=REBASE(0x52827E0);
            const uintptr_t RobloxAudioDeviceStartPlayout=REBASE(0x52823A0);
            const uintptr_t RobloxAudioDeviceStartRecording=REBASE(0x5283300);
            const uintptr_t RobloxAudioDeviceStopPlayout=REBASE(0x52826A0);
            const uintptr_t RobloxAudioDeviceTerminate=REBASE(0x52819C0);
            const uintptr_t RomarkAudioDeviceInit=REBASE(0x527E850);
            const uintptr_t RomarkAudioDeviceInitPlayout=REBASE(0x527EA40);
            const uintptr_t RomarkAudioDeviceModuleFailedCreatePlatf=REBASE(0x5276E60);
            const uintptr_t RomarkAudioDeviceModuleSetSelectedMicInd=REBASE(0x5276A80);
            const uintptr_t RomarkAudioDeviceStartPlayout=REBASE(0x527EC40);
            const uintptr_t RomarkAudioDeviceStartRecording=REBASE(0x527F040);
            const uintptr_t RomarkAudioDeviceStopPlayout=REBASE(0x527EF20);
            const uintptr_t RomarkAudioDeviceStopRecording=REBASE(0x527F510);
            const uintptr_t SelectedSpeakerDeviceNameGuidIndex=REBASE(0x52765D0);
            const uintptr_t SendAllPendingStreamTransactionsSendErro=REBASE(0x52A56C0);
            const uintptr_t SessionIDChangedAbandoningClientPeer=REBASE(0x52323E0);
            const uintptr_t SessionIDChangedAbandoningClientPublish=REBASE(0x52206A0);
            const uintptr_t SessionIDChangedAbandoningClientSubscrib=REBASE(0x5202570);
            const uintptr_t SetRemoteAnswerMovingOpenData=REBASE(0x523FBB0);
            const uintptr_t SettingLocalOffer=REBASE(0x523F490);
            const uintptr_t SettingMsgOverDc=REBASE(0x5240100);
            const uintptr_t SettingRemoteAnswer=REBASE(0x523F870);
            const uintptr_t SetupDataChannelForCullingENTRYSession=REBASE(0x52CA290);
            const uintptr_t SetupPublishConnectionENTRYSessionUserna=REBASE(0x52C9DB0);
            const uintptr_t SetupSubscriptionConnectionENTRYSessionU=REBASE(0x52CA020);
            const uintptr_t StartCaptureFMODRecordingStartedRingBuff=REBASE(0x52CCE70);
            const uintptr_t StartPlayoutGetAudioDeviceReturnedNull=REBASE(0x52CCBE0);
            const uintptr_t StatsRtt1fMsInBytesOutBytes=REBASE(0x52CBC90);
            const uintptr_t StopPlayout=REBASE(0x52CC4D0);
            const uintptr_t StreamSwitchFailedCouldFindHandle=REBASE(0x52033F0);
            const uintptr_t StreamSwitchingFinalStateAfterApplying=REBASE(0x51F34A0);
            const uintptr_t StreamSwitchingReceivedEventSsrcUserIdMa=REBASE(0x4C94BC0);
            const uintptr_t StreamTransactionMessageTransportDataCha=REBASE(0x528ED40);
            const uintptr_t StreamTransactionMessageTransportReceive=REBASE(0x52C8A70);
            const uintptr_t SubmitGetStatsAsyncENTRYSession=REBASE(0x52CC170);
            const uintptr_t SubmitPublisherGetStatsAsyncENTRYSession=REBASE(0x52CBF50);
            const uintptr_t SubmitSubscriberGetStatsAsyncENTRYSessio=REBASE(0x52CC060);
            const uintptr_t SubscriberVoiceQualityBufferDrainAndEnco=REBASE(0x5241D70);
            const uintptr_t SubscriberVoiceQualityBufferPristineAccu=REBASE(0x5241B4F);
            const uintptr_t SubscriberVoiceQualityBufferUnexpectedFo=REBASE(0x52411E0);
            const uintptr_t SubscriberVoiceQualityBufferVADActiveEne=REBASE(0x5241A76);
            const uintptr_t SubscriberVoiceQualityBufferVADInactiveC=REBASE(0x5241CB5);
            const uintptr_t SubscriptionCreateAnswerENTRYSession=REBASE(0x52CAE90);
            const uintptr_t SubscriptionOperationStillInitializingPe=REBASE(0x5207980);
            const uintptr_t SubscriptionSetRemoteDescriptionENTRYSes=REBASE(0x52CACC0);
            const uintptr_t TearDownWebrtcConnectionsENTRYSession=REBASE(0x52CA730);
            const uintptr_t TryPopSdpMessageWithTagENTRYTagSession=REBASE(0x52CB760);
            const uintptr_t VoiceChatClientGameDataClientImplSendOnP=REBASE(0x4C974E0);
            const uintptr_t VoiceChatClientGameDataClientImplSendSub=REBASE(0x4C9BDA0);
            const uintptr_t VoiceChatClientGameDataClientImplSendUpd=REBASE(0x4C96710);
            const uintptr_t VoiceChatExtensionIsVoiceEnabledForUserI=REBASE(0x4921E70);
            const uintptr_t VoiceChatInternalAPISecurityCheckFailed=REBASE(0x52675A0);
            const uintptr_t VoiceChatInternalCtor=REBASE(0x52663B0);
            const uintptr_t VoiceChatInternalDtor=REBASE(0x5266C70);
            const uintptr_t VoiceChatInternalOnServiceProviderOldPro=REBASE(0x5274FD0);
            const uintptr_t VoiceChatInternalPublishPausePausedInvok=REBASE(0x526AB60);
            const uintptr_t VoiceChatServiceIsVoiceEnabledForUserIdA=REBASE(0x5253730);
            const uintptr_t VoiceChatServiceProcessRemoteEventReplic=REBASE(0x524F5E0);
            const uintptr_t VoiceChatServiceTriggerClientVoiceCapabi=REBASE(0x4C961B0);
            const uintptr_t VoiceChatStatsAccumulateAllTrackersIsPub=REBASE(0x5245FA0);
            const uintptr_t VoiceChatStatsLoggedMilestone=REBASE(0x5244C60);
            const uintptr_t VoiceChatStatsLoggedVoiceExperienceClick=REBASE(0x5244D80);
            const uintptr_t VoiceChatStatsLoggedVoiceSubscribeFailur=REBASE(0x5245660);
            const uintptr_t VoiceChatStatsLoggedVoiceTurnAuthInfo=REBASE(0x5245370);
            const uintptr_t VoiceChatStatsReportPublishSecConsumeSec=REBASE(0x52465B0);
            const uintptr_t VoiceChatV2ControlPlaneClientStartFailed=REBASE(0x4C89A30);
            const uintptr_t VoiceChatV2ControlPlaneClientStarted=REBASE(0x4C8A2D0);
            const uintptr_t VoiceConnectionInterruptionOutcomeConnec=REBASE(0x52480F0);
            const uintptr_t VoiceSettingsEndpointReturnedInvalidResp=REBASE(0x5269180);
            const uintptr_t VoiceSubscriberAudioQualityCaptureDelayM=REBASE(0x51F53E0);
            const uintptr_t WebRTCConnectionCallingSetRemoteAnswerCa=REBASE(0x529E140);
            const uintptr_t WebRTCConnectionCallingSignalingFrameByt=REBASE(0x529C700);
            const uintptr_t WebRTCConnectionCallingSignalingFrameFai=REBASE(0x52B52B0);
            const uintptr_t WebRTCConnectionCloseConnectionsSettingP=REBASE(0x52A7690);
            const uintptr_t WebRTCConnectionDeallocatePeerConnection=REBASE(0x52A6510);
            const uintptr_t WebRTCConnectionDeliverSignalingMessageR=REBASE(0x529CA30);
            const uintptr_t WebRTCConnectionOnSignalingDataChannelSt=REBASE(0x528F0F0);
            const uintptr_t WebRTCConnectionSetupCallingConnection=REBASE(0x529C0A0);
            const uintptr_t WebRTCConnectionSetupCallingSignalingDat=REBASE(0x529C1B0);
            const uintptr_t WebRTCConnectionSetupDataChannelForCulli=REBASE(0x529A330);
            const uintptr_t WebRTCConnectionWebRTCConnectionWaitShut=REBASE(0x5293CA0);
            const uintptr_t WebRTCConnectonSetupCallingConnectionCou=REBASE(0x529ADF0);
            const uintptr_t WebRTCHostTelemetryUnknownCounter=REBASE(0x52CD7E7);
            const uintptr_t WebRTCHostTelemetryUnknownStat=REBASE(0x52CDCD0);
            const uintptr_t WebRTCPeerConnectionObserverOnIceConnect=REBASE(0x5291700);
        }
        namespace Voxel
        {
            const uintptr_t DeserializeFragmentAssetContentMapDone=REBASE(0x4BDB1C0);
            const uintptr_t DeserializeStart=REBASE(0x4BD99B0);
        }
        namespace VoxelGridStreaming
        {
            const uintptr_t ByteRangeLengthExceedsMaximumAllowedSize=REBASE(0x495E040);
            const uintptr_t CDNResponseSizeDoesMatchExpected=REBASE(0x49602C0);
        }
        namespace WHAM1707StateMachine
        {
            const uintptr_t EnteredRecordingStartedReportIDVideoPath=REBASE(0x4364740);
            const uintptr_t ExceededMaxRetriesFileRemoval=REBASE(0x4363830);
            const uintptr_t RecordingStartedStateTransitionUnhandled=REBASE(0x43648A0);
            const uintptr_t RecordingStoppedEnterCalledWhileOutputPa=REBASE(0x4364170);
            const uintptr_t RecordingStoppedStateTransitionUnhandled=REBASE(0x4364380);
            const uintptr_t ReportSubmissionInProgressStateTransitio=REBASE(0x4364F40);
            const uintptr_t RetryingTryRemoveFile=REBASE(0x43657B0);
            const uintptr_t Transitioning=REBASE(0x4363030);
            const uintptr_t UploadCompleteTransitioningRecordingStop=REBASE(0x43655B0);
            const uintptr_t VideoReportRecorderReportDetachAnalaytic=REBASE(0x4363CF0);
            const uintptr_t WaitForVideoFinalizeStateTransitionUnhan=REBASE(0x4365250);
            const uintptr_t WaitingForRecorderStatusStateTransitionU=REBASE(0x4364560);
            const uintptr_t WaitingForReportSubmitStateTransitionUnh=REBASE(0x4364C40);
        }
        namespace WRR
        {
            const uintptr_t BeginFrameLoadingTextureHash=REBASE(0x37F98B0);
            const uintptr_t BindDataModelFoundExistingHash=REBASE(0x37FA910);
            const uintptr_t DisableIfSentinelExcludingSession=REBASE(0x37FA6B0);
            const uintptr_t PropertyChangedSignalReceivedHash=REBASE(0x37FAE60);
            const uintptr_t TierAlphaCapFinal=REBASE(0x37F9640);
            const uintptr_t TierMatchDefault=REBASE(0x37FDBD0);
        }
        namespace WaitForAll
        {
            const uintptr_t WaitForAllFailedErrorCount=REBASE(0x24A81C0);
        }
        namespace Warning
        {
            const uintptr_t AdPortalInvalid=REBASE(0x1082BE0);
            const uintptr_t AppAgeSignalsOnGetAgeSignalFailedIgnorin=REBASE(0x4E858F0);
            const uintptr_t AppAgeSignalsOnGetAgeSignalSucceededIgno=REBASE(0x4E84F60);
            const uintptr_t CheckForUpdateSkippingUpdateCheckBecause=REBASE(0x320D670);
            const uintptr_t ControlsToJointDriverShortestPathRotatio=REBASE(0x2496160);
            const uintptr_t CustomAudioMixerMixFailedGetAudioSource=REBASE(0x5D18920);
            const uintptr_t DecodedFramesAvailableTimestampLld=REBASE(0x5A234F0);
            const uintptr_t EventHasDuplicateParameterEventWill=REBASE(0x2B876C0);
            const uintptr_t ExperienceProtocolStartListeningWithCall=REBASE(0x44F23E0);
            const uintptr_t ExponentialDecaySmoothingSmoothPreviousF=REBASE(0x1C11853);
            const uintptr_t GetAvailableSubscriptionProductsAsyncAPI=REBASE(0x1218D60);
            const uintptr_t GetWindowsVersionVersionSupported=REBASE(0x52DB020);
            const uintptr_t HSRDataDoesHaveAssetPlease=REBASE(0x1B0BCF0);
            const uintptr_t HiddenSurfaceRemovalAssetIdDoesExist=REBASE(0x181C8F0);
            const uintptr_t HiddenSurfaceRemovalDataInvalidReason=REBASE(0x1D67260);
            const uintptr_t LaunchUGCGameAttemptingRecursivelyJoinSa=REBASE(0x1469CC0);
            const uintptr_t LauncherLocalDidInstallAnyWebView2=REBASE(0x16A7D90);
            const uintptr_t LinkingProtocolOnHandlePlatformURLRegexH=REBASE(0x44E2990);
            const uintptr_t LinkingProtocolStartListeningAttemptedSt=REBASE(0x44E1A40);
            const uintptr_t LinkingProtocolStopListeningAttemptedSto=REBASE(0x74A0C0);
            const uintptr_t LocalStorageLoadingDataGotInvalidOperati=REBASE(0x29B9CE0);
            const uintptr_t MachineIdCheckFailure=REBASE(0x743E90);
            const uintptr_t RestartLuaAppCalledWhilePlayingUGCGame=REBASE(0x14646C0);
            const uintptr_t ScreenTimeGotInvalidErrorCode=REBASE(0x4D58470);
            const uintptr_t ScreenTimeHeartbeatHttpStatusErrorBody=REBASE(0x4D58AA0);
            const uintptr_t ScreenTimeNotificationResponseEmpty=REBASE(0x4D57CD0);
            const uintptr_t ScreenTimeStartFailedStatusCodeBodyError=REBASE(0x4D57A90);
            const uintptr_t SetCookieRBXEventTrackerV2Detected=REBASE(0x7233E0);
            const uintptr_t SimpleLinearSmoothingSmoothPreviousFACSD=REBASE(0x1C11B52);
            const uintptr_t SkinningTransferContextMeshAssociatedPar=REBASE(0x1B405F0);
            const uintptr_t VideoCaptureClientCapturePointerWentOutS=REBASE(0x3EE5790);
            const uintptr_t VideoCaptureClientHandleSuspendPointerSW=REBASE(0x3EE3330);
            const uintptr_t VideoCaptureClientHandleSuspendPointerWe=REBASE(0x3EE3CC0);
            const uintptr_t VideoCaptureClientOnClientPlayPointerWen=REBASE(0x3EE35E0);
            const uintptr_t VideoCaptureClientSignalVideoFrameArrive=REBASE(0x3EE55E0);
            const uintptr_t WebLoginAuthenticationFailedAppQuitting=REBASE(0x747E60);
            const uintptr_t WebLoginCannotRunAuthenticationUrlTicket=REBASE(0x4CEF2C0);
            const uintptr_t WebLoginErrorAuthTicketEmpty=REBASE(0x4CEE8F0);
            const uintptr_t WebLoginErrorAuthURLTicketEmpty=REBASE(0x4CEE250);
            const uintptr_t WebLoginHttpErrorStatusCode=REBASE(0x4CEF950);
            const uintptr_t WebPlayGameLaunchJoinScriptUrlEmpty=REBASE(0x4CF0750);
            const uintptr_t WebView2PlatformSupported=REBASE(0x754D00);
        }
        namespace WebChatFiltering
        {
            const uintptr_t InvalidLocaleId=REBASE(0x2F91510);
        }
        namespace WebLoginProtocol
        {
            const uintptr_t ErrorPerformingWebLoginErrorCode=REBASE(0x44DB0D0);
            const uintptr_t InvalidPlaceIdValue=REBASE(0x621EB30);
            const uintptr_t PlaceIdOutRange=REBASE(0x621EA70);
            const uintptr_t WebLoginProtocolInitializedStopHandling=REBASE(0x44DB610);
        }
        namespace WebSocketClient
        {
            const uintptr_t ErrorClosingWebSocket=REBASE(0x61EA1A0);
        }
        namespace WebSocketTraceError
        {
            const uintptr_t WsUrlError=REBASE(0x2C80B60);
        }
        namespace WebSocketTraceLight
        {
            const uintptr_t AddWsAbortedWebSockets=REBASE(0x2C81030);
            const uintptr_t CouldAddWsDevOriginatedLimit=REBASE(0x2CA9990);
            const uintptr_t WsConnecting=REBASE(0x2CB9200);
            const uintptr_t WsState=REBASE(0x2C807F0);
        }
        namespace WebStreamClient
        {
            const uintptr_t ErrorClosingWebStreamClient=REBASE(0x61E9E70);
        }
        namespace WebView
        {
            const uintptr_t SendingCommandWebViewService=REBASE(0x515DE20);
        }
        namespace WebView2ClickoutDialog
        {
            const uintptr_t CancelWasClickedClickoutDialog=REBASE(0x16C4FA0);
            const uintptr_t ContinueWasClickedClickoutDialog=REBASE(0x16D07D0);
            const uintptr_t CouldnTMakeValidDialogResetting=REBASE(0x16D0520);
            const uintptr_t FamiliesWereGottenDuringFontInitializati=REBASE(0x16DC150);
            const uintptr_t L0x08X=REBASE(0x16DC8D0);
        }
        namespace WebrtcInput
        {
            const uintptr_t AudioPacketReceivedWithinMsProceeding=REBASE(0x1E2E2B0);
            const uintptr_t AudioStreamCreatedOPUSHzCh=REBASE(0x1E30380);
            const uintptr_t BytesVideoAudio=REBASE(0x1E276B0);
            const uintptr_t DequeuePts=REBASE(0x1E297C0);
            const uintptr_t ExchangeSdpTookMsNetMsParse=REBASE(0x1E2A8E0);
            const uintptr_t FailedSendDataChannelMessage=REBASE(0x1E312A0);
            const uintptr_t ICEGatheringTimedOutAfterMs=REBASE(0x1E2BA70);
            const uintptr_t OnConnectionStateChange=REBASE(0x1E2D870);
            const uintptr_t OnIceCandidate=REBASE(0x1E2D690);
            const uintptr_t OnInputMessageSize=REBASE(0x1E32980);
            const uintptr_t OnRemoteMessageSize=REBASE(0x1E327B0);
            const uintptr_t RemoteDataChannel=REBASE(0x1E2DCE0);
            const uintptr_t SPSFoundFirstFrameCannotDetermine=REBASE(0x1E2EAE0);
            const uintptr_t StratusTurnServerOverrideValidTURNJSON=REBASE(0x1E299C0);
            const uintptr_t TransportSilentMsThresholdMsDisconnectin=REBASE(0x1E31680);
            const uintptr_t VideoTransceiverSendPLI=REBASE(0x1E31090);
            const uintptr_t WaitStreamInfoTookMs=REBASE(0x1E295D0);
        }
        namespace WildMeshSimplifierLog
        {
            const uintptr_t StartWildMeshSimplifierSimplificationPro=REBASE(0x2C08530);
        }
        namespace WinPinShortcut
        {
            const uintptr_t CannotFindPathRevealPinnedExperience=REBASE(0x16AEB60);
            const uintptr_t FailedCreateStartMenuPinnedShortcuts=REBASE(0x16AB4F0);
            const uintptr_t FailedCreateUrlFileFileUse=REBASE(0x16AD100);
            const uintptr_t GdiplusBitmapFromStreamFailure=REBASE(0x16ACFB7);
        }
        namespace WinRawInput
        {
            const uintptr_t FailedSetupInputDevicesViaWindowsRawInpu=REBASE(0x16D5B00);
            const uintptr_t GetRawInputDataReturnedBufferSizeWhileWe=REBASE(0x16D6EE0);
        }
        namespace WindowProtocolCore
        {
            const uintptr_t BeginDragAvailableCurrentPlatform=REBASE(0x5159ED0);
            const uintptr_t CloseAvailableCurrentPlatform=REBASE(0x5159990);
            const uintptr_t EndDragAvailableCurrentPlatform=REBASE(0x515A020);
            const uintptr_t GetLogicalCaptionButtonsBoundsAvailableC=REBASE(0x515A8D0);
            const uintptr_t GetNativeTitleBarControlsPositionAvailab=REBASE(0x515A190);
            const uintptr_t GetTitleBarHeightAvailableCurrentPlatfor=REBASE(0x515A780);
            const uintptr_t GetTitleBarModeAvailableCurrentPlatform=REBASE(0x515A4D0);
            const uintptr_t GetWindowStateAvailableCurrentPlatform=REBASE(0x515AA50);
            const uintptr_t MaximizeAvailableCurrentPlatform=REBASE(0x5159C30);
            const uintptr_t MinimizeAvailableCurrentPlatform=REBASE(0x5159AE0);
            const uintptr_t OnDragAreaDoubleClickedAvailableCurrentP=REBASE(0x515ABA0);
            const uintptr_t OnDragAreaRightClickedAvailableCurrentPl=REBASE(0x515ACF0);
            const uintptr_t RestoreAvailableCurrentPlatform=REBASE(0x5159D80);
            const uintptr_t SetCustomTitleBarHeightAvailableCurrentP=REBASE(0x515A620);
            const uintptr_t SetTitleBarModeAvailableCurrentPlatform=REBASE(0x515A390);
            const uintptr_t ShouldRenderTitleBarControlsNativelyAvai=REBASE(0x515A290);
            const uintptr_t UnregisterWindowCalledWindowIdWhichRegis=REBASE(0x51594B0);
            const uintptr_t WindowIdHasBeenRegistered=REBASE(0x5159740);
        }
        namespace WindowProtocolService
        {
            const uintptr_t WindowProtocolServiceMethodBeginDragInternal=REBASE(0x4EB0620);
            const uintptr_t WindowProtocolServiceMethodCloseImplCann=REBASE(0x4EB0160);
            const uintptr_t WindowProtocolServiceMethodEndDragImplCa=REBASE(0x4EB0750);
            const uintptr_t WindowProtocolServiceMethodGetLogicalCap=REBASE(0x4EB0C30);
            const uintptr_t WindowProtocolServiceMethodGetNativeTitl=REBASE(0x4EAFF00);
            const uintptr_t WindowProtocolServiceMethodGetTitleBarMo=REBASE(0x4EB09C0);
            const uintptr_t WindowProtocolServiceMethodGetWindowStat=REBASE(0x4EB0D70);
            const uintptr_t WindowProtocolServiceMethodIsAvailableIm=REBASE(0x4EAFDD0);
            const uintptr_t WindowProtocolServiceMethodMaximizeImplC=REBASE(0x4EB03C0);
            const uintptr_t WindowProtocolServiceMethodMinimizeImplC=REBASE(0x4EB0290);
            const uintptr_t WindowProtocolServiceMethodOnDragAreaDou=REBASE(0x4EB0EB0);
            const uintptr_t WindowProtocolServiceMethodOnDragAreaRig=REBASE(0x4EB0FE0);
            const uintptr_t WindowProtocolServiceMethodRestoreImplCa=REBASE(0x4EB04F0);
            const uintptr_t WindowProtocolServiceMethodSetCustomTitl=REBASE(0x4EB0AF0);
            const uintptr_t WindowProtocolServiceMethodSetTitleBarMo=REBASE(0x4EB0880);
            const uintptr_t WindowProtocolServiceMethodShouldRenderT=REBASE(0x4EB0030);
        }
        namespace WindowsEmbeddedWebView
        {
            const uintptr_t ErrorWhileCallingDomainAllowListChecker=REBASE(0x16D3600);
            const uintptr_t InvalidThemeValueMappedUserId=REBASE(0x16CB000);
            const uintptr_t WebView2ClosingHwnd=REBASE(0x16D0360);
            const uintptr_t WebView2OpenWebViewWindowMHwndIsAdPlayer=REBASE(0x16C4150);
            const uintptr_t WebView2TabNavigateUrl=REBASE(0x16CAB00);
        }
        namespace WindowsLuaApp
        {
            const uintptr_t CannotInitializeWindowsNativeAdsImplMars=REBASE(0x750470);
            const uintptr_t FailedParseNotificationDataJsonWhile=REBASE(0x74EB60);
            const uintptr_t FailedRetrieveAuthTokenErrorCode=REBASE(0x753240);
            const uintptr_t WinAuthTokenCopyAuthCookieFromBrowserToE=REBASE(0x753670);
            const uintptr_t WinAuthTokenLoadAuthTokenFromDiskEmptyAu=REBASE(0x744E20);
            const uintptr_t WinAuthTokenSaveAuthTokenToDiskSizeZu=REBASE(0x744680);
        }
        namespace WindowsMediaPicker
        {
            const uintptr_t UserCanceledSelectFileAction=REBASE(0x5133410);
        }
        namespace WindowsNativeAdsProtocol
        {
            const uintptr_t AdPlayerStartsCallingHandleGetQueryInfoI=REBASE(0x16B66C0);
            const uintptr_t AdPlayerStep1FinishGetQueryInfoCallbackC=REBASE(0x16BB9F0);
            const uintptr_t AdPlayerStep1InitContainerWndInvisiblyPr=REBASE(0x16B5D50);
            const uintptr_t AdPlayerStep2FinishLoadAdSetAdStringSucc=REBASE(0x16B6C00);
            const uintptr_t AdPlayerStep2LoadAdUsingHandleSetAdStrin=REBASE(0x16B68D0);
            const uintptr_t AdPlayerStep41FinishErrorAdProgress=REBASE(0x16B75A0);
            const uintptr_t AdPlayerStep4ERRORShowAdPreviousSteps=REBASE(0x16B7320);
            const uintptr_t AdPlayerStep5AdPlayerHasNeverBeen=REBASE(0x16B8170);
            const uintptr_t CreatingWindowsNativeAdsImplInstance=REBASE(0x16B47F0);
            const uintptr_t GettingWindowsNativeAdsImplInstance=REBASE(0x16B4AF0);
            const uintptr_t SendEventToEngineCalledEventMarshallingT=REBASE(0x16B43B0);
        }
        namespace WindowsRawInputBrokerLog
        {
            const uintptr_t GetRawInputDataSizeQueryFailedErrorRetur=REBASE(0x44D6418);
            const uintptr_t RegisterRawInputDevicesFailedErrorHwndRe=REBASE(0x44D6260);
        }
        namespace WindowsSystemThemeProtocol
        {
            const uintptr_t DestroyingWindowsSystemThemeProtocol=REBASE(0x5157110);
            const uintptr_t FailedInitializeWinRTWindowsSystemTheme=REBASE(0x5155B20);
            const uintptr_t IsDarkModeCalledButWinRTFailedInitialize=REBASE(0x5157220);
        }
        namespace WindowsThemeInit
        {
            const uintptr_t InvalidThemeValueMappedUserId=REBASE(0x718570);
        }
        namespace WndProcessCheck
        {
            const uintptr_t CannotCreateListeningEventVideoPreroll=REBASE(0x75AAE0);
            const uintptr_t FailedParseCommandLineArgs=REBASE(0x606BE20);
            const uintptr_t UnableRestoreResolutionChangeDisplaySett=REBASE(0x16BD120);
            const uintptr_t Version=REBASE(0x756190);
            const uintptr_t ViewFindBestMonitorMatchEnumDisplaySetti=REBASE(0x16BCC90);
            const uintptr_t ViewGeCurrentDesctopResolutionGetMonitor=REBASE(0x16BDB90);
            const uintptr_t WaitForNewPlayerProcessNewWaitingMutexRe=REBASE(0x759240);
        }
        namespace WrapLogChannel
        {
            const uintptr_t AutoSkinnedMeshFailedLoad=REBASE(0x1B36DC0);
            const uintptr_t DeformerContextCorePerformFittingSkipped=REBASE(0x1D1F690);
            const uintptr_t DeformerContextCorePerformFittingWithSha=REBASE(0x1D202C0);
            const uintptr_t DeformerContextCorePerformSkippedPerform=REBASE(0x1D24510);
            const uintptr_t DeformerVertexBufferAllocationOOMVertexC=REBASE(0x1D469D8);
            const uintptr_t DistinctWrapTargetsHaveSameCanonical=REBASE(0x1D10350);
            const uintptr_t HsrDataSizeMismatchVsClear=REBASE(0x1B06B60);
            const uintptr_t LCDEFORMERPROPERTYSETResultFlight=REBASE(0x18C9660);
            const uintptr_t LCDEFORMERPROPERTYSETResultHit=REBASE(0x18C8730);
            const uintptr_t LCFPCLAIMFingerprintResultSource=REBASE(0x1900A30);
            const uintptr_t LCFPKEYResultCacheableReason=REBASE(0x1D27EB0);
            const uintptr_t LCFPKEYResultCompletePropertySetId=REBASE(0x1D297E0);
            const uintptr_t LCFPPUBLISHFingerprintResultWinner=REBASE(0x18FFBE0);
            const uintptr_t LCFPSOLVEFingerprintResultOwner=REBASE(0x19025C0);
            const uintptr_t LCFPSOLVEFingerprintResultReleased=REBASE(0x18FBB70);
            const uintptr_t LCPSDEBUGEventSeqModel=REBASE(0x1B191D0);
            const uintptr_t LLTAllocationOOMBuildInternalRbfSize=REBASE(0x6156440);
            const uintptr_t LLTAllocationOOMBuildOrGetFromRegistryRb=REBASE(0x61568D0);
            const uintptr_t LLTDecompositionFailedBuildInternalInfoR=REBASE(0x1D4E010);
            const uintptr_t LLTSolveAllocationOOMBuildInternalWithCa=REBASE(0x6156690);
            const uintptr_t LayeredClothingCacheOptimizations=REBASE(0x18BABD0);
            const uintptr_t LayeredClothingFetchBailREASONValid=REBASE(0x18D1190);
            const uintptr_t MeshDeformerContextAvatarTooFarAwayOrigi=REBASE(0x1D47C00);
            const uintptr_t MeshDeformerContextPartSetAlternateMeshI=REBASE(0x1B39CC0);
            const uintptr_t MeshDeformerPerformTaskLaunchedDifferent=REBASE(0x18D38F0);
            const uintptr_t MeshDeformerUpdateDatamodelSolvedContext=REBASE(0x18C1DC0);
            const uintptr_t OffThreadRbxStorageWriteFailedMesh=REBASE(0x1B3B930);
            const uintptr_t RBFAllocationOOMBuildInternalRbfSize=REBASE(0x6156590);
            const uintptr_t RBFAllocationOOMBuildInternalWsRbfSize=REBASE(0x6156350);
            const uintptr_t RBFAllocationOOMPackZeroWeightsRbfSize=REBASE(0x6155E70);
            const uintptr_t RbfFoundMemSizeKBCount=REBASE(0x1D09D30);
            const uintptr_t RbfLLTFRESHCacheMissWill=REBASE(0x1D51F10);
            const uintptr_t RejectingComposedCageTopologyExceeds16=REBASE(0x1D0F030);
            const uintptr_t ShapeFitSolvingLayerCageVertices=REBASE(0x1D21FB0);
            const uintptr_t SkinningTransferFailedSaveMesh=REBASE(0x1B3FA70);
            const uintptr_t SkinningTransferUpdateDatamodelSkinningC=REBASE(0x18CE7B0);
            const uintptr_t SkinningTransferUpdateEndTransferCalled=REBASE(0x18CEB30);
            const uintptr_t WrapContentProviderProcessTaskUnexpected=REBASE(0x19033D0);
            const uintptr_t WrapDeformMeshProviderFailedReadMeshRbxS=REBASE(0x118D950);
            const uintptr_t WrapDeformMeshProviderFailedSaveMeshRbxS=REBASE(0x18F9200);
            const uintptr_t WrapDeformMeshProviderFetchCachedMeshIdT=REBASE(0x18F9EB0);
            const uintptr_t WrapDeformMeshProviderRegisterDeformedMe=REBASE(0x18F99B0);
            const uintptr_t WrapDeformMeshProviderUpdateTunableMinCu=REBASE(0x1B36B4B);
            const uintptr_t WrapDeformerCanceledAsyncUpdateContextTh=REBASE(0x18BE260);
            const uintptr_t WrapDeformerCoalesceStructuralInvalidati=REBASE(0x18C5360);
            const uintptr_t WrapDeformerContextCoreBaseWrapCAddedPie=REBASE(0x1D0E210);
            const uintptr_t WrapDeformerContextCoreLayerOutBounds=REBASE(0x1D175A0);
            const uintptr_t WrapDeformerContextCoreLayerSolutionName=REBASE(0x1D1D3B0);
            const uintptr_t WrapDeformerCreateDispatcher=REBASE(0x18BCC00);
            const uintptr_t WrapDeformerDispatcherStepSucceeded=REBASE(0x1B13A78);
            const uintptr_t WrapDeformerFetchMeshesCouldAccess=REBASE(0x18C2370);
            const uintptr_t WrapDeformerForceUpdate=REBASE(0x18C81D0);
            const uintptr_t WrapDeformerInvalidateHSR=REBASE(0x18C7D00);
            const uintptr_t WrapDeformerPerformTaskLaunchedDifferent=REBASE(0x18CC800);
            const uintptr_t WrapDeformerProcessInvalidationImmediate=REBASE(0x18C5700);
            const uintptr_t WrapDeformerRegisterWrap=REBASE(0x18C3D30);
            const uintptr_t WrapDeformerStartAsyncAssetFetch=REBASE(0x18D0720);
            const uintptr_t WrapDeformerStartAsyncPerformContextFlig=REBASE(0x18CA800);
            const uintptr_t WrapDeformerStartAsyncSkinningTransferCo=REBASE(0x18CD9E0);
            const uintptr_t WrapDeformerSuppressedInvalidationDeadAv=REBASE(0x18C4C10);
            const uintptr_t WrapDeformerUnregisterWrap=REBASE(0x18C43F0);
            const uintptr_t WrapDeformerUpdateDatamodelSkinningCould=REBASE(0x18DA3B0);
            const uintptr_t WrapDeformerUpdateDatamodelSolvedContext=REBASE(0x18BF510);
            const uintptr_t WrapDeformerWrapComponentsLayersTargetsD=REBASE(0x18C38F0);
            const uintptr_t WrapLayeredDeformerApplySkinningTransfer=REBASE(0x18D26D0);
        }
        namespace WriteOnlyBuffer
        {
            const uintptr_t CannotAppendDataMovedWriteOnlyBuffer=REBASE(0x4A2BEB0);
            const uintptr_t CannotExtractReadOnlySharedBufferMovedWr=REBASE(0x4A2C0A0);
            const uintptr_t FailedAllocateMemoryWriteOnlyBuffer=REBASE(0x623E540);
            const uintptr_t FailedAppendBuffer=REBASE(0x623E610);
            const uintptr_t FailedOpenFileErrno=REBASE(0x4A2B7D0);
            const uintptr_t WriteOnlyBufferMovedCannotExtractFilePat=REBASE(0x4A2C3E0);
            const uintptr_t WriteOnlyBufferMovedCannotGetFilePath=REBASE(0x4A2C290);
        }
    }
}
