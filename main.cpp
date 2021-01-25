#define TEST_WITH_OBJECT_MATRIX true
#define OLD_TEST false


#if TEST_WITH_OBJECT_MATRIX
#include <list>
#include <atomic>
#include <string>
#include <iostream>
#include <random>
#include <variant>
#include <stack>
#include "3d_graph_mat.hpp"

using namespace std;

#include "classes.hpp"

template<typename T1, typename  T2, typename  T3>
std::ostream& operator<<(std::ostream& os, const std::tuple<T1,T2,T3>& t) noexcept {
	return os << std::get<0>(t) << std::get<1>(t) << std::get<2>(t) << '\n';
}

struct Pool {
	std::stack<BoxObject*> pool;
	
	inline void push(BoxObject* p) {
		pool.push(p);
	}
	inline auto top() {
		return pool.top();
	}
	~Pool() {
		while (!pool.empty()) {
			delete pool.top();
			pool.pop();
		}
	}
};

int main() {
	Pool pool;
	auto initialiser = [n = 0, &pool](int x, int y, int z) mutable -> BoxObject* {
		++n;
		if(n%10 == 0) std::cout << "Adding box " << n << '\n';

		if ((x > -3 && x < 3) && (y > -3 && y < 3) && (z > -3 && z < 3)) {
			pool.push(new BoxObject(to_string(100 * x + 10 * y + z), {}, x ^ y ^ z));
			return pool.top();
		}

		return nullptr;
	};

	std::cout << std::boolalpha << std::is_invocable_v<function<void(BoxObject&, int, int, int)>, BoxObject&, int, int, int> << '\n';
	std::cout << std::is_invocable_v<function<void(BoxObject&, int, int, int)>, BoxObject&, int, int, int> << '\n';

	Graph_Matrix_3D<BoxObject*> matrix({5, 5, 5}, initialiser);
	matrix.set_expansion_rate(1);
	matrix.resume_auto_expansion( initialiser );
	//std::this_thread::sleep_for(std::chrono::seconds(5));
	matrix.pause_auto_expansion();
	cout << matrix.get_size() << std::endl;

	Graph_Matrix_3D<int> imat({ 100,100,100 }, [](int x, int y, int z) -> int {
		return 100 * x + 10 * y + z;
		});
	auto* box = imat.find(235);
	cout << imat.get_size() << std::endl;
}

#elif OLD_TEST
#include <iostream>

#include "graph_square_mat.hpp"
#include "3d_graph_mat.hpp"

using namespace std;

void distMat(Graph_Matrix_3D<int>& mat) {
	static int count = 1;
	std::cout << "Called " << count++ << "th time: \n";

	for (int i = mat.min_z; i <= mat.max_z; i++)
	{
		mat.disp_xy_layer(i);	// debug
		std::cout << "\n\n";	// debug
	}
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