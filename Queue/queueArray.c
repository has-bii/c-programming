#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 3

typedef struct
{
    int counter;
    int front, rear;
    int data[QUEUE_SIZE];
} queue;

// Functions prototypes

void initialize(queue *q);
int isFull(queue *q);
int isEmpty(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);

// Main code

int main()
{
    queue *q = (queue *)malloc(sizeof(queue));
    int x;

    initialize(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);

    x = dequeue(q);
    printf("\n1. %d", x);

    x = dequeue(q);
    printf("\n2. %d", x);

    x = dequeue(q);
    printf("\n3. %d", x);

    x = dequeue(q);

    return 0;
}

// Functions

void initialize(queue *q)
{
    q->counter = 0;
    q->rear = -1;
    q->front = 0; 
}

int isFull(queue *q)
{
    if (q->counter == QUEUE_SIZE)
    {
        return 1;
    } else
    {
        return 0;
    }
}

int isEmpty(queue *q)
{
    if (q->counter == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}

void enqueue(queue *q, int x)
{
    if (isFull(q))
    {
        printf("\nQueue is full");
    } else
    {
        q->rear++;
        q->counter++;
        if (q->rear == QUEUE_SIZE)
            q->rear = 0;
        q->data[q->rear] = x;   
    }
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty");
        return -100;
    } else
    {
        int x = q->data[q->front];
        q->front++;
        q->counter--;
        if (q->front == QUEUE_SIZE)
            q->front = 0;
        return x;
    }
}