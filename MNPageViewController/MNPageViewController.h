//
//  MNPageViewController.h
//  MNPageViewController
//
//  Created by Min Kim on 7/22/13.
//  Copyright (c) 2013 min. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MNPageViewControllerDelegate;
@protocol MNPageViewControllerDataSource;

@interface MNPageViewController : UIViewController

@property(nonatomic,strong,readonly) UIScrollView *scrollView;

@property(nonatomic,strong) UIViewController *viewController;

@property(nonatomic,weak) id <MNPageViewControllerDataSource> dataSource;
@property(nonatomic,weak) id <MNPageViewControllerDelegate>   delegate;

// JM: Removes children and resets state.
- (void)reset;

// JM: Allows you to jump to any view controller after pager has already been initialized.
- (void)jumpToViewController:(UIViewController*)viewController;

// JM: Allows you to page to the next view controller
- (void)scrollToNextViewController:(BOOL)animated;

// JM: Allows you to page to the previous view controller
- (void)scrollToPreviousViewController:(BOOL)animated;

@end

@protocol MNPageViewControllerDataSource <NSObject>

@required

// View controllers coming 'before' would be to the left of the argument view controller, those coming 'after' would be to the right.
// Return 'nil' to indicate that no more progress can be made in the given direction.
- (UIViewController *)mn_pageViewController:(MNPageViewController *)pageViewController viewControllerBeforeViewController:(UIViewController *)viewController;

- (UIViewController *)mn_pageViewController:(MNPageViewController *)pageViewController viewControllerAfterViewController:(UIViewController *)viewController;

@end

@protocol MNPageViewControllerDelegate <NSObject>

@optional

- (void)mn_pageViewController:(MNPageViewController *)pageViewController didPageToViewController:(UIViewController *)viewController;

// JM: Added this for convenience so we can tell controllers they lost focus.
- (void)mn_pageViewController:(MNPageViewController *)pageViewController didPageFromViewController:(UIViewController *)viewController;

- (void)mn_pageViewController:(MNPageViewController *)pageViewController willPageToViewController:(UIViewController *)viewController withRatio:(CGFloat)ratio;

- (void)mn_pageViewController:(MNPageViewController *)pageViewController willPageFromViewController:(UIViewController *)viewController withRatio:(CGFloat)ratio;

@end