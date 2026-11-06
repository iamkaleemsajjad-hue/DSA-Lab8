// Name: Muhammad Kaleem Sajjad
// Registration No: 544147
// Section: BSCS-15E
// Lab 08 - Task 2: Level order traversal using a queue

#include <iostream>
#include <queue>
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

// level order: print nodes level by level using a queue
void levelOrder(Node* root) {
    // empty tree: nothing to print
    if (root == nullptr) {
        return;
    }

    // enqueue root to start the traversal
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        // dequeue front node and print it
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";

        // enqueue left child first, then right
        if (temp->left != nullptr) {
            q.push(temp->left);
        }
        // right child goes in after the left
        if (temp->right != nullptr) {
            q.push(temp->right);
        }
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

    // expected output: 40 20 60 10 30 50 70
    cout << "Test 1: seven node tree" << endl;
    levelOrder(root);
    cout << endl << endl;

    // empty tree: nothing should be printed
    cout << "Test 2: empty tree" << endl;
    levelOrder(nullptr);
    cout << endl << endl;

    // single node: only 99 should be printed
    cout << "Test 3: single node tree" << endl;
    Node* single = createNode(99);
    levelOrder(single);
    cout << endl;

    // free all created nodes
    ClearTree(root);
    ClearTree(single);

    return 0;
}
