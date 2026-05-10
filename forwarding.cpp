#include <iostream>
#include <utility>
#include <vector>

struct Foo{
	Foo(int x, const std::vector<int>& v) : m_v(v), m_i(x) { std::cout << 'c'; }
	Foo(int x, std::vector<int>&& v) : m_v(v), m_i(x) { std::cout << 'm'; }
	
private:
	std::vector<int> m_v;
	int m_i;
};

struct Bar
{
	template<class ... T>
	void AddFoo(T&& ... args) //universal reference
	{
		// v.emplace_back(std::forward<T>(args)...);     //forward so move will run
		v.emplace_back(args...);  //no forward -> move(v) still copies
	}
	
private:
	std::vector<Foo> v;
};


int main()
{
	Bar b1;
	std::vector<int> v = {1,2,3,4};
	b1.AddFoo(1, move(v));
}