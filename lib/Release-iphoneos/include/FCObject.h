//
//  FCObject.h
//  FitCloud
//
//  Created by 远征 马 on 2016/10/18.
//  Copyright © 2016年 远征 马. All rights reserved.
//



#import <Foundation/Foundation.h>


#pragma mark - FCAlarmObject (闹钟)

@interface FCAlarmObject : NSObject
@property (nonatomic, strong) NSNumber *alarmId; // 闹钟id
@property (nonatomic, strong) NSNumber *year;
@property (nonatomic, strong) NSNumber *month;
@property (nonatomic, strong) NSNumber *day;
@property (nonatomic, strong) NSNumber *hour;
@property (nonatomic, strong) NSNumber *minute;
@property (nonatomic, assign) BOOL isOn;
// 闹钟循环周期 7bits 从低位到高位道标周一到周日设置 ，所有bit都为0,表示当天有效
@property (nonatomic, strong) NSNumber *cycle;
- (NSData*)alarmData;
@end




#pragma mark - FCDisplayObject（手表显示设置）
// 手表显示设置，打开其中任何一项，手表屏幕点击都会显示对应的条目
@interface FCDisplayObject : NSObject
@property (nonatomic, assign) BOOL dateTime;
@property (nonatomic, assign) BOOL stepCount;
@property (nonatomic, assign) BOOL calorie;
@property (nonatomic, assign) BOOL distance;
@property (nonatomic, assign) BOOL sleep;
@property (nonatomic, assign) BOOL heartRate;
@property (nonatomic, assign) BOOL bloodOxygen;
@property (nonatomic, assign) BOOL bloodPressure;
@property (nonatomic, assign) BOOL weatherForecast;
@property (nonatomic, assign) BOOL findPhone;
@property (nonatomic, assign) BOOL displayId;
+ (instancetype)modelWithData:(NSData*)data;
- (NSData*)displayData;
@end


#pragma mark - FCMsgNotificationObject (消息通知设置)

@interface FCNotificationObject : NSObject
@property (nonatomic, assign) BOOL callEnable;
@property (nonatomic, assign) BOOL smsEnable;
@property (nonatomic, assign) BOOL qqEnable;
@property (nonatomic, assign) BOOL weChatEnable;
@property (nonatomic, assign) BOOL facebookEnable;
@property (nonatomic, assign) BOOL twitterEnable;
@property (nonatomic, assign) BOOL linkedinEnable;
@property (nonatomic, assign) BOOL instagramEnable;
@property (nonatomic, assign) BOOL pinterestEnable;
@property (nonatomic, assign) BOOL whatsappEnable;
@property (nonatomic, assign) BOOL lineEnable;
@property (nonatomic, assign) BOOL fbMessageEnable;
@property (nonatomic, assign) BOOL otherAppEnable;
@property (nonatomic, assign) BOOL showMsgEnable;
@property (nonatomic, assign) BOOL disconnectPhoneEnable;
@property (nonatomic, assign) BOOL disconnectDeviceEnable;
@property (nonatomic, assign) BOOL heartRateEnable;
+ (instancetype)modelWithData:(NSData*)data;
- (NSData*)nfSettingData;
@end

#pragma mark -  FCFunctionSwitchObject (功能开关)

@interface FCFunctionSwitchObject : NSObject
@property (nonatomic, assign) BOOL twLightScreen;
+ (instancetype)modelWithData:(NSData*)data;
- (NSData*)functionSwitchData;
@end


#pragma mark - FCLongSitObject (久坐提醒)

@interface FCLongSitObject : NSObject
@property (nonatomic, assign) BOOL isOn;
@property (nonatomic, assign) BOOL isLunchBreakFree;
@property (nonatomic, assign) NSUInteger stMinute;
@property (nonatomic, assign) NSUInteger edMinute;
@end


#pragma mark - FCDefaultBloodPressureObject (默认血压)

@interface FCDefaultBloodPressureObject : NSObject

@end
