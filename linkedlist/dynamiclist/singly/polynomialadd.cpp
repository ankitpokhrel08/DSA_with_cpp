#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node* next;
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = nullptr;
    }

    ~Polynomial() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void insertTerm(int coeff, int exp) {
        if (coeff == 0) return; // Ignore zero coefficients

        Node* newNode = new Node{coeff, exp, nullptr};

        if (head == nullptr || head->exp < exp) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        while (temp != nullptr && temp->exp > exp) {
            prev = temp;
            temp = temp->next;
        }

        if (temp != nullptr && temp->exp == exp) { 
            temp->coeff += coeff;
            if (temp->coeff == 0) { // Remove node if coefficient becomes zero
                if (prev == nullptr) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
            }
            delete newNode; 
        } else { 
            newNode->next = temp;
            if (prev != nullptr) {
                prev->next = newNode;
            } else {
                head = newNode;
            }
        }
    }

    Polynomial add(const Polynomial& other) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = other.head;

        while (p1 != nullptr || p2 != nullptr) {
            if (p1 == nullptr) {
                result.insertTerm(p2->coeff, p2->exp);
                p2 = p2->next;
            } else if (p2 == nullptr) {
                result.insertTerm(p1->coeff, p1->exp);
                p1 = p1->next;
            } else if (p1->exp == p2->exp) {
                result.insertTerm(p1->coeff + p2->coeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->exp > p2->exp) {
                result.insertTerm(p1->coeff, p1->exp);
                p1 = p1->next;
            } else {
                result.insertTerm(p2->coeff, p2->exp);
                p2 = p2->next;
            }
        }

        return result;
    }

    void display() const {
        if (head == nullptr) {
            cout << "0" << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            if (temp != head && temp->coeff > 0) {
                cout << " + ";
            }
            cout << temp->coeff << "x^" << temp->exp;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly1, poly2, result;
    int n, coeff, exp;

    cout << "Enter the number of terms in the first polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and exponent: ";
        cin >> coeff >> exp;
        poly1.insertTerm(coeff, exp);
    }

    cout << "Enter the number of terms in the second polynomial: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Enter coefficient and exponent: ";
        cin >> coeff >> exp;
        poly2.insertTerm(coeff, exp);
    }

    result = poly1.add(poly2);

    cout << "First Polynomial: ";
    poly1.display();

    cout << "Second Polynomial: ";
    poly2.display();

    cout << "Resultant Polynomial: ";
    result.display();

    return 0;
}