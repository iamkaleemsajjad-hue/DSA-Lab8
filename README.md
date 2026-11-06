# DSA Lab 08 - Trees

**Name:** Muhammad Kaleem Sajjad  
**Reg No:** 544147  
**Section:** BSCS-15E  
**Course:** Data Structures and Algorithms  
**Date:** 6th November 2026  

---

## Overview

This lab covers **binary tree traversals** (recursive, queue-based, and stack-based) and **Binary Search Tree (BST)** search and insertion implemented in C++. All programs use a plain `Node` structure (`data`, `left`, `right`) with functions only (no classes).

---

## Files

| File | Task | Description |
|------|------|-------------|
| Q1.cpp | Task 1 | Recursive depth-first traversals (inorder, preorder, postorder) |
| Q2.cpp | Task 2 | Level-order traversal using a queue |
| Q3.cpp | Task 3 | Iterative traversals using a stack |
| Q4.cpp | Task 4 | BST search (recursive and iterative) |
| Q5.cpp | Task 5 | Recursive insertion in a BST |
| Q6.cpp | Task 6 | Iterative insertion in a BST + skewed tree analysis |

---

## Task Descriptions

### Task 1 – Recursive DFS Traversals
Builds a seven-node tree (root 40, children 20 and 60, leaves 10, 30, 50, 70) using `createNode()`. Implements `inorder()`, `preorder()`, and `postorder()` recursively. Tested on the main tree, an empty tree, and a single-node tree.

### Task 2 – Level-Order Traversal
`levelOrder()` uses `std::queue<Node*>`. Enqueues the root first, then for each dequeued node prints its value and enqueues its children left-to-right. Expected output for the main tree: `40 20 60 10 30 50 70`.

### Task 3 – Iterative Traversals
Replaces recursion with an explicit `std::stack<Node*>`. `preorderIterative()` pushes the right child before the left so the left is processed first. `inorderIterative()` walks left pushing nodes, then pops, prints, and moves right. Outputs match the recursive versions.

### Task 4 – BST Search
`searchRecursive()` and `searchIterative()` both return the node pointer if found, else `nullptr`. Tested with keys present (40, 10, 70), a missing key (25), and an empty tree. For key 25 the path is 40 → 20 → 30 → `nullptr`.

### Task 5 – Recursive BST Insertion
`insertRecursive()` returns the root of the updated subtree. Starts from an empty tree and inserts 40, 20, 60, 10, 30, 50, 70. Then inserts 25 (new) and 20 again (duplicate, ignored). Inorder output stays sorted and search confirms 25 was added.

### Task 6 – Iterative BST Insertion
`insertIterative()` uses a `parent` pointer to find the correct insertion point without recursion. Both methods produce identical inorder and preorder output. A separate skewed tree (10, 20, 30, 40, 50) demonstrates O(n) search — searching for 50 compares all 5 nodes.

> **Note:** In a balanced BST the height is ~log n so search takes O(log n). Inserting values in sorted order creates a right-skewed tree with height n, degrading search to O(n).

---

## How to Compile and Run

```bash
g++ Q1.cpp -o Q1 && ./Q1
g++ Q2.cpp -o Q2 && ./Q2
g++ Q3.cpp -o Q3 && ./Q3
g++ Q4.cpp -o Q4 && ./Q4
g++ Q5.cpp -o Q5 && ./Q5
g++ Q6.cpp -o Q6 && ./Q6
```

Each file compiles and runs independently. Requires C++11 or later.
