#include <stdio.h>
#include <stdlib.h>

struct node {
    int data, height;
    struct node *left, *right;
};

typedef struct node AVLTREE;

AVLTREE *new_node(int number) {
    AVLTREE *node = (AVLTREE *)malloc(sizeof(AVLTREE));

    node->data = number;
    node->left = node->right = NULL;
    node->height = 0;

    return node;
}

int maxValue(int x, int y) {
    return x >= y ? x : y;
}

AVLTREE *rightRotate(AVLTREE *z) {
    AVLTREE *temp = z->left;
    z->left = temp->right;
    temp->right = z;

    z->height = maxValue(z->left == NULL ? -1 : z->left->height, z->right == NULL ? -1 : z->right->height) + 1;
    temp->height = maxValue(temp->left == NULL ? -1 : temp->left->height, temp->right == NULL ? -1 : temp->right->height) + 1;

    return temp; 
}

AVLTREE *leftRotate(AVLTREE *z) {
    AVLTREE *temp = z->right;
    z->right = temp->left;
    temp->left = z;

    z->height = maxValue(z->left == NULL ? -1 : z->left->height, z->right == NULL ? -1 : z->right->height) + 1;
    temp->height = maxValue(temp->left == NULL ? -1 : temp->left->height, temp->right == NULL ? -1 : temp->right->height) + 1;

    return temp;
}

AVLTREE *leftRightRotate(AVLTREE *z) {
    z->left = leftRotate(z->left);

    return rightRotate(z);
}

AVLTREE *rightLeftRotate(AVLTREE *z) {
    z->right = rightRotate(z->right);

    return leftRotate(z);
}

AVLTREE *insertAVL(AVLTREE *tree, int x) {
    if (tree == NULL)
        tree = new_node(x);
    else {
        if (x < tree->data)
            tree->left = insertAVL(tree->left, x);
        else
            tree->right = insertAVL(tree->right, x);

        tree->height = maxValue(tree->left == NULL ? -1 : tree->left->height, tree->right == NULL ? -1 : tree->right->height);

        if (((tree->left == NULL ? -1 : tree->left->height) - (tree->right == NULL ? -1 : tree->right->height)) > 1 && x < tree->left->data)
            return rightRotate(tree);

        if (((tree->left == NULL ? -1 : tree->left->height) - (tree->right == NULL ? -1 : tree->right->height)) > 1 && x > tree->left->data)
            return leftRightRotate(tree);   

        if (((tree->left == NULL ? -1 : tree->left->height) - (tree->right == NULL ? -1 : tree->right->height)) < -1 && x > tree->left->data)
            return leftRotate(tree);

        if (((tree->left == NULL ? -1 : tree->left->height) - (tree->right == NULL ? -1 : tree->right->height)) < -1 && x < tree->left->data)
            return rightLeftRotate(tree);   
    }

    return tree;
}

void preOrder(AVLTREE *root)
{
    if (root != NULL)
    {
        printf("%4d", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }   
}

void inOrder(AVLTREE *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%4d", root->data);
        inOrder(root->right);
    }   
}

void postOrder(AVLTREE *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%4d", root->data);
    }   
}

int main()
{

    AVLTREE *myroot = NULL;
    int x, program;


    while (program != 0)
    {
        printf("\n\nPlease choose a program:\n1) Insert data to the AVL.\n2) Get the height of the AVL.\n3) Print inorderly.\n0) Exit.\n");
        scanf("%d", &program);

        switch (program)
        {
        case 1:
            printf("Inserting data-->\nEnter an integer: ");
            scanf("%d", &x);

            myroot = insertAVL(myroot, x);
            break;
        
        case 2:
            printf("Getting the height-->\nThe height is: %d", myroot->height);
            break;
        
        case 3:
            printf("Printing the AVL-->\n");
            inOrder(myroot);
            break;
        
        default:
            break;
        }
    }
    
    

    return 0;
}