#pragma once

#include "Rubberduck.hpp"
#include "src/Application.hpp"

extern Rubberduck::Application* Rubberduck::CreateApplication();

int main(int argc, char** argv)
{
    (void)argc;
    (void)argv;
    cout << "Hello Rubberduck Engine!\n";
    auto app = Rubberduck::CreateApplication();
    app->Run();
    delete app;
}

