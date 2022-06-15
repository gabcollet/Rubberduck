#include <Rubberduck.hpp>

class Sandbox : public Rubberduck::Application
{
public:
    Sandbox(){}
    ~Sandbox(){}
};

Rubberduck::Application* Rubberduck::CreateApplication()
{
    return new Sandbox();
}