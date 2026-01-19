//
//  JMapOffSetPolygonConfig.h
//  JMapZoneKit
//
//  Created by Abdur Rafay on 16/01/2026.
//  Copyright © 2026 Jibestream. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  The JMapOffSetPolygonConfig model for configuring outer polygon stroke styling
 */
@interface JMapOffSetPolygonConfig : NSObject

/**
 *  Offset value to expand the outer polygon (required to enable outer polygon)
 */
@property (nonatomic, assign) CGFloat offset;

/**
 *  Stroke width for the outer polygon
 */
@property (nonatomic, assign) CGFloat strokeWidth;

/**
 *  Stroke color for the outer polygon (nullable; if nil, uses zone.color; if zone.color is nil, falls back to black)
 */
@property (nonatomic, strong, nullable) UIColor *strokeColor;

/**
 *  Fill color for the outer polygon (nullable; if nil, defaults to transparent/clear)
 */
@property (nonatomic, strong, nullable) UIColor *fillColor;

/**
 *  Initialize with required offset
 *
 *  @param offset offset value to expand the outer polygon
 *  @return newly created JMapOffSetPolygonConfig object
 */
- (nonnull instancetype)initWithOffset:(CGFloat)offset;

@end
