#include <iostream>
#include <string>

void checkBlock(int sudokuBlock[9]) {

}

void checkSudoku(int sudokuPart[9], int indexNum, std::string category, bool *isCorrect) {
	for (int index = 0; index < 8; index++) {
		for (int innerIndex = index + 1; innerIndex < 8; innerIndex++) {
			if (sudokuPart[index] == sudokuPart[innerIndex]) {
				if (category == "line") {
					std::cout << "Zeile " << indexNum << ": " << "Zahl " << sudokuPart[index] << " kommt mehrfach vor." << std::endl;
				} else if (category == "column") {
					std::cout << "Spalte " << indexNum << ": " << "Zahl " << sudokuPart[index] << " kommt mehrfach vor." << std::endl;
				} else if (category == "block") {
					std::cout << "Block " << indexNum << ": " << "Zahl " << sudokuPart[index] << " kommt mehrfach vor." << std::endl;
				}
				isCorrect = false;
			}
		}
	}
}

int main() {
	std::string eingabe[11];
	int sudoku[9][9] = { 0 };
	int lineIndex = 0;
	int columnIndex = 0;
	bool isCorrect = true;

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

	int sudokuColumn[9] = { 0 };
	int sudokuLine[9] = { 0 };

	for (int line = 0; line < 9; line++) {	
		for (int column = 0; column < 9; column++) {
			sudokuLine[column] = sudoku[line][column];
			sudokuColumn[column] = sudoku[column][line];
		}

		checkSudoku(sudokuLine, line, "line", &isCorrect);
		checkSudoku(sudokuColumn, line, "column", &isCorrect);
	}

	for (int line = 0; line < 9; line++) {

	}

	if (isCorrect) {
		std::cout << "Das Sudoku ist gueltig." << std::endl;
	}

	std::system("PAUSE");
	return 0;
}