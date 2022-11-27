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

void printQueue(queue *q)
{
    if (q->counter == 0)
    {
        printf("\nQueue is empty");
    } else
    {
        queue *temp = q;
        int x = q->front;

        for (int i = 0; i < q->counter; i++)
        {
            if (x == MAX_SIZE)
                x = 0;
            printf("%d-->", q->data[x++]);
        }
    }
}

void printStack(stack *s)
{
    if (s->top == -1)
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

void swap(stack *s, queue *q)
{
    queue qTemp;
    initializeQueue(&qTemp);

    while (s->top != -1) // transferring stack to queue temp
    {
        enqueue(&qTemp, pop(s));
    }

    while (q->counter != 0) // transferring queue to stack
    {
        push(s, dequeue(q));
    }
    
    while (qTemp.counter != 0) // transferring queue temp to queue
    {
        enqueue(q, dequeue(&qTemp));
    }
}

int main()
{
    stack s;
    initializeStack(&s);

    queue q;
    initializeQueue(&q);

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
    push(&s, 4);
    push(&s, 5);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);
    enqueue(&q, 50);

    printf("\n\nQUEUE------>\n");
    printQueue(&q);
    printf("\n\nSTACK------>");
    printStack(&s);

    swap(&s, &q);

    printf("\n\nQUEUE------>\n");
    printQueue(&q);
    printf("\n\nSTACK------>");
    printStack(&s);

    return 0;
}