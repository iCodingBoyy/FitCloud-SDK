//
//  FCDefine.h
//  FitCloud
//
//  Created by 远征 马 on 16/9/5.
//  Copyright © 2016年 远征 马. All rights reserved.
//

#ifndef FCDefine_h
#define FCDefine_h

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>


/**
 *  手表同步类型
 */
typedef NS_ENUM(NSInteger, FCSyncType) {

    FCSyncTypeNone,
    FCSyncTypeUnBindDevice = 18, /* 解绑设备*/
    FCSyncTypeLoginDevice = 19, /* 登录设备*/
    FCSyncTypeBindDevice = 20, /* 绑定设备*/
    FCSyncTypeLoginToSyncTime = 21, /* 登录设备同步时间*/
    FCSyncTypeFindWristband = 23, /* 查找手环*/
    FCSyncTypeGetAlarmList = 24, /* 同步闹钟列表*/
    FCSyncTypeSetAlarmData = 25, /* 闹钟设置*/
    FCSyncTypeBatteryPowerAndChargingState = 26, /* 电量电量和充电状态获取*/
    FCSyncTypeGetSystemSettings = 27, /* 获取系统设置*/
    FCSyncTypeDisplaySettings = 28, /* 手表显示设置*/
    FCSyncTypeFunctionSwitchSettings = 29, /* 手表功能开关设置*/
    FCSyncTypeNotificationSettings = 30, /* 消息通知开关设置*/
    FCSyncTypeSedentaryReminder = 31, /* 久坐提醒设置*/
    FCSyncTypeHealthMonitoring = 32, /* 健康实时监测设置*/
    FCSyncTypeDrinkReminder = 33, /* 喝水提醒设置*/
    FCSyncTypeWearingStyle = 34, /* 穿戴方式设置*/
    FCSyncTypeCameraState = 35, /* 相机前后台状态*/
    FCSyncTypeDefaultBloodPressure = 36, /* 默认血压*/
    FCSyncTypeUpdateWeather = 37, /* 天气设置*/
    FCSyncTypeUserProfile = 38, /* 用户资料设置*/
    FCSyncTypeHistoryData = 39, /* 历史数据同步*/
    FCSyncTypeExercise = 40, /* 运动数据*/
    FCSyncTypeSleep = 41, /* 睡眠数据*/
    FCSyncTypeHeartRate = 42, /* 心率数据*/
    FCSyncTypeBloodOxygen = 43, /* 血氧数据*/
    FCSyncTypeUltraviolet = 44, /* 紫外线数据*/
    FCSyncTypeBreathingRate = 45, /* 呼吸频率数据*/
    FCSyncTypeBloodPressure = 46, /* 血压数据*/
    FCSyncTypeOpenRealtimeSync = 47, /* 打开健康实时同步*/
    FCSyncTypeCloseRealtimeSync = 48, /* 关闭健康实时同步*/
    FCSyncTypeEnd = 100, /* 同步结束*/
};


/**
 实时同步类型

 - FCRTSyncTypeNone:
 - FCRTSyncTypeHeartRate:     心率实时同步
 - FCRTSyncTypeBloodOxygen:   血氧实时同步
 - FCRTSyncTypeBloodPressure: 血压实时同步
 - FCRTSyncTypeBreathingRate: 呼吸频率实时同步
 */
typedef NS_ENUM(NSInteger, FCRTSyncType)
{
    FCRTSyncTypeNone,
    FCRTSyncTypeHeartRate,
    FCRTSyncTypeBloodOxygen,
    FCRTSyncTypeBloodPressure,
    FCRTSyncTypeBreathingRate,
};

/**
 *  手表同步响应状态
 */
typedef NS_ENUM(NSInteger, FCSyncResponseState) {

    FCSyncResponseStateNone,
    FCSyncResponseStatePowerOff, // 蓝牙未打开
    FCSyncResponseStateNotConnected, // 蓝牙未连接
    FCSyncResponseStateDisconnect, // 蓝牙断开连接
    FCSyncResponseStateParameterError, // 参数错误
    FCSyncResponseStateSyncing, // 正在同步数据
    FCSyncResponseStateSuccess, // 同步响应成功
    FCSyncResponseStateError, // 同步响应失败
    FCSyncResponseStateTimeOut, // 同步超时
    FCSyncResponseStateRTTimeOut, //健康实时同步2分钟超时
};


/**
 扫描到的外设列表回调

 @param retArray    扫描到的外设列表
 @param aPeripheral 当前返回的外设
 */
typedef void (^FCDeviceListHandler)(NSArray<CBPeripheral*>*retArray,CBPeripheral *aPeripheral);


/**
 蓝牙外设回调

 @param aPeripheral 当前返回的外设
 */
typedef void (^FCPeripheralHandler)(CBPeripheral *aPeripheral);


/**
 绑定所需用户信息

 @param sex    用户性别
 @param age    用户年龄
 @param weight 用户体重
 @param height 用户身高
 */
