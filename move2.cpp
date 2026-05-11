#include <iostream>
#include <vector>
#include <utility>

struct Log {
    Log() {}
    Log(const Log&) { std::cout << "copy "; }
	Log(Log&&) noexcept { std::cout << "move "; }
	// Log& operator=(Log&& data) noexcept { std::cout << "move "; }
	int size;
	
};

int main() {
	// Log l{};
	// static const int& x = l.size;
	static const Log& lll = Log();  //itt nem fut le a ctor mert rvo !!! sima ctor hivas (ideiglenes objektum atadas)
	//plusz az efeletti sor mivel const ezert nem tudja lvaluebol attenni rvalue-vá
	// std::move(lll);  //ez igy onmagaban nem eleg
	Log ll = Log();
    std::vector<Log> v;
    v.reserve(1);
    v.push_back(Log()); //alapbol move mivel ideigneles
    v.push_back(Log());
	v.push_back(std::move(ll)); //kulonben copy
}
/*
Mikor kell az std::move?
Ha named objektumot akarsz move-olni — mert a fordító alapból azt hiszi hogy még kell:
cppMyClass a;
MyClass b = a;            // ❌ copy! a fordító nem tudja hogy a-t nem akarod már
MyClass c = std::move(a); // ✅ move! jelzed hogy a-t "feláldozod"
// a ettől érvényes de üres/meghatározatlan állapotban van!
*/