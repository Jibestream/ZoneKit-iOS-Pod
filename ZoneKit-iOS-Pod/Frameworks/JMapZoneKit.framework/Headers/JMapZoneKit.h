//
//  JMapZoneKit.h
//  JMapZone
//
//  Created by Aaron Wong on 2017-04-03.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JMapControllerKit/JMapController.h>
#import <JMapZoneKit/JMapZoneCollection.h>
#import <JMapZoneKit/JMapZone.h>

/**
 *  The JMapZoneKitDelegate model.
 */
@protocol JMapZoneKitDelegate <NSObject>

@optional
/**
 *  Delegate method for zones entered by moving object
 *
 *  @param movingObject referenced moving object
 *  @param zones zones entered by moving object
 */
- (void) zonesEnteredByMovingObject:(nullable JMapMovingObject*)movingObject zones:(nullable NSArray <JMapZone *>*)zones;

/**
 *  Delegate method for zones exited by moving object
 *
 *  @param movingObject referenced moving object
 *  @param zones zones exited by moving object
 */
- (void) zonesExitedByMovingObject:(nullable JMapMovingObject*)movingObject zones:(nullable NSArray <JMapZone *>*)zones;

@end


@interface JMapZoneKit : NSObject

#pragma mark Zone Kit Initialization

/**
 * Collection of all zones
 */
@property (nonatomic, strong, readonly, nullable) JMapZoneCollection *zones;

/**
 * The JMapZoneKitDelegate property
 */
@property (nonatomic, weak, nullable) id<JMapZoneKitDelegate> delegate;

/**
 *  Init With Controller : Contructor to create a JMapZoneKit with controller
 *
 *  @param core JMapJCore being used in implmentation
 *  @param controller JMapController being used in implementation
 *
 *  @return newly created JMapZoneKit object
 */
- (nonnull instancetype)initWithCore:(nonnull JMapJCore *)core andController:(nonnull JMapController *)controller;

/**
 *  Get Zones
 *
 *  @param completionHandler returns error if error has occured with network request
 */
- (void)getZones:(nonnull __attribute__((noescape)) void(^)(JMapError* _Nullable error))completionHandler;

#pragma mark Get With Zone Methods

/**
 *  Set Zones Interactivity
 *
 *  @param interactive BOOL used to set interactivity of all zones
 */
- (void)setZonesInteractivity:(BOOL)interactive;

/**
 *  Get Destinations In Zone
 *
 *  @param zone JMapZone being used for searching
 *
 *  @return array of JMapDestination objects
 */
- (nonnull NSArray<JMapDestination *>*)getDestinationsInZone:(nonnull JMapZone*)zone;

/**
 *  Get Waypoints In Zone
 *
 *  @param zone JMapZone being used for searching
 *
 *  @return array of JMapWaypoint objects
 */
- (nonnull NSArray <JMapWaypoint *>*)getWaypointsInZone:(nonnull JMapZone *)zone;

/**
 *  Get Amenities In Zone
 *
 *  @param zone JMapZone being used for searching
 *
 *  @return array of created JMapAmenity objects
 */
- (nonnull NSArray<JMapAmenity*> *)getAmenitiesInZone:(nonnull JMapZone *)zone;

/**
 *  Get Closest Waypoint In Zone To Point
 *
 *  @param zone JMapZone being used for searching
 *
 *  @param point JMapPoint reference to search from
 *
 *  @param searchType Search types: Proximity/Grid. Defaults to Proximity.
 *
 *  @return a JMapWaypoint object or nil if zone does not contain waypoints
 */
- (nullable JMapWaypoint*)getClosestWaypointInZone:(nonnull JMapZone *)zone toPoint:(nonnull JMapPoint*)point withSearchType:(nullable NSString *)searchType;

/**
 *  Get Centroid Of Zone
 *
 *  @param zone JMapZone being used for getting the centroid
 *
 *  @param map JMapMap being used to getting centroid of zone on the map
 *
 *  @return CGPoint centroid of the zone
 */
- (CGPoint)getCentroidOfZone:(nonnull JMapZone *)zone onMap:(nonnull JMapMap*)map;

/**
 *  Get Bounds Of Zone
 *
 *  @param zone JMapZone object to retrieve the bound
 *  @param map JMapMap object to retrieve the bound
 *  @return rect bound of the zone
 */
- (CGRect)getBoundsOfZone:(nonnull JMapZone *)zone onMap:(nonnull JMapMap *)map;

#pragma mark Zone Drawing

/**
 *  Highlight Units In Zone
 *
 *  @param zone JMapZone being used to search for units
 */
- (void)highlightUnitsInZone:(nonnull JMapZone *)zone withStyle:(nonnull JMapStyle*)style;

/**
 *  Get Polygon Of Zone
 *
 *  @param zone JMapZone object to get polygon from
 *  @param map JMapMap object to get the polygon
 *  @return a polygon object of the zone
 */
- (nullable Polygon *)getPolygonOfZone:(nonnull JMapZone *)zone onMap:(nonnull JMapMap *)map;

/**
 *  Draw Polygon Of Zone
 *
 *  @param zone JMapZone object to draw
 *  @param map JMapMap object to draw the polygon
 *  @param style optional JMapStyle object to set the styling of the zone on the map
 */
- (void)drawPolygonOfZone:(nonnull JMapZone *)zone onMap:(nonnull JMapMap *)map withStyle:(nullable JMapStyle *)style;

/**
 *  Listener For Moving Object Animation Completion
 *
 *  @param notification NSNotification callback object
 */
- (void)receiveAnimationComplete:(nonnull NSNotification *)notification;

/**
 *  Method To Subscribe To Listening For Moving Object Animations
 *
 *  @param delegate JMapZoneKitDelegate passed in for triggering delegate callbacks
 */
- (void)watchMovingObjects:(nonnull id <JMapZoneKitDelegate>)delegate;

/**
 *  Method To Unsubscribe To Listening For Moving Object Animations
 */
- (void)unwatchMovingObjects;

@end
