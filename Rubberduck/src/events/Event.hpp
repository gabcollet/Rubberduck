/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : Event.hpp                  */
/* ##.    __       __  o       __  ##                                          */
/* ##.   |_  |\ | | __ | |\ | |_    *#.   Created : Gabcollet                  */
/*  ##   |__ | \| |__| | | \| |__   ,#,             2022/06/16                 */
/*   ##.............................##                                         */
/*    /##........................*##      Updated : Gabcollet                  */
/*       ###/................*###.                  2022/06/16                 */
/*            ##############.                                                  */
/* *************************************************************************** */

#pragma once

#include "../headers.hpp"
#include "../core.hpp"

namespace Rubberduck 
{

    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::type; }\
                                  virtual EventType GetEventType() const override { return GetStaticType(); }\
                                  virtual const char* GetName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

    enum class EventType
    {
        None = 0,
        WindowClose, WindowResize, WindowLostFocus, WindowMoved,
        AppTick, AppUpdate, AppRender,
        KeyPressed, KeyReleased,
        MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
    };

    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0), 
        EventCategoryInput          = BIT(1),
        EventCategoryKeyboard       = BIT(2),
        EventCategoryMouse          = BIT(3),
        EventCategoryMouseButton    = BIT(4)
    };

    class Event
    {
        friend class EventDispatcher;
        
    public:
        virtual EventType   GetEventType() const = 0;
        virtual const char* GetName() const = 0;
        virtual int         GetCategoryFlags() const = 0;
        virtual std::string ToString() const { return GetName(); }

        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags()& category;
        }

    protected:
        bool _handled = false;
    };

    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;

    public:
        EventDispatcher(Event& event) : _event(event) {}

        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            if (_event.GetEventType() == T::GetStaticType())
            {
                _event._handled = func(*(T*)&_event);
                return true;
            }
            return false;
        }

    private:
        Event& _event;
    };

    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}