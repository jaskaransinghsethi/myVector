#include "myVector.h"
#include <iostream>

int main() {
	myVector<int> vec;
	vec.push_back(9);
	vec.push_back(10);
	vec.push_back(11);
	for (auto ch : vec) {
		std::cout << ch << "\n";
	}
	std::cout << "\nSize:" << vec.size();
	vec.pop_back();
	std::cout << "\nSize after popping out one element:" << vec.size();

	return 0;
}