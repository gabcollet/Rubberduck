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

#include "Application.hpp"

namespace Rubberduck
{

#define BIND_EVENT_FM(x) std::bind(&Application::x, this, std::placeholders::_1)

    Application::Application()
    {
        _Window = std::unique_ptr<Window>(Window::Create());
        _Window->SetEventCallback(BIND_EVENT_FM(OnEvent));
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
/*         WindowResizeEvent e(1200, 700);
        if (e.IsInCategory(EventCategoryApplication))
        {
            RUBBERDUCK_TRACE(e);
        }
        if (e.IsInCategory(EventCategoryInput))
        {
            RUBBERDUCK_TRACE(e);
        }
 */
        while (_running)
        {
            glClearColor(0, 0, 1, 0);
            glClear(GL_COLOR_BUFFER_BIT);
            _Window->OnUpdate();
        }
    }
    
    void Application::OnEvent(Event& e) 
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FM(OnWindowClose));

        //Display Events on log
        RUBBERDUCK_CORE_TRACE("{0}", e);
    }
    
    bool Application::OnWindowClose(WindowCloseEvent& e) 
    {
        _running = false;
        return true;
    }
}