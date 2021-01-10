#define TEST_WITH_OBJECT_MATRIX true
#define OLD_TEST false


#if TEST_WITH_OBJECT_MATRIX
#include <list>
#include <atomic>
#include <string>
#include <iostream>
#include <random>
#include <variant>
#include "3d_graph_mat.hpp"

using namespace std;

#include "classes.hpp"

int main() {
	auto f = []{
		return BoxObject{ "name", {}, 5 };
	};

	auto fint = [] {
		return 5;
	};
	cout << boolalpha << std::is_same_v <invoke_result_t<decltype(f)>, BoxObject> << '\n' <<
		is_invocable_r_v<BoxObject&&, decltype(f)> 
		<< "\n" << is_invocable_r_v<invoke_result_t<decltype(f)>&&, decltype(f)> << endl;

	cout << boolalpha << std::is_same_v <invoke_result_t<decltype(fint)>, int> << typeid(int).name() << '\n' <<
		is_invocable_r_v<int, decltype(fint)>
		<< "\n" << is_invocable_r_v<invoke_result_t<decltype(fint)>, decltype(fint)> << endl;

	typedef	variant<
		function<BoxObject && ()>,
		function<BoxObject && (int, int, int)>,
		function<BoxObject && (Graph_Box_3D<BoxObject>&)>
	> Init_Func;

	Init_Func initialiser;
	//initialiser = [](int x, int y, int z) {
	//	return BoxObject(to_string(100 * x + 10 * y + z), {}, x ^ y ^ z);
	//};

	return 0;

	Graph_Matrix_3D<BoxObject> matrix({40, 40, 40});
	matrix.resume_auto_expansion();
	std::this_thread::sleep_for(std::chrono::seconds(10));

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

	//matrix.init([](BoxObject& box) {
		//box.entities = { nullptr, nullptr, nullptr };
		//box.id = std::rand();
		//box.name = "Some name";
	//});
}

#elif OLD_TEST
#include <iostream>

#include "graph_square_mat.hpp"
#include "3d_graph_mat.hpp"

using namespace std;

void func(Graph_Matrix_3D<int>& mat) {
	static int count = 1;
	std::cout << "Called " << count++ << "th time: \n";
	//for (int i = mat.min_z; i <= mat.max_z; i++)
	//{
	//	mat.disp_xy_layer(i);	// debug
	//	std::cout << "\n\n";	// debug
	//}
}

int main(int argc, char const* argv[])
{
#if 0
	int init_rows{ 4 }, init_cols{ 8 }, final_rows{ 3 }, final_cols{ 15 };
	Graph_Matrix<int> mat(init_rows, init_cols);
	mat.displayMat();
	mat.resize(final_rows, final_cols);
	mat.displayMat();
#endif

#if 1
	Graph_Matrix_3D<int> mat;

	mat.resize({ 3,3,3 });
	mat.init([](int x, int y, int z) {	return x + y + z;	});
	func(mat);
	//mat.pop_xminus_layer();
	//func(mat);
	//mat.pop_xplus_layer();

	//func(mat);
	//mat.pop_yminus_layer();	// @problem
	//func(mat);
	//mat.pop_yplus_layer();

	//func(mat);
	//mat.pop_zplus_layer();
	//func(mat);
	//mat.resize({ 4,6,5 });
	//mat.init([](int x, int y, int z) {	return x + y + z;	});
	//func(mat);
	//mat.pop_zminus_layer();
	func(mat);

#endif

	return 0;
}
#endif