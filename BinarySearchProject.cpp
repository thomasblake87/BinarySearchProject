#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

void printVector(const vector<int>& vec) {
	for (int item : vec) {
		cout << item << " ";

	}
	cout << endl;
}

//Recursive binary search

int recursiveBinarySearch(const vector<int>& vec, int target, int low, int high) {
	if (low <= high) {
		int mid = low + (high - low) / 2;

		if (vec[mid] == target) {
			return mid; //Target found
		}
		else if (vec[mid] < target) {
			return recursiveBinarySearch(vec, target, mid + 1, high);
		}
		else {
			return recursiveBinarySearch(vec, target, low, mid - 1);
		}
	}
	else {
		return -1;
	}
}

int iterativeBinarySearch(const std::vector<int>& vec, int target) {
	int low = 0, high = vec.size() - 1;
	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (vec[mid] == target) {
			return mid;
		}
		else if (vec[mid] > target) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	return -1; // Target not found
}

// Sequential Search Function
int sequentialSearch(const std::vector<int>& vec, int target) {
	for (int i = 0; i < vec.size(); ++i) {
		if (vec[i] == target) {
			return i;
		}
	}
	return -1; // Target not found
}

int main() {
	int x = rand() % 100 + 1;
	int y = rand() % 100 + 1;
	int z = rand() % 100 + 1;
	int a = rand() % 100 + 1;
	int b = rand() % 100 + 1;
	int c = rand() % 100 + 1;
	vector<int> data = { a, b, c, x, y, z }; //Numbers to test

	//Sort vector data
	sort(data.begin(), data.end());

	//Print sorted vector (debugging)
	cout << "Sorted vector: " << endl;
	printVector(data);

	//target1 is in the list, target2 is not
	int target1 = 15;
	int target2 = 3;

	int recursiveBinaryResult = recursiveBinarySearch(data, target1, 0, data.size() - 1);
	int recursiveBinaryResult2 = recursiveBinarySearch(data, target2, 0, data.size() - 1);
	//Recursive binary search
	if (recursiveBinaryResult != -1) {
		std::cout << "Target " << target1 << " found at location " << recursiveBinaryResult << endl;
	}
	else {
		std::cout << "Target " << target1 << " was not found" << endl;
	}

	if (recursiveBinaryResult2 != -1) {
		std::cout << "Target " << target2 << " found at location " << recursiveBinaryResult2 << endl;
	}
	else {
		std::cout << "Target " << target2 << " was not found" << endl;
	}

	return 0;
}

