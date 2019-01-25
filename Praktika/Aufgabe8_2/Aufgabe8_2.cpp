#include <iostream>
#include <string>

int bubbleSort(int sudokuPart[9]) {
	int tmp = 0;
	bool swapped;
	for (int i = 0; i < 9; i++) {
		swapped = false;
		for (int j = 0; j < 8; j++) {
			if (sudokuPart[j] > sudokuPart[j + 1]) {
				tmp = sudokuPart[j];
				sudokuPart[j] = sudokuPart[j + 1];
				sudokuPart[j + 1] = tmp;
				swapped = true;
			}
		}

		if (!swapped) {
			break;
		}
	}

	return *sudokuPart;
}

void checkSudoku(int sudokuPart[9], int indexNum, std::string category, bool &isCorrect) {
	int multiple;

	*sudokuPart = bubbleSort(sudokuPart);

	if (sudokuPart[0] != 1) {
		std::cout << category << " " << indexNum << ": Zahl " << 1 << " kommt nicht vor." << std::endl;
		isCorrect = false;
	}

	for (int index = 0; index < 9; index++) {
		int diff = sudokuPart[index + 1] - sudokuPart[index];
		
		if (diff > 1) {
			for (int pos = 1; pos < diff; pos++) {
				std::cout << category << " " << indexNum << ": Zahl " << sudokuPart[index] + pos << " kommt nicht vor." << std::endl;
			}
			isCorrect = false;
		} else if (sudokuPart[index + 1] == sudokuPart[index]) {
			multiple = sudokuPart[index];
			std::cout << category << " " << indexNum << ": Zahl " << multiple << " kommt mehrfach vor." << std::endl;
			isCorrect = false;
		}
	}

	if (sudokuPart[8] != 9) {
		std::cout << category << " " << indexNum << ": Zahl " << 9 << " kommt nicht vor." << std::endl;
		isCorrect = false;
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
	int sudokuBlock[9] = { 0 };

	for (int line = 0; line < 9; line++) {	
		for (int column = 0; column < 9; column++) {
			sudokuColumn[column] = sudoku[column][line];
		}
		checkSudoku(sudokuColumn, line, "Spalte", isCorrect);
	}

	for (int line = 0; line < 9; line++) {
		for (int column = 0; column < 9; column++) {
			sudokuLine[column] = sudoku[line][column];
		}
		checkSudoku(sudokuLine, line, "Zeile", isCorrect);
	}

	for (int block = 0; block < 9; block++) {
		int index = 0;
		for (int line = block / 3 * 3; line <= block / 3 * 3 + 2; line++) {
			for (int column = block % 3 * 3; column <= block % 3 * 3 + 2; column++) {
				sudokuBlock[index] = sudoku[line][column];
				index++;
			}
		}
		checkSudoku(sudokuBlock, block, "Block", isCorrect);
	}

	if (isCorrect) {
		std::cout << "Das Sudoku ist gueltig." << std::endl;
	}

	std::system("PAUSE");
	return 0;
}