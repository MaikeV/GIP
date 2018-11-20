#include <iostream>

int main() {

	int values[9];
	int diffVals = 0;
	int input;
	bool isNew = true;

	for (int index = 0; index <= 8; index++) {
		isNew = true;
		do {
			std::cout << "Bitte geben Sie die " << index + 1 << ". Zahl ein: ";
			std::cin >> input;
		} while (input < 1 || input >= 7);

		values[index] = input;

		for (int index2 = 0; index2 < index; index2++) {
			if (values[index] == values[index2]) {
				isNew = false;
			}
		}

		if (isNew) {
			diffVals++;
		}
	}

	std::cout << "In der Eingabe kamen " << diffVals << " unterschiedliche Zahlen vor." << std::endl;

	std::system("PAUSE");
	return 0;
}