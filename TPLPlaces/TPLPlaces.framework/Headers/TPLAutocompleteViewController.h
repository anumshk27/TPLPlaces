//
//  TPLAutocompleteViewController.h
//  TPLPlaces
//
//  Created by Haider Shahzad on 24/03/2020.
//  Copyright © 2020 TPLMaps. All rights reserved
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

#import "Place.h"

@class TPLAutocompleteViewController;

NS_ASSUME_NONNULL_BEGIN

/**
* Protocol used by |TPLAutocompleteViewController|, to communicate the user's interaction
* with the controller to the application.
*/
@protocol TPLAutocompleteViewControllerDelegate <NSObject>

/**
* Called when a place has been selected from the available autocomplete suggestions.
*
* Implementations of this method should dismiss the view controller as the view controller will not
* dismiss itself.
*
* @param viewController The |TPLAutocompleteViewController| that generated the event.
* @param place The |Place| that was returned.
*/
- (void)viewController:(TPLAutocompleteViewController *)viewController
didAutocompleteWithPlace:(Place *)place;

/**
* Called when a non-retryable error occurred when retrieving autocomplete suggestions or place
* details.
*
* Only the following values of Error are retryable:
* <ul>
* <li>NetworkError
* <li>ServerError
* <li>InternalError
* </ul>
* All other error codes are non-retryable.
*
* @param viewController The |TPLAutocompleteViewController| that generated the event.
* @param error The |NSError| that was returned.
*/
- (void)viewController:(TPLAutocompleteViewController *)viewController
didFailAutocompleteWithError:(NSError *)error;

/**
* Called when the user taps the Cancel button in a |TPLAutocompleteViewController|.
*
* Implementations of this method should dismiss the view controller as the view controller will not
* dismiss itself.
*
* @param viewController The |TPLAutocompleteViewController| that generated the event.
*/
- (void)wasCancelled:(TPLAutocompleteViewController *)viewController;


@end

/**
* TPLAutocompleteViewController provides an interface that displays a table of autocomplete
* predictions that updates as the user enters text. Place selections made by the user are
* returned to the app via the |TPLAutocompleteViewControllerDelegate| protocol.
*/

@interface TPLAutocompleteViewController : UIViewController

/** Delegate to be notified when a place is selected or picking is cancelled. */
@property(nonatomic, weak, nullable) id<TPLAutocompleteViewControllerDelegate> delegate;

/** The background color of table cells. */
@property(nonatomic, strong) UIColor *tableCellBackgroundColor;

/** The color of the separator line between table cells. */
@property(nonatomic, strong) UIColor *tableCellSeparatorColor;

/** The color of result name text in autocomplete results */
@property(nonatomic, strong) UIColor *primaryTextColor;

/** The color of the second row of text in autocomplete results. */
@property(nonatomic, strong) UIColor *secondaryTextColor;

/** The tint color applied to controls in the Autocomplete view. */
@property(nonatomic, strong, nullable) UIColor * tintColor;

/** The latitude and longitude associated with a location. */
@property(nonatomic) CLLocationCoordinate2D locationCoordinate;

@end

NS_ASSUME_NONNULL_END
