#include <iostream>

int main() {
	int total = 0;
	int candidate1 = 0;
	int candidate2 = 0;

	std::cout << "Bitte geben Sie die Gesamtzahl der abgegebenen gueltigen Stimmen ein: ? ";
	std::cin >> total;
	std::cout << "Bitte geben Sie die Anzahl Stimmen des ersten Kandidaten ein: ? ";
	std::cin >> candidate1;
	std::cout << "Bitte geben Sie die Anzahl Stimmen des zweiten Kandidaten ein: ? ";
	std::cin >> candidate2;

	int candidate3 = total - candidate1 - candidate2;

	std::cout << "Auf den dritten Kandidaten sind somit " << candidate3 << " Stimmen entfallen." << std::endl;

	double c1_per = (candidate1 / total);
	double c2_per = (candidate2 / total);
	double c3_per = (candidate3 / total);

	std::cout << "Kandidat 1 erhielt " << c1_per << " % der Stimmen." << std::endl;
	std::cout << "Kandidat 2 erhielt " << c2_per << " % der Stimmen." << std::endl;
	std::cout << "Kandidat 3 erhielt " << c3_per << " % der Stimmen." << std::endl;

	std::system("PAUSE");

	return 0;
}