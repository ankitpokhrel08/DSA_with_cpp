#include <iostream>
#include <vector>
using namespace std;

// Function to perform non-recursive binary search
int binarySearch(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at mid
        if (arr[mid] == target) {
            return mid;
        }

        // If target is greater, ignore the left half
        if (arr[mid] < target) {
            left = mid + 1;
        }
        // If target is smaller, ignore the right half
        else {
            right = mid - 1;
        }
    }

    // Return -1 if the target is not found
    return -1;
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
    int result = binarySearch(arr, target);

    // Display the result
    if (result != -1) {
        cout << "Number " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Number " << target << " not found in the array." << endl;
    }

    return 0;
}