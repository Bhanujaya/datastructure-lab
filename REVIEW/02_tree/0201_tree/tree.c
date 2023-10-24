//use linked structure 
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int key ; 
    struct node * leftChild;
    struct node * rightSibling;
    struct node * parent;
    

} Node ;


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

struct node * getParent(struct node * node) {
    return node->parent;

}

struct node * getChild(struct node * node , int k) {
    struct node * child = node->leftChild;
    for (int i = 1 ; i < k ; i++) {
        child = child->rightSibling;
        
    }

    return child;
}

void isRoot(struct node * node) {
    if (node->parent == NULL) {
        printf("YES\n");
    } else {
        printf("NO\n");

    }


}

void isExternal(struct node * node) {
    if (node->leftChild == NULL) {
        printf("YES\n");
    } else {
        printf("NO\n");

    }
}

int depth(struct node * node) {
    struct node * temp = node;
    int depth = 0;
    while (temp->parent != NULL) {
        temp = temp->parent;
        depth++;
    }

    return depth;

}


int getHeight(struct node* node) {
    if (node == NULL) {
        return 0;  // Height of an empty tree is 0.
    }

    struct node* child = node->leftChild;
    int maxHeight = 0;

    // Iterate over all child nodes and find the maximum height.
    while (child != NULL) {
        int childHeight = getHeight(child);
        if (childHeight > maxHeight) {
            maxHeight = childHeight;
        }
        child = child->rightSibling;
    }

    // return the maximum child height plus 1 for the current node.
    return maxHeight + 1;
}


int main() {
    struct node *root = createNode(1, NULL);
    struct node *node2 = createNode(2, root);
    struct node *node3 = createNode(3, root);
    struct node *node4 = createNode(4, node2);

    printf("Child 1 of node: %d\n", getChild(node2, 1)->key);
    printf("Depth of node 4: %d\n", depth(node4));

    isRoot(root);
    isRoot(node2);
    isExternal(node2);
    isExternal(node4);

    printf("Height of the tree: %d\n", getHeight(root));

    return 0;
}
