//
//  FitCloud.h
//  FitCloud
//
//  Created by 远征 马 on 16/9/5.
//  Copyright © 2016年 远征 马. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "FCConstants.h"
#import "FCDefine.h"



@interface FitCloud : NSObject
@property (nonatomic, strong) CBCentralManager *centralManager;
@property (nonatomic, strong) CBPeripheral *servicePeripheral;

@property (nonatomic, assign, readonly) FCSyncType syncType;

@property (nonatomic, assign, readonly) BOOL isSynchronizing;

@property (nonatomic, copy) dispatch_block_t findMobilePhoneBlock;
@property (nonatomic, copy) dispatch_block_t takePicturesBlock;

+ (instancetype)shared;


#pragma mark - 扫描与连接

/**
 扫描蓝牙外设
 
 @param retHandler 扫描到的外设数组回调block
 */

- (void)scanningPeripherals:(FCDeviceListHandler)retHandler;


/**
 扫描指定uuid的外设
 
 @param uuidString 蓝牙外设uuid
 @param retHandler 扫描外设对象回调block
 */
- (void)scanningPeripheralWithUUID:(NSString *)uuidString retHandler:(FCPeripheralHandler)retHandler;


/**
 停止扫描外设
 */
- (void)stopScanning;


/**
 连接指定的外设

 @param peripheral 要连接的外设
 */
- (void)connectPeripheral:(CBPeripheral*)peripheral;


/**
 断开连接指定外设

 @param peripheral 要断开连接的外设
 */
- (void)disconnectPeripheral:(CBPeripheral*)peripheral;


#pragma mark - 控制监听

/**
 查找手机控制监听
 */
- (void)setFindMobilePhoneBlock:(dispatch_block_t)findMobilePhoneBlock;


/**
 相机拍照控制监听
 */
- (void)setTakePicturesBlock:(dispatch_block_t)takePicturesBlock;


/**
 查找手环，手机发出此命令，手环震动响应
 
 @param retHandler 同步结果回调
 */
- (void)fcSetFindWristband:(FCSyncResultHandler)retHandler;



#pragma mark - 手表登录、绑定或解绑操作
/**
 手表绑定同步
 
 @param paramsHandler 手表绑定入参，如不设置则使用默认数据，具体描述见参数定义。
 @param dataHandler   手表绑定数据回调，此处回调数据为系统设置信息
 @param retHandler    手表绑定结果回调
 */
- (void)fcSetBindDevice:(FCBoundDataHandler)paramsHandler dataHandler:(FCSyncDataHandler)dataHandler retHandler:(FCSyncResultHandler)retHandler;


/**
 手表登录同步
 
 @param paramHandler 手表登录所需用户信息
 @param retHandler      同步结果回调
 */
- (void)fcSetLoginDevice:(FCLoginDatahandler)paramHandler retHandler:(FCSyncResultHandler)retHandler;

/**
 手表解除绑定
 
 @param retHandler 同步结果回调
 */
- (void)fcSetUnBindDevice:(FCSyncResultHandler)retHandler;



#pragma mark - 闹钟同步
/**
 同步闹钟设置数据

 @param data       闹钟设置数据
 @param retHandler 同步结果回调
 */
- (void)fcSetAlarmData:(NSData*)data retHandler:(FCSyncResultHandler)retHandler;

/**
 同步闹钟列表
 
 @param dataHandler 手表闹钟列表数据回调
 @param retHandler  同步结果回调
 */
- (void)fcGetAlarmList:(FCSyncDataHandler)dataHandler retHandler:(FCSyncResultHandler)retHandler;


#pragma mark - 功能设置

/**
 获取手表系统设置信息
 
 @param dataHandler 手表系统设置数据回调
 @param retHandler 同步结果回调
 */
- (void)fcGetSystemSetting:(FCSyncDataHandler)dataHandler retHandler:(FCSyncResultHandler)retHandler;


/**
 获取手表充电状态和电量信息
 
 @param dataHandler  手表电量和充电状态返回
 @param retHandler 同步结果回调
 */
- (void)fcGetBatteryPowerAndChargingState:(FCSyncPowerAndChargingStateHandler)dataHandler retHandler:(FCSyncResultHandler)retHandler;


/**
 设置手表显示数据

 @param data       手表显示设置数据
 @param retHandler 同步结果回调
 */
