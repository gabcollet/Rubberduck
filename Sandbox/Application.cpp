
#include "Rubberduck.hpp"

class Sandbox : public Rubberduck::Application
{
public:
    Sandbox() {}
    ~Sandbox() {}
};

int main()
{
    Sandbox* sandbox = new Sandbox();
    sandbox->Run();
    delete sandbox;
}