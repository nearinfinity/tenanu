//
//  RemoteService.h
//  Ketled
//
//  Created by Jason Harwig on 1/8/13.
//
//

#import <Foundation/Foundation.h>

@class SynchronousWebView, AccountRequest;

#define RETRY_COUNT 4

@interface RemoteService : NSObject<UIWebViewDelegate>  {
    NSThread *workerThread;
    SynchronousWebView *syncronousWebView;
}

+ (id)sharedInstance;

- (void)chargesWithCompletion:(void(^)(AccountRequest *request, NSString *errorMessage)) block;
- (void)saveHours:(NSString *)hours accountIndex:(NSUInteger)accountIndex dayIndex:(NSUInteger)dayIndex completion:(void(^)(BOOL success, NSString *errorMessage))completion;

@end