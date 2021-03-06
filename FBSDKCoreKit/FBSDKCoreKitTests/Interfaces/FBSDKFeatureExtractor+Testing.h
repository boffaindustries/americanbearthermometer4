/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the license found in the
 * LICENSE file in the root directory of this source tree.
 */

#if !TARGET_OS_TV

#import <Foundation/Foundation.h>

#import "FBSDKFeatureExtracting.h"
#import "FBSDKFeatureExtractor.h"
#import "FBSDKRulesFromKeyProvider.h"

NS_ASSUME_NONNULL_BEGIN

@interface FBSDKFeatureExtractor (Testing)

+ (nullable id<FBSDKRulesFromKeyProvider>)keyProvider;

+ (void)configureWithRulesFromKeyProvider:(id<FBSDKRulesFromKeyProvider>)keyProvider;

+ (void)reset;

+ (nullable float *)getDenseFeatures:(NSDictionary<NSString *, id> *)viewHierarchy;

+ (BOOL)pruneTree:(NSMutableDictionary<NSString *, id> *)node
         siblings:(NSMutableArray *)siblings;

+ (float *)nonparseFeatures:(NSMutableDictionary<NSString *, id> *)node
                   siblings:(NSMutableArray *)siblings
                 screenname:(NSString *)screenname
             viewTreeString:(NSString *)viewTreeString;

+ (BOOL)isButton:(NSDictionary<NSString *, id> *)node;

+ (void)update:(NSDictionary<NSString *, id> *)node
          text:(NSMutableString *)buttonTextString
          hint:(NSMutableString *)buttonHintString;

+ (BOOL)foundIndicators:(NSArray *)indicators
               inValues:(NSArray *)values;

+ (float)regextMatch:(NSString *)pattern
                text:(NSString *)text;

+ (float *)parseFeatures:(NSMutableDictionary<NSString *, id> *)node;

@end

NS_ASSUME_NONNULL_END

#endif
