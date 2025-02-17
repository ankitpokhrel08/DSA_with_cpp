#include <iostream>
using namespace std;

class LinearQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    LinearQueue(int size) {
        arr = new int[size];
        capacity = size;
        front = 0;
        rear = -1;
    }

    ~LinearQueue() {
        delete[] arr;
    }

    void enqueue(int x) {
        if (rear == capacity - 1) {  // Linear queue condition (no wrapping around)
            cout << "Queue Overflow\n";
            return;
        }
        rear++;
        arr[rear] = x;
        cout << "Inserting " << x << endl;
    }

    int dequeue() {
        if (front > rear) {  // When front crosses rear, the queue is empty
            cout << "Queue Underflow\n";
            return -1;
        }
        int x = arr[front];
        cout << "Removing " << x << endl;
        front++;  // Just move the front forward (no wrapping)
        return x;
    }

    void display() {
        if (front > rear) {
            cout << "Queue is empty\n";
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size = 5;
    LinearQueue queue(size);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);
    
    cout << "Queue elements: ";
    queue.display();

    queue.dequeue();
    queue.dequeue();
    cout << "After dequeuing 2 elements: ";
    queue.display();

    // Now trying to insert again should fail because rear has reached the last index
    queue.enqueue(60);
    queue.enqueue(70);

    cout << "Final Queue state: ";
    queue.display();

    return 0;
}