#include <iostream>

struct Base
{
    virtual void f(double d=2)
    {
        std::cout << "Base " << d << '\n';
    }
};

struct Derived : Base
{
    void f(double d=3.4) override
    {
        std::cout << "Derived " << d << '\n';
    }
};

void g()
{
    Base *b = new Derived();
    b->f();
}

int main()
{
    g();
}