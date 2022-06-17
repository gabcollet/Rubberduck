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

#include "Headers.hpp"
#include "events/ApplicationEvent.hpp"

namespace Rubberduck
{
    
    Application::Application()
    {
		m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
        // WindowResizeEvent e(1200, 700);
        // if (e.IsInCategory(EventCategoryApplication))
        // {
        //     RUBBERDUCK_TRACE(e);
        // }
        // if (e.IsInCategory(EventCategoryInput))
        // {
        //     RUBBERDUCK_TRACE(e);
        // }

        // while (true);
    }
}