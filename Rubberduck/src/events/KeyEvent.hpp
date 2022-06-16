/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : KeyEvent.h                 */
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
    class KeyEvent : public Event
    {
    public: 
        inline int GetKeyCode() const { return _keycode; }

        EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)

    protected:
        KeyEvent(int keycode) : _keycode(keycode) {}
        int _keycode;
    };

    class KeyPressedEvent : public KeyEvent
    {
    public:
        KeyPressedEvent(int keycode, int repeatCount) : 
            KeyEvent(keycode), _reapeatCount(repeatCount) {}

        inline int GetRepeatCount() const { return _reapeatCount; }

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << _keycode << " (" << _reapeatCount << " repeats)";
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyPressed)

    private:
        int _reapeatCount;
    };
    
    class KeyReleasedEvent : public KeyEvent
    {
    public:
        KeyReleasedEvent(int keycode) : 
            KeyEvent(keycode) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << _keycode;
            return ss.str();
        }

        EVENT_CLASS_TYPE(KeyReleased)
    };

}