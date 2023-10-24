#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node * left;
    struct node * right;
    struct node * parent;

};


struct node * createNode(int key) {
    struct node * new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->parent = NULL;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;

}

struct node * createLeft(int key , struct node * parent) {
    if (parent == NULL) {
        return NULL;
    }
    struct node * new_node = createNode(key);
    new_node->key = key;
    new_node->parent = parent;
    parent->left = new_node;
    return new_node;


}


void preorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    printf("%d ", root->key);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->key);
}

void inorder(struct node *root) {
    if (root == NULL) {
        return;
    }

    inorder(root->left);
    printf("%d ", root->key);
    inorder(root->right);
}



struct node * createRight(int key , struct node * parent) {
    if (parent == NULL) {
        return NULL;
    }
    struct node * new_node = createNode(key);
    new_node->key = key;
    new_node->parent = parent;
    parent->right = new_node;

    return new_node;

}

void printTree(struct node *root, int level) {
    if (root == NULL) {
        return;
    }

    printf("Level %d: %d\n", level, root->key);

    printTree(root->left, level + 1);
    printTree(root->right, level + 1);
}






int main() {
    struct node* root = createNode(1);
    struct node* node2 = createLeft(2, root);
    struct node* node3 = createRight(3, root);
    struct node* node4 = createLeft(4, node2);
    struct node* node5 = createRight(5, node2);
    struct node* node6 = createLeft(6, node3);
    struct node* node7 = createRight(7, node3);


    printf("Pre traversal of the tree: ");
    preorder(root);
    printf("\n");

    printf("Post traversal of the tree: ");
    postorder(root);
    printf("\n");

    printf("Inorder traversal of the tree: ");
    inorder(root);
    printf("\n");
}
