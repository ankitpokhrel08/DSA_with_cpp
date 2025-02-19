#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    ~DoublyLinkedList() {
        Node* current = head;
        Node* next;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void insertBeforeNode(int target, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = temp->prev;
        newNode->next = temp;
        if (temp->prev != nullptr) {
            temp->prev->next = newNode;
        } else {
            head = newNode;
        }
        temp->prev = newNode;
    }

    void insertAfterNode(int target, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) return;
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        if (temp->prev != nullptr) {
            temp->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }

    void deleteBeforeNode(int target) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->prev == nullptr) return;
        Node* nodeToDelete = temp->prev;
        if (nodeToDelete->prev != nullptr) {
            nodeToDelete->prev->next = temp;
        } else {
            head = temp;
        }
        temp->prev = nodeToDelete->prev;
        delete nodeToDelete;
    }

    void deleteAfterNode(int target) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) return;
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        if (nodeToDelete->next != nullptr) {
            nodeToDelete->next->prev = temp;
        }
        delete nodeToDelete;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertBeforeNode(30, 25);
    list.insertAfterNode(10, 15);

    cout << "List elements: ";
    list.display();

    list.deleteFromBeginning();
    list.deleteFromEnd();
    list.deleteBeforeNode(25);
    list.deleteAfterNode(15);

    cout << "List elements after deletions: ";
    list.display();

    return 0;
}
