#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

typedef struct
{
    int counter;
    node *top;
}stack;

void initialize(stack *s)
{
    s->counter = 0;
    s->top = NULL;
}

void push(stack *s, int x)
{
    if (s->counter == MAX_STACK_SIZE)
    {
        printf("\nStack is full.");
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
    if (s->counter == 0)
    {
        printf("\nStack is empty.");
        return -100;
    } else
    {
        int x = s->top->data;
        node *deleted = s->top;

        s->top = s->top->next;
        free(deleted);
        s->counter--;

        return x;
    }
}

int main() {

    stack s;

    initialize(&s);
    
    printf("%d\n", pop(&s));

    push(&s, 10);
    push(&s, 20);
    push(&s, 40);
    push(&s, 50);

    printReversely(&s.top);

    return 0;
}