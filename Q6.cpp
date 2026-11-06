// Name: Muhammad Kaleem Sajjad
// Registration No: 544147
// Section: BSCS-15E
// Lab 08 - Task 6: Iterative insertion in a BST

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

// recursive insert from task 5, used to build the second tree
Node* insertRecursive(Node* root, int value) {
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

// iterative insert using a loop, returns the root
Node* insertIterative(Node* root, int value) {
    // empty tree: new node becomes root
    if (root == nullptr) {
        return createNode(value);
    }

    Node* curr = root;
    Node* parent = nullptr;

    // traverse down, tracking the parent at each step
    while (curr != nullptr) {
        parent = curr;
        // value smaller: go left
        if (value < curr->data) {
            curr = curr->left;
        // value larger: go right
        } else if (value > curr->data) {
            curr = curr->right;
        } else {
            return root; // duplicate: ignore and return root
        }
    }

    // link new node to the correct side of parent
    if (value < parent->data) {
        parent->left = createNode(value);
    } else {
        parent->right = createNode(value);
    }

    return root;
}

// iterative search; count tracks the number of comparisons made
Node* searchIterative(Node* root, int key, int& count) {
    Node* curr = root;
    count = 0;

    while (curr != nullptr) {
        // increment count for each node visited
        count++;
        if (curr->data == key) {
            return curr;
        }
        // go left if smaller, right if larger
        if (key < curr->data) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
    }

    // key not found
    return nullptr;
}

// inorder: left -> root -> right
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    inorder(root->left);
    // print root between left and right subtrees
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
    // same values as task 5; last 20 is a duplicate
    int values[9] = {40, 20, 60, 10, 30, 50, 70, 25, 20};

    // build both trees with the same values
    Node* iterTree = nullptr;
    Node* recTree = nullptr;
    for (int i = 0; i < 9; i++) {
        iterTree = insertIterative(iterTree, values[i]);
        recTree = insertRecursive(recTree, values[i]);
    }

    // print traversals of the iterative tree
    cout << "Iterative tree" << endl;
    cout << "Inorder:  ";
    inorder(iterTree);
    cout << endl;
    // preorder of the iterative tree
    cout << "Preorder: ";
    preorder(iterTree);
    cout << endl << endl;

    // should produce identical output to the iterative tree
    cout << "Recursive tree" << endl;
    cout << "Inorder:  ";
    inorder(recTree);
    cout << endl;
    cout << "Preorder: ";
    preorder(recTree);
    cout << endl << endl;

    // sorted input produces a right-skewed tree
    cout << "Skewed tree (10, 20, 30, 40, 50)" << endl;
    Node* skewed = nullptr;
    int skewValues[5] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; i++) {
        // each value inserts to the right of the previous
        skewed = insertIterative(skewed, skewValues[i]);
    }

    cout << "Inorder: ";
    inorder(skewed);
    cout << endl;

    // 50 is at depth n, so search requires n comparisons — O(n)
    int count = 0;
    if (searchIterative(skewed, 50, count) != nullptr) {
        cout << "Search 50: Found" << endl;
    } else {
        cout << "Search 50: Not found" << endl;
    }
    cout << "Nodes compared: " << count << endl;

    // balanced tree has height ~log n, so far fewer comparisons
    ClearTree(iterTree);
    ClearTree(recTree);
    ClearTree(skewed);

    return 0;
}
