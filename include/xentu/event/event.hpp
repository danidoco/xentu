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
      Event(const EventCategory &category, const EventType &type);
      EventCategory GetEventCategory() const { return category; }
      EventType GetEventType() const { return type; }
      bool IsTypeInCategory() const;

      void operator=(const Event &event);
   };
} // namespace xentu
