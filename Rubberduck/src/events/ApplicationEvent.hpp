/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : Applicatio                 */
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
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) :
            _width(width), _height(height) {}

        inline unsigned int GetWidth() const { return _width; }
        inline unsigned int GetHeight() const { return _height; }

        // Should never be used for anything else then debuggin 
        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << _width << ", " << _height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    private:
        unsigned int _width, _height;
    };
    
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CLASS_CATEGORY(EventCategoryApplication)
    };
    
    class AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}

        EVENT_CLASS_TYPE(AppTick);
        EVENT_CLASS_CATEGORY(EventCategoryApplication);
    };
    
    class AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(AppUpdate);
        EVENT_CLASS_CATEGORY(EventCategoryApplication);
    };
    
    class AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender);
        EVENT_CLASS_CATEGORY(EventCategoryApplication);
    };
}