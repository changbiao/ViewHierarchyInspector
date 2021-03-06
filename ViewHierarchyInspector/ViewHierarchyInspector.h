//
//  ViewHierarchyInspector.h
//  ViewHierarchyInspector
//

/**
 * Copyright (C) 2012 Yogesh Prem Swami. http://www.axelexic.org
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
* 
* http://www.apache.org/licenses/LICENSE-2.0
* 
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/


#import <Foundation/Foundation.h>
#import <QuartzCore/QuartzCore.h>

#define MAX_WINDOW_CACHE_SIZE   32

@interface ViewHierarchyInspector : NSObject{
@private
    void* windowsTraversed[MAX_WINDOW_CACHE_SIZE];
    NSInteger maxIndex;
    BOOL        likesFrames;
    CGColorRef _viewBorderColor;
    CGColorRef _textColor;
}

+(id) sharedViewInspector;
@property(assign, atomic) BOOL likesFrames;
@property(assign, nonatomic) CGColorRef viewBorderColor;
@property(assign, nonatomic) CGColorRef textColor;
-(void) applicationWillFinishLaunching: (NSNotification*) aNotification;
-(void) applicationDidFinishLaunching:(NSNotification *)aNotification;
-(void) traverseViewHierarchy: (id) viewOrLayer currentTreeHeight: (NSUInteger) height;
-(void) printVewHierarchyOfMainWindow: (NSNotification*) aNotification;

@end
