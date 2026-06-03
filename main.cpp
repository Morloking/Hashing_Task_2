#include <iostream>
#include <string>
#include <cmath>

#include <Windows.h>

int realStringHash(std::string str, int simpleNumP,int moduleN) {
	uint64_t hash{}, power{1};//так как simpleNumP в нулевой степени дает 1
	char symbol{};
	for (char symbol : str) {
		hash = (hash + static_cast<unsigned char>(symbol) * power) % moduleN;
		power = (power * simpleNumP) % moduleN;
	}
	return hash;
}

int main() {
	SetConsoleOutputCP(1251);
	std::string str{};
	int simpleNumP{}, moduleN{};

	std::cout << "Введите p: ";
	std::cin >> simpleNumP;
	std::cout << "Введите n: ";
	std::cin >> moduleN;
	do {
		std::cout << "Введите строку: ";
		std::cin >> str;
		std::cout << "Хэш строки " << str << " = " << realStringHash(str, simpleNumP, moduleN) << "\n";
	} while (str != "exit");
	return 0;
}
