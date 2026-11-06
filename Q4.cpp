// Name: Muhammad Kaleem Sajjad
// Registration No: 544147
// Section: BSCS-15E
// Lab 08 - Task 4: Searching in a BST

#include <iostream>
using namespace std;

// node structure with data and two child pointers
struct Node {
    int data;
    Node* left;
    Node* right;
};

// creates and returns a new node with the given value
Node* createNode(int value) {
    Node* n = new Node;
    n->data = value;
    // no children yet, initialize both to nullptr
    n->left = nullptr;
    n->right = nullptr;
    return n;
}

// recursive search; returns the node if found, else nullptr
Node* searchRecursive(Node* root, int key) {
    // empty tree or key not found
    if (root == nullptr) {
        return nullptr;
    }

    if (root->data == key) {
        return root;
    }

    // go left if smaller, right if larger
    if (key < root->data) {
        return searchRecursive(root->left, key);
    }
    return searchRecursive(root->right, key);
}

// iterative search using a while loop
Node* searchIterative(Node* root, int key) {
    Node* curr = root;

    while (curr != nullptr) {
        if (curr->data == key) {
            return curr;
        }
        // move left or right based on comparison
        if (key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // key not found
    return nullptr;
}

// frees the whole tree; deletes children before the parent
void ClearTree(Node* root) {
    if (root == nullptr) {
        return;
    }
    ClearTree(root->left);
    ClearTree(root->right);
    // children deleted, now delete this node
    delete root;
}

// searches with both functions and prints Found or Not found
void Show(Node* root, int key) {
    cout << "Search " << key << endl;

    // recursive search result
    if (searchRecursive(root, key) != nullptr) {
        cout << "Recursive: Found" << endl;
    } else {
        cout << "Recursive: Not found" << endl;
    }

    // iterative search result
    if (searchIterative(root, key) != nullptr) {
        cout << "Iterative: Found" << endl;
    } else {
        cout << "Iterative: Not found" << endl;
    }
    // blank line to separate outputs
    cout << endl;
}

int main() {
    // same BST as task 1
    Node* root = createNode(40);
    // 20 and 60 are children of root 40
    root->left = createNode(20);
    root->right = createNode(60);
    // 10, 30, 50, 70 are the leaf nodes
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    // 40, 10, 70 are present — expect Found
    Show(root, 40);
    Show(root, 10);
    Show(root, 70);

    // 25 is not in the tree — expect Not found
    Show(root, 25);

    // empty tree: both searches should return Not found
    cout << "Empty tree" << endl;
    Show(nullptr, 40);

    // path for 25: compare 40 -> 20 -> 30 -> nullptr
    cout << "Nodes compared for 25: 40, 20, 30" << endl;

    ClearTree(root);

    return 0;
}
