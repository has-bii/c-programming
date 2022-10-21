#include <stdio.h>
#include <stdlib.h>

struct linkedList
{
    int number;
    struct linkedList *next;
};

typedef struct linkedList node;

void *printAll(node *head);
node *addFront(node *head);
node *addLast(node *head);
node *delNode(node *head, int x);
node *destroyAllNode(node *head);
void *printReversely(node *head);

int main() {

    int N;
    int x;

    node *head = NULL;

    printAll(head);

    printf("\n1) Add node to the front\n2) Add node to the last\n3) Delete node\n4) Print all nodes reversely\n9) Destroy all nodes\n0) Exit\nChoose the program: ");
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

        case 9:
            head = destroyAllNode(head);
            break;

        default:
            break;
        }
    
        printf("\n");
        printAll(head);
        printf("\n");
        printf("\n1) Add node to the front\n2) Add node to the last\n3) Delete node\n4) Print all nodes reversely\n9) Destroy all nodes\n0) Exit\nChoose the program: ");
        scanf("%d", &N);
    }
    

    return 0;
}

void *printAll(node *head) {
    
    if (head == NULL)
    {
        printf("\nThere is no node!\n");
    } else if (head != NULL)
    {
        while (head != NULL)
        {
        printf("%d-->", head->number);
        head = head->next;
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
}

node *delNode(node *head, int x) {

    node *p = head;
    node *deleted;

    if (head->number == x)
    {
        deleted = head;

        head = head->next;

        free(deleted);
    } else
    {
        while (p->next->number != x && p->next != NULL)
        {
            p = p->next;
        }
        
        if (p->next != NULL)
        {
            deleted = p->next;

            p->next = deleted->next;

            free(deleted);
        } else
        {
            deleted = p->next;
            p->next = NULL;

            free(deleted);
        }
           
    }

    return head;
}

node *destroyAllNode(node *head){

    if (head == NULL)
    return NULL;

    destroyAllNode(head->next);
    free(head);
}

void *printReversely(node *head) {

    if (head == NULL)
        return NULL;
    
    printReversely(head->next);
    printf("%d<--", head->number);

}