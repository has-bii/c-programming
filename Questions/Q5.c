#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data, height;
    struct node *left, *right;
} AVLTREE;

int height(AVLTREE *root){

    if (root == NULL)
        return -1;
    else {
        int left_height, right_height;
        left_height = height(root->left);
        right_height = height(root->right);
        if (left_height > right_height)
            return 1 + left_height;
        else
            return 1 + right_height;
    }
}

int max(int x, int y) {
    return x > y ? x : y;
}

AVLTREE *rightRotate(AVLTREE *z) {
    AVLTREE *temp = z->left;
    z->left = temp->right;
    temp->right = z;

    z->height = max(height(z->left), height(z->right));
    temp->height = max(height(temp->left), height(temp->right));

    return temp;
}

AVLTREE *leftRotate(AVLTREE *z) {
    AVLTREE *temp = z->right;
    z->right = temp->left;
    temp->left = z;

    z->height = max(height(z->left), height(z->right));
    temp->height = max(height(temp->left), height(temp->right));

    return temp;
}

int getBalance(AVLTREE *root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}

AVLTREE *new_node(int key) {
    AVLTREE *temp = (AVLTREE *)malloc(sizeof(AVLTREE));

    temp->data = key;
    temp->left = temp->right = NULL;
    temp->height = 0;
    
    return temp;
}

AVLTREE *insertAVL(AVLTREE *root, int key) {
    if (root == NULL)
        root = new_node(key);
    else {
        if (key < root->data)
            root->left = insertAVL(root->left, key);
        else if (key > root->data)
            root->right = insertAVL(root->right, key);
        else
            return root;

        root->height = 1 + max(height(root->left), height(root->right));

        int balance = getBalance(root);

        if (balance > 1 && key < root->left->data)
            return rightRotate(root);
        if (balance < -1 && key > root->right->data)
            return leftRotate(root);
        if (balance > 1 && key > root->left->data) {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
        if (balance < -1 && key < root->right->data){
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

AVLTREE *minValue(AVLTREE *root) {
    AVLTREE *temp = root;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

AVLTREE *delete(AVLTREE *root, int key){
    if (root == NULL)
        return NULL;
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        // No child or only one child
        if (root->left == NULL || root->right == NULL)
        {
            AVLTREE *temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else 
                *root = *temp;
            free(temp);
        } else { // There are 2 children
            AVLTREE *temp = minValue(root->right);

            root->data = temp->data;

            root->right = delete(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inOrder(AVLTREE *root) {
    if (root == NULL)
        return ;
    inOrder(root->left);
    printf("%4d", root->data);
    inOrder(root->right);
}

int numberOfNodesInDepth(AVLTREE *root, int depth){
    if (root == NULL)
        return 0;
    if (depth == 0)
        return 1;
    else 
        return numberOfNodesInDepth(root->left, depth-1) + numberOfNodesInDepth(root->right, depth-1);
}

int main()
{

    AVLTREE *myroot = NULL;
    int x, program;


    while (program != 0)
    {
        printf("\n\nPlease choose a program:\n1) Insert data to the AVL.\n2) Get the height of the AVL.\n3) Delete data.\n4) Print inorderly.\n5) Number of nodes in a given depth.\n0) Exit.\n");
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
            printf("Deleting data-->\nEnter an integer: ");
            scanf("%d", &x);

            myroot = delete(myroot, x);
            break;

        case 4:
            printf("Number of nodes in a given depth-->\nEnter the depth: ");
            scanf("%d", &x);

            printf("\n Number of nodes: %d", numberOfNodesInDepth(myroot, x));
            break;

        case 5:
            printf("Printing the AVL-->\n");
            inOrder(myroot);
            break;
        
        default:
            break;
        }
    }

    return 0;
}