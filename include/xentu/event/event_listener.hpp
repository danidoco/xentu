#pragma once

#include <functional>

namespace xentu
{
   class EventListener
   {
   private:
      std::function<void()> dispatchCallback;

   public:
      EventListener(const std::function<void()> &callback);

      void SetDispatchCallback(const std::function<void()> &callback)
      {
         dispatchCallback = callback;
      }

      std::function<void()> GetDispatchCallback() const
      {
         return dispatchCallback;
      }
   };
} // namespace xentu