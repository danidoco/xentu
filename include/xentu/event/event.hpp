#pragma once

#include <vector>
#include "xentu/event/event_listener.hpp"
#include "xentu/event/event_type.hpp"

namespace xentu
{
   template<typename A>
   class Event
   {
   private:
      EventCategory category;
      EventType type;
      std::vector<EventListener> listeners;

   public:
      Event(const EventCategory &category, const EventType &type);
      void AddListener(const EventListener &listener);
      void Dispatch();
   };
} // namespace xentu
