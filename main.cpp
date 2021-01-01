#include "3d_graph_mat.hpp"
#include <list>
#include <atomic>
#include <string>
#include <iostream>
#include <random>

using namespace std;

struct ID_Creator {
	typedef uint16_t id_type;

	inline static id_type currID { 10000 };

public:
	const atomic<id_type> id;
};
//ID_Creator 

struct Entity: ID_Creator {
	int id;
};

struct BoxObject {
public:
	std::string name;
	std::list<Entity*> entities;
	int id;

	BoxObject() : id(decltype(id){}) {}
	BoxObject(BoxObject&) = delete;
	BoxObject(BoxObject&&) = delete;
};

int main() {
	Graph_Matrix_3D<BoxObject> matrix({100, 100, 1000});

	//auto func = [](Graph_Box_3D<BoxObject>&) {};
	//auto func2 = [](int i, int j, int z) {
	//	return i + j + z;
	//};
	//auto func3 = [](int i, int j, int z) {
	//	return;
	//};

	//std::cout << std::boolalpha << std::is_invocable_r_v<void, decltype(func), Graph_Box_3D<BoxObject>&>;	// true
	//std::cout << std::boolalpha << std::is_invocable_r_v<void, decltype(func2), int, int, int>;	// true	(actually returns int, but it is 'convertible to void')
	//std::cout << std::boolalpha << std::is_invocable_r_v<void, decltype(func2), int, int, int, int>;	// false
	//std::cout << std::boolalpha << std::is_invocable_r_v<int, decltype(func2), int, int, int>;	// true
	//std::cout << std::boolalpha << std::is_invocable_r_v<int, decltype(func2), int, int, int, int>;	// false
	//std::cout << std::boolalpha << std::is_invocable_r_v<int, decltype(func2), int, int, int, int, Graph_Box_3D<BoxObject>>;	// false
	//std::cout << std::boolalpha << std::is_invocable_r_v<void, decltype(func3), int, int, int>;	// true
	//std::cout << std::boolalpha << std::is_invocable_r_v<int, decltype(func3), int, int, int>;	// false
	//std::cout << std::boolalpha << std::is_invocable_r_v<int, decltype(func3), int, int>;	// false

	matrix.init([](BoxObject& box) {
		//box.entities = { nullptr, nullptr, nullptr };
		//box.id = std::rand();
		//box.name = "Some name";
	});
	system("pause");
}