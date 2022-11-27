#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

struct node
{
    int data;
    struct node *next;
};

typedef struct node node;

typedef struct
{
    int counter;
    node *front;
    node *rear;
} queue;

void initialize(queue *q)
{
    q->counter = 0;
    q->front = q->rear = NULL;
}

void enqueue(queue *q, int x)
{
    if (q->counter == QUEUE_SIZE)
        printf("Queue is full");
    else
    {
        node *temp = (node*)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;

        if(q->counter == 0)
            q->front = q->rear = temp;
        else
        {
            q->rear->next = temp;
            q->rear = temp;
        }

        q->counter++;
    }
}

int dequeue(queue *q)
{
    if (q->counter == 0)
    {
        printf("Queue is empty.");
        return -100;
    }
    else
    {
        node *deleted = q->front;
        int x = deleted->data;

        q->front = deleted->next;
        free(deleted);

        q->counter--;
        return x;
    }
}

int main()
{
    queue q;
    initialize(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);

    printf("%d-->", dequeue(&q));
    printf("%d-->", dequeue(&q));
    printf("%d-->", dequeue(&q));
    printf("%d-->", dequeue(&q));

    return 0;
}