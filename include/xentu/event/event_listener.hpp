#pragma once

#include <functional>

namespace xentu
{
   class EventListener
   {
   private:
      std::function<void()> dispatchCallback;

   public:
      EventListener(std::function<void()> callback);
      void SetDispatchCallback(std::function<void()> callback);
      std::function<void()> GetDispatchCallback();
   };
} // namespace xentu