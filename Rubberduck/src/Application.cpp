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
        while (_running)
        {
            glClearColor(0, 0, 1, 0);
            glClear(GL_COLOR_BUFFER_BIT);

            for (Layer* layer : _layerstack)
                layer->OnUpdate();

            _Window->OnUpdate();
        }
    }
    
    void Application::OnEvent(Event& e) 
    {
        EventDispatcher dispatcher(e);
        dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FM(OnWindowClose));

        //Display Events on log
        // RUBBERDUCK_CORE_TRACE("{0}", e);

        for (auto it = _layerstack.end(); it != _layerstack.begin();)
        {
            (*--it)->OnEvent(e);
            if (e.Handled)
                break;
        }
    }
    
    void Application::PushLayer(Layer* layer) 
    {
        _layerstack.PushLayer(layer);
    }
    
    void Application::PushOverlay(Layer* layer) 
    {
        _layerstack.PushOverlay(layer);
    }
    
    bool Application::OnWindowClose(WindowCloseEvent& e) 
    {
        _running = false;
        return true;
    }
}