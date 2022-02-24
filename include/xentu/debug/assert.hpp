#pragma once

#include <cassert>
#include "xentu/debug/logger.hpp"
#include "xentu/debug/debug_utils.hpp"

#define XN_ENGINE_ASSERT(condition)                                            \
   if (!(condition))                                                           \
   {                                                                           \
      XN_ENGINE_CRITICAL("assertion failed");                                  \
      XN_ENGINE_TERMINATE();                                                   \
   }                                                                           \
   do                                                                          \
   {                                                                           \
   } while (0)

#define XN_ASSERT(condition)                                                   \
   if (!(condition))                                                           \
   {                                                                           \
      XN_CRITICAL("assertion failed");                                         \
      XN_TERMINATE();                                                          \
   }                                                                           \
   do                                                                          \
   {                                                                           \
   } while (0)
