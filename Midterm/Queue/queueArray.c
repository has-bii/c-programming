#include <stdio.h>
#define QUEUE_SIZE 5

typedef struct
{
    int counter;
    int front, rear;
    int data[QUEUE_SIZE];
} queue;

void initialize(queue *q)
{
    q->counter = 0;
    q->front = 0;
    q->rear = -1;
}

void enqueue(queue *q, int x)
{
    if (q->counter == QUEUE_SIZE)
        printf("QUEUE IS FULL.");
    else
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
    if (q->counter == 0)
    {
        printf("Queue is empty.");
        return -100;
    } else
    {
        int x = q->data[q->front++];
        q->counter--;
        if (q->front == QUEUE_SIZE)
            q->front = 0;
        return x;
    }
}

int main()
{
    queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 2560);
    enqueue(&q, 30);

    printf("%d-->", dequeue(&q));
    printf("%d-->", dequeue(&q));
    printf("%d-->", dequeue(&q));

    return 0;
}