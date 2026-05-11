#include <iostream>

int counter(int val) {
	static int c = val;
	return c++;
}

int main() {

std::cout << counter(5) << " ";
std::cout << counter(10);
}

//miert lesz 5 6 ?? megnezni