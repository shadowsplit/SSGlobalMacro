
//
//  SSGlobalMacroNS.h
//  Pods
//
//  Created by John TSai on 2019/5/13.
//

#ifndef SSGlobalMacroNS_h
#define SSGlobalMacroNS_h

#if DEBUG
#define NSLog(FORMAT, ...) fprintf(stderr,"%s\n", [[NSString stringWithFormat:FORMAT, ##__VA_ARGS__] UTF8String]);
#else
#define NSLog(FORMAT, ...) {}
#endif

#ifndef weakobj
#if DEBUG
#if __has_feature(objc_arc)
#define weakobj(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakobj(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakobj(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakobj(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif

#ifndef strongobj
#if DEBUG
#if __has_feature(objc_arc)
#define strongobj(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongobj(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongobj(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongobj(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif

#endif /* SSGlobalMacroNS_h */
