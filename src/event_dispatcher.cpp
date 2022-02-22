#include "xentu/event/event_dispatcher.hpp"

namespace xentu
{
   EventDispatcher::EventDispatcher(EventCategory category, EventType type)
      : event(category, type)
   {}

   void EventDispatcher::Dispatch()
   {
      for (auto listener : listeners)
      {
         std::function<void()> callback = listener->GetDispatchCallback();
         callback();
      }
   }

   void EventDispatcher::AddListener(std::shared_ptr<EventListener> listener)
   {
      listeners.push_back(listener);
   }
} // namespace xentu
