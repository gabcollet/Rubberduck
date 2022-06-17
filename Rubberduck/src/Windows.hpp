/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : Windows.hp                 */
/* ##.    __       __  o       __  ##                                          */
/* ##.   |_  |\ | | __ | |\ | |_    *#.   Created : Gabcollet                  */
/*  ##   |__ | \| |__| | | \| |__   ,#,             2022/06/17                 */
/*   ##.............................##                                         */
/*    /##........................*##      Updated : Gabcollet                  */
/*       ###/................*###.                  2022/06/17                 */
/*            ##############.                                                  */
/* *************************************************************************** */

#pragma once

#include "headers.hpp"
#include "src/events/Event.hpp"
#include <glfw/GLFW/glfw3.h>

namespace Rubberduck
{
    struct WindowProps
    {
        std::string _title;
        unsigned int _width;
        unsigned int _height;

        WindowProps(const std::string& title = "Rubberduck Engine",
                    unsigned int width = 1500,
                    unsigned int height = 720) :
            _title(title), _width(width), _height(height) {}
    };

    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() {}

        virtual void OnUpdate() = 0;
        virtual unsigned int GetWidth() const = 0;
        virtual unsigned int GetHeight() const = 0;
        //Window attributes
        virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
        virtual void SetVSync(bool enabled) = 0;
        virtual bool IsVSync() const = 0;

        static Window* Create(const WindowProps& props = WindowProps());
    };

    class MacWindow : public Window
    {
    public:
        MacWindow(const WindowProps& props);
        virtual ~MacWindow();

        void OnUpdate() override;

        inline unsigned int GetWidth() const override { return _data._width; }
        inline unsigned int GetHeight() const override { return _data._height; }
        
        inline void SetEventCallback(const EventCallbackFn& callback) override
        { _data._eventcallback = callback; }
        void SetVSync(bool enabled) override;
        bool IsVSync() const override;

    private:
        virtual void Init(const WindowProps& props);
        virtual void Shutdown();
    private:
        GLFWwindow* _Window;

        struct WindowData
        {
            std::string _title;
            unsigned int _width, _height;
            bool _vsync;

            EventCallbackFn _eventcallback;
        };

        WindowData _data;
    };
}