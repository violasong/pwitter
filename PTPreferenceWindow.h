//
//  PTPreferenceWindow.h
//  Pwitter
//
//  Created by Akihiro Noguchi on 26/12/08.
//  Copyright 2008 Aki. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <ShortcutRecorder/SRRecorderControl.h>
#import "PTHotKey.h"


@interface PTPreferenceWindow : NSPanel {
    IBOutlet id fPassword;
    IBOutlet id fUserName;
    IBOutlet id fAlwaysOnTop;
    IBOutlet id fTimeInterval;
    IBOutlet id fMainController;
    IBOutlet id fMainWindow;
    IBOutlet id fAutoLogin;
    IBOutlet id fReceiveFromNonFollowers;
    IBOutlet id fMessageUpdateInterval;
    IBOutlet id fUseMiniView;
    IBOutlet id fActivateGlobalKey;
    IBOutlet id fShortcutRecorder;
    IBOutlet id fIgnoreErrors;
    IBOutlet id fMainActionHandler;
    IBOutlet id fDisableGrowl;
    IBOutlet id fDisableMessageNotification;
    IBOutlet id fDisableReplyNotification;
    IBOutlet id fDisableSoundNotification;
    IBOutlet id fDisableStatusNotification;
    IBOutlet id fPostTextField;
	PTHotKey *fHotKey;
}
- (void)loadPreferences;
- (IBAction)pressOK:(id)sender;
- (IBAction)pressCancel:(id)sender;
- (IBAction)quickPostChanged:(id)sender;
- (void)turnOnHotKey;
- (void)turnOffHotKey;
- (void)saveKeyCombo;
- (void)loadKeyCombo;

@end
