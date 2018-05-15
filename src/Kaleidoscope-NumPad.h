#pragma once

#include "Kaleidoscope-LEDControl.h"
#include "Kaleidoscope-Macros.h"
#include "LEDUtils.h"

class NumPad_ : public kaleidoscope::Plugin {
 public:
  NumPad_(void) {}

  static uint8_t numPadLayer;

  kaleidoscope::EventHandlerResult onSetup(void);
  kaleidoscope::EventHandlerResult afterEachCycle();

#if KALEIDOSCOPE_ENABLE_V1_PLUGIN_API
 protected:
  void begin();
  static void legacyLoopHook(bool is_post_clear);
#endif

 private:
  static byte row, col;
  static bool cleanupDone;
  static bool originalNumLockState;
};

extern NumPad_ NumPad;
