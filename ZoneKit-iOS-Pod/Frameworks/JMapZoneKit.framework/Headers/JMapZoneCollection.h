//
//  JMapZoneCollection.h
//  JMapZone
//
//  Created by Aaron Wong on 2017-04-04.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapZoneKit/JMapZone.h>

@interface JMapZoneCollection : JMapBaseCollection

/*!
 * Get all object in collection
 *
 * @return an array of JMapZone objects
 */
- (nonnull NSArray <JMapZone *>*)getAll;

/*!
 * Get By External ID
 * @param externalId ID to search for
 *
 * @return An array of JMapZone objects associase to the external ID
 */
- (nonnull NSArray <JMapZone *>*)getByExternalId:(nonnull NSString *)externalId;

/*!
 * Get JMapZone object by ID in collection
 * @param id ID to search for
 *
 * @return JMapZone associated to ID or a nil if JMapBaseModel does not exists
 */
- (nullable JMapZone *)getById:(NSInteger)id;

/*!
 * Get JMapZones by name in collection
 * @param name String to search for in zone collections
 *
 * @return Array of JMapZone associated to name provided
 */
- (nonnull NSArray<JMapZone *>*)getByName:(nonnull NSString *)name;

/*!
 * Get JMapZones by wapoint in collection
 * @param waypoint JMapWaypoint to search for in zone collections
 *
 * @return Array of JMapZone associated to waypoint provided
 */
- (nonnull NSArray<JMapZone *>*)getByWaypoint:(nonnull JMapWaypoint *)waypoint;

/*!
 * Get JMapZones by map in collection
 * @param map JMapMap to search for in zone collections
 *
 * @return Array of JMapZone associated to map object provided
 */
- (nonnull NSArray<JMapZone *>*)getByMap:(nonnull JMapMap *)map;

@end
