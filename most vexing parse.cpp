#include <iostream>

class X {
public:
    X() { std::cout << "X\n"; }
};

class Y {
public:
    Y(X) { std::cout << "Y\n"; }
};

int main() {
    Y y(X());  //most vexing parse
}