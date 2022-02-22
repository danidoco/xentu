#pragma once

#include "xentu/debug/logger.hpp"
#include "xentu/event/event_listener.hpp"
#include "xentu/event/event_category.hpp"
#include "xentu/event/event_type.hpp"

namespace xentu
{
   class Event
   {
   private:
      EventCategory category;
      EventType type;

   public:
      Event(EventCategory category, EventType type);
      EventCategory GetEventCategory() const { return category; }
      EventType GetEventType() const { return type; }
      bool IsTypeInCategory() const;
   };
} // namespace xentu
