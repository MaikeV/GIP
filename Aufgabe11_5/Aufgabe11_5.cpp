#include <iostream>
#define CIMGGIP_MAIN
#include "CImgGIP05.h"

using namespace cimg_library;

const int grid_size = 10; // Anzahl an Kaestchen in x- und y-Richtung
const int box_size = 30; // size der einzelnen Kaestchen (in Pixel)
const int border = 20; // Rand links und oben bis zu den ersten Kaestchen (in Pixel)

int checkNeighbours(bool grid[grid_size][grid_size], int origColumn, int origRow) {
	//c-1r-1;c  r-1;c+1r-1
	//c-1r  ;  na  ;c+1r
	//c-1r+1;c  r+1;c+1r+1
	int counter = 0;
	for (int column = -1; column <= 1; column++) {
		for (int row = -1; row <= 1; row++) {
			if (!(origColumn + column < 0 || origColumn + column > grid_size - 1) && !(origRow + row < 0 || origRow + row > grid_size - 1) &&
				!(row == 0 && column == 0)) {
				if (grid[origColumn + column][origRow + row]) {
					counter++;
				}
			}
		}
	}

	return counter;
}

// Prototyp der Funktionen zum Vorbelegen des Grids ...
void grid_init(bool grid[][grid_size]);
int main() {
	bool grid[grid_size][grid_size] = { 0 };
	bool next_grid[grid_size][grid_size] = { 0 };
	// Erstes Grid vorbelegen ...
	grid_init(grid);

	while (gip_window_not_closed()) {
		// Spielfeld anzeigen ...
		// Ggfs gip_stop_updates();
		// TO DO

		gip_draw_rectangle(border, border, border + box_size * grid_size, border + box_size * grid_size, white);

		for (int column = 0; column <= grid_size - 1; column++) { //column
			for (int row = 0; row <= grid_size - 1; row++) { //row
				if (grid[column][row]) {
					gip_draw_rectangle(border + row * box_size, border + column * box_size, //top left corner
						border + row * box_size + box_size, border + column * box_size + box_size, blue); //bottom right corner
				}
			}
		}
		
		gip_start_updates();
		gip_sleep(3);
		// Berechne das naechste Spielfeld ...
		// Achtung; Für die Zelle (x,y) darf die Position (x,y) selbst *nicht*
		// mit in die Betrachtungen einbezogen werden.
		// Ausserdem darf bei zellen am rand nicht über den Rand hinausgegriffen
		// werden (diese Zellen haben entsprechend weniger Nachbarn) ...
		// TO DO

		for (int column = 0; column <= grid_size - 1; column++) {
			for (int row = 0; row <= grid_size - 1; row++) {
				int counter = checkNeighbours(grid, column, row);

				if (counter == 3) {
					next_grid[column][row] = true;
				} else if (counter == 2) {
					next_grid[column][row] = grid[column][row];
				} else {
					next_grid[column][row] = false;
				}
			}
		}

		// Kopiere das naechste Spielfeld in das aktuelle Spielfeld ...
		// TO DO
		for (int column = 0; column <= grid_size - 1; column++) {
			for (int row = 0; row <= grid_size - 1; row++) {
				grid[column][row] = next_grid[column][row];
			}
		}
	}

	return 0;
}
void grid_init(bool grid[][grid_size]) {
	int eingabe = -1;

	do {
		std::cout << "Bitte waehlen Sie die Vorbelegung des Grids aus:" << std::endl
			<< "0 - Zufall" << std::endl
			<< "1 - Statisch" << std::endl
			<< "2 - Blinker" << std::endl
			<< "3 - Oktagon" << std::endl
			<< "4 - Gleiter" << std::endl
			<< "5 - Segler 1 (Light-Weight Spaceship)" << std::endl
			<< "6 - Segler 2 (Middle-Weight Spaceship)" << std::endl
			<< "? ";
		std::cin >> eingabe;
		std::cin.clear();
		std::cin.ignore(1000, '\n');
	} while (eingabe < 0 || eingabe > 6);
	if (eingabe == 0) {
		// Erstes Grid vorbelegen (per Zufallszahlen) ...
		// TO DO
		for (int column = 0; column <= grid_size; column++) {
			for (int row = 0; row <= grid_size; row++) {
				if (gip_random(0, 1) == 1) {
					grid[column][row] = true;
				} else {
					grid[column][row] = false;
				}
			}
		}
	} else if (eingabe == 1) {
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] = {
			{ '.', '*', '.' },
			{ '*', '.', '*' },
			{ '.', '*', '.' },
		};

		for (int y = 0; y < pattern_size; y++) {
			for (int x = 0; x < pattern_size; x++) {
				if (pattern[y][x] == '*') {
					grid[x][y + 3] = true;
				}
			}
		}		
	} else if (eingabe == 2) {
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] = {
			{ '.', '*', '.' },
			{ '.', '*', '.' },
			{ '.', '*', '.' },
		};

		for (int y = 0; y < pattern_size; y++) {
			for (int x = 0; x < pattern_size; x++) {
				if (pattern[y][x] == '*') {
					grid[x][y + 3] = true;
				}
			}
		}			
	} else if (eingabe == 3) {
		const int pattern_size = 8;
		char pattern[pattern_size][pattern_size] = {
			{ '.', '.', '.', '*', '*', '.', '.', '.' },
			{ '.', '.', '*', '.', '.', '*', '.', '.' },
			{ '.', '*', '.', '.', '.', '.', '*', '.' },
			{ '*', '.', '.', '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '.', '.', '.', '*' },
			{ '.', '*', '.', '.', '.', '.', '*', '.' },
			{ '.', '.', '*', '.', '.', '*', '.', '.' },
			{ '.', '.', '.', '*', '*', '.', '.', '.' },
		};

		for (int y = 0; y < pattern_size; y++) {
			for (int x = 0; x < pattern_size; x++) {
				if (pattern[y][x] == '*') {
					grid[x][y + 1] = true;
				}
			}
		}
	} else if (eingabe == 4) {
		const int pattern_size = 3;
		char pattern[pattern_size][pattern_size] = {
			{ '.', '*', '.' },
			{ '.', '.', '*' },
			{ '*', '*', '*' },
		};

		for (int y = 0; y < pattern_size; y++) {
			for (int x = 0; x < pattern_size; x++) {
				if (pattern[y][x] == '*') {
					grid[x][y + 3] = true;
				}
			}
		}			
	} else if (eingabe == 5) {
		const int pattern_size = 5;
		char pattern[pattern_size][pattern_size] = {
			{ '*', '.', '.', '*', '.' },
			{ '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '*' },
			{ '.', '*', '*', '*', '*' },
			{ '.', '.', '.', '.', '.' },
		};

		for (int y = 0; y < pattern_size; y++) {
			for (int x = 0; x < pattern_size; x++) {
				if (pattern[y][x] == '*') {
					grid[x][y + 3] = true;
				}	
			}	
		}
	}
	else if (eingabe == 6) {
		const int pattern_size = 6;
		char pattern[pattern_size][pattern_size] = {
			{ '.', '*', '*', '*', '*', '*' },
			{ '*', '.', '.', '.', '.', '*' },
			{ '.', '.', '.', '.', '.', '*' },
			{ '*', '.', '.', '.', '*', '.' },
			{ '.', '.', '*', '.', '.', '.' },
			{ '.', '.', '.', '.', '.', '.' },
		};

		for (int y = 0; y < pattern_size; y++) {
			for (int x = 0; x < pattern_size; x++) {
				if (pattern[y][x] == '*') {
					grid[x][y + 3] = true;
				}	
			}	
		}		
	}
}