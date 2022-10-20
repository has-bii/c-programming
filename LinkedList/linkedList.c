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

int main() {

    int N;

    node *head = NULL;

    printAll(head);

    printf("\n1) Add node to the front\n2) Add node to the last\n3) Delete node\n0) Exit\nChoose the program: ");
    scanf("%d", &N);

    while (N != 0)
    {
        
        switch (N)
        {
        case 1:
            head = addFront(head);
            break;
        
        case 2:
            printAll(head);
            break;
        
        default:
            break;
        }
    
        printf("\n");
        printAll(head);
        printf("\n");
        printf("\n1) Add node to the front\n2) Add node to the last\n3) Delete node\n0) Exit\nChoose the program: ");
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

        printf("Enter an integer:: ");
        scanf("%d", &temp->number);

        temp->next = head;
        head = temp;
    }
    
    return head;
}