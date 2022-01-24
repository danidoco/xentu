#pragma once

namespace xentu
{
   class Window
   {
   private:
      int width, height;
      const char *caption;
      bool fullscreen;

   public:
      Window(int width, int height, const char *caption, bool fullscreen);
      ~Window();

      inline int GetWidth() { return width; }
      inline int GetHeight() { return height; }
      inline const char *GetCaption() { return caption; }
      inline bool IsFullscreen() { return fullscreen; }

      void Draw();
   };

   Window *CreateWindow();
} // namespace xentu
