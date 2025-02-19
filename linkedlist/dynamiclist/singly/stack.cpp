#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* head;

public:
    Stack() {
        head = nullptr;
    }

    ~Stack() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << "Pushed " << value << " onto the stack\n";
    }

    int pop() {
        if (head == nullptr) {
            cout << "Stack Underflow\n";
            return -1;
        }
        Node* temp = head;
        head = head->next;
        int poppedValue = temp->data;
        delete temp;
        cout << "Popped " << poppedValue << " from the stack\n";
        return poppedValue;
    }

    int peek() {
        if (head != nullptr) {
            return head->data;
        } else {
            cout << "Stack is empty\n";
            return -1;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void display() {
        if (head == nullptr) {
            cout << "Stack is empty\n";
            return;
        }
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack elements: ";
    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    cout << "Stack elements after pop: ";
    stack.display();

    return 0;
}
