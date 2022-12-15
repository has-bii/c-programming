#include <stdio.h>
#include <stdlib.h>

// Sum of datas on tree, height of tree find depth of any node

struct node {
    int data;
    struct node *left, *right;
};

typedef struct node BTREE;

int leafCount(BTREE *b) {
    if (b == NULL)
        return 0;
    if (b->left == NULL && b->right == NULL)
        return 1;
    else
        return leafCount(b->left) + leafCount(b->right);   
}

BTREE *new_node(int data)
{
    BTREE *node = (BTREE*)malloc(sizeof(BTREE));

    node->data = data;
    node->left = node->right = NULL;

    return node;
}

BTREE *insert(BTREE *root, int data)
{
    if (root != NULL)
    {
        if (data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
    } else
        root = new_node(data);
    return root;
}

int sumBTREE(BTREE *root) {
    if (root == NULL)
        return 0;
    else
        return (root->data+sumBTREE(root->left)+sumBTREE(root->right));
}

int find_depth(BTREE *root, int data) {
    if (root == NULL){
        printf("There is no %d\n", data);
        return -1000;
    }
    if (root->data == data)
        return 0;
    else if (data < root->data)
        return 1 + find_depth(root->left, data);
    else
        return 1 + find_depth(root->right, data);
}

int tree_height(BTREE *root){
    if (!root)
        return -1;
    else {
        int left_height = tree_height(root->left);
        int right_height = tree_height(root->right);

        if (left_height > right_height)
            return left_height + 1;
        else
            return right_height + 1;
    }   
}

int main()
{
    BTREE *myroot = new_node(10);
    myroot = insert(myroot, 12);
    myroot = insert(myroot, 8);
    myroot = insert(myroot, 7);
    myroot = insert(myroot, 9);
    myroot = insert(myroot, 13);
    myroot = insert(myroot, 11);
    myroot = insert(myroot, 6);

    printf("Leaf count of the tree is = %d\n", leafCount(myroot));
    printf("sum of data in tree = %d\n", sumBTREE(myroot));
    printf("depth of the given node: %d\n", find_depth(myroot, 6));
    printf("Height of the Binary Tree: %d\n", tree_height(myroot));


    return 0;
}