#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node node;

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
    }
}

node *addFront(node *head, int x)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = x;
    temp->prev = NULL;

    if (head == NULL)
        temp->next = NULL;
    else {
        temp->next = head;
        head->prev = temp;
    }
    
    head = temp;

    return head;
}

node *addLast(node *head, int x)
{
    if (head == NULL)
        head = addFront(head, x);
    else 
    {
        node *temp = (node*)malloc(sizeof(node));
        node *p = head;

        temp->data = x;
        temp->next = NULL;

        while (p->next != NULL)
        {
            p = p->next;
        }
        
        p->next = temp;
        temp->prev = p;
    }
    
    return head;
}

node *delNode(node *head, int x)
{
    if (head == NULL) {
        printf("\nThe list is empty.");
        return head;
    }
    else
    {
        node *deleted;
        node *p = head;

        while (p != NULL)
        {
            if (p->data == x)
            {
                deleted = p;

                if (p->prev == NULL)
                {
                    p = p->next;
                    p->prev = NULL;
                    head = p;
                } else if (p->next == NULL)
                {
                    p = p->prev;
                    p->next = NULL;
                } else
                {
                    p = p->prev;
                    p->next = deleted->next;
                    p->next->prev = p;
                }
                
                free(deleted);
                return head;
            }
            p = p->next;
        }
    }
}

node *destroy(node *head)
{
    if (head == NULL)
    {
        printf("\nThe list is empty.");
        return head;
    } else
    {
        node *deleted;

        while (head != NULL)
        {
            deleted = head;
            head = head->next;
            free(deleted);
        }

        return NULL;
    }
}

int main() {

    node *head = NULL;

    printAll(head);

    head = addFront(head, 20);
    head = addFront(head, 10);
    head = addLast(head, 30);

    printAll(head);

    head = delNode(head, 30);

    printAll(head);

    head = destroy(head);

    printAll(head);

    return 0;
}