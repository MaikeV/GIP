#include <iostream>

int main() {
	int v1 = 0;
	int v2 = 0;
	int v_tmp = 0;

	std::cout << "Bitte geben Sie den ganzzahligen Wert der ersten Variable ein: ? ";
	std::cin >> v1;
	std::cout << "Bitte geben Sie den ganzzahligen Wert der zweiten Variable ein: ? ";
	std::cin >> v2;

	v_tmp = v2;
	v2 = v1;
	v1 = v_tmp;

	std::cout << "Nach dem Tausch:" << std::endl;
	std::cout << "Wert der ersten Variable: " << v1 << std::endl;
	std::cout << "Wert der zweiten Variable: " << v2 << std::endl;

	std::system("PAUSE");

	return 0;
}