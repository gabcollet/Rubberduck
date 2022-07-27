/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : Windows.cp                 */
/* ##.    __       __  o       __  ##                                          */
/* ##.   |_  |\ | | __ | |\ | |_    *#.   Created : Gabcollet                  */
/*  ##   |__ | \| |__| | | \| |__   ,#,             2022/06/17                 */
/*   ##.............................##                                         */
/*    /##........................*##      Updated : Gabcollet                  */
/*       ###/................*###.                  2022/06/17                 */
/*            ##############.                                                  */
/* *************************************************************************** */

#include "Windows.hpp"
#include "events/KeyEvent.hpp"
#include "events/MouseEvent.hpp"
#include "events/ApplicationEvent.hpp"
#include "glfw/glfw3.h"
#include "src/core.hpp"

#define RUBBERDUCK_ENABLE_ASSERTS

namespace Rubberduck 
{

    static bool s_GLFWInitialized = false;

    static void GLFWErrorCallback(int error, const char* description)
    {
        RUBBERDUCK_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }

    Window* Window::Create(const WindowProps& props)
    { 
        return new MacWindow(props); 
    }

    MacWindow::MacWindow(const WindowProps& props) 
    {
        Init(props);
    }
    
    MacWindow::~MacWindow() 
    {
    }
    
    void MacWindow::OnUpdate() 
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(_Window);
    }
    
    void MacWindow::SetVSync(bool enabled) 
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        _data._vsync = enabled;
    }
    
    bool MacWindow::IsVSync() const 
    {
        return _data._vsync;
    }
    
    void MacWindow::Init(const WindowProps& props) 
    {
        _data._title = props._title;
        _data._width = props._width;
        _data._height = props._height;

        RUBBERDUCK_CORE_INFO("Creating window {0} ({1}, {2})", props._title, props._width, props._height);

        if (!s_GLFWInitialized)
        {
            int success = glfwInit();
            RUBBERDUCK_CORE_ASSERT(success, "Could not initialize GLFW!");
            (void) success;
            glfwSetErrorCallback(GLFWErrorCallback);
            s_GLFWInitialized = true;
        }

        _Window = glfwCreateWindow((int)props._width, (int)props._height, _data._title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(_Window);
        int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        RUBBERDUCK_CORE_ASSERT(status, "Could not initialize GLAD!");
        (void) status;
        glfwSetWindowUserPointer(_Window, &_data);
        SetVSync(true);

        // Set GLFW callbacks
        glfwSetWindowSizeCallback(_Window, [](GLFWwindow* window, int width, int height)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            data._width = width;
            data._height = height;

            WindowResizeEvent event(width, height);
            data._eventcallback(event);
        });

        glfwSetWindowCloseCallback(_Window, [](GLFWwindow* window)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
            WindowCloseEvent event;
            data._eventcallback(event);
        });

        glfwSetKeyCallback(_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    KeyPressedEvent event(key, 0);
                    data._eventcallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    KeyReleasedEvent event(key);
                    data._eventcallback(event);
                    break;
                }
                case GLFW_REPEAT:
                {
                    KeyPressedEvent event(key, 1);
                    data._eventcallback(event);
                    break;
                }
            }
        });

        glfwSetMouseButtonCallback(_Window, [](GLFWwindow* window, int button, int action, int mods)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            switch (action)
            {
                case GLFW_PRESS:
                {
                    MouseButtonPressedEvent event(button);
                    data._eventcallback(event);
                    break;
                }
                case GLFW_RELEASE:
                {
                    MouseButtonReleasedEvent event(button);
                    data._eventcallback(event);
                    break;
                }
            }
        });

        glfwSetScrollCallback(_Window, [](GLFWwindow* window, double xOffset, double yOffset)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseScrolledEvent event((float)xOffset, (float)yOffset);
            data._eventcallback(event);
        });

        glfwSetCursorPosCallback(_Window, [](GLFWwindow* window, double xPos, double yPos)
        {
            WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

            MouseMovedEvent event((float)xPos, (float)yPos);
            data._eventcallback(event);
        });
    }
    
    void MacWindow::Shutdown() 
    {
        glfwDestroyWindow(_Window);
    }
    


}