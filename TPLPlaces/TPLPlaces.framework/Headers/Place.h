//
//  Places.h
//  TPLPlacesSDK
//
//  Created by Muhammad Anum on 03/24/2020.
//  Copyright © 2020 TPLMaps. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
Place object holds the required information about place
 */
@interface Place : NSObject

/**
 The country of the local entity, e.g. Pakistan.
 */
@property (nonatomic) NSString * country;
/**
 The type of the local entity, e.g. POI(point of interest), HOUSE, ROAD.
 */
@property (nonatomic) NSString * type;

/**
 The complete address of the local entity.
 */
@property (nonatomic) NSString * address;

/**
 The name of the local entity, e.g. KFC, New Yorker.
 */
@property (nonatomic) NSString * name;

/**
 The category of the local entity, e.g. BEAUTY & SPA.
 */
@property (nonatomic) NSString * category;

/**
 The subCategory of the local entity, e.g. BEAUTY SALON.
 */
@property (nonatomic) NSString * subCategory;

/**
 The unique identifier of the local entity.
 */
@property (nonatomic) NSInteger  uid;

/**
 The referance unique identifier of the local entity.
 */
@property (nonatomic) NSInteger  fkey;

/**
 The priority of the local entity.
 */
@property (nonatomic) NSInteger  priority;

/**
 The latitude of the local entity.
 */
@property (nonatomic) double  lat;

/**
 The longitude of the local entity.
 */
@property (nonatomic) double  lng;


/**
 Initilize Place object with NSDictionary
 */

- (id)initWithItems:(NSDictionary *)items;

/**
 Provide NSDictionary from place object
 */
- (NSDictionary *)getAllItems;



@end
