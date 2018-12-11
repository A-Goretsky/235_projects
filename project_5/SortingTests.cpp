//ANTON GORETSKY
//Sorting Tests Implementation

#include <iostream>
#include "SortingTests.hpp"
#include <utility>    // for std::swap
#include <algorithm>  // for std::copy
#include <cmath>      // for round
#include <chrono>     // for timing functions
#include <cstdlib>    // for rand and srand

/**
 @post Sorts an array in ascending order using the selection sort algorithm.
 @param a the array to sort
 @param size the number of elements in a
 */

//My Old Java Selection Sort
/*public static void selectionSortV( ArrayList<Comparable> data ) {
		int minIndex; 
		Comparable temp;  
		for (int i = 0; i < data.size() - 1; i++) {
		    minIndex = i;   
		    for (int j = i + 1; j < data.size(); j++) {
				if(data.get(j).compareTo(data.get(minIndex)) <= 0 ){
				    minIndex = j;
				}
		    }
		    temp = data.get(minIndex);
		    data.set(minIndex, data.get(i));
		    data.set(i, temp); 
		}          
  }
*/


void selectionSort(int a[], size_t size) {
	int minInd;
    int temp;
    for (int i = 0; i < size - 1; i++) {
        minInd = i;
        for (int x = i + 1; x < size; x++) {
            if (a[x] < a[minInd]) {
                minInd = x;
            }
        }
        temp = a[minInd];
        a[minInd] = a[i];
        a[i] = temp;
    }
	
	//printing array test
}


//Convert of my old Java insertionSort

void insertionSort(int a[], size_t size) {
	for (int part = 0; part < size; part++) {
		for (int x = part; x > 0; x--) {
			if (a[x] < a[x-1]) {
				std::swap(a[x], a[x-1]);
			}
			else {
				break;
			}
		}
	}

	//printing array test
	/*for (int x = 0; x < size; x++) {
		std::cout << a[x] << " ";
	}
	std::cout << "\n";
	*/
}

void mergeSort(int a[], int from, int to) {
	if (from < to) {
		int mid = (from + to) / 2;

		mergeSort(a, from, mid);
		mergeSort(a, mid+1, to);

		mid = (from + to) / 2;

		const int left_SIZE = mid - from + 1;
		const int right_SIZE = to - mid;

        int* left = new int[left_SIZE];
        int* right = new int[right_SIZE];

		for (int x = 0; x < left_SIZE; ++x) {
			left[x] = a[from + x];
		}
		for (int x = 0; x < right_SIZE; ++x) {
			right[x] = a[mid + 1 + x];
		}

		int left_IND = 0;
		int right_IND = 0;
		int merge_IND = from;

		while (left_IND < left_SIZE && right_IND < right_SIZE) {
			if (left[left_IND] < right[right_IND]) {
				a[merge_IND] = left[left_IND];
				left_IND++;
			}
			else {
				a[merge_IND] = right[right_IND];
				right_IND++;
			}
			merge_IND++;
		}

		while (left_IND < left_SIZE) {
			a[merge_IND] = left[left_IND];
			left_IND++;
			merge_IND++;
		}

		while (right_IND < right_SIZE) {
			a[merge_IND] = right[right_IND];
			right_IND++;
			merge_IND++;
		}
	}


}

/*void mergeSort(int a[], int from, int to) {
	if (from < to) {
		int mid = (from + to) / 2;

		mergeSort(a, from, mid);
		mergeSort(a, mid+1, to);

		mid = (from + to) / 2;

		const int left_SIZE = mid - from + 1;
		const int right_SIZE = to - mid;

		int left[left_SIZE];
		int right[right_SIZE];

		for (int x = 0; x < left_SIZE; ++x) {
			left[x] = a[from + x];
		}
		for (int x = 0; x < right_SIZE; ++x) {
			right[x] = a[mid + 1 + x];
		}

		int left_IND = 0;
		int right_IND = 0;
		int merge_IND = from;

		while (left_IND < left_SIZE && right_IND < right_SIZE) {
			if (left[left_IND] < right[right_IND]) {
				a[merge_IND] = left[left_IND];
				left_IND++;
			}
			else {
				a[merge_IND] = right[right_IND];
				right_IND++;
			}
			merge_IND++;
		}

		while (left_IND < left_SIZE) {
			a[merge_IND] = left[left_IND];
			left_IND++;
			merge_IND++;
		}

		while (right_IND < right_SIZE) {
			a[merge_IND] = right[right_IND];
			right_IND++;
			merge_IND++;
		}
	}


}
*/
int getRandomNumber(int min, int max) {
	int randNum = rand()%(max-min + 1) + min;
	return randNum;
}

void generateRandomArray(int values[], size_t size) {
	for (int x = 0; x < size; x++) {
		values[x] = getRandomNumber(0, 10000);
	}
}

void generateAscendingArray(int values[], size_t size) {
	for (int x = 0; x < size; x++) {
		values[x] = x;
	}
}

void generateDescendingArray(int values[], size_t size) {
	for (int x = 0; x < size; x++) {
		values[x] = size - x;
	}
}

void generateLastTenRandomArray(int values[], size_t size) {
	generateAscendingArray(values, size - 10);
	for (int x = size - 10; x < size; x++) {
		values[x] = getRandomNumber(0, 10000);
	}
}

void generateFewRandomArray(int values[], size_t size) {
	for (int x = 0; x < size; x++) {
		values[x] = getRandomNumber(0, size / 10);
	}
}

double sortTest(void (*sortingFunction)(int a[], size_t size), int values[], size_t size) {
	double res = 0;
	int* copy = values;
	for (int x = 0; x < 10; ++x) {
		auto start = high_resolution_clock().now();
		sortingFunction(copy, size);
		auto end = high_resolution_clock().now();
		duration<float,std::micro> run_time = duration_cast<microseconds>(end-start);
		res += run_time.count();
		copy = values;
	}

	return res / 10.0;
}


double mergeSortTest(int values[], size_t size) {
	double res = 0;
	int *copy = values;
	for (int x = 0; x < 10; x++) {
		auto start = high_resolution_clock().now();
		mergeSort(copy, 0, size - 1);
		auto end = high_resolution_clock().now();
		duration<float, std::micro> run = duration_cast<microseconds>(end - start);
		res += run.count();
		copy = values;
	}

	return res / 10.0;
}
