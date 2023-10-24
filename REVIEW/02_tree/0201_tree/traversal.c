#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int key ; 
    struct node * leftChild;
    struct node * rightSibling;
    struct node * parent;
    

} Node ;


void preorder(struct node * root) {
    printf("%d " , root->key);
    struct node * child = root->leftChild;
    while (child != NULL) {
        preorder(child);
        child = child->rightSibling;

    }

}

void postorder(struct node * root) {
    struct node * child = root->leftChild;
    while (child != NULL) {
        postorder(child);
        child = child->rightSibling;

    }
    printf("%d " , root->key);


} 

struct node * createNode(int key, struct node * parent) {
    struct node * new_node = malloc(sizeof(struct node));
    new_node->key = key;
    new_node->parent = parent;
    new_node->leftChild = NULL;
    new_node->rightSibling = NULL;
    if (parent != NULL) {
        if (new_node->parent->leftChild != NULL) {
            struct node * child = new_node->parent->leftChild;
            while (child->rightSibling != NULL) {
                child = child->rightSibling;

            }
            child->rightSibling = new_node;
        

        } else {
            new_node->parent->leftChild = new_node;
        }

    }

    return new_node;
  
}

int main() {
    struct node* root = createNode(1, NULL);
    struct node* node2 = createNode(2, root);
    struct node* node3 = createNode(3, root);
    struct node* node4 = createNode(4, node2);
    struct node* node5 = createNode(5, node2);
    struct node* node6 = createNode(6, node3);
    struct node* node7 = createNode(7, node3);
  

    printf("Pre traversal of the tree: ");
    preorder(root);
    printf("\n");


    printf("Post traversal of the tree: ");
    postorder(root);
    printf("\n");

}
