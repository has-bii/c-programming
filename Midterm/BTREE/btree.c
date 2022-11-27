#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node BTREE;

BTREE *new_node(int x)
{
    BTREE *p = (BTREE *)malloc(sizeof(BTREE));

    p->data = x;
    p->left = p->right = NULL;

    return p;
}

BTREE *insert(BTREE *root, int x)
{
    if (root == NULL)
        root = new_node(x);
    else
    {
        if (x < root->data)
            root->left = insert(root->left, x);
        else
            root->right = insert(root->right, x);
    }
    return root;
}

void preOrder(BTREE *root)
{
    if (root != NULL)
    {
        printf("%d4", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }   
}

void inOrder(BTREE *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d4", root->data);
        inOrder(root->right);
    }   
}

void postOrder(BTREE *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d4", root->data);
    }   
}

int main() {
    
}