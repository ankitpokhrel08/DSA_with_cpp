#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    ~LinkedList() {
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
        cout << "Inserting " << value << " at the beginning\n";
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        cout << "Inserting " << value << " at the end\n";
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insertBeforeNode(int target, int value) {
        if (head == nullptr) return;
        if (head->data == target) {
            insertAtBeginning(value);
            return;
        }
        cout << "Inserting " << value << " before " << target << endl;
        Node* newNode = new Node();
        newNode->data = value;
        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != target) {
            temp = temp->next;
        }
        if (temp->next == nullptr) return;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfterNode(int target, int value) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp == nullptr) return;
        cout << "Inserting " << value << " after " << target << endl;
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteFromBeginning() {
        if (head == nullptr) return;
        cout << "Deleting from the beginning\n";
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            cout << "Deleting from the end\n";
            delete head;
            head = nullptr;
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        cout << "Deleting from the end\n";
        delete temp->next;
        temp->next = nullptr;
    }

    void deleteBeforeNode(int target) {
        if (head == nullptr || head->next == nullptr) return;
        if (head->next->data == target) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next->next != nullptr && temp->next->next->data != target) {
            temp = temp->next;
        }
        if (temp->next->next == nullptr) return;
        cout << "Deleting before " << target << endl;
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void deleteAfterNode(int target) {
        Node* temp = head;
        while (temp != nullptr && temp->data != target) {
            temp = temp->next;
        }
        if (temp == nullptr || temp->next == nullptr) return;
        cout << "Deleting after " << target << endl;
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
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
    LinkedList list;

    list.insertAtBeginning(10);
    list.insertAtEnd(20);
    cout << "List elements: ";
    list.display();
    list.insertAtEnd(30);
    list.insertBeforeNode(30, 25);
    cout << "List elements: ";
    list.display();
    list.insertAfterNode(10, 15);

    cout << "List elements: ";
    list.display();

    list.deleteFromBeginning();
    cout << "List elements: ";
    list.display();
    list.deleteFromEnd();
    cout << "List elements: ";
    list.display();
    list.deleteBeforeNode(25);
    cout << "List elements: ";
    list.display();
    list.deleteAfterNode(15);
    cout << "List elements: ";
    list.display();

    return 0;
}
