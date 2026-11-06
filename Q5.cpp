// Name: Muhammad Kaleem Sajjad
// Registration No: 544147
// Section: BSCS-15E
// Lab 08 - Task 5: Recursive insertion in a BST

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

// inserts value and returns the root of the updated subtree
Node* insertRecursive(Node* root, int value) {
    // empty spot found: create and return the new node
    if (root == nullptr) {
        return createNode(value);
    }

    // go left or right, reconnect the returned subtree
    if (value < root->data) {
        root->left = insertRecursive(root->left, value);
    } else if (value > root->data) {
        root->right = insertRecursive(root->right, value);
    }

    // duplicate: ignore and return root unchanged
    return root;
}

// recursive search from task 4, used to verify insertion
Node* searchRecursive(Node* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }
    // found the key
    if (root->data == key) {
        return root;
    }
    // go left if smaller, right if larger
    if (key < root->data) {
        return searchRecursive(root->left, key);
    }
    return searchRecursive(root->right, key);
}

// inorder of a BST prints values in sorted order
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    // print root between left and right subtrees
    cout << root->data << " ";
    inorder(root->right);
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

int main() {
    // start with an empty tree
    Node* root = nullptr;

    // insert values in given order, saving the returned root each time
    int values[7] = {40, 20, 60, 10, 30, 50, 70};
    for (int i = 0; i < 7; i++) {
        root = insertRecursive(root, values[i]);
    }

    cout << "After first 7 insertions" << endl;
    inorder(root);
    cout << endl << endl;

    // 25 is new, so it should appear in its sorted position
    cout << "After inserting 25" << endl;
    root = insertRecursive(root, 25);
    inorder(root);
    cout << endl << endl;

    // 20 already exists, so the tree should stay the same
    cout << "After inserting 20 again" << endl;
    root = insertRecursive(root, 20);
    inorder(root);
    cout << endl << endl;

    // confirm 25 is now in the tree
    cout << "Search 25: ";
    if (searchRecursive(root, 25) != nullptr) {
        cout << "Found" << endl;
    } else {
        cout << "Not found" << endl;
    }

    // free all created nodes
    ClearTree(root);

    return 0;
}
