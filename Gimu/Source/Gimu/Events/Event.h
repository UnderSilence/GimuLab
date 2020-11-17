//
// Created by Metal on 2020/11/15.
// Copy and Edit from Hazel Engine
//

#ifndef GIMUDEV_EVENT_H
#define GIMUDEV_EVENT_H

#include "gmpch.h"
#include "Gimu/Core/Base.h"

namespace Gimu {

    /* Copy from Hazel Engine */
    enum class EventType {
        None = 0,
        WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased, KeyTyped,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0U),
        EventCategoryInput = BIT(1U),
        EventCategoryKeyboard = BIT(2U),
        EventCategoryMouse = BIT(3U),
        EventCategoryMouseButton = BIT(4U)
    };

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                virtual EventType GetEventType() const override { return GetStaticType(); }\
                                virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    class Event {
    public:
        bool Handled = false;
        virtual ~Event() = default;

        // Pure virtual function
        virtual EventType GetEventType() const = 0;
        virtual const char *GetName() const = 0;
        virtual int GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category) const {
            return category & GetCategoryFlags();
        }
    };

    class EventDispatcher {
    public:
        EventDispatcher(Event &e) : m_Event(e) {}

        // F will be deduced by the compiler
        template<typename T, typename F>
        bool Dispatch(const F &func) {
            if (m_Event.GetEventType() == T::GetStaticType()) {
                m_Event.Handled |= func(static_cast<T &>(m_Event));
                return true;
            }
            return false;
        }
    private:
        Event &m_Event;
    };
}


#endif //GIMUDEV_EVENT_H
