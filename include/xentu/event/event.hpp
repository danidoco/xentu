#pragma once

#include "xentu/event/event_listener.hpp"
#include "xentu/event/event_type.hpp"

namespace xentu
{
   class Event
   {
   private:
      EventCategory category;
      EventType type;

   public:
      Event(const EventCategory &category, const EventType &type);
      EventCategory GetEventCategory();
      EventType GetEventType();
      bool IsTypeInCategory();
   };
} // namespace xentu
