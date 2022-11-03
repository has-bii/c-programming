#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 5

struct linkedList
{
    int data;
    struct linkedList *next;
};

typedef struct linkedList node;

typedef struct
{
    int counter;
    node *front;
    node *rear;
}queue;

// Function prototypes

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
    q->front = q->rear = NULL;
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
        q->counter++;
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
        node *temp = q->front;
        int x = temp->data;
        q->front = q->front->next;
        free(temp);
        q->counter--;

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
        node *temp = q->front;

        do
        {
            printf("%d-->", temp->data);
            temp = temp->next;
        } while (temp != NULL);
    }
}