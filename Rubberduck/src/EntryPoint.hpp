/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : EntryPoint                 */
/* ##.    __       __  o       __  ##                                          */
/* ##.   |_  |\ | | __ | |\ | |_    *#.   Created : gcollet                    */
/*  ##   |__ | \| |__| | | \| |__   ,#,             2022/06/16                 */
/*   ##.............................##                                         */
/*    /##........................*##      Updated : gcollet                    */
/*       ###/................*###.                  2022/06/16                 */
/*            ##############.                                                  */
/* *************************************************************************** */

#pragma once

#include "headers.hpp"
#include "Application.hpp"

extern Rubberduck::Application* Rubberduck::CreateApplication();

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;

    Rubberduck::Log::Init();
    RUBBERDUCK_CORE_WARN("Initialized Log");
    int a = 5;
    RUBBERDUCK_INFO("Hello! Var={0}", a);
    RUBBERDUCK_CORE_CRITICAL("Criticality!!!");
    
    auto app = Rubberduck::CreateApplication();
    app->Run();
    delete app;
}

