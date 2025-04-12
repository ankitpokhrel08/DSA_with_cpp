#include <iostream>
#include <vector>
#include <list>
using namespace std;

const int TABLE_SIZE = 10;

// Linear Probing
void linearProbing(vector<int>& hashTable, int key) {
    int index = key % TABLE_SIZE;
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
}

// Quadratic Probing
void quadraticProbing(vector<int>& hashTable, int key) {
    int index = key % TABLE_SIZE;
    int i = 1;
    while (hashTable[index] != -1) {
        index = (key % TABLE_SIZE + i * i) % TABLE_SIZE; // Fixed calculation
        i++;
    }
    hashTable[index] = key;
}

// Double Hashing
int secondHash(int key) {
    return 7 - (key % 7); // Second hash function
}

void doubleHashing(vector<int>& hashTable, int key) {
    int index = key % TABLE_SIZE;
    int step = secondHash(key);
    if (step == 0) step = 1; // Ensure step is not zero
    
    int i = 0;
    while (hashTable[index] != -1) {
        i++;
        index = (key % TABLE_SIZE + i * step) % TABLE_SIZE; // Fixed calculation
    }
    hashTable[index] = key;
}

// Chaining with Linked List
void chaining(vector<list<int>>& hashTable, int key) {
    int index = key % TABLE_SIZE;
    hashTable[index].push_back(key);
}

// Function to display hash table for probing techniques
void displayHashTable(const vector<int>& hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            cout << i << " --> " << hashTable[i] << endl;
        } else {
            cout << i << " --> " << "Empty" << endl;
        }
    }
    cout.flush(); // Ensure output is displayed
}

// Function to display hash table for chaining
void displayChaining(const vector<list<int>>& hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << " --> ";
        for (int key : hashTable[i]) {
            cout << key << " ";
        }
        cout << endl;
    }
    cout.flush(); // Ensure output is displayed
}

int main() {
    vector<int> keys = {23, 43, 13, 27, 33, 19, 29, 37}; // Example keys

    cout << "Starting program..." << endl;

    // Linear Probing
    vector<int> linearHashTable(TABLE_SIZE, -1);
    for (int key : keys) {
        linearProbing(linearHashTable, key);
    }
    cout << "Linear Probing:" << endl;
    displayHashTable(linearHashTable);
    cout << endl;

    // Quadratic Probing
    vector<int> quadraticHashTable(TABLE_SIZE, -1);
    for (int key : keys) {
        quadraticProbing(quadraticHashTable, key);
    }
    cout << "Quadratic Probing:" << endl;
    displayHashTable(quadraticHashTable);
    cout << endl;

    cout << "Debug: Before Double Hashing" << endl;
    // Double Hashing
    vector<int> doubleHashTable(TABLE_SIZE, -1);
    for (int key : keys) {
        doubleHashing(doubleHashTable, key);
    }
    cout << "Double Hashing:" << endl;
    displayHashTable(doubleHashTable);
    cout << endl;
    cout << "Debug: After Double Hashing" << endl;

    cout << "Debug: Before Chaining" << endl;
    // Chaining
    vector<list<int>> chainingHashTable(TABLE_SIZE);
    for (int key : keys) {
        chaining(chainingHashTable, key);
    }
    cout << "Chaining with Linked List:" << endl;
    displayChaining(chainingHashTable);
    cout << "Debug: After Chaining" << endl;

    cout << "Program completed." << endl;
    return 0;
}