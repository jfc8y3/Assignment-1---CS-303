#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;

int main() {

	// Open the .txt file
	ifstream file("A1input.txt");

	// This counts the number of integers in file.
	int numInt = 0;
	int num; // Reads integers from file
	while (file >> num) {
		++numInt;
	}

	// This clears the condition that the end of the file has been read, in order to read it again for the next while loop.
	file.clear();
	// This sets the file reading to the beginning, 0 is the position of file, and "beg" means beginning.
	file.seekg(0, ios::beg);

	// Dynamically allocate memory for the array (to use "numInt")
	int* numbers = new int[numInt];


	// Reads the integers into the array.
	int index = 0;
	while (file >> num and index < numInt) {
		numbers[index++] = num;
	}

	// This is the menu loop
	while (true) {
		char choice;

		cout << "Q: Check index of given number" << endl; // checkNum function
		cout << "W: Change value of integer" << endl;  // modifyValue function
		cout << "E: Add integer to array" << endl;  // addNum function
		cout << "R: Remove integer / replace with 0" << endl;  // numRemove function
		cout << endl;

	
		cin >> choice;


		// Choice Q
		if (choice == 'Q' or choice == 'q') {
			int choiceNum;
			cout << endl;
			cout << "Enter a number to see its index: " << endl;
			cin >> choiceNum;
			int numIndex = checkNum(numbers, numInt, choiceNum);
			if (numIndex == -1) {
				cout << "This number is not in the array." << endl;
			}
			else {
				cout << endl;
				cout << "The number " << choiceNum << " is in index " << numIndex << "." << endl;
				cout << endl;
				cout << "The current array:" << endl;
				for (int i = 0; i < numInt; ++i) {
					cout << numbers[i] << " ";
				}
				cout << endl;
				cout << endl;
			}
		}



		// Choice W
		else if (choice == 'W' or choice == 'w') {
			int chosenNum, replacement;
			cout << "Enter replacement number: " << endl;
			cin >> replacement;
			cout << "Enter number to be replaced: " << endl;
			cin >> chosenNum;
			int numFound = modifyValue(numbers, chosenNum, replacement, numInt);
			if (numFound == -1) {
				cout << "This number is not in the array." << endl;
			}
			else {
				cout << "You replaced the value " << chosenNum << " with " << replacement << "." << endl;
				cout << "The current array:" << endl;
				for (int i = 0; i < numInt; ++i) {
					cout << numbers[i] << " ";
				}
				cout << endl;
				cout << endl;
			}
		}

		// Choice E
		else if (choice == 'E' or choice == 'e') {
			int chosenInt;
			cout << "Enter number to add to array: ";
			cin >> chosenInt;
			numbers = addNum(numbers, numInt, chosenInt);
			cout << endl;
			cout << "The updated array:" << endl;
			for (int i = 0; i < numInt; ++i) {
				cout << numbers[i] << " ";
			}
			cout << endl;
			cout << endl;
		}

		// Choice R
		else if (choice == 'R' or choice == 'r') {
			cout << "A: Replace number with 0" << endl;
			cout << "B: Remove number" << endl;
			while (true) {
				char choice1;
				cin >> choice1;

				// Replaces number with 0
				if (choice1 == 'A' or choice1 == 'a') {
					int indexChoice;
					cout << "Enter index: " << endl;
					cin >> indexChoice;
					numRemove(numbers, 'A', indexChoice, numInt);
					cout << endl;
					cout << "The updated array:" << endl;
					for (int i = 0; i < numInt; ++i) {
						cout << numbers[i] << " ";
					}
					cout << endl;
					cout << endl;
					break;
				}

				// Removes Number
				else if (choice1 == 'B' or choice1 == 'b') {
					int indexChoice;
					cout << "Enter index: " << endl;
					cin >> indexChoice;
					numRemove(numbers, 'B', indexChoice, numInt);
					cout << endl;
					cout << "The updated array:" << endl;
					for (int i = 0; i < numInt; ++i) {
						cout << numbers[i] << " ";
					}
					cout << endl;
					cout << endl;
					break;
				}

				// Invalid Choice
				else {
					cout << "Please enter a valid choice." << endl;
				}
			}
			
		}

		// Invalid Choice
		else {
			cout << "Invalid choice, please try again." << endl;
			cout << endl;
		}
	}


	
	
}