#pragma once

#include <cstdlib>
#include "xentu/debug/logger.hpp"

#if defined(XN_DEBUG)
   #define XN_ENGINE_TERMINATE()                                               \
      XN_ENGINE_CRITICAL("application terminated abnormally by engine");       \
      exit(1)

   #define XN_ENGINE_DEBUGBREAK()                                              \
      XN_ENGINE_TRACE("{}:{}: debug break called by engine", __FILE__,         \
                      __LINE__);                                               \
      XN_ENGINE_TERMINATE()

   #define XN_TERMINATE()                                                      \
      XN_CRITICAL("application terminated abnormally");                        \
      exit(1)

   #define XN_DEBUGBREAK()                                                     \
      XN_TRACE("{}:{}: debug break called", __FILE__, __LINE__);               \
      XN_TERMINATE()
#elif defined(XN_RELEASE)
   #define XN_ENGINE_TERMINATE()                                               \
      XN_ENGINE_CRITICAL("application terminated abnormally by engine");       \
      exit(1)

   #define XN_ENGINE_DEBUGBREAK()

   #define XN_TERMINATE()                                                      \
      XN_CRITICAL("application terminated abnormally");                        \
      exit(1)

   #define XN_DEBUGBREAK()
#endif
