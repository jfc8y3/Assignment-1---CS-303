#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;


// This function iterates through the array until the given number is found.
// If it is found, it returns the index of it.
// If the number does not exist, an error message prints and returns -1.
int checkNum(int array[], int size, int givenNum) {
	for (int i = 0; i < size; i++) {
		if (array[i] == givenNum) {
			return i;
		}
	}
	cout << "Number not found" << endl;
	return -1;
}

// This function iterates through the array until the chosen number is found.
// When the number is found, the index where that number is located is replaced with the replacement number.
// If the number given isn't found, and error message prints and returns -1.
int modifyValue(int array[], int chosenNum, int replacement, int size) {
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (array[i] == chosenNum) {
			index = i;
			array[index] = replacement;
			return array[index];
		}
	}
	cout << "Number not found" << endl;
	return -1;
}


// This function will add a new integer to the end of the array.
// It increments the size by 1 (passed by reference value)
// New integer array is made with the updated new size (dynamically allocated)
// The function then copies elements from original array into new array and adds the new number.
int* addNum(int array[], int& size, int givenNum) {
	int newSize = size + 1;
	int* newArray = new int[newSize];
	
	for (int i = 0; i < size; ++i) {
		newArray[i] = array[i];
	}

	newArray[size] = givenNum;

	size = newSize;

	return newArray;
}


// Since this function has two functionalitites, return type is void and has if branch.
// Choice "A" takes the user input index, and reassigns the index in the array with 0.
// Choice "B" first checks if index is valid.
// The function then shifts every number in the array one position to the left, starting from index to exlude (delete) the number.
// The size is the decremented by 1.
void numRemove(int array[], char choice, int index, int& size) {
	if (choice == 'A' or choice == 'a') {
		array[index] = 0;
	}
	else if (choice == 'B' or choice == 'b') {
		if (index >= 0 and index < size) {
			for (int i = index; i < size - 1; i++) {
				array[i] = array[i + 1];
			}
			size = size - 1;
		}
		else {
			cout << "Invalid index." << endl;
		}
	}
}
