#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

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
void printQueue(queue *q);

// Main code

int main() {
    
    queue *q = (queue *)malloc(sizeof(queue));
    int x, N;

    initialize(q);

    printf("\n");
    printQueue(q);
    printf("\n");
    printf("\n1) Enqueue\n2) Dequeue\n0) Exit\nChoose a program: ");
    scanf("%d", &N);

    while (N != 0)
    {
        switch (N)
        {
        case 1:
            printf("\nEnqueue----->\n");
            printf("\nEnter an integer: ");
            scanf("%d", &x);
            enqueue(q, x);
            break;
        
        case 2:
            printf("\nDequeue----->\n");
            x = dequeue(q);
            if (x != -100)
                printf("\nDequeue number = %d", x);
            break;

        default:
            break;
        }

        printf("\n");
        printQueue(q);
        printf("\n");
        printf("\n1) Enqueue\n2) Dequeue\n0) Exit\nChoose a program: ");
        scanf("%d", &N);
    }
    
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
        q->counter++;
        q->rear++;
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
        {
            q->front = 0;
        }
        return x;
    }
}

void printQueue(queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty");
    } else
    {
        queue *temp = q;
        int x = q->front;

        for (int i = 0; i < q->counter; i++)
        {
            if (x == QUEUE_SIZE)
                x = 0;
            printf("%d-->", q->data[x++]);
        }
    }
}