//
//  JMapZoneLabelPlacementBuilder.h
//  JMapZoneKit
//
//  Copyright © 2026 Jibestream. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <JMapCoreKit/JMapCoreKit.h>
#import <JMapRenderingKit/JMapRenderingKit.h>

@class JMapZoneObject;

NS_ASSUME_NONNULL_BEGIN

/**
 *  Resolves a CMS waypoint id to a waypoint, or nil if it no longer exists.
 *
 *  Injected rather than reached for, so placement can be tested without a controller or a parsed
 *  map — and so a waypoint deleted in the CMS is a nil return rather than a crash.
 */
typedef JMapWaypoint * _Nullable (^JMapZoneWaypointResolver)(NSNumber *waypointId);

/**
 *  Where to put a whole-zone label on a map, and how much room to give it.
 */
@interface JMapZoneLabelFallbackGeometry : NSObject

/** Centre of the zone, in map units. */
@property (nonatomic, assign, readonly) CGPoint anchor;
/** Room the text has, in map units, or 0 when the zone has no usable extent. */
@property (nonatomic, assign, readonly) CGFloat spanMapUnits;

/** A negative span is stored as 0. */
- (instancetype)initWithAnchor:(CGPoint)anchor spanMapUnits:(CGFloat)spanMapUnits NS_DESIGNATED_INITIALIZER;
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

@end

/**
 *  Turns a zone's CMS waypoints into label placements.
 *
 *  Placement — grouping a zone's waypoints by tag, classifying the shape of the group, and deriving
 *  an anchor, an orientation and a span — belongs with the zone data and the polygon geometry it
 *  depends on, not in an app. The boundary it produces is plain data: the SDK creates and owns the
 *  labels, this only says where they go.
 *
 *  Every method is pure, with the waypoint lookup injected, so the rules can be tested without a
 *  live venue.
 */
@interface JMapZoneLabelPlacementBuilder : NSObject

- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 *  Placements for one zone on one map: one per tagged waypoint group, or a single whole-zone label
 *  when no tagged group on this map yields one — including a tagged pair rejected for sitting on
 *  one coordinate, as on web.
 *
 *  Groups are walked in sorted tag order. A two-waypoint pair is ordered by position (x, then y,
 *  then id), as Android orders it, so its angle always points rightward or straight down the map:
 *  the same line reads the same way whichever waypoint the CMS numbered first.
 *
 *  @param zone             The zone to label.
 *  @param map              The map to place on; waypoints on other maps are ignored.
 *  @param resolveWaypoint  Waypoint lookup by id.
 *  @param fontFamily       Font family for the labels, or nil for the system font.
 *  @param textColor        Text colour for the labels, or nil for the SDK's
 *                          `JMapLabelOptions.zoneTextColor`.
 */
+ (NSArray<JMapZoneLabelPlacement *> *)placementsForZone:(nullable JMapZoneObject *)zone
                                                   onMap:(nullable JMapMap *)map
                                         resolveWaypoint:(JMapZoneWaypointResolver)resolveWaypoint
                                              fontFamily:(nullable NSString *)fontFamily
                                               textColor:(nullable UIColor *)textColor;

/**
 *  A zone's waypoints on one map, grouped by their CMS `externalId` — the label tag. A numeric
 *  `externalId` is grouped by its string form, as web does.
 *
 *  Untagged waypoints are excluded: they belong to the whole-zone fallback, not to a tag group.
 *  Waypoints that fail to resolve, that carry a non-finite coordinate, or that are reachable
 *  through two of the zone's locations are dropped — counted twice, one waypoint turns a genuine
 *  pair into a zero-span "pair", or a pair into a lopsided centroid.
 */
+ (NSDictionary<NSString *, NSArray<JMapWaypoint *> *> *)waypointsGroupedByTagForZone:(nullable JMapZoneObject *)zone
                                                                               onMap:(nullable JMapMap *)map
                                                                     resolveWaypoint:(JMapZoneWaypointResolver)resolveWaypoint;

/**
 *  The widest separation across a set of points.
 *
 *  Used as the room a multi-waypoint label has to fill. Deliberately not the bounding box, which is
 *  axis-aligned and so counts space the label never occupies.
 */
+ (CGFloat)widestSeparationBetweenPoints:(NSArray<NSValue *> *)points;

/**
 *  Whole-zone anchor and extent from a zone's waypoint coordinates on one map.
 *
 *  Three or more distinct points that enclose an area give the centroid of their convex hull and
 *  the larger dimension of their bounding box, so the label is gated by the same physical fit as
 *  every other kind. Fewer than three distinct points — or three or more that are collinear — have
 *  no hull, so the anchor is their mean and the span is 0, leaving the viewport fraction to bound
 *  the label. On a centroid-dominant venue the sparse case is most of the zones, so it decides
 *  whether those zones are named at all. Nil when there are no finite points.
 *
 *  Mirrors web's `fallbackGeometry` in ZoneKit.js and Android's `ZoneLabelManager` sparse fallback.
 */
+ (nullable JMapZoneLabelFallbackGeometry *)fallbackGeometryForPoints:(NSArray<NSValue *> *)points;

@end

NS_ASSUME_NONNULL_END
