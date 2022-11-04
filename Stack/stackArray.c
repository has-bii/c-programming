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

// Main code
int main() {

    stack *s = (stack *)malloc(sizeof(stack));
    int x;
    
    reset(s);

    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);

    x = pop(s);
    printf("\n1. %d", x);

    x = pop(s);
    printf("\n2. %d", x);

    x = pop(s);
    printf("\n3. %d", x);

    x = pop(s);

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
    } else
    {
        int x = s->data[s->top--];
        return x;
    }
}