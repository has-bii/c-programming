#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    struct node *right;
    int data;
};

typedef struct node *BTREE;

// Funtion Prototypes
BTREE new_node(int x);
BTREE insert(BTREE root, int x);
void preOrder(BTREE root);
void inOrder(BTREE root);
void postOrder(BTREE root);

int main()
{

    BTREE root = NULL;

    int N;
    printf("\nEnter an integer until -1 entered: ");
    scanf("%d", &N);

    while (N != -1)
    {
        root = insert(root, N);

        printf("\nEnter an integer until -1 entered: ");
        scanf("%d", &N);
    }
    
    preOrder(root);

    return 0;
}

// Functions

BTREE new_node(int x)
{
    BTREE p = (BTREE)malloc(sizeof(BTREE));

    p->data = x;
    p->left = p->right = NULL;

    return p;
}

BTREE insert(BTREE root, int x)
{

    if (root == NULL)
        root = new_node(x);
    else {
        if (x < root->data)
            root->left = insert(root->left, x);
        else
            root->right = insert(root->right, x);
    }
    return root;
}

void preOrder(BTREE root)
{
    if (root != NULL)
    {
        printf("%d4", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }   
}

void inOrder(BTREE root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d4", root->data);
        inOrder(root->right);
    }   
}

void postOrder(BTREE root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d4", root->data);
    }   
}