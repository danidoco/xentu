#include "xentu/event/event.hpp"
#include "xentu/event/event_dispatcher.hpp"
#include "xentu/event/event_listener.hpp"

namespace xentu
{
   Event::Event(EventCategory category, EventType type)
      : category(category)
      , type(type)
   {}

   bool Event::IsTypeInCategory() const
   {
      // TODO: implement this method
      XN_WARN("Event::IstTypeInCategory is not implemented yet");
      return true;
   }

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

   EventListener::EventListener(const std::function<void()> &callback)
      : dispatchCallback(callback)
   {}
} // namespace xentu