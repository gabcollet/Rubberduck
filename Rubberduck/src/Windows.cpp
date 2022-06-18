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

#define RUBBERDUCK_ENABLE_ASSERTS

namespace Rubberduck 
{

    static bool s_GLFWInitialized = false;

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
            //This line is to silence the variable not used error.
            (void)success;
            s_GLFWInitialized = true;
        }

        _Window = glfwCreateWindow((int)props._width, (int)props._height, _data._title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(_Window);
        glfwSetWindowUserPointer(_Window, &_data);
        SetVSync(true);
    }
    
    void MacWindow::Shutdown() 
    {
        glfwDestroyWindow(_Window);
    }
    


}