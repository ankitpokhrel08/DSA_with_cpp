#include <iostream>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

Node* newNode(int item) {
    Node* temp = new Node();
    temp->key = item;
    temp->left = temp->right = nullptr;
    return temp;
}

Node* insert(Node* node, int key) {
    if (node == nullptr) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

void preOrder(Node* root) {
    if (root != nullptr) {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(Node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->key << " ";
    }
}

void printTree(Node* root, int space = 0, int height = 10) {
    if (root == nullptr) return;
    space += height;
    printTree(root->right, space);
    cout << endl;
    for (int i = height; i < space; i++) cout << ' ';
    cout << root->key << "\n";
    printTree(root->left, space);
}

int main() {
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
    return 0;
}
