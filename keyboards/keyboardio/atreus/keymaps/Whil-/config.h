#pragma once

// By default, when holding a dual-function key shortly after tapping it, the
// tapped key will begin repeating. This is handy for fast typists when typing
// words with double letters, such as "happy". If you turn this setting ON, it
// will be counted as a held modifier instead.
//#define TAPPING_FORCE_HOLD

#define TAPPING_TERM 200

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define QUICK_TAP_TERM 0

// When enabled, typing a mod-tap plus second within term will register as the mod-combo
// Ref: https://beta.docs.qmk.fm/using-qmk/software-features/tap_hold#permissive-hold
#define PERMISSIVE_HOLD
