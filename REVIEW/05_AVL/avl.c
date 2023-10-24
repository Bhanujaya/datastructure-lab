#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* left;
    struct Node* right;
    struct Node* parent;
    int key;
    int height;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int getBalance(struct Node* node) {
    if (node == NULL)
        return 0;
    return height(node->left) - height(node->right);
}

struct Node* newNode(int key) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;
    node->height = 1;
    return node;
}

struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL)
        return newNode(key);

    if (key < node->key) {
        node->left = insert(node->left, key);
        node->left->parent = node;
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
        node->right->parent = node;
    }
    else
        return node; // Duplicate keys are not allowed

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    // Right-Right Case
    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    // Right-Left Case
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->key);

        inOrder(root->right);
    }
}

void printTree(struct Node *root, int level) {
    if (root == NULL) {
        return;
    }

    printf("Level %d: %d\n", level, root->key);

    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}



int main() {
    struct Node* root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 25);
    root = insert(root, 30);

   
 
}
