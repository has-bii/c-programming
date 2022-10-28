#include <stdio.h>
#include <stdlib.h>

struct doubleLinkedList
{
    int data;
    struct doubleLinkedList *next;
    struct doubleLinkedList *prev;
};

typedef struct doubleLinkedList node;

void *printAll(node *head);
node *addFront(node *head);
node *addLast(node *head);
node *delNode(node *head, int x);
void *checkAllNode(node* head);
void *checkNode(node* head);
void *printReversely(node *head);
void *sortNode(node *head);
node *destroyAllNode(node *head);

int main() {

    int N, x;

    node *head = NULL;

    printf("\n");
    printAll(head);
    printf("\n");
    printf("\n1) Add node to the front\n2) Add node to the last\n3) Delete node\n4) Print all nodes reversely\n5) Sort all nodes\n6) Check all nodes\n9) Destroy all nodes\n0) Exit\nChoose the program: ");
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

            printf("\n\n<-----The program has ended.\n\n");
            break;
        
        case 5:
            sortNode(head);
            break;

        case 6:
            checkAllNode(head);
            break;

        case 9:
            printf("\nAdding node to the front----->\n");
            head = destroyAllNode(head);
            printf("\n<-----The program has ended.\n");
            break;

        default:
            break;
        }

        printf("\n");
        printAll(head);
        printf("\n");
        printf("\n1) Add node to the front\n2) Add node to the last\n3) Delete node\n4) Print all nodes reversely\n5) Sort all nodes\n6) Check all nodes\n9) Destroy all nodes\n0) Exit\nChoose the program: ");
        scanf("%d", &N);
    }

    return 0;
}

void *printAll(node *head) {

    if (head == NULL)
    {
        printf("\nThere is no node!\n");
    } else
    {
        while (head != NULL)
        {
            printf("%d-->", head->data);
            head = head->next;
        } 
    }
    
}

node *addFront(node *head) {

    printf("\nAdding node to the front----->\n");

    if (head == NULL)                                   //If there is no any node
    {
        head = (node *)malloc(sizeof(node));

        printf("\nEnter an integer: ");
        scanf("%d", &head->data);

        head->next = NULL;
        head->prev = NULL;
    } else                                              //If there is node in head
    {
        node *temp = (node *)malloc(sizeof(node));

        printf("\nEnter an integer: ");
        scanf("%d", &temp->data);

        temp->next = head;
        temp->prev = NULL;
        head = temp;
    }

    printf("\n<-----The program has ended.\n");

    return head;
}

node *addLast(node *head) {

    if (head != NULL)
    {
        printf("\nAdding node to the last----->\n");

        node *p = head;

        node *temp = (node *)malloc(sizeof(node));          //Making new node
        printf("\nEnter an integer: ");
        scanf("%d", &temp->data);
        temp->next = NULL;

        while (p->next != NULL)                             //Finding the last node
        {
            p = p->next;
        }
        
        p->next = temp;                                     //Connecting the last node with the new node
        temp->prev = p;                                     //Connecting the new node prev with the last node

        printf("\n<-----The program has ended.\n");
        return head;                                        //Returning head
    } else                                                  //If there is no node in head, automatically addFront will be done
    {
        head = addFront(head);
        return head;
    }
}

node *delNode(node *head, int x) {

    printf("\nDeleting the node that contains number %d----->\n", x);

    node *p = head;
    node *delSoon;

    if (head == NULL)
    {
        printf("\n Node cannot be deleted. There is no any node.\n");
    } else
    {
        do
        {
            
            if (p->data == x)
            {
                delSoon = p;

                if (head == p)                                              //If head contains x number
                {
                    head = p->next;
                    head->prev = NULL;
                    p = head;
                } else if (p->next == NULL)                                 //If x in the last node
                {
                    p = p->prev;
                    p->next = NULL;
                } else                                                      //If x in the middle
                {
                    p->prev->next = p->next;
                    p->next->prev = p->prev;
                    p = p->next;
                }
                
                free(delSoon);                                              //Deleting the node
            }

            p = p->next;

        } while (p != NULL);
        
    }
    
    printf("\n<-----The program has ended.\n");
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
    printf("%d<--", head->data);

}

void *sortNode(node *head){

    node *p = head;

        printf("\nThe node is being sorted----->\n");

        printf("\n");
        printAll(head);
        printf("\n");

    do
    {

        if (p->data > p->next->data)
        {
            
            int temp = p->data;
            p->data = p->next->data;
            p->next->data = temp;

            p = head;

            printf("\n");
            printAll(head);
            printf("\n");

        } else 
        {
            p = p->next;
        }
        
    } while (p->next != NULL);

    printf("\n<-----The program has ended.\n");
}

void *checkAllNode(node* head) {

    printf("\nChecking all nodes----->\n");

    node *temp = head;

    if (temp == NULL)
    {
        printf("\nThere is no node!\n");
    } else
    {

        printf("\n");

        do
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        } while (temp != NULL);

        printf("\n");

        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        do
        {
            printf("%d-->", temp->data);
            temp = temp->prev;
        } while (temp != NULL);

    }

    printf("\n<-----The program has ended.\n");
}

void *checkNode(node* head) {

    node *temp = head;

    printf("\n");

    do
    {
        printf("%d-->", temp->data);
        temp = temp->next;
    } while (temp != NULL);

    printf("\n");
}