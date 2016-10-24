//
//  FCDataHandler.h
//  FitCloud
//
//  Created by 远征 马 on 16/9/5.
//  Copyright © 2016年 远征 马. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FCDefine.h"

/**
 如果接口入参为空数据则不做回调处理
 */

@interface FCDataHandler : NSObject

/**
 *  手表系统设置数据解析
 *
 *  @param data       手环系统设置数据
 *  @param retHandler 分割结果回调(传入空数据回调不会处理)
 */
+ (void)divideConfigureData:(NSData*)data retHandler:(FCConfigureDataHandler)retHandler;

/**
 *  手表软硬件版本数据解析
 *
 *  @param versionData 软硬件版本数据
 *  @param retHandler 解析结果NSData回调(传入空数据回调不会处理)
 */
+ (void)divideVersionData:(NSData*)versionData retHandler:(FCVersionDataHandler)retHandler;

/**
 *  手表软硬件版本数据解析
 *
 *  @param versionData 软硬件版本数据
 *  @param retHandler 解析结果字符串回调(传入空数据回调不会处理)
 */
+ (void)parseVersionData:(NSData *)versionData retHandler:(FCVersionStringHandler)retHandler;


/**
 解析闹钟数据

 @param alarmData  闹钟原始数据
 @param retHandler 解析结果回调(包含FCAlarmObject的数组)
 */
+ (void)parseAlarmData:(NSData*)alarmData retHandler:(void(^)(NSArray *retArray))retHandler;


/**
 消息通知开关设置数据解析

 @param data       消息通知开关数据
 @param retHandler 消息通知开关解析结果回调
 */
+ (void)parseNotificationData:(NSData*)data retHandler:(void(^)(NSDictionary *retDict))retHandler;

/**
 手环显示设置数据解析

 @param data       手环显示设置数据
 @param retHandler 手环显示设置数据解析结果回调
 */
+ (void)parseDisplayData:(NSData*)data retHandler:(void(^)(NSDictionary *retDict))retHandler;


/**
 手环功能设置数据解析
 @{
    功能开关设置2byte: bit 1:翻腕亮屏 bit2-bit16 保留位
 @}
 @param data       手环功能设置数据
 @param retHandler 结果回调
 */
+ (void)parseFunctionSwicthData:(NSData*)data retHandler:(void(^)(NSDictionary *retDict))retHandler;



/**
 健康定时监测数据
 @{ 
    健康定时监测项目：（1）开关状态 （2）开始时间 （3）结束时间
    注：开始时间和结束时间是从0点开始的分钟数 （2:00 则为 2x60 = 120分钟）
 @}
 @param data       健康定时监测数据
 @param retHandler 结果回调
 */
+ (void)parseHealthMonitorData:(NSData*)data retHandler:(void(^)(NSDictionary *retDict))retHandler;

/**
 日总运动数据解析

 @param data       日总运动数据
 @param retHandler 日总运动数据结果回调
 */
+ (void)parseTotalDailyData:(NSData*)data retHandler:(FCTotalDailyDataHandler)retHandler;


/**
 解析运动数据，返回的每五分钟运动数据记录
 retArray 返回NSDictionary对象:
 @{
    @"year":@(16),@"month":@(9),@"day":@(29),@"minutes":@(200),@"stepCount":@(1000)};
 @}
 
 @param data       手表返回的运动数据包
 @param retHandler 每五分钟运动数据回调
 */
+ (void)parseMotionData:(NSData*)data retHandler:(void(^)(NSArray *retArray))retHandler;


/**
 解析睡眠数据，返回每五分钟睡眠数据记录
 retArray 返回NSDictionary对象：
 @{
    @"year":@(16),@"month":@(9),@"day":@(29),@"minutes":@(200),@"sleep":@(1000)
 @};
 
 @param data       睡眠数据包
 @param retHandler 每五分钟睡眠数据回调
 */
+ (void)parseSleepData:(NSData*)data retHandler:(void(^)(NSArray *retArray))retHandler;
@end
