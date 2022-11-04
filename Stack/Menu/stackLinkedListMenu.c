#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 3

// Stack using linked list

typedef struct node
{
    int data;
    struct node *next;
}node;

typedef struct 
{
    int counter;
    node *top;
}stack;

// Function prototypes

void initialize(stack *s);
int isFull(stack *s);
int isEmpty(stack *s);
void push(stack *s, int x);
int pop(stack *s);
void printStack(stack *s);

// Main code

int main() {

    stack *s = (stack *)malloc(sizeof(stack));
    int x, N;

    initialize(s);

    printf("\n");
    printStack(s);
    printf("\n");
    printf("\n1) Push\n2) Pop\n0) Exit\nChoose a program: ");
    scanf("%d", &N);

    while (N != 0)
    {
        switch (N)
        {
        case 1:
            printf("\nPush----->\n");
            printf("\nEnter an integer: ");
            scanf("%d", &x);
            push(s, x);
            break;
        
        case 2:
            printf("\nPop----->\n");
            x = pop(s);
            if (x != -100)
                printf("\npopped number = %d", x);
            break;

        default:
            break;
        }

        printf("\n");
        printStack(s);
        printf("\n");
        printf("\n1) Push\n2) Pop\n0) Exit\nChoose a program: ");
        scanf("%d", &N);
    }

    return 0;
}

// Functions

void initialize(stack *s)
{
    s->counter = 0;
    s->top = NULL;
}

int isFull(stack *s)
{
    if (s->counter == STACK_SIZE)
        return 1;
    else
        return 0;
}

int isEmpty(stack *s)
{
    if (s->counter == 0)
        return 1;
    else
        return 0;
}

void push(stack *s, int x)
{
    if (isFull(s))
    {
        printf("\nStack is full");
    } else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = x;
        temp->next = s->top;
        s->top = temp;
        s->counter++;
    }    
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is empty");
        return -100;
    } else
    {
        int x = s->top->data;
        node *temp = s->top;

        s->top = s->top->next;
        free(temp);
        s->counter--;

        return x;
    }
}

void printStack(stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is empty");
    } else
    {
        node *temp  = s->top;

        for (int i = 0; i < s->counter; i++)
        {
            printf("\n%4d", temp->data);
            temp = temp->next;
        }
    }
}