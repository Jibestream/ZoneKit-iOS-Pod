//
//  JMapZoneObject.h
//  JMapZoneObject
//
//  Created by Aaron Wong on 2017-04-04.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>

/**
 *  The JMapZoneObject model
 */
@interface JMapZoneObject : JMapBaseModel

/**
 * Zone Name
 */
@property (nonatomic, strong, readonly, nullable) NSString *name;

/**
 * Zone Description
 */
@property (nonatomic, strong, readonly, nullable) NSString *zoneDescription;

/**
 * Color of the zone
 */
@property (nonatomic, strong, readonly, nullable) UIColor *color;

/**
 * Location association to the zone
 */
@property (nonatomic, strong, readonly, nullable) NSArray<JMapLocation*> *locations;

/**
 * JMapZoneObject init method
 *
 *  @param dict NSDictionary properties of the zone object
 *  @return A JMapZoneObject instance
 */
-(nullable instancetype)initWithDictionary:(nonnull NSDictionary *)dict;

@end
