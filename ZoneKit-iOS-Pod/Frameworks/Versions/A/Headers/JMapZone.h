//
//  JMapZone.h
//  JMapZone
//
//  Created by Aaron Wong on 2017-04-04.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

@interface JMapZone : JMapBaseModel

/*!
 * Zone Name
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;

/*!
 * Zone Description
 */
@property (nonatomic, strong, readonly, nullable) NSString *zoneDescription;

/*!
 * Color of the zone
 */
@property (nonatomic, strong, readonly, nullable) UIColor *color;

@property (nonatomic, strong, readonly, nullable) NSArray<JMapLocation*> *locations;

-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
