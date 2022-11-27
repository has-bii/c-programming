#include <stdio.h>
#include <ctype.h>
#define MAX_SIZE 10

typedef struct
{
    int counter;
    int front, rear;
    int data[MAX_SIZE];
} queue;

typedef struct
{
    int top;
    int data[MAX_SIZE];
} stack;

void initializeStack(stack *s)
{
    s->top = -1;
}

void initializeQueue(queue *q)
{
    q->counter = 0;
    q->front = 0;
    q->rear = -1;
}

void push(stack *s, int x)
{
    if (s->top == MAX_SIZE-1)
        printf("Stack is full.");
    else
        s->data[++s->top] = x;
}

int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty");
        return -100;
    } else
        return s->data[s->top--];
}

void enqueue(queue *q, int x)
{
    if (q->counter == MAX_SIZE)
        printf("Stack is full.");
    else
    {
        q->counter++;
        q->rear++;
        if (q->rear == MAX_SIZE)
            q->rear = 0;
        q->data[q->rear] = x;
    }
}

int dequeue(queue *q)
{
    if (q->counter == 0)
    {
        printf("Stack is empty");
        return -100;
    } else
    {
        int x = q->data[q->front];
        q->counter--;
        q->front++;
        if (q->front == MAX_SIZE)
            q->front = 0;
        return x;
    }  
}

int main()
{
    stack s;
    initializeStack(&s);

    queue q;
    initializeQueue(&q);

    char string[20];
    char *sptr = string;

    printf("Enter a polindrome thing: ");
    scanf("%s", string);

    while (*sptr != '\0')
    {
        push(&s, (int)(*sptr));
        enqueue(&q, (int)(*sptr));

        sptr++;
    }
    
    while (q.counter != 0)
    {
        if (dequeue(&q) != pop(&s))
        {
            printf("It is not a polindrome thing");
            return 0;
        }
    }
    
    printf("The sentence is polindrome!");

    return 0;
}