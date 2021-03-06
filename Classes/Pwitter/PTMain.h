//
//  PTMain.h
//  Pwitter
//
//  Created by Akihiro Noguchi on 24/12/08.
//  Copyright 2008 Aki. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <MGTwitterEngine.h>
#import "PTPreferenceManager.h"
#import "PTStatusBox.h"
#import "PTPreferenceWindow.h"
#import "PTMenuBarIcon.h"
#import "PTImageManager.h"

typedef enum soundEventType {
	NoneReceived = 0,
	StatusReceived = 1,
	ReplyOrMessageReceived = 2,
	ErrorReceived = 3,
	StatusSent = 4
}SoundEventType;

@interface PTMain : NSObject <MGTwitterEngineDelegate> {
    IBOutlet id fStatusUpdateField;
    IBOutlet id fStatusController;
    IBOutlet id fTextLevelIndicator;
    IBOutlet id fReplyButton;
    IBOutlet id fWebButton;
    IBOutlet id fMessageButton;
    IBOutlet id fProgressBar;
    IBOutlet id fStatusBoxGenerator;
    IBOutlet id fUpdateButton;
    IBOutlet id fNotificationMan;
    IBOutlet id fMainWindow;
    IBOutlet id fMainActionHandler;
    IBOutlet id fIconMenu;
    IBOutlet id fStatusCollection;
	MGTwitterEngine *fTwitterEngine;
	int fLastUpdateID;
	int fLastMessageID;
	int fLastReplyID;
	int fReplyUpdateId;
	NSMutableDictionary *fRequestDetails;
	NSMutableDictionary *fIgnoreList;
	NSMutableDictionary *fFavRecord;
	NSMutableDictionary *fDeleteRecord;
	PTImageManager *fImageMan;
	NSTimer *fUpdateTimer;
	NSTimer *fMessageUpdateTimer;
	SoundEventType fCurrentSoundStatus;
	// array of boxes that has been received for the current session
	NSMutableArray *fBoxesToNotify;
	NSMutableArray *fBoxesToAdd;
	NSMutableArray *fBoxesToRemove;
	PTMenuBarIcon *fMenuItem;
	// core animation frame size fix
	NSRect fCurrentTarget;
	// cached sound effects;
	NSSound *fStatusReceived;
	NSSound *fReplyReceived;
	NSSound *fErrorReceived;
	NSSound *fStatusPosted;
	BOOL fUpdating;
	BOOL fIgnoreErrors;
}
- (IBAction)updateTimeline:(id)sender;
- (IBAction)postStatus:(id)sender;
- (IBAction)changeAccount:(id)sender;
- (IBAction)activateApp:(id)sender;
- (NSImage *)requestUserImage:(NSString *)aImageLocation forBox:(PTStatusBox *)aNewBox;
- (void)setupUpdateTimer;
- (void)setupMessageUpdateTimer;
- (void)openTwitterWeb;
- (void)runInitialUpdates;
- (void)setUpTwitterEngine;
- (void)makePost:(NSString *)aMessage;
- (void)setReplyID:(int)aId;
- (void)favStatus:(PTStatusBox *)aBox;
- (void)saveUnread;
- (void)loadUnread;
- (void)toggleApp;
- (void)deleteTweet:(PTStatusBox *)aBox;

@property(readonly) PTMenuBarIcon *fMenuItem;

@end
