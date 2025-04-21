#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

const int TABLE_SIZE = 10; // Size of the hash tables

// Function to initialize an empty hash table
vector<int> initializeHashTable() {
    return vector<int>(TABLE_SIZE, -1); // -1 indicates empty slot
}

// 1. Direct/Identity Hashing
int directHash(int key) {
    return key;
}

// 2. Modulo Division Hashing
int moduloHash(int key) {
    return key % TABLE_SIZE;
}

// 3. Multiplication Hashing
int multiplicationHash(int key) {
    const double A = 0.618033; // Golden ratio constant
    double product = key * A;
    double fractionalPart = product - floor(product);
    return floor(TABLE_SIZE * fractionalPart);
}

// 4. Mid-Square Hashing
int midSquareHash(int key) {
    int squared = key * key;
    string squaredStr = to_string(squared);
    
    // If the squared value is too short, pad it
    while (squaredStr.length() < 2) {
        squaredStr = "0" + squaredStr;
    }
    
    // Extract the middle digit(s)
    int midPosition = squaredStr.length() / 2;
    string midDigits;
    
    if (squaredStr.length() % 2 == 0) {
        midDigits = squaredStr.substr(midPosition - 1, 2);
    } else {
        midDigits = squaredStr.substr(midPosition, 1);
    }
    
    int hashValue = stoi(midDigits) % TABLE_SIZE;
    return hashValue;
}

// 5. Folding Hashing
int foldingHash(int key) {
    string keyStr = to_string(key);
    int sum = 0;
    
    // Sum all digits
    for (char digit : keyStr) {
        sum += (digit - '0');
    }
    
    return sum % TABLE_SIZE;
}

// Insert a key into the hash table using linear probing to resolve collisions
void insertIntoHashTable(vector<int>& hashTable, int key, int (*hashFunction)(int)) {
    int index = hashFunction(key);
    
    // Handle index out of bounds
    index = abs(index) % TABLE_SIZE;
    
    // If there's a collision, use linear probing
    int originalIndex = index;
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
        
        // If we've checked all positions and returned to original, table is full
        if (index == originalIndex) {
            cout << "Hash table is full. Cannot insert " << key << endl;
            return;
        }
    }
    
    hashTable[index] = key;
}

// Display the hash table
void displayHashTable(const vector<int>& hashTable, const string& methodName) {
    cout << "\n" << methodName << " Hash Table:" << endl;
    cout << "----------------" << endl;
    cout << "Index | Value" << endl;
    cout << "----------------" << endl;
    
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << setw(5) << i << " | ";
        if (hashTable[i] == -1) {
            cout << "Empty";
        } else {
            cout << hashTable[i];
        }
        cout << endl;
    }
    cout << "----------------" << endl;
}

int main() {
    int n;
    cout << "How many numbers do you want to input? ";
    cin >> n;
    
    vector<int> numbers;
    cout << "Enter " << n << " numbers:" << endl;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        numbers.push_back(num);
    }
    
    // Create hash tables for each method
    vector<int> directHashTable = initializeHashTable();
    vector<int> moduloHashTable = initializeHashTable();
    vector<int> multiplicationHashTable = initializeHashTable();
    vector<int> midSquareHashTable = initializeHashTable();
    vector<int> foldingHashTable = initializeHashTable();
    
    // Insert numbers into each hash table
    for (int num : numbers) {
        insertIntoHashTable(directHashTable, num, directHash);
        insertIntoHashTable(moduloHashTable, num, moduloHash);
        insertIntoHashTable(multiplicationHashTable, num, multiplicationHash);
        insertIntoHashTable(midSquareHashTable, num, midSquareHash);
        insertIntoHashTable(foldingHashTable, num, foldingHash);
    }
    
    // Display all hash tables
    displayHashTable(directHashTable, "Direct/Identity");
    displayHashTable(moduloHashTable, "Modulo Division");
    displayHashTable(multiplicationHashTable, "Multiplication");
    displayHashTable(midSquareHashTable, "Mid-Square");
    displayHashTable(foldingHashTable, "Folding");
    
    return 0;
}