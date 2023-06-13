#include<iostream>

int findInteger(const int* arr, int size, int target) {
	for (int i = 0; i < size; i++) {
		if (arr[i] == target) {
			return i;
		}
	}
	return -1;
}

int main() {

	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int target = 2112;
	int index = findInteger(arr, size, target);

	if (index != -1) {
		std::cout << "Target Integer " << target << " found at index ";
	}
	else {
		std::cout << "Target Integer " << target << " did not find in the array.";
	}
	return 0;
}