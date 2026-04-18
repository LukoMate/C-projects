#include <iostream>
using namespace std;

class Base {
    std::string name = "Joe";
public:
    virtual void print() {
        cout << "Base Function" << endl;
    }
    std::string getName()
    {
        return name;
    }
};

class Derived : public Base {
public:
    
    void print() override {
        cout << "Derived Function" << endl;
    }
    
};

int main() {
    /*
    Derived derived1;
    derived1.print();


    */
    Base b;

    Base* b1 = new Derived;
    b1->print();
    std::cout << b1->getName() << '\n';


    Base b2 = Derived(); //object slicing
    b2.print();
    

    return 0;
}
