#pragma once

#include <vector>

#include "xentu/event/event_category.hpp"
#include "xentu/event/event_type.hpp"
#include "xentu/event/event_listener.hpp"
#include "xentu/event/event.hpp"
#include "xentu/event/event_listener.hpp"

namespace xentu
{
   class EventDispatcher
   {
   private:
      Event event;
      std::vector<std::shared_ptr<EventListener>> listeners;

   public:
      EventDispatcher(EventCategory category, EventType type);
      void Dispatch();
      void AddListener(std::shared_ptr<EventListener> listener);
   };
} // namespace xentu
