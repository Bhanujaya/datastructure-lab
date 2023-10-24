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

struct node * getParent(struct node * node) {
    return node->parent;
}

struct node * getLeft(struct node * node) {
    return node->left;
}

struct node * getRight(struct node * node) {
    return node->right;
}

//others same as normal tree //

void expandExternal(struct node * node , int leftKey , int rightKey) {
    createLeft(leftKey, node);
    createRight(rightKey, node);

}

void removeAboveExternal(struct node * node) {
    struct node * parent = node->parent;
    struct node * sib = (node == parent->left ? parent->right : parent->left );

    if (parent->parent ==NULL) {
        sib->parent = NULL;

    } else {
        struct node * grandparent = parent->parent;
        sib->parent = grandparent;
        if (grandparent->left == parent) {
            grandparent->left = sib;
        } else {
            grandparent->right = sib;
        }
    }
    free(parent);
    free(node);
   
   

}



int depth(struct node * node) {
    int depth = 0;
    struct node * temp = node->parent;
    while (temp!= NULL) {
        depth++;
        temp = temp->parent;
    }

    return depth;
}


int height(struct node* node) {
    if (node == NULL) {
        return 0;  // Height of an empty tree is 0.
    } else {
        int maxLeftHeight = 0;
        int maxRightHeight = 0;
        
        // Calculate the height of the left subtree
        if (node->left != NULL) {
            maxLeftHeight = height(node->left);
        }

        // Calculate the height of the right subtree
        if (node->right != NULL) {
            maxRightHeight = height(node->right);
        }

        // Return the maximum height among left and right subtrees, plus 1 for the current node.
        return (maxLeftHeight > maxRightHeight ? maxLeftHeight : maxRightHeight) + 1;
    }
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

    struct node* parentOfNode4 = getParent(node4);
    struct node* leftOfNode2 = getLeft(node2);
    struct node* rightOfNode3 = getRight(node3);
    
    printf("Parent of Node4: %d\n", parentOfNode4->key);
    printf("Left of Node2: %d\n", leftOfNode2->key);
    printf("Right of Node3: %d\n", rightOfNode3->key);

    int depthOfNode7 = depth(node7);
    int treeHeight = height(root);
    
    printf("Depth of Node7: %d\n", depthOfNode7);
    printf("Height of the tree: %d\n", treeHeight);


     // Expand node4 with two external children
    expandExternal(node4, 8, 9);

    printf("Tree structure before removal:\n");
    printTree(root, 0);
    
    removeAboveExternal(getLeft(node4));

    printf("\nTree structure after removal:\n");
    printTree(root, 0);


}




