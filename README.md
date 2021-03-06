<!--
# license: Licensed to the Apache Software Foundation (ASF) under one
#         or more contributor license agreements.  See the NOTICE file
#         distributed with this work for additional information
#         regarding copyright ownership.  The ASF licenses this file
#         to you under the Apache License, Version 2.0 (the
#         "License"); you may not use this file except in compliance
#         with the License.  You may obtain a copy of the License at
#
#           http://www.apache.org/licenses/LICENSE-2.0
#
#         Unless required by applicable law or agreed to in writing,
#         software distributed under the License is distributed on an
#         "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
#         KIND, either express or implied.  See the License for the
#         specific language governing permissions and limitations
#         under the License.
-->

# cordova-plugin-foxitpdf
    This plugin adds the ability to easily preview any PDF file in your Cordova application

## Major update
    Now our plugin is also using Foxit RDK 5.0
    It made a lot of major adjustments to optimize a lot of problems
    It make our plugin easier to use

This is RDK 5.0 Introduction

> New features for PDF Core API:
* PDF watermark operation (add/edit/delete)
* Indexed Full-Text Search for Android (already supported in iOS)
* New e_saveFlagXRefStream option for "SaveAS" function
* New "SetDefaultContentsLength" method for Signature feature
* Third-Party Security Handler support
* Get page box information by box type (MediaBox, CropBox, TrimBox)
* Provide API to Access/Create an Image file (BMP, JPG, PNG, GIF, TIF, JPX, JBIG2)

>New features for UI Extensions:
* Add/Remove buttons from/to the default UI so that the UI can be customized easily
* Show/Hide a special panel runtime (Reading Bookmarks/Outline/Annotations/Attachments Panel)
* Show/Hide the UI element in the view setting bar at runtime
* The type of annotations supported can be set by the configuration json file
* New event provided to allow developers to control what happens if the end user clicks on the "back" button
* New event provided for when end-user opens/taps on link
* Facing Mode support for Android (already supported in iOS)
* Support Relative Link and GoToR Action

> etc.

## Installation
```bash
cordova plugin add cordova-plugin-foxitpdf
```

## Usage Instructions for iOS
Thanks to the new version, and now we use the plug-in iOS only need a few simple steps on it (no longer like the 3.0 version of the kind of cumbersome operation)

