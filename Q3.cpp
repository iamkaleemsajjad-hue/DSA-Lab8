// Name: Muhammad Kaleem Sajjad
// Registration No: 544147
// Section: BSCS-15E
// Lab 08 - Task 3: Iterative traversals using a stack

#include <iostream>
#include <stack>
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

// recursive inorder from task 1, used to compare outputs
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    // print root between left and right subtrees
    cout << root->data << " ";
    inorder(root->right);
}

// recursive preorder from task 1, used to compare outputs
void preorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    // print root before its subtrees
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// iterative preorder using a stack
void preorderIterative(Node* root) {
    if (root == nullptr) {
        return;
    }

    stack<Node*> s;
    s.push(root);

    while (!s.empty()) {
        // pop the top node and print it
        Node* temp = s.top();
        s.pop();
        cout << temp->data << " ";

        // push right first so left is processed first
        if (temp->right != nullptr) {
            s.push(temp->right);
        }
        // left is pushed last so it stays on top
        if (temp->left != nullptr) {
            s.push(temp->left);
        }
    }
}

// iterative inorder using a curr pointer and a stack
void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (curr != nullptr || !s.empty()) {
        // go left, pushing each node onto the stack
        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        // no more left nodes: pop, print, then go right
        curr = s.top();
        s.pop();
        cout << curr->data << " ";

        // move to the right subtree
        curr = curr->right;
    }
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
    // same seven-node tree as task 1
    Node* root = createNode(40);
    // 20 and 60 are children of root 40
    root->left = createNode(20);
    root->right = createNode(60);
    // 10, 30, 50, 70 are the leaf nodes
    root->left->left = createNode(10);
    root->left->right = createNode(30);
    root->right->left = createNode(50);
    root->right->right = createNode(70);

    // recursive and iterative outputs must match
    cout << "Test 1: preorder" << endl;
    cout << "Recursive: ";
    preorder(root);
    cout << endl;
    cout << "Iterative: ";
    preorderIterative(root);
    cout << endl << endl;

    // recursive and iterative outputs must match
    cout << "Test 2: inorder" << endl;
    cout << "Recursive: ";
    inorder(root);
    cout << endl;
    cout << "Iterative: ";
    inorderIterative(root);
    cout << endl << endl;

    // empty tree: nothing should be printed
    cout << "Test 3: empty tree" << endl;
    cout << "Preorder:  ";
    preorderIterative(nullptr);
    cout << endl;
    // same empty tree test for inorder
    cout << "Inorder:   ";
    inorderIterative(nullptr);
    cout << endl;

    // free all created nodes
    ClearTree(root);

    return 0;
}
