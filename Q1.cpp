// Name: Muhammad Kaleem Sajjad
// Registration No: 544147
// Section: BSCS-15E
// Lab 08 - Task 1: Recursive depth first traversals

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

// inorder: left -> root -> right
void inorder(Node* root) {
    // base case: null means no node to visit
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// preorder: root -> left -> right
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    // print root before its subtrees
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// postorder: left -> right -> root
void postorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    // visit both subtrees before printing root
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
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

// prints all three traversals on separate lines
void Show(Node* root) {
    cout << "Inorder:   ";
    inorder(root);
    cout << endl;

    // preorder of the same tree
    cout << "Preorder:  ";
    preorder(root);
    cout << endl;

    // postorder of the same tree
    cout << "Postorder: ";
    postorder(root);
    cout << endl << endl;
}

int main() {
    // build the tree by linking nodes directly
    Node* root = createNode(40);
    // 20 is left child, 60 is right child of root
    root->left = createNode(20);
    root->right = createNode(60);
    // 10, 30, 50, 70 are the leaf nodes
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    cout << "Test 1: seven node tree" << endl;
    // expected inorder: 10 20 30 40 50 60 70
    cout << "Inorder:   ";
    inorder(root);
    cout << endl;
    // expected preorder: 40 20 10 30 60 50 70
    cout << "Preorder:  ";
    preorder(root);
    cout << endl;
    // expected postorder: 10 30 20 50 70 60 40
    cout << "Postorder: ";
    postorder(root);
    cout << endl << endl;

    // empty tree: nothing should be printed
    cout << "Test 2: empty tree" << endl;
    Show(nullptr);

    // single node: all three traversals print only 99
    cout << "Test 3: single node tree" << endl;
    Node* single = createNode(99);
    Show(single);

    ClearTree(root);
    ClearTree(single);

    return 0;
}
