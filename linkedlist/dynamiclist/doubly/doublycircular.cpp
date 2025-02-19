#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyCircularLinkedList {
private:
    Node* head;

public:
    DoublyCircularLinkedList() {
        head = nullptr;
    }

    ~DoublyCircularLinkedList() {
        if (head == nullptr) return;
        Node* current = head;
        Node* next;
        do {
            next = current->next;
            delete current;
            current = next;
        } while (current != head);
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (head == nullptr) {
            newNode->next = newNode;
            newNode->prev = newNode;
            head = newNode;
        } else {
            Node* tail = head->prev;
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
        }
    }

    void insertBeforeNode(int target, int value) {
        if (head == nullptr) return;
        Node* temp = head;
        do {
            if (temp->data == target) {
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp;
                newNode->prev = temp->prev;
                temp->prev->next = newNode;
                temp->prev = newNode;
                if (temp == head) {
                    head = newNode;
                }
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void insertAfterNode(int target, int value) {
        if (head == nullptr) return;
        Node* temp = head;
        do {
            if (temp->data == target) {
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void deleteFromBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            Node* tail = head->prev;
            head = head->next;
            head->prev = tail;
            tail->next = head;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) return;
        Node* tail = head->prev;
        if (head->next == head) {
            head = nullptr;
        } else {
            tail->prev->next = head;
            head->prev = tail->prev;
        }
        delete tail;
    }

    void deleteBeforeNode(int target) {
        if (head == nullptr || head->next == head) return;
        Node* temp = head;
        do {
            if (temp->data == target) {
                Node* nodeToDelete = temp->prev;
                if (nodeToDelete == head) {
                    deleteFromBeginning();
                    return;
                }
                nodeToDelete->prev->next = temp;
                temp->prev = nodeToDelete->prev;
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void deleteAfterNode(int target) {
        if (head == nullptr || head->next == head) return;
        Node* temp = head;
        do {
            if (temp->data == target) {
                Node* nodeToDelete = temp->next;
                if (nodeToDelete == head) {
                    deleteFromEnd();
                    return;
                }
                temp->next = nodeToDelete->next;
                nodeToDelete->next->prev = temp;
                delete nodeToDelete;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void display() {
        if (head == nullptr) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    DoublyCircularLinkedList list;

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
