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

//node = where to start searching 
struct node * search(int key , struct node * node ) {
    if ((node == NULL) || (key==node->key)) {
        return node;
    } else if (node->key > key) {
        return search(key , node->left);

    } else {
        return search(key , node->right);

    }

}


struct node * minimum(struct node * node) {
    while (node->left != NULL) {
        node = node->left;

    }
    return node;
}

struct node * maximum(struct node * node) {
    while (node->right != NULL) {
        node = node->right;

    }
    return node;
}




struct node * sucessor(struct node * node) {
    if (node->right != NULL) {
       return minimum(node->right);
    } 
    struct node * ancestor = node->parent;
    while ((ancestor!= NULL)  && (node == ancestor->right)) {
        node = ancestor;
        ancestor = node->parent;
    }

    return ancestor;

}


struct node * predecessor(struct node * node) {
    if (node->left != NULL) {
        return maximum(node->left);
    }
    struct node * ancestor = node->parent;
    while ((ancestor != NULL) && (node == ancestor->left)) {
        node = ancestor;
        ancestor = node->parent;
    }
    return ancestor;
}


struct node * treeInsert(int key , struct node * root ) {
    struct node * new_node = createNode(key);
    new_node->key = key;
    struct node * check_node = NULL;
    struct node * node = root;
    while (node != NULL) {
        check_node = node;
        if  ( node->key > key) {
            node = node->left;
        } else {
            node = node->right;
        }
    }

    new_node->parent = check_node;
    if  (check_node != NULL) {
        if (new_node->key > check_node->key) {
            check_node->right = new_node;
        } else {
            check_node->left = new_node;
        }
    }
    return new_node;
    
    
}

void transplant(struct node * u , struct node * v) {
    struct node * p = u->parent;

    if (u == p->left) {
        p->left = v;
    } else {
        p->right = v;
    }
    if (v != NULL) {
        v->parent = p;
    }
}

void treeDelete(struct node * node) {
    if (node->left == NULL) {
        transplant(node, node->right);
    } else if (node->right == NULL) {
        transplant(node, node->left);
    } else {
        struct node * y = minimum(node->right);
        if (y->parent != node) {
            transplant(y, y->right);
            y->right = node->right;
            y->right->parent = y;
        }
        transplant(node, y);
        y->left = node->left;
        y->left->parent = y;
    }
    free(node);
    
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
    struct node* root = NULL; // Initialize an empty tree

    // Insert some nodes into the tree
    root = treeInsert(5, root);
    treeInsert(3, root);
    treeInsert(8, root);
    treeInsert(2, root);
    treeInsert(4, root);
    treeInsert(7, root);
    treeInsert(9, root);

    // Print the tree structure
    printf("Tree structure before removal:\n");
    printTree(root, 0);

    // Search for a node with key 5
    struct node* nodeToSearch = search(5, root);
    if (nodeToSearch) {
        printf("Node with key 5 found\n");
    } else {
        printf("Node with key 5 not found\n");
    }

    // Delete a node (e.g., node with key 3)
    struct node* nodeToDelete = search(3, root);
    if (nodeToDelete) {
        treeDelete(nodeToDelete);
        printf("Deleted node with key 3\n");
    } else {
        printf("Node with key 3 not found\n");
    }

    // Print the tree structure after removal
    printf("Tree structure after removal:\n");
    printTree(root, 0);

    // Find the successor of a node (e.g., node with key 5)
    struct node* successorNode = sucessor(nodeToSearch);
    if (successorNode) {
        printf("Successor of node 5: %d\n", successorNode->key);
    } else {
        printf("No successor found for node 5\n");
    }

    // Find the predecessor of a node (e.g., node with key 5)
    struct node* predecessorNode = predecessor(nodeToSearch);
    if (predecessorNode) {
        printf("Predecessor of node 5: %d\n", predecessorNode->key);
    } else {
        printf("No predecessor found for node 5\n");
    }

}