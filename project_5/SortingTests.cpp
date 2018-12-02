#include <iostream>
#include "SortingTests.hpp"


/**
 @post Sorts an array in ascending order using the selection sort algorithm.
 @param a the array to sort
 @param size the number of elements in a
 */

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
        for (int x = i + 1; i < size; i++) {
            if (a[x] < a[minInd]) {
                minInd = x;
            }
        }
        temp = a[minInd];
        a[minInd] = a[i];
        a[i] = temp;
    }
}

void insertionSort(int a[], size_t size) {
	
}

void mergeSort(int a[], int from, int to) {
	
}

void generateRandomArray(int values[], size_t size) {
	
}

void generateAscendingArray(int values[], size_t size) {
	
}

void generateDescendingArray(int values[], size_t size) {
	
}

void generateLastTenRandomArray(int values[], size_t size) {

}


double sortTest(void (*sortingFunction)(int a[], size_t size), int values[], size_t size) {

}

double mergeSortTest(int values[], size_t size) {

}


