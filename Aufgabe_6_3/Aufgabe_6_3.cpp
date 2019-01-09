#include <iostream>

const char empty_pixel = '.';
const char filled_pixel = '#';
const int canvas_size = 40;

void init_canvas(char canvas[][canvas_size]) {
	for (int x = 0; x < canvas_size; x++) {
		for (int y = 0; y < canvas_size; y++) {
			canvas[x][y] = empty_pixel;
		}
	}
}

void print_canvas(char canvas[][canvas_size]) {
	for (int y = 0; y < canvas_size; y++) {
		for (int x = 0; x < canvas_size; x++) {
			std::cout << canvas[x][y];
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void linie(int x1, int y1, int x2, int y2, char canvas[][canvas_size]) {
	// ... Ihr Code hier ...

	int diffX = x2 - x1;
	int diffY = y2 - y1;

	if (diffX < 0) {
		diffX = diffX * (-1);
	}

	if (diffY < 0) {
		diffY = diffY * (-1);
	}

	if ((diffX == 0 && diffY == 1) || (diffY == 0 && diffX == 1) || (diffX == 1 && diffY == 1)) { //(x1, y1) und(x2, y2) sind benachbart) {
		//Zeichne die Punkte(x1, y1) und(x2, y2)
		canvas[x1][y1] = filled_pixel;
		canvas[x2][y2] = filled_pixel;

	} else {
		// Berechne die ganzzahligen Koordinaten des
		// Punktes in der Mitte zwischen den beiden
		// Ausgangspunkten:
		int x_mitte = (x1 + x2) / 2;
		int y_mitte = (y1 + y2) / 2;

		// Rekursive Aufrufe:
		//1. Linie vom ersten Punkt bis zur Mitte
		linie(x1, y1, x_mitte, y_mitte, canvas);
		//2. Linie von der Mitte bis zum zweiten Punkt
		linie(x_mitte, y_mitte, x2, y2, canvas);
	}
}

int main() {
	char canvas[canvas_size][canvas_size];
	init_canvas(canvas);
	int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

	do {
		std::cout << "Bitte geben Sie den ersten Punkt ein: ? ";
		std::cin >> x1 >> y1;
	} while (x1 < 0 || x1 >= canvas_size || y1 < 0 || y1 >= canvas_size);

	do {
		std::cout << "Bitte geben Sie den zweiten Punkt ein: ? ";
		std:: cin >> x2 >> y2;
	} while (x2 < 0 || x2 >= canvas_size || y2 < 0 || y2 >= canvas_size);

	linie(x1, y1, x2, y2, canvas);
	print_canvas(canvas);

	system("PAUSE");
	return 0;
}