#include <iostream>
#include <vector>
using namespace std;

// Recursive function to perform binary search
int binarySearchRecursive(const vector<int>& arr, int left, int right, int target) {
    if (left > right) {
        return -1; // Base case: target not found
    }

    int mid = left + (right - left) / 2;

    // Check if the target is at mid
    if (arr[mid] == target) {
        return mid;
    }

    // If target is smaller, search in the left half
    if (arr[mid] > target) {
        return binarySearchRecursive(arr, left, mid - 1, target);
    }

    // If target is larger, search in the right half
    return binarySearchRecursive(arr, mid + 1, right, target);
}

int main() {
    // Predefined sorted array
    vector<int> arr = {10, 20, 30, 40, 50, 60, 70, 80, 90};

    cout << "Array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Ask the user for the number to search
    int target;
    cout << "Enter the number to search: ";
    cin >> target;

    // Perform binary search
    int result = binarySearchRecursive(arr, 0, arr.size() - 1, target);

    // Display the result
    if (result != -1) {
        cout << "Number " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Number " << target << " not found in the array." << endl;
    }

    return 0;
}