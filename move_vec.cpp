#include <utility>
#include <vector>
#include <iostream>
using namespace std;

struct Foo
{
	Foo() = default;
	
	Foo(vector<int>& v) : v1(v) { std::cout << "copy "; }
	
	Foo(vector<int>&& v) : v1(move(v)) { std::cout << "move "; }  // we need move(v) so vector<int>&& v won't be lvalue
	vector <int> v1;
};



void FillVector(vector<int>& v) {}

int main()
{
	vector<int> v {1,2,3,4};

	Foo f1(move(v));  //v valid but unspecified state

	Foo f2(v);
	
	v.push_back(42);
	
	v.clear();  //this is fine, because it doesn't depend on the state of v
	//v.front();  //not fine
}
