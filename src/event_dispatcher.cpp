#include "xentu/event/event_dispatcher.hpp"

namespace xentu
{
   EventDispatcher::EventDispatcher(const Event &event)
      : event(event)
   {}

   EventDispatcher::EventDispatcher(const EventCategory &category, const EventType &type)
   {
      event = Event(category, type);
   }

   void EventDispatcher::AddListener(const EventListener &listener)
   {
      listeners.push_back(listener);
   }
} // namespace xentu