1. Target -> Build setting -> Other Linker Flags -> + ->  `-lstdc++`
    ![](https://raw.githubusercontent.com/foxitsoftware/cordova-plugin-foxitpdf/master/ios_step1.png)
2. If appear FoxitRDK.framework `image not found` error, Make sure that Target -> General -> Embedded Binaries -> have FoxitRDK.framework
```diff
-PS:
-    Maybe xcode does not help us to add FoxitRDK.framework or libFoxitRDKUIExtensions.a correctly
-    Just delete it and re-add it
```   
3. Target -> Build Phases -> Copy Bundle Resources ->  +  -> `uiextensions_config.json`
4. Target -> Build Phases -> Copy Bundle Resources ->  +  -> `Resource`

    Resource folder -- found in the `Plugins/cordova-plugin-foxitpdf/uiextensions/resource` folder

    or use the method of `Add Files to xxx` ,remember check the option of `Create Group`
 

> `Note` Do not forget to add pdf files  
   You can add the PDF to Copy Bundle Resources directly. Just left-click the your project, find Copy Bundle Resources in the Build Phases tab, press on the + button, and choose the file to add. You can refer to any PDF file, just add it to the Xcode’s Copy Bundle Resources.


The preparatory work has been completed，Now,you can use this code everywhere in your project

```js
    var success = function(data){
        console.log(data);
    }
    var error = function(data){
        console.log(data);
    }

    var filePath = 'file://path/to/your/file';
    //var filePath = cordova.file.applicationDirectory + 'getting_started_ios.pdf';
    window.FoxitPdf.preview(filePath,success,error);
```

<s>1. In your Xcode project, find the FoxitSource folder and  "UI Extension" folder(in blue), right click and delete it, confirm "Remove Reference" when prompted. Create the FoxitSource group (in yellow) (because Cordova plug-in can not create iOS group).</s>

<s>2. Turn off arc mode, Build Settings -> Objective-C Automatic Reference Counting to NO </s>

<s>3. Embed Foxit RDK.framework General -> Embed Frameworks -> + -> FoxitRDK.framework </s>

<s>4. Insert the following code into the AppDelegate.h file

	```objective-c
	#import "UIExtensionsSharedHeader.h"
	#import "Defines.h"
	#define DEMO_APPDELEGATE  ((AppDelegate*)[[UIApplication sharedApplication] delegate])

	@property (nonatomic, strong) FSPDFViewCtrl* pdfViewCtrl;
	@property (nonatomic, assign) BOOL isFileEdited;
	@property (nonatomic, copy) NSString* filePath;
	@property (nonatomic, assign) BOOL isScreenLocked;
	```
</s>

<s>5. In the project configuration to increase the direction of support
	General -> Deployment info -> Device Orientation ,   Check
	Portrait , Landscape Left , Landscape Right
</s>




## Usage Instructions for Android
Android do not have to make any changes, you can directly use

```js
var success = function(data){
    console.log(data);
}
var error = function(data){
    console.log(data);
}
var filePath = 'file://path/to/your/file';
// var filePath = "/mnt/sdcard/getting_started_ios.pdf";
window.FoxitPdf.preview(filePath,success,error);
```

## PPT
Want to see more details, see forums.

[PPTX - How to use cordova-plugin-foxitpdf](http://forums.foxitsoftware.com/forum/portable-document-format-pdf-tools/foxit-cloud/cordova-plugin-foxitpdf/162972-ppt-how-to-use-cordova-plugin-foxitpdf)

## YOUTUBE
[![How to use cordova-plugin-foxitpdf](http://img.youtube.com/vi/3stdbwcm68k/maxresdefault.jpg)](https://youtu.be/3stdbwcm68k)


## iOS Screen Shot
![](https://raw.githubusercontent.com/foxitsoftware/cordova-plugin-foxitpdf/master/plugin_ios.gif)



## Android Screen Shot
![](https://raw.githubusercontent.com/foxitsoftware/cordova-plugin-foxitpdf/master/plugin_android.gif)


## Supported Platforms

- iOS

- Android



## IOS Quirks

1. The first argument in the preview method currently only supports absolute paths for incoming files.

    You can obtain the absolute path to the file using the method provided by the [cordova-plugin-file] (https://github.com/apache/cordova-plugin-file) plugin.

    Use the following command to add the [cordova-plugin-file] (https://github.com/apache/cordova-plugin-file) plugin to your project

    ```bash
    cordova plugin add cordova-plugin-file
    ```

2. Note: in some cases the resource folder are not added correctly and the number of items is the same because of XCode bug.（e.g.  Xcode 8.3.3）
In that case remove the added reference from project tree and then add the Resource using the project tree - Add files to "YourProjectName" ,remember when use this method enable the option of
"copy items if needed" and "create groups"

If something like the error in the following picture appears, try the method in step 2
![](https://raw.githubusercontent.com/foxitsoftware/cordova-plugin-foxitpdf/master/lack_resource.png)

## Android Quirks

<s>NOTE: Since the functionality associated with Reply in UIExtension is using FragmentActivity, the current plugin does not handle it, so there is a problem with using it. Will do further processing.</s>

<s>In addition: the current plug-ins already contain armeabi-v7a library, if you want to support other platforms, you need to refer to the Foxit RDK library for other libraries which can be introduced into the project.</s>


## Quick Example

The PDF file needs to be placed in the project beforehand. The location is in the project root by default

```js
var success = function(data){
    console.log(data);
}
var error = function(data){
    console.log(data);
}
function preview(){
    var filePath = cordova.file.applicationDirectory + 'getting_started_ios.pdf';
    window.FoxitPdf.preview(filePath,success,error);
}
```


## Attention

The product is still in the early stage of development. We will continue to focus on refining and improving this project.

## Feedback or contribution code

You can ask us questions or report bugs in [here](https://github.com/foxitsoftware/cordova-plugin-foxitpdf/issues).

You can also send email **huang_niu@foxitsoftware.com** to explain your problem.

If you have a better code implementation, please fork this project and launch your Pull-Request, we will promptly deal with. Thanks!


## Request a Quote
If you encounter “Invalid license” tips, please go to the following URL for official trial license key:

http://www.foxitsdk.com/products/mobile-pdf-sdk/request-quote/?from=cordova-plugin-foxitpdf

## More Support

http://forums.foxitsoftware.com/forum/portable-document-format-pdf-tools/foxit-cloud/cordova-plugin-foxitpdf
