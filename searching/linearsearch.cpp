#include <iostream>
#include <vector>
using namespace std;

// Function to perform linear search
int linearSearch(const vector<int>& arr, int target) {
    for (int i = 0; i < arr.size(); ++i) {
        if (arr[i] == target) {
            return i; // Return the index if the target is found
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    // Predefined array
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

    // Perform linear search
    int result = linearSearch(arr, target);

    // Display the result
    if (result != -1) {
        cout << "Number " << target << " found at index " << result << "." << endl;
    } else {
        cout << "Number " << target << " not found in the array." << endl;
    }

    return 0;
}