#ifndef XN_WINDOW_PROPERTIES_H
#define XN_WINDOW_PROPERTIES_H

namespace Xentu
{
   struct WindowProperties
   {
      int width;
      int height;
      const char *caption;
      bool windowed;
      bool fullscreen;
      int refresh_rate;
   };
} // namespace Xentu

#endif