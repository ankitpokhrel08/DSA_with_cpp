#include <iostream>
using namespace std;

class ArrayQueue {
private:
    int* arr;
    int front;
    int rear;
    int size;
    int capacity;

public:
    ArrayQueue(int initialSize) {
        capacity = 2 * initialSize;
        arr = new int[capacity];
        front = -1;
        rear = -1;
        size = 0;
    }

    ~ArrayQueue() {
        delete[] arr;
    }

    void enqueue(int value) {
        if (size == capacity) {
            cout << "Queue Overflow\n";
            return;
        }
        if (rear == -1) {
            front = 0;
            rear = 0;
        } else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = value;
        size++;
    }

    int dequeue() {
        if (size == 0) {
            cout << "Queue Underflow\n";
            return -1;
        }
        int value = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % capacity;
        }
        size--;
        return value;
    }

    void display() {
        if (size == 0) {
            cout << "Queue is empty\n";
            return;
        }
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % capacity;
        }
        cout << endl;
    }
};

int main() {
    int initialSize = 5;
    ArrayQueue queue(initialSize);

    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.enqueue(50);

    cout << "Queue elements: ";
    queue.display();

    queue.dequeue();
    queue.dequeue();
    cout << "Queue elements after dequeue: ";
    queue.display();

    queue.enqueue(60);
    queue.enqueue(70);
    cout << "Queue elements after enqueue: ";
    queue.display();

    return 0;
}
