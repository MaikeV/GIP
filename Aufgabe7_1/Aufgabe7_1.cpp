#include <iostream>
#include <string>

int main() {
	std::string eingabe[11];
	int sudoku[9][9] = { 0 };
	int lineIndex = 0;
	int columnIndex = 0;

	std::cout << "Bitte geben Sie das Sudoku ein: " << std::endl;

	for (int index = 0; index <= 10; index++) {
		std::getline(std::cin, eingabe[index]);
	}

	for (int line = 0; line <= 10; line++) {
		for (int column = 0; column <= eingabe[line].length() - 1; column++) {
			if (eingabe[line].at(column) != '-' && eingabe[line].at(column) != '.' && eingabe[line].at(column) != '|') {
				sudoku[lineIndex][columnIndex] = eingabe[line].at(column) - '0';
				columnIndex++;
			} else if (eingabe[line].at(0) == '-') {
				lineIndex--;
				break;
			}
		}

		columnIndex = 0;
		lineIndex++;
	}

	std::cout << std::endl << "Das Sudoku lautet: " << std::endl;

	for (int line = 0; line < 9; line++) {
		for (int column = 0; column < 9; column++) {
			std::cout << ";" << sudoku[line][column];

			if (column == 2 || column == 5) {
				std::cout << ";//";
			}

			if (column == 8) {
				std::cout << std::endl;
			}
		}

		if (line == 2 || line == 5) {
			std::cout << "=======//=======//=======" << std::endl;
		}
	}

	std::system("PAUSE");
	return 0;
}