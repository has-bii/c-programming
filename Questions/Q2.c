#include <stdio.h>
#include <stdlib.h>

struct circularLinkedList
{
    int data;
    struct circularLinkedList *next;
};

typedef struct circularLinkedList node;

void *printAll(node *head);
node *addFront(node *head);
node *addLast(node *head);
node *delNode(node *head, int x);
node *catchTail(node *head);
void *printReversely(node *head);
void *sortNode(node *head);
void swap(node *p, node *q);
node *destroyAllNode(node *head);
node *fun(node *head);

int main() {

    int N, x;

    node *head = NULL;

    printAll(head);

    printf("\n1) Add node to the front\n2) Add node to the last\n3) Delete node\n4) Print all nodes reversely\n5) Sort all nodes\n9) Destroy all nodes\n0) Exit\nChoose the program: ");
    scanf("%d", &N);

    while (N != 0)
    {
        
        switch (N)
        {
        case 1:
            head = addFront(head);
            break;
        
        case 2:
            head = addLast(head);
            break;

        case 3:
            printf("\nDeleting node-->\n");
            printf("\nEnter number of node: ");
            scanf("%d", &x);

            head = delNode(head, x);
            break;
        
        case 4:
            printf("\nPrinting all nodes reversely-->\n\n");

            printReversely(head);

            printf("\n\n");
            break;

        case 5:
            sortNode(head);
            break;

        case 6:
            head = fun(head);
            break;

        case 9:
            head = destroyAllNode(head);
            break;

        default:
            break;
        }
    
        printf("\n");
        printAll(head);
        printf("\n");
        printf("\n1) Add node to the front\n2) Add node to the last\n3) Delete node\n4) Print all nodes reversely\n5) Sort all nodes\n9) Destroy all nodes\n0) Exit\nChoose the program: ");
        scanf("%d", &N);
    }
    

    return 0;
}

void *printAll(node *head) {
    
    node *temp = head;

    if (head == NULL)
    {
        printf("\nThere is no node!\n");
    } else
    {
        do
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    
}

node *addFront(node *head) {

    printf("\nAdding node to the front-->\n");

    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));

        printf("Enter an integer: ");
        scanf("%d", &head->data);

        head->next = head;
    } else 
    {
        node *temp = (node *)malloc(sizeof(node));

        printf("Enter an integer: ");
        scanf("%d", &temp->data);

        temp->next = head;

        node *p = head;

        while (p->next != head)
        {
            p = p->next;
        }
        
        p->next = temp;
        head = temp;
    }
    

    return head;
}

node *addLast(node *head) {

    if (head != NULL)
    {
        printf("\nAdding node to the last-->\n");

        node *p = head;

        node *temp = (node *)malloc(sizeof(node));
        printf("\nEnter an integer: ");
        scanf("%d", &temp->data);
        temp->next = head;

        while (p->next != head)
        {
            p = p->next;
        }
        
        p->next = temp;

        return head;
    } else
    {
        head = addFront(head);
    }
    
    
    return head;
}

node *delNode(node *head, int x) {

    node *tail = catchTail(head);
    node *deleted;
    node *p = head;

    if (head == NULL)
    {
        printf("\nThe node is empty\n");
    } else if (head->data == x)
    {
        deleted = head;

        if (head->next != head)
        {
            tail->next = head->next;
            head = head->next;
        } else
        {
            head = NULL;
        }

        free(deleted);
    } else
    {
        do
        {
            if (p->next->data == x)
            {
                deleted = p->next;
                p->next = deleted->next;

                free(deleted);                
            }           

            p = p->next;
        } while (p != head && p->data != x);
        
    }    

    return head;
}

void *printReversely(node *head) {

    printf("\nThe program has not found!\n");

}

void *sortNode(node *head){

    node *p = head;

        printf("\nThe node is being sorted-->\n");

        printf("\n");
        printAll(head);
        printf("\n");

    do
    {

        if (p->data > p->next->data)
        {
            swap(p, p->next);
            p = head;

            printf("\n");
            printAll(head);
            printf("\n");

        } else 
        {
            p = p->next;
        }
        
    } while (p->next != head);

    printf("\nThe node has been sorted.\n");
}

void swap(node *p, node *q) {
    int temp = p->data;
    p->data = q->data;
    q->data = temp;
}

node *destroyAllNode(node *head) {

    node *deleted;
    node *p = head;

    do
    {
        deleted = p;
        p = p->next;
        free(deleted);
    } while (p != head);

    return NULL;
}

node *catchTail(node *head) {

    node *tail = head;

    while (tail->next != head)
    {
        tail = tail->next;
    }
    
    return tail;
}

node *fun(node *head) {
    node *p = head->next;

    while (p->next != head)
        p = p->next;

    node *new = (node *)malloc(sizeof(node));
    new->data = head->data + p->data;
    new->next = head;

    p->next = new;

    return head;
}