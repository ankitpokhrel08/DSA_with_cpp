#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyCircularLinkedList {
private:
    Node* head;

public:
    SinglyCircularLinkedList() {
        head = nullptr;
    }

    ~SinglyCircularLinkedList() {
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
        cout << "Inserting " << value << " at the beginning\n";
        Node* newNode = new Node();
        newNode->data = value;
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    void insertAtEnd(int value) {
        cout << "Inserting " << value << " at the end\n";
        Node* newNode = new Node();
        newNode->data = value;
        if (head == nullptr) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void insertBeforeNode(int target, int value) {
        if (head == nullptr) return;
        if (head->data == target) {
            insertAtBeginning(value);
            return;
        }
        Node* temp = head;
        do {
            if (temp->next->data == target) {
                cout << "Inserting " << value << " before " << target << endl;
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
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
                cout << "Inserting " << value << " after " << target << endl;
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
                return;
            }
            temp = temp->next;
        } while (temp != head);
    }

    void deleteFromBeginning() {
        if (head == nullptr) return;
        cout << "Deleting from the beginning\n";
        Node* temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }
            head = head->next;
            last->next = head;
        }
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) return;
        cout << "Deleting from the end\n";
        Node* temp = head;
        if (head->next == head) {
            head = nullptr;
        } else {
            while (temp->next->next != head) {
                temp = temp->next;
            }
            Node* last = temp->next;
            temp->next = head;
            delete last;
        }
    }

    void deleteBeforeNode(int target) {
        if (head == nullptr || head->next == head) return;
        if (head->next->data == target) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        do {
            if (temp->next->next->data == target) {
                cout << "Deleting before " << target << endl;
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
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
                cout << "Deleting after " << target << endl;
                Node* nodeToDelete = temp->next;
                temp->next = temp->next->next;
                if (nodeToDelete == head) {
                    head = temp->next;
                }
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
    SinglyCircularLinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    cout << "List elements: ";
    list.display();
    list.insertAtEnd(30);
    cout << "List elements: ";
    list.display();
    list.insertBeforeNode(30, 25);
    cout << "List elements: ";
    list.display();
    list.insertAfterNode(10, 15);

    cout << "List elements: ";
    list.display();

    list.deleteFromBeginning();
    list.deleteFromEnd();
    cout << "List elements: ";
    list.display();
    list.deleteBeforeNode(25);
    cout << "List elements: ";
    list.display();
    list.deleteAfterNode(15);

    cout << "List elements after deletions: ";
    list.display();

    return 0;
}
