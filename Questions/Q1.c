#include <stdio.h>
#include <stdlib.h>

struct linkedList
{
    int number;
    struct linkedList *next;
};

typedef struct linkedList node;

void printAll(node *head);
node *addFront(node *head);
node *addLast(node *head);
node *delNode(node *head, int x);
node *destroyAllNode(node *head);
void *printReversely(node *head);
void *sortNode(node *head);
void swap(node *p, node *q);
int smallestValue(node *head);
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

void printAll(node *head) {
    
    node *temp = head;

    if (head == NULL)
    {
        printf("\nThere is no node!\n");
    } else
    {
        while (temp != NULL)
        {
            printf("%d-->", temp->number);
            temp = temp->next;
        } 
    }
    
}

node *addFront(node *head) {

    printf("\nAdding node to the front-->\n");

    if (head == NULL)
    {
        head = (node *)malloc(sizeof(node));

        printf("Enter an integer: ");
        scanf("%d", &head->number);

        head->next = NULL;
    } else {
        node *temp = (node *)malloc(sizeof(node));

        printf("Enter an integer: ");
        scanf("%d", &temp->number);

        temp->next = head;
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
        scanf("%d", &temp->number);

        temp->next = NULL;

        while (p->next != NULL)
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

    node *p = head;
    node *deleted;

    if (head == NULL)
    {
        printf("\nThe node is empty\n");
    } else if (head->number == x)
    {
        deleted = head;

        head = head->next;

        free(deleted);
    } else
    {
        do
        {
            if (p->next->number == x)
            {
                deleted = p->next;
                p->next = deleted->next;

                free(deleted);
            }
            
            p = p->next;
        } while (p->next != NULL);
    }

    return head;
}

node *destroyAllNode(node *head){

    node *deleted;

    while (head != NULL)
    {
        deleted = head;
        head = head->next;
        free(deleted);
    }

    return head;
}

void *printReversely(node *head) {

    if (head == NULL)
        return NULL;
    
    printReversely(head->next);
    printf("%d<--", head->number);

}

void *sortNode(node *head){

    node *p = head;

        printf("\nThe node is being sorted-->\n");

        printf("\n");
        printAll(head);
        printf("\n");

    do
    {

        if (p->number > p->next->number)
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
        
    } while (p->next != NULL);

    printf("\nThe node has been sorted.\n");
}

void swap(node *p, node *q) {
    int temp = p->number;
    p->number = q->number;
    q->number = temp;
}

int smallestValue(node *head) {
    if (head == NULL)
        return -1000;
    int min = head->number;

    while (head->next != NULL)
    {
        if (min > head->next->number)
        min = head->next->number;
        head = head->next;
    }
    
    return min;
}

node *fun(node *head) {
    int min = smallestValue(head);

    node *p = head;

    while (p != NULL)
    {
        p->number -= min;
        p = p->next;
    }
    
    return head;
}