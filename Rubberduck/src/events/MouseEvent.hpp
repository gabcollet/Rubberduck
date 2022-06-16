/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : MouseEvent                 */
/* ##.    __       __  o       __  ##                                          */
/* ##.   |_  |\ | | __ | |\ | |_    *#.   Created : Gabcollet                  */
/*  ##   |__ | \| |__| | | \| |__   ,#,             2022/06/16                 */
/*   ##.............................##                                         */
/*    /##........................*##      Updated : Gabcollet                  */
/*       ###/................*###.                  2022/06/16                 */
/*            ##############.                                                  */
/* *************************************************************************** */

#pragma once

#include "Event.hpp"

namespace Rubberduck
{
    class MouseMovedEvent : public Event
    {
    public:
        MouseMovedEvent(float x, float y) : _mouseX(x), _mouseY(y) {}

        inline float GetX() const { return _mouseX; }
        inline float GetY() const { return _mouseY; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << _mouseX << ", " << _mouseY;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float _mouseX, _mouseY;
    };
    
    class MouseScrolledEvent : public Event
    {
    public:
        MouseScrolledEvent(float xOffset, float yOffset) : 
            _XOffset(xOffset), _YOffset(yOffset) {}

        inline float GetXOffset() const { return _XOffset; }
        inline float GetYOffset() const { return _YOffset; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    private:
        float _XOffset, _YOffset;
    };
   
    class MouseButtonEvent : public Event
    {
    public:
        inline int GetMouseButton() const { return _button; } 

        EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
    protected:
        MouseButtonEvent(int button) : _button(button) {}
        int _button;
    };
   
    class MouseButtonPressedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonPressedEvent(int button) : 
            MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << _button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };
    
    class MouseButtonReleasedEvent : public MouseButtonEvent
    {
    public:
        MouseButtonReleasedEvent(int button) : 
            MouseButtonEvent(button) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << _button;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };

}