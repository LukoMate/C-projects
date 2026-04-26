#include <iostream>

class MyClass
{
    int id;

public:
    MyClass()=default;
    MyClass(int z) : id(z) {}
    ~MyClass(){}
    //copy ctor:
    MyClass(const MyClass& other)
    {
        this->id = other.id;
    }

    //ertekado

    MyClass& operator=(const MyClass& other)
    {
        if (this == &other) {return *this;}
        this->id = other.id;
        return *this;
    }

    int getId() const 
    {
        return this->id;
    }
};

int main()
{
    MyClass mc1(5);
    MyClass asdf(mc1); 
    std::cout << asdf.getId() << '\n';
    MyClass pp(1);
    pp = mc1 = asdf;
    pp.operator=(mc1);

    std::cout << pp.getId();
}