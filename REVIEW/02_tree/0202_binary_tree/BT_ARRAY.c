//array-based structure
#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100 // Define the maximum number of nodes in the array

struct node {
    int key;
};

struct node tree[MAX_NODES];

// Initialize the tree array
void initTree() {
    for (int i = 0; i < MAX_NODES; i++) {
        tree[i].key = -1; // -1 can be used to represent an empty node
    }
}

struct node* createNode(int key) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->key = key;
    return newNode;
}

int getLeftChild(int index) {
    int leftChildIndex = 2 * index + 1;
    return (leftChildIndex < MAX_NODES) ? leftChildIndex : -1;
}

int getRightChild(int index) {
    int rightChildIndex = 2 * index + 2;
    return (rightChildIndex < MAX_NODES) ? rightChildIndex : -1;
}

int getParent(int index) {
    int parentIndex = (index - 1) / 2;
    return (parentIndex >= 0) ? parentIndex : -1;
}

// Insert a left child with the given key at the specified index
void insertLeftKey(int index, int key) {
    int leftChildIndex = getLeftChild(index);
    if (leftChildIndex != -1 && tree[leftChildIndex].key == -1) {
        tree[leftChildIndex] = *createNode(key);
    }
}

// Insert a right child with the given key at the specified index
void insertRightKey(int index, int key) {
    int rightChildIndex = getRightChild(index);
    if (rightChildIndex != -1 && tree[rightChildIndex].key == -1) {
        tree[rightChildIndex] = *createNode(key);
    }
}

// Traverse the array-based tree and print the structure
void printTree() {
    for (int i = 0; i < MAX_NODES; i++) {
        if (tree[i].key != -1) {
            printf("Node %d: %d\n", i, tree[i].key);
            int leftChild = getLeftChild(i);
            int rightChild = getRightChild(i);

            if (leftChild != -1 && tree[leftChild].key != -1) {
                printf("  Left Child: %d\n", tree[leftChild].key);
            }

            if (rightChild != -1 && tree[rightChild].key != -1) {
                printf("  Right Child: %d\n", tree[rightChild].key);
            }
        }
    }
}

int main() {
    initTree();

    // Create nodes and add them to the array-based tree
    tree[0] = *createNode(1);

    // Insert left and right children
    insertLeftKey(0, 2);
    insertRightKey(0, 3);

    // Print the tree structure
    printTree();

}
