#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 3

typedef struct 
{
    int top;
    int data[STACK_SIZE];
} stack;

// Functions prototypes
void reset(stack *s);
int isFull(stack *s);
int isEmpty(stack *s);
void push(stack *s, int x);
int pop(stack *s);
void printStack(stack *s);

// Main code
int main() {

    stack *s = (stack *)malloc(sizeof(stack));
    int x, N;

    reset(s);

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

void reset(stack *s)
{
    s->top = -1;
}

int isFull(stack *s)
{
    if (s->top == STACK_SIZE-1)
        return 1;
    else
        return 0;
}

int isEmpty(stack *s)
{
    if (s->top == -1)
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
        s->data[++s->top] = x;
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
        int x = s->data[s->top--];
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
        int x = s->top;

        do
        {
            printf("\n%4d", s->data[x--]);
        } while (x != -1);

    }
}