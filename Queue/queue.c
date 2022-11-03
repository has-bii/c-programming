#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 3

struct linkedList
{
    int data;
    struct linkedList *next;
};

typedef struct linkedList node;

typedef struct 
{
    int cnt;
    node *front;
    node *rear;
}queue;

// Function Prototypes

void intialize(queue *q);
int isFull(queue *q);
int isEmpty(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);

// Main Code

int main() {

    queue *q = (queue *)malloc(sizeof(queue));
    int x;

    intialize(q);

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
    printf("\n4. %d", x);

    x = dequeue(q);
    printf("\n4. %d", x);

    return 0;
}

// Functions

void intialize(queue *q)
{
    q->cnt = 0;
    q->front = q->rear = NULL;
}

int isFull(queue *q)
{
    if (q->cnt == QUEUE_SIZE)
    {
        return 1;
    } else
    {
        return 0;
    }
}

int isEmpty(queue *q)
{
    if (q->cnt == 0)
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
        printf("\nQueue is full\n");
    } else
    {
        node *temp = (node *)malloc(sizeof(node));
        temp->data = x;
        temp->next = NULL;

        if (isEmpty(q))
        {
            q->front = q->rear = temp;
        } else
        {
            q->rear->next = temp;
            q->rear = temp;
        }
        q->cnt++;   
    }
}

int dequeue(queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is empty\n");
        return -100;
    } else
    {
        node *temp = q->front;
        int x = temp->data;
        q->front = temp->next;
        free(temp);
        q->cnt--;
        return x;
    }    
}