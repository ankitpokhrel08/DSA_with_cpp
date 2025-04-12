#include <iostream>
#include <vector>
using namespace std;

// Function to print the array
void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Function to heapify a subtree rooted at index i
void heapify(vector<int>& arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        cout << "Heap after swapping " << arr[i] << " and " << arr[largest] << ": ";
        printArray(arr);

        // Recursively heapify the affected subtree
        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; --i) {
        heapify(arr, n, i);
        cout << "Max heap after heapifying index " << i << ": ";
        printArray(arr);
    }

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; --i) {
        // Move current root to end
        swap(arr[0], arr[i]);
        cout << "Heap after moving max element " << arr[i] << " to the end: ";
        printArray(arr);

        // Call heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    vector<int> arr;
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements in random order: ";
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        arr.push_back(num);
    }

    cout << "Original array: ";
    printArray(arr);

    heapSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}