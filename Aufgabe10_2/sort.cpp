#include <iostream>
#include "sort.h"

void sort(int array[], int length) {
	for (int index = 0; index <= length - 1; index++) {
		int numToSort = array[index];
		unsigned int j = index;

		while (j > 0 && array[j - 1] > numToSort) {
			array[j] = array[j - 1];
			j = j - 1;
		}

		array[j] = numToSort;
	}

}