#include <iostream>
#include "sort.h"

int main() {
	const int N = 10;
	int a[] = { 9, 3, 5, 2, 8, 6, 4, 3, 7, 8 };

	// Ausgabe des "Vorher" Zustands des Arrays...
	std::cout << "Vorher: ";

	for (int k = 0; k < N; k++) {
		std::cout << a[k] << (k < N - 1 ? ", " : "\n");
	}
		
	// Aufruf der sortiere() Funktion...
	sort(a, N);
	
	// Ausgabe des "Nachher" Zustands des Arrays...
	std::cout << "Nachher: ";
	for (int k = 0; k < N; k++) {
		std::cout << a[k] << (k < N - 1 ? ", " : "\n");
	}
		
	system("PAUSE");
	return 0;
}