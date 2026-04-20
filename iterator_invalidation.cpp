#include <iostream>
#include <vector>

int main()
{
    std::vector v1 = {1,2,3};
    auto it = v1.begin() + 1;
    v1.reserve(100);
    *it = 42; //itt memóriaszemeten akarunk módosítani
    std::cout << *(v1.begin()+1) << '\n';

    //biztonságos:
    std::vector v2 = {1,2,3};
    auto idx = 1;
    v2.reserve(100);
    v2[idx] = 42;
    std::cout << v2[idx];
    //itt pozíciót tárolunk el ami nem tud invalidálódni
}