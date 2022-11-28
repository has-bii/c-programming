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
void printReversely(node *p);

// Main code

int main() {

    stack *s = (stack *)malloc(sizeof(stack));
    int x;

    initialize(s);

    push(s, 10);
    push(s, 20);
    push(s, 30);

    printReversely(s->top);

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

void printReversely(node *p)
{
    if (p == NULL)
    {}
    else
    {
        printReversely(p->next);
        printf("\n%d", p->data);
    }
}