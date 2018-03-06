//
//  JMapZoneCollection.h
//  JMapZone
//
//  Created by Aaron Wong on 2017-04-04.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>
#import "JMapZoneObject.h"

/**
 *  The JMapZoneCollection model
 */
@interface JMapZoneCollection : JMapBaseCollection

/**
 * Get all object in collection
 *
 * @return an array of JMapZoneObjects
 */
- (nonnull NSArray <JMapZoneObject *>*)getAll;

/**
 * Get By External ID
 * @param externalId ID to search for
 *
 * @return An array of JMapZoneObjects associase to the external ID
 */
- (nonnull NSArray <JMapZoneObject *>*)getByExternalId:(nonnull NSString *)externalId;

/**
 * Get JMapZoneObject by ID in collection
 * @param id ID to search for
 *
 * @return JMapZoneObject associated to ID or a nil if JMapBaseModel does not exists
 */
- (nullable JMapZoneObject *)getById:(NSInteger)id;

/**
 * Get JMapZoneObjects by name in collection
 * @param name String to search for in zone collections
 *
 * @return Array of JMapZoneObject associated to name provided
 */
- (nonnull NSArray<JMapZoneObject *>*)getByName:(nonnull NSString *)name;

/**
 * Get JMapZoneObjects by wapoint in collection
 * @param waypoint JMapWaypoint to search for in zone collections
 *
 * @return Array of JMapZoneObject associated to waypoint provided
 */
- (nonnull NSArray<JMapZoneObject *>*)getByWaypoint:(nonnull JMapWaypoint *)waypoint;

/**
 * Get JMapZoneObject by map in collection
 * @param map JMapMap to search for in zone collections
 *
 * @return Array of JMapZoneObject associated to map object provided
 */
- (nonnull NSArray<JMapZoneObject *>*)getByMap:(nonnull JMapMap *)map;

@end
