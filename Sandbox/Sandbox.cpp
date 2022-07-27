/* *************************************************************************** */
/*                 *#########                                                  */
/*                ##........../##           KWAK!                              */
/*              *#,.......,##....#######  /                                    */
/*              ##........./....##////##                                       */
/*    ##          ##...........,##((##                                         */
/*   #.###/        ##,..........*                                              */
/*  #(.....(######(###*........,##                                             */
/* ##.............................##      File    : Sandbox.cp                 */
/* ##.    __       __  o       __  ##                                          */
/* ##.   |_  |\ | | __ | |\ | |_    *#.   Created :                            */
/*  ##   |__ | \| |__| | | \| |__   ,#,             Invalid dat                */
/*   ##.............................##                                         */
/*    /##........................*##      Updated : Gabcollet                  */
/*       ###/................*###.                  2022/06/16                 */
/*            ##############.                                                  */
/* *************************************************************************** */

#include <Rubberduck.hpp>

class ExampleLayer : public Rubberduck::Layer
{
public:
    ExampleLayer() : Layer("Example") {}

    void OnUpdate() override
    {
        RUBBERDUCK_INFO("Examplelayer::Update");
    }

    void OnEvent(Rubberduck::Event& event) override
    {
        RUBBERDUCK_TRACE("Examplelayer::Event: {0}", event);
    }
};

class Sandbox : public Rubberduck::Application
{
public:
    Sandbox()
    {
        PushLayer(new ExampleLayer());
    }
    ~Sandbox(){}
};

Rubberduck::Application* Rubberduck::CreateApplication()
{
    return new Sandbox();
}