- (void)fcSetDisplayData:(NSData*)data retHandler:(FCSyncResultHandler)retHandler;


/**
 设置手表功能开关

 @param data       功能开关配置数据
 @param retHandler 同步结果回调
 */
- (void)fcSetFunctionSwitchData:(NSData*)data retHandler:(FCSyncResultHandler)retHandler;

/**
 设置手表消息通知开关

 @param data       要同步的消息通知开关数据
 @param retHandler 同步结果回调
 */
- (void)fcSetNotificationSettingData:(NSData*)data retHandler:(FCSyncResultHandler)retHandler;


/**
 设置久坐提醒信息

 @param data       久坐提醒数据
 @param retHandler 同步结果回调
 */
- (void)fcSetLongSitData:(NSData*)data retHandler:(FCSyncResultHandler)retHandler;


/**
 设置健康实时监测数据

 @param data       健康实时监测数据
 @param retHandler 同步结果回调
 */
- (void)fcSetHealthMonitorData:(NSData*)data retHandler:(FCSyncResultHandler)retHandler;



/**
 设置喝水提醒数据

 @param bEnabled   喝水提醒开关状态
 @param retHandler 同步结果回调
 */
- (void)fcSetDrinkRemindEnable:(BOOL)bEnabled retHandler:(FCSyncResultHandler)retHandler;


/**
 设置手表穿戴方式

 @param bEnabled   是否是左手佩戴
 @param retHandler 同步结果回调
 */
- (void)fcSetLeftHandWearEnable:(BOOL)bEnabled retHandler:(FCSyncResultHandler)retHandler;


/**
 设置app相机前后台状态，用于手表拍照控制

 @param bInForeground 是否在前台
 @param retHandler    同步结果回调
 */
- (void)fcSetCameraState:(BOOL)bInForeground retHandler:(FCSyncResultHandler)retHandler;


/**
 设置用户基本资料

 @param sex        性别
 @param age        年龄
 @param height     身高
 @param weight     体重
 @param retHandler 同步结果回调
 */
- (void)fcSetUserProfile:(UInt32)sex age:(UInt32)age height:(UInt32)height weight:(UInt32)weight retHandler:(FCSyncResultHandler)retHandler;


/**
 设置默认血压

 @param sbp        收缩压
 @param dbp        舒张压
 @param retHandler 同步结果回调
 */
- (void)fcSetBloodPressure:(UInt16)sbp dbp:(UInt16)dbp retHandler:(FCSyncResultHandler)retHandler;


/**
 设置天气

 @param temperature 当前温度
 @param hTemp       最高温度
 @param lTemp       最低温度
 @param state       状态
 @param cityName    城市名称
 @param retHandler  同步结果回调
 */
- (void)fcSetWeather:(int)temperature highTemp:(int)hTemp lowTemp:(int)lTemp state:(int)state cityName:(NSString*)cityName retHandler:(FCSyncResultHandler)retHandler;


#pragma mark - 健康实时同步

/**
 打开健康实时同步
 
 @param syncType    健康实时同步类型
 @param dataHandler 健康实时同步数据回调
 @param retHandler  同步结果回调
 */
- (void)fcOpenRealTimeSync:(FCRTSyncType)syncType dataHandler:(FCSyncDataHandler)dataHandler retHandler:(FCSyncResultHandler)retHandler;

/**
 关闭健康实时同步
 
 @param retHandler 同步结果回调
 */
- (void)fcCloseRealTimeSync:(FCSyncResultHandler)retHandler;



#pragma mark - 历史数据同步
/**
 手表历史数据同步，历史数据有不同类型，需要分步同步
 syncStepHandler返回当前正在同步的类型，dataHandler返回某一步同步的数据（如果有数据的话），retHandler返回最终同步结果
 @param syncStepHandler 同步流程回调，回调每一步的操作
 @param dataHandler     同步数据回调，每一步产生数据都会回调，无数据不回调
 @param retHandler      同步结果回调，一次调用后结束，返回响应结果和正在同步的操作
 */
- (void)fcGetHistoryData:(FCSyncStepHandler)syncStepHandler dataHandler:(FCSyncDataHandler)dataHandler retHandler:(FCSyncResultHandler)retHandler;

@end

