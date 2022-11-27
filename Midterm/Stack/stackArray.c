#include <stdio.h>
#define STACK_SIZE 3

typedef struct
{
    int top;
    int data[STACK_SIZE];
} stack;

void initialize(stack *s)
{
    s->top = -1;
}

void push(stack *s, int x)
{
    if (s->top == STACK_SIZE-1)
        printf("\nStack is full.");
    else
        s->data[++s->top] = x;
}

int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("\nStack is empty.");
        return -100;
    } else 
        return s->data[s->top--];
    
}

int main()
{
    stack s;

    initialize(&s);

    printf("%d\n", pop(&s));

    push(&s, 10);
    push(&s, 20);
    push(&s, 40);
    push(&s, 50);

    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));
    printf("%d\n", pop(&s));

    return 0;
}