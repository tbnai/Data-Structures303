#include<iostream>

// *---Question 1---* //
// This loop will find the number 
int findInteger(const int arr[], int size, int target) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	// if number is not found return -1
	return -1;
}
// *---Question 2---*
// Will check if the value is valid 
int modifyArray(int arr[], int size, int indexTwo, int newValue) {
	if (indexTwo >= 0 && indexTwo < size) {
		int oldValue = arr[indexTwo];
		arr[indexTwo] = newValue;
		return oldValue;
	}
	return -1;
}
// *---Question 3---* //
// Will add a new integer
void addNewInteger(int arrThree[], int& sizeThree, int newValueThree) {
	arrThree[sizeThree] = newValueThree;
	sizeThree++;
}
// *---Question 4---* //
// This void will remove an integer
void removeInteger(int arrFour[], int& sizeFour, int indexFour) {
	if (indexFour >= 0 && indexFour < sizeFour) {
		for (int i = indexFour;i < sizeFour - 1;i++) {
			arrFour[i] = arrFour[i + 1];
		}
	}
	sizeFour--;
}

int main() {
	// finding an index in the array and confirm whether or not its in the array
	// *---Question 1---* //
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int target = 10;
	int index = findInteger(arr, size, target);

	// output for question 1 
	std::cout << "*---Question 1---*" << std::endl;
	if (index != -1) {
		std::cout << "Target Integer " << target << " found at index. " << std::endl << std::endl;;
	}
	else {
		std::cout << "Target Integer " << target << " did not find in the array." << std::endl << std::endl;;
	}

	// switching out an index in the array and replacing with another number
	// *---Question 2---* //
	int arrTwo[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
	int sizeTwo = sizeof(arrTwo) / sizeof(arrTwo[0]);
	int indexTwo = 4;
	int newValueTwo = 100;

	int oldValue = modifyArray(arrTwo, sizeTwo, indexTwo, newValueTwo);

	std::cout << "*---Question 2---*" << std::endl;
	if (oldValue != -1) {
		std::cout << "Modified array is: ";
		for (int i = 0;i < sizeTwo;i++) {
			std::cout << arrTwo[i] << " "; 
		}
		std::cout << std::endl;
		std::cout << "Old Value is: " << oldValue << std::endl;
		std::cout << "New Value is: " << newValueTwo << std::endl << std::endl;
	}
	else {
		std::cout << "Invalid index." << std::endl << std::endl;
	}
	
	// adding another integer to the end of the array
	// *---Question 3---* //
	int arrThree[10] = {3, 5, 6, 7, 2};
	int sizeThree = 5;
	int newValueThree = 11;

	std::cout << "*---Question 3---*" << std::endl;
	addNewInteger(arrThree, sizeThree, newValueThree);
	std::cout << "New array: ";
	for (int i = 0;i < sizeThree;i++) {
		std::cout << arrThree[i] << " ";
	}
	std::cout << std::endl << std::endl;

	//replacing or removing an integer in an array
	// *---Question 4---* //
	int arrFour[] = { 2, 5, 76, 3, 5 };
	int sizeFour = sizeof(arrFour) / sizeof(arrFour[0]);
	int indexFour = 2;

	std::cout << "*---Question 4---*" << std::endl;
	removeInteger(arrFour, sizeFour, indexFour);

	std::cout << "New array: ";
	for (int i = 0;i < sizeFour;i++) {
		std::cout << arrFour[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}