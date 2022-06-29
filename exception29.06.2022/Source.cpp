#include <iostream>
#include <exception>

int F00(int a) {
	if (a == 0) {
		throw std::runtime_error("divaided by zero. Coz a == 0");
	}
	int result{ 123 / a };
	return result;
}

int F01(int a, int b) {
	if (a < b) {
		const char *str = "lower argument" ;
		throw str;
	}
	int result{ a - b };
	return result;
}

// noexcept - без исключения
void Bar() noexcept {

}

int main() {
	int a{ 0 };
	mark1: ;
	try {
		F00(0);
		F01(1, 6);
	} 
	catch (std::runtime_error &ex) {
		std::cerr << ex.what();
		a = 1;
		goto mark1;
	}
	catch (std::exception &ex) {
		std::cerr << ex.what();
	}
	catch (...) {
		std::cerr << "undefined xception";
	}

	return 0;
}