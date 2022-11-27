#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

void printAll(node *head)
{
    if (head == NULL)
        printf("\nThe list is empty.");
    else {
        node *p = head;

        printf("\n");
        
        do
        {
            printf("%d-->", p->data);
            p = p->next;
        } while (p != head);
    }
}

node *addFront(node *head, int x)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = x;

    if (head == NULL)
    {
        head = temp;
        head->next = head;
    } else
    {
        temp->next = head;

        node *p = head;

        while (p->next != head)
            p = p->next;
        
        p->next = temp;

        head = temp;
    }
    
    return head;
}

node *addLast(node *head, int x)
{
    if (head == NULL)
        head = addFront(head, x);
    else 
    {
        node *temp = (node *)malloc(sizeof(node));

        temp->data = x;
        temp->next = head;

        node *p = head;

        while (p->next != head)
            p = p->next;

        p->next = temp;
    }
    
    return head;
}

node *delNode(node *head, int x)
{
    if (head == NULL)
        printf("\nThe list is empty.");
    else
    {
        node *deleted;
        node *p = head;

        do
        {
            if (p->next->data == x)
            {
                deleted = p->next;

                p->next = deleted->next;

                if (deleted == head)
                    head = deleted->next;
                
                free(deleted);
                return head;
            }

            p = p->next;
        } while (p != head);
    }

    return head;
}

node *destroy(node *head)
{
    if (head == NULL)
        printf("\nThe list is empty.");
    else
    {
        node *p = head;
        node *deleted;

        do
        {
            deleted = p;
            p = p->next;
            free(deleted);

        } while (p->next != head);
    }

    return NULL;
}

int main() {

    node *head = NULL;

    printAll(head);

    head = addFront(head, 30);
    head = addFront(head, 20);
    head = addFront(head, 10);

    printAll(head);

    head = addLast(head, 40);

    printAll(head);

    head = delNode(head, 10);

    printAll(head);

    head = destroy(head);

    printAll(head);

    return 0;
}