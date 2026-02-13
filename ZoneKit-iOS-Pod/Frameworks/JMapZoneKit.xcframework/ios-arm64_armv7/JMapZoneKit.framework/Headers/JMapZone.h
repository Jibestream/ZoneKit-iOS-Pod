//
//  JMapZone.h
//  JMapZone
//
//  Created by Aaron Wong on 2017-04-03.
//  Copyright © 2017 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <JMapControllerKit/JMapController.h>
#import "JMapZoneObject.h"
#import "JMapZoneCollection.h"

/**
 *  The JMapZoneDelegate model.
 */
@protocol JMapZoneDelegate <NSObject>

@optional
/**
 *  Delegate method for zones entered by moving object
 *
 *  @param movingObject referenced moving object
 *  @param zones zones entered by moving object
 */
- (void) zonesEnteredByMovingObject:(nullable JMapMovingObject*)movingObject zones:(nonnull NSArray <JMapZoneObject *>*)zones;

/**
 *  Delegate method for zones exited by moving object
 *
 *  @param movingObject referenced moving object
 *  @param zones zones exited by moving object
 */
- (void) zonesExitedByMovingObject:(nullable JMapMovingObject*)movingObject zones:(nonnull NSArray <JMapZoneObject *>*)zones;

@end

/**
 *  The JMapZone model
 */
@interface JMapZone : NSObject

#pragma mark Zone Initialization

/**
 * Collection of all zones
 */
@property (nonatomic, strong, readonly, nullable) JMapZoneCollection *zones;

/**
 * The JMapZoneDelegate property
 */
@property (nonatomic, weak, nullable) id<JMapZoneDelegate> delegate;

/**
 *  Init With Controller : Contructor to create a JMapZone with controller
 *
 *  @param core JMapJCore being used in implmentation
 *  @param controller JMapController being used in implementation
 *
 *  @return newly created JMapZone object
 */
- (nonnull instancetype)initWithCore:(nonnull JMapJCore *)core andController:(nonnull JMapController *)controller;

/**
 *  Get Zones
 *
 *  @param completionHandler returns error if error has occured with network request
 */
- (void)getZones:(void(^)(JMapError* _Nullable error))completionHandler;

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
 *  @param zone JMapZoneObject being used for searching
 *
 *  @return array of JMapDestination objects
 */
- (nonnull NSArray<JMapDestination *>*)getDestinationsInZone:(nonnull JMapZoneObject*)zone;

/**
 *  Get Waypoints In Zone
 *
 *  @param zone JMapZoneObject being used for searching
 *
 *  @return array of JMapWaypoint objects
 */
- (nonnull NSArray <JMapWaypoint *>*)getWaypointsInZone:(nonnull JMapZoneObject *)zone;

/**
 *  Get Amenities In Zone
 *
 *  @param zone JMapZoneObject being used for searching
 *
 *  @return array of created JMapAmenity objects
 */
- (nonnull NSArray<JMapAmenity*> *)getAmenitiesInZone:(nonnull JMapZoneObject *)zone;

/**
 *  Get Closest Waypoint In Zone To Point
 *
 *  @param zone JMapZoneObject being used for searching
 *
 *  @param point JMapPoint reference to search from
 *
 *  @param searchType Search types: Proximity/Grid. Defaults to Proximity.
 *
 *  @return a JMapWaypoint object or nil if zone does not contain waypoints
 */
- (nullable JMapWaypoint*)getClosestWaypointInZone:(nonnull JMapZoneObject *)zone toPoint:(nonnull JMapPoint*)point withSearchType:(nullable NSString *)searchType;

/**
 *  Get Centroid Of Zone
 *
 *  @param zone JMapZoneObject being used for getting the centroid
 *
 *  @param map JMapMap being used to getting centroid of zone on the map
 *
 *  @return CGPoint centroid of the zone
 */
- (CGPoint)getCentroidOfZone:(nonnull JMapZoneObject *)zone onMap:(nonnull JMapMap*)map;

/**
 *  Get Bounds Of Zone
 *
 *  @param zone JMapZoneObject to retrieve the bound
 *  @param map JMapMap object to retrieve the bound
 *  @return rect bound of the zone
 */
- (CGRect)getBoundsOfZone:(nonnull JMapZoneObject *)zone onMap:(nonnull JMapMap *)map;

#pragma mark Zone Drawing

/**
 *  Highlight Units In Zone
 *
 *  @param zone JMapZoneObject being used to search for units
 */
- (void)highlightUnitsInZone:(nonnull JMapZoneObject *)zone withStyle:(nonnull JMapStyle*)style;

/**
 *  Get Polygon Of Zone
 *
 *  @param zone JMapZoneObject to get polygon from
 *  @param map JMapMap object to get the polygon
 *  @return a polygon object of the zone
 */
- (nullable Polygon *)getPolygonOfZone:(nonnull JMapZoneObject *)zone onMap:(nonnull JMapMap *)map;

/**
 *  Draw Polygon Of Zone
 *
 *  @param zone JMapZoneObject to draw
 *  @param map JMapMap object to draw the polygon
 *  @param style optional JMapStyle object to set the styling of the zone on the map
 */
- (void)drawPolygonOfZone:(nonnull JMapZoneObject *)zone onMap:(nonnull JMapMap *)map withStyle:(nullable JMapStyle *)style;

/**
 *  Listener For Moving Object Animation Completion
 *
 *  @param notification NSNotification callback object
 */
- (void)receiveAnimationComplete:(nonnull NSNotification *)notification;

/**
 *  Method To Subscribe To Listening For Moving Object Animations
 *
 *  @param delegate JMapZoneDelegate passed in for triggering delegate callbacks
 */
- (void)watchMovingObjects:(nonnull id <JMapZoneDelegate>)delegate;

/**
 *  Method To Unsubscribe To Listening For Moving Object Animations
 */
- (void)unwatchMovingObjects;

@end
