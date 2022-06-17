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

#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#pragma once

#include "headers.hpp"
#include "Windows.hpp"
#include "events/ApplicationEvent.hpp"

namespace Rubberduck
{
    
    class Application
    {
    public:
        Application();
        ~Application();

        void Run();

    private:
        std::unique_ptr<Window> _Window;
        bool _running = true;
    };

    // To be defined in CLIENT
    Application* CreateApplication();
}

#endif