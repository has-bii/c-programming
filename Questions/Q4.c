#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    char name[20];
    int number;
    float final;
};

typedef struct node node;

struct BTREE {
    node *data;
    struct BTREE *left, *right;
};

typedef struct BTREE BTREE;

BTREE *new_node(char NAME[], int NUMBER, float FINAL) {

    node *new = (node *)malloc(sizeof(node));

    strcpy(new->name, NAME);
    new->number = NUMBER;
    new->final = FINAL;

    BTREE *newBTREE = (BTREE *)malloc(sizeof(BTREE));

    newBTREE->data = new;
    newBTREE->left = newBTREE->right = NULL;

    return newBTREE;
}

BTREE *insertBTREE(BTREE *root, char NAME[], int NUMBER, float FINAL) {
    if (root == NULL)
        root = new_node(NAME, NUMBER, FINAL);
    else {
        if (NUMBER < root->data->number)
            root->left = insertBTREE(root->left, NAME, NUMBER, FINAL);
        else
            root->right = insertBTREE(root->right, NAME, NUMBER, FINAL);
    }

    return root;
}

int numberNodes(BTREE *root){
    if (root == NULL)
        return 0;
    return 1 + numberNodes(root->left) + numberNodes(root->right);
}

float total(BTREE *root){
    if (root == NULL)
        return 0;
    return (root->data->final) + total(root->left) + total(root->right);
}

float average(BTREE *root){
    return total(root)/numberNodes(root);
}

void printList(BTREE *root, float average){
    if (root == NULL)
        return ;
    else {
        printList(root->left, average);

        if (root->data->final > average)
            printf("\n%s: %f", root->data->name, root->data->final);
        
        printList(root->right, average);
    }
}

int main() {

    BTREE *myroot = NULL;

    myroot = insertBTREE(myroot, "HasbiyRobbiy", 1, 100);
    myroot = insertBTREE(myroot, "Hasbiy", 2, 90);
    myroot = insertBTREE(myroot, "Ahmet", 3, 50);
    myroot = insertBTREE(myroot, "Alex", 4, 50);
    myroot = insertBTREE(myroot, "David", 5, 20);

    printList(myroot, average(myroot));

    printf("\n%f", average(myroot));

    return 0;
}