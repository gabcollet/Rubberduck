#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#pragma once

namespace Rubberduck
{
    
    class Application
    {
    public:
        Application();
        ~Application();

        void Run();

    private:

    };

    // To be defined in CLIENT
    Application* CreateApplication();
}

#endif