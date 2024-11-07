#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <chrono>

using namespace std;

int recursiveBinarySearch(const vector<int>& vec, int target, int low, int high);
int iterativeBinarySearch(const std::vector<int>& vec, int target);
int sequentialSearch(const std::vector<int>& vec, int target);

int main() {
    // Variables
    int n = 1000000;
    double sumRBS = 0;
    double sumIBS = 0;
    double sumSeqS = 0;

    srand(time(0));

    for (int i = 0; i < 10; ++i) {
        vector<int> data(n);

        for (int& num : data) {
            num = rand() % 100 + 1;
        }

        // Sort vector data
        sort(data.begin(), data.end());

        int target1 = rand() % 100 + 1;

        // Recursive binary search timing
        auto startRBS = std::chrono::high_resolution_clock::now();
        recursiveBinarySearch(data, target1, 0, data.size() - 1);
        auto endRBS = std::chrono::high_resolution_clock::now();
        sumRBS += std::chrono::duration_cast<std::chrono::microseconds>(endRBS - startRBS).count();

        // Iterative binary search timing
        auto startIBS = std::chrono::high_resolution_clock::now();
        iterativeBinarySearch(data, target1);
        auto endIBS = std::chrono::high_resolution_clock::now();
        sumIBS += std::chrono::duration_cast<std::chrono::microseconds>(endIBS - startIBS).count();

        // Iterative sequential search timing
        auto startseqS = std::chrono::high_resolution_clock::now();
        sequentialSearch(data, target1);
        auto endseqS = std::chrono::high_resolution_clock::now();
        sumSeqS += std::chrono::duration_cast<std::chrono::microseconds>(endseqS - startseqS).count();
    }

    cout << "Average running time for recursive binary search in microseconds is: " << sumRBS / 10 << endl;
    cout << "Average running time for iterative binary search in microseconds is: " << sumIBS / 10 << endl;
    cout << "Average running time for sequential search in microseconds is: " << sumSeqS / 10 << endl;

    return 0;  // Added return statement for main
}

// Recursive binary search
int recursiveBinarySearch(const vector<int>& vec, int target, int low, int high) {
    if (low <= high) {
        int mid = low + (high - low) / 2;

        if (vec[mid] == target) {
            return mid; // Target found
        }
        else if (vec[mid] < target) {
            return recursiveBinarySearch(vec, target, mid + 1, high);
        }
        else {
            return recursiveBinarySearch(vec, target, low, mid - 1);
        }
    }
    return -1;
}

// Iterative binary search
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

// Sequential search function
int sequentialSearch(const std::vector<int>& vec, int target) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == target) {
            return i;
        }
    }
    return -1; // Target not found
}