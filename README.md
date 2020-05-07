

![TPLMaps](https://api.tplmaps.com/apiportal/assets/images/portal_landing_image.png)

[![Build Status](https://travis-ci.com/anumshk27/TPLMapDemo.svg?token=pAxNL3frqpRC6rqwAYgv&branch=master)](https://travis-ci.com/anumshk27/TPLMapDemo)
[![Version](https://img.shields.io/cocoapods/v/TPLMaps.svg?style=flat)](http://cocoapods.org/pods/TPLMaps)
[![Platform](https://img.shields.io/cocoapods/p/TPLMaps.svg?style=flat)](http://cocoapods.org/pods/TPLMaps)

### Introduction
The TPLPlaces SDK for iOS allows you to build location-aware apps that respond contextually to the local businesses and other places near the device. The autocomplete service in the TPLPlaces SDK for iOS returns place suggestions in response to user search queries as the user types.

### Getting Started
Before you can start using the TPLMaps Platform APIs and SDKs, you must sign up and create a [billing account](https://api.tplmaps.com/apiportal/#/portal/pricing-plan).

### Step 1: Get the latest version of Xcode
To build a project using the TPLPlaces SDK for iOS, you need **version 11.0** or later of [Xcode](https://developer.apple.com/xcode/).

### Step 2: Generate tplservices File
To use the TPLPlaces SDK for iOS, you must get **tplservices.plist** file which you can then add to your iOS application. The **tplservices.plist** is used to track API requests associated with your project for usage and billing.

**Get the latest tplservices file**
[HERE](http://api.tplmaps.com/apiportal/#/portal/home).

This file contains configuration details, such as keys and identifiers, for the services that you have just enabled. Add the **tplservices.plist** file to your xcode project downloaded from the TPLMaps portal to start working with TPLMaps Platform APIs and SDKs.


### Step 3: Install the SDK

The TPLPlaces SDK for iOS is available as a CocoaPods pod. CocoaPods is an open source dependency manager for Swift and Objective-C Cocoa projects.

If you don't already have the CocoaPods tool, install it on macOS by running the following command from the terminal. For details, see the [CocoaPods Getting Started guide](https://guides.cocoapods.org/using/getting-started.html).

> sudo gem install cocoapods

Create a `Podfile` for the TPLMaps SDK for iOS and use it to install the API and its dependencies:

1. If you don't have an Xcode project yet, create one now and save it to your local machine. (If you're new to iOS development, create a Single View Application.)

2. Create a file named `Podfile` in your project directory. This file defines your project's dependencies. 

3. Edit the `Podfile` and add your dependencies. Here is an example which includes the dependencies you need for the TPLMaps SDK for iOS:

```ruby
source 'https://github.com/CocoaPods/Specs.git'
platform :ios, '9.3'

target 'YOUR_APPLICATION_TARGET_NAME_HERE' do
pod 'TPLPlaces'
end
```

4. Save the `Podfile`

5. Open a terminal and go to the directory containing the `Podfile`:
```ruby
cd <path-to-project>
```

6. Run the `pod install` command. This will install the APIs specified in the `Podfile`, along with any dependencies they may have.

7. Close Xcode, and then open (double-click) your project's `.xcworkspace` file to launch Xcode. From this time onwards, you must use the `.xcworkspace` file to open the project.

Now that you have integrated **TPLPlaces SDK** in to your iOS project, Lets add an **autocomplete UI control** to your default view controller.

### Add a full-screen control
Use the full-screen control when you want a modal context, where the autocomplete UI temporarily replaces the UI of your app until the user has made their selection. This functionality is provided by the **TPLAutocompleteViewController** class. When the user selects a place, your app receives a callback.

To add a full-screen control to your app:
1.  Create a UI element in your main app to launch the autocomplete UI control, for example a touch handler on a  `UIButton`.
2.  Implement the  **`TPLAutocompleteViewControllerDelegate`** protocol in the parent view controller.
3.  Create an instance of  **`TPLAutocompleteViewController`** and assign the parent view controller as the delegate property.
4.  Present the  **`TPLAutocompleteViewController`** using  `[self presentViewController...]`.
5.  Handle the user's selection in the  `didAutocompleteWithPlace`  delegate method.
6.  Dismiss the controller in the  `didAutocompleteWithPlace`,  `didFailAutocompleteWithError`, and  `wasCancelled`  delegate methods.

```objective-c
#import "ViewController.h"
@import TPLPlaces;

@interface  ViewController () <TPLAutocompleteViewControllerDelegate>

@end

@implementation  ViewController

- (void)viewDidLoad {
[super  viewDidLoad];
// Do any additional setup after loading the view.

[self  makeUIButton];

}

// Add a button to the view.

-(void)makeUIButton {

UIButton * button = [UIButton  buttonWithType:UIButtonTypeSystem];
button.frame = CGRectMake(0.0, 0.0, 300.0, 35.0);
button.center = self.view.center;
[button setTitle:@"Show autocomplete"  forState:UIControlStateNormal];
[button addTarget:self action:NSSelectorFromString(@"autocompleteClicked") forControlEvents:UIControlEventTouchUpInside];
[self.view addSubview:button];

}

// Present the autocomplete view controller when the button is pressed.
-(void)autocompleteClicked {

// Initialize the instance of TPLAutocompleteViewController
TPLAutocompleteViewController * controller = [[TPLAutocompleteViewController  alloc] init];

// Assign the parent view controller as the delegate property.
controller.delegate = self;

// Assign search location coordinate
controller.locationCoordinate = CLLocationCoordinate2DMake(33.522324, 73.094098);

// Display the autocomplete view controller.
[self  presentViewController:controller animated:YES  completion:nil];

}

// Handle the user's selection.

-(void)viewController:(TPLAutocompleteViewController *)viewController didAutocompleteWithPlace:(Place *)place 
{

// Do something with the selected place.
NSLog(@"place name %@", place.name);
NSLog(@"place type %@", place.type);
NSLog(@"place address %@", place.address);

}

// Called when a error occurred

- (void)viewController:(TPLAutocompleteViewController *)viewController didFailAutocompleteWithError:(NSError *)error 
{

[self  dismissViewControllerAnimated:YES  completion:nil];
// TODO: handle the error.
NSLog(@"Error: %@", [error description]);

}

// User canceled autocomplete controller.
- (void)wasCancelled:(TPLAutocompleteViewController *)viewController 
{

[self  dismissViewControllerAnimated:YES  completion:nil];
}

@end
```

d'9/
90-,o/l

