//
//  SSGlobalMacroUI.h
//  SSGlobalMacro
//
//  Created by John TSai on 2019/5/13.
//

#ifndef SSGlobalMacroUI_h
#define SSGlobalMacroUI_h

#define SS_SCREEN_WIDTH [[UIScreen mainScreen] bounds].size.width
#define SS_SCREEN_HEIGHT [[UIScreen mainScreen] bounds].size.height
#define SS_STATUS_BAR_HEIGHT 20 + safeAreaInsets.top
#define SS_NAVIGATION_BAR_HEIGHT 44.0f
#define SS_TABBAR_HEIGHT 49.0 + safeAreaInsets.bottom

#define SS_HEX_COLOR_A(h, a) [UIColor colorWithRed:((float)((h & 0xFF0000) >> 16))/255.0 green:((float)((h & 0xFF00) >> 8))/255.0 blue:((float)(h & 0xFF))/255.0 alpha:a]
#define SS_HEX_COLOR(h) SS_HEX_COLOR_A(h, 1)
#define SS_RGBA(r,g,b,a) [UIColor colorWithRed:r/255.0f green:g/255.0f blue:b/255.0f alpha:a]
#define SS_RGB(r,g,b) RGBA(r,g,b,1.0f)

static inline UIEdgeInsets safeAreaInsets() {
    UIWindow *window = UIApplication.sharedApplication.keyWindow;
    if (@available(iOS 11.0, *)) {
        return window.safeAreaInsets;
    } else {
        return UIEdgeInsetZero;
    }
}

#endif /* SSGlobalMacroUI_h */
