#include <iostream>

void printSizeV(int param[6]) {
    std::cout << sizeof(param) << "<-value \n"; //8 mivel tömböt nem lehet érték szerint átadni függvénynek, ezért ptr lesz belőle
}									   //ezért ha el akarjuk kerülni array decay-t használjunk referenciát

//void printSize(const int& param[6]) {  rossz szintaxis

void printSizeR(int (&param)[6]) { 
	std::cout << sizeof(param) << "<-reference \n"; 
}

void printSizeVLastElement(int param[6]) { 
	std::cout << sizeof(param[6]) << ' ' << sizeof(*(param+6)) << "<-value \n"; 
}

void printSizeRLastElement(int (&param)[6]) { 
	std::cout << sizeof(param[6]) << "<-reference \n"; 
}

int main() {
    int t[6] = {1, 2, 3, 4, 5, 6};
    std::cout << sizeof(t) << "<-main vagyok \n";  //24
    printSizeR(t);
    printSizeV(t);
	printSizeRLastElement(t);
	printSizeVLastElement(t);
}