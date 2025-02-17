#include <iostream>
using namespace std;

class CircularQueue {
private:
    int* arr;
    int front;
    int rear;
    int capacity;

public:
    CircularQueue(int size) {
        arr = new int[size];
        capacity = size;
        front = -1;
        rear = -1;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    void enqueue(int item) {
        if ((front == 0 && rear == capacity - 1) || (front == rear + 1)) {
            cout << "Circular Queue Overflow\n";
            return;
        }
        if (front == -1) {
            front = 0;
            rear = 0;
        } else if (rear == capacity - 1 && front != 0) {
            rear = 0;
        } else {
            rear = rear + 1;
        }
        cout << "Inserting " << item << endl;
        arr[rear] = item;
    }

    int dequeue() {
        if (front == -1) {
            cout << "Circular Queue Underflow\n";
            return -1;
        }
        int item = arr[front];
        cout << "Removing " << item << endl;
        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == capacity - 1) {
            front = 0;
        } else {
            front = front + 1;
        }
        return item;
    }

    void display() {
        if (front == -1) {
            cout << "Circular Queue is empty\n";
            return;
        }
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        } else {
            for (int i = front; i < capacity; i++) {
                cout << arr[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    int size = 5;
    CircularQueue cq(size);

    
    cq.enqueue(10);
    cq.enqueue(20);
    cq.enqueue(30);
    cq.enqueue(40);
    cq.enqueue(50);
    cout << "Initial Queue state: ";
    cq.display();

    cq.dequeue();
    cq.dequeue();
    cout << "After dequeuing 2 elements: ";
    cq.display();

    cq.enqueue(60);
    cq.enqueue(70);
    cout << "Final Queue state: ";
    cq.display();

    return 0;
}
