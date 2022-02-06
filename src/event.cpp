#include "xentu/event/event.hpp"

namespace xentu
{
   Event::Event(const EventCategory &category, const EventType &type)
      : category(category)
      , type(type)
   {}

   bool Event::IsTypeInCategory() const
   {
      // TODO: implement this method
      XN_WARN("Event::IstTypeInCategory is not implemented yet");
      return true;
   }

   void Event::operator=(const Event &event)
   {
      this->category = event.category;
      this->type = event.type;
   }

} // namespace xentu
