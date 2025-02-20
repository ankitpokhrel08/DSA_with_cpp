#include <iostream>
#include "avltree.cpp"
#include "binarysearchtree.cpp"
using namespace std;

void avlTreeMain();
void bstMain();

int main() {
    int choice;
    cout << "Choose tree type:\n1. AVL Tree\n2. Binary Search Tree\nEnter choice: ";
    cin >> choice;
    if (choice == 1) {
        avlTreeMain();
    } else if (choice == 2) {
        bstMain();
    } else {
        cout << "Invalid choice!";
    }
    return 0;
}

void avlTreeMain() {
    Node *root = nullptr;
    int key;
    cout << "Enter node values (enter -1 to stop): ";
    while (true) {
        cin >> key;
        if (key == -1) break;
        root = insert(root, key);
    }
    cout << "Tree structure:\n";
    printTree(root);
}

void bstMain() {
    Node* root = nullptr;
    int key;
    cout << "Enter node values (enter -1 to stop): ";
    while (true) {
        cin >> key;
        if (key == -1) break;
        root = insert(root, key);
    }
    cout << "Tree structure:\n";
    printTree(root);
}