typedef void (^FCUserDataHandler)(UInt32 sex, UInt32 age, UInt32 weight, UInt32 height);


/**
 手表穿戴方式

 @param lefthHand 是否是左手佩戴
 */
typedef void (^FCWearStyleHandler)(BOOL lefthHand);



/**
 登录、绑定所需用户和手机信息回调

 @param guestId 用户唯一id
 @param mode    手机系统版本
 @param os      手机系统类型
 */
typedef void (^FCAuthDataHandler)(UInt64 guestId, UInt8 mode, UInt8 os);


/**
 *  同步结果回调
 *
 *  @param syncType 当前同步类型，当state为FCSyncResponseStateSuccess返回最后一种同步类型
 *  @param state    同步结果返回状态
 */
typedef void (^FCSyncResultHandler)(FCSyncType syncType, FCSyncResponseState state);


/**
 同步流程回调

 @param syncType 当前同步的类型
 */
typedef void (^FCSyncStepHandler)(FCSyncType syncType);


/**
 手表绑定入参block

 @param authDataHandler  用户id和手机系统信息，注：FCAuthDataHandler参数必填
 @param userDataHandler  用户信息，如不设置则使用默认数据
 @param wearStyleHandler 穿戴方式，如不设置则使用默认值
 */
typedef void (^FCBoundDataHandler)(FCAuthDataHandler authDataHandler,FCUserDataHandler userDataHandler,FCWearStyleHandler wearStyleHandler);


typedef void (^FCLoginDatahandler)(FCAuthDataHandler authDataHandler);

/**
 *  同步数据回调
 *
 *  @param syncType 同步数据的类型
 *  @param data     同步的数据
 */
typedef void (^FCSyncDataHandler)(FCSyncType syncType, NSData *data);


/**
 *  同步数据记录条数回调
 *
 *  @param count 同步记录个数
 */
typedef void (^FCSyncCountHandler) (UInt16 count);


/**
 *  解除绑定回调
 *
 *  @param state  同步响应结果
 *  @param status 解绑结果
 */
typedef void (^FCSyncUnBoundHandler)(FCSyncResponseState state, UInt8 status);


/**
 *  数据实时同步回调
 *
 *  @param data 实时同步响应数据
 */
typedef void (^FCRTSyncDataHandler)(NSData *data);


/**
 *  手表电池电量和充电状态回调
 *
 *  @param powerValue    电池电量
 *  @param chargingState 充电状态
 */
typedef void (^FCSyncPowerAndChargingStateHandler)(UInt8 powerValue, UInt8 chargingState);


/**
 *  手环系统配置信息回调
 *
 *  @param msgNFData    消息通知开关 4byte
 *  @param displayData  手环显示配置 2byte
 *  @param fcSwitchData 功能开关配置 2byte
 *  @param versionData  软硬件版本信息配置 32byte
 *  @param monitorData  健康实时监测配置 5byte
 *  @param longSitData  久坐提醒配置 5byte
 *  @param bpData       默认血压配置 2byte
 *  @param drinkData    喝水提醒配置 1byte
 */
typedef void (^FCConfigureDataHandler)(NSData *msgNFData, NSData *displayData,NSData *fcSwitchData,NSData *versionData,NSData *monitorData,NSData *longSitData,NSData *bpData,NSData *drinkData);


/**
 *  手环软硬件版本信息回调
 *
 *  @param projData     项目号 6byte
 *  @param hardwareData 硬件号 4byte
 *  @param sdkData      sdk版本号 4byte
 *  @param patchData    软件patch版本号 6byte
 *  @param flashData    flash版本号 4byte
 *  @param fwAppData    固件app版本号 4byte
 *  @param seqData      序号 4byte
 */
typedef void (^FCVersionDataHandler)(NSData *projData,NSData *hardwareData,NSData *sdkData,NSData *patchData,NSData *flashData,NSData *fwAppData,NSData *seqData);


/**
 *  手环软硬件版本信息字符串回调
 *
 *  @param projNum       项目号
 *  @param hardware      硬件号
 *  @param sdkVersion    sdk版本号
 *  @param patchVerson   软件patch版本号
 *  @param falshVersion  flash版本号
 *  @param appVersion    固件app版本号
 *  @param serialNum     序号
 */
typedef void (^FCVersionStringHandler)(NSString *projNum,NSString *hardware,NSString *sdkVersion,NSString *patchVerson,NSString *falshVersion,NSString *appVersion,NSString *serialNum);


/**
 每日运动总数据结果回调

 @param steps        日总运动步数
 @param distance     日总运动距离
 @param calorie      日总运动卡路里
 @param dSleepTime   日总共深睡眠时间
 @param lSleepTime   日总浅睡眠时间
 @param avgHeartRate 平均心率
 */
typedef void (^FCTotalDailyDataHandler)(UInt32 steps, UInt32 distance, UInt32 calorie, UInt32 dSleepTime, UInt32 lSleepTime,UInt32 avgHeartRate);


#endif /* FCDefine_h */
