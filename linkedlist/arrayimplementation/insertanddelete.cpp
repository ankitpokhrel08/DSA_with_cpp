#include <iostream>
using namespace std;

class ArrayList {
private:
    int* data;
    int* index;
    int size;
    int capacity;

public:
    ArrayList(int initialSize) {
        capacity = 2 * initialSize;
        data = new int[capacity];
        index = new int[capacity];
        size = 0;
    }

    ~ArrayList() {
        delete[] data;
        delete[] index;
    }

    void insert(int idx, int value) {
        if (size == capacity) {
            cout << "List is full\n";
            return;
        }
        if (idx < 0 || idx > size) {
            cout << "Invalid index\n";
            return;
        }
        for (int i = size; i > idx; i--) {
            data[i] = data[i - 1];
            index[i] = index[i - 1];
        }
        data[idx] = value;
        index[idx] = idx;
        size++;
    }

    void remove(int idx) {
        if (size == 0) {
            cout << "List is empty\n";
            return;
        }
        if (idx < 0 || idx >= size) {
            cout << "Invalid index\n";
            return;
        }
        for (int i = idx; i < size - 1; i++) {
            data[i] = data[i + 1];
            index[i] = index[i + 1];
        }
        size--;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Index: " << index[i] << ", Value: " << data[i] << endl;
        }
    }
};

int main() {
    int initialSize = 5;
    ArrayList list(initialSize);

    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(3, 40);
    list.insert(4, 50);

    cout << "List elements: ";
    list.display();

    list.remove(2);
    cout << "List elements after deletion: ";
    list.display();

    list.insert(2, 60);
    cout << "List elements after insertion: ";
    list.display();

    return 0;
}
