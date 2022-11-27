#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

node *addFront(node *head, int x)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->data = x;
    
    if (head == NULL)
        temp->next = NULL;
    else 
        temp->next = head;
    
    head = temp;
        
    return head;
}

node *addLast(node *head, int x)
{
    if (head == NULL)
        head = addFront(head, x);
    else {
        node *p = head;
        node *temp = (node*)malloc(sizeof(node));

        temp->data = x;
        temp->next = NULL;

        while (p->next != NULL)
            p = p->next;
        
        p->next = temp;
    }
    
    return head;
}

void printAll(node *head)
{
    if (head == NULL)
        printf("\nThe list is empty.");
    else {
        printf("\n");
        while (head != NULL)
        {
            printf("%d-->", head->data);
            head = head->next;
        }
        printf("\n");
    }
}

node *delNode(node *head, int x)
{
    if (head == NULL)
        printf("\nThe list is empty.");
    else {
        node *p = head;
        node *deleted;

        if (head->data == x)
        {
            deleted = head;
            head = head->next;
            free(deleted);
        } else
        {
            while (p != NULL)
            {
                if (p->next->data == x)
                {
                    deleted = p->next;
                    p->next = deleted->next;
                    free(deleted);

                    return head;
                }
                p = p->next;
            }
        }
    }
    
    return head;
}

node *destroy(node *head)
{
    if (head == NULL){
        printf("\nThe list is empty.");
    } else {
        node *deleted;
        node *p = head;

        while (p != NULL)
        {
            deleted = p;
            p = p->next;
            free(deleted);
        }

        return NULL;
    }
    return head;
}

int main(){

    node *head = NULL;

    head = destroy(head);

    head = addLast(head, 10);
    head = addLast(head, 20);
    head = addLast(head, 30);

    printAll(head);

    head = destroy(head);

    printAll(head);

    return 0;
}