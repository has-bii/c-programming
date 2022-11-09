#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_SIZE 20

typedef struct {
    int counter;
    int front, rear;
    int data[MAX_SIZE];
} queue;

typedef struct {
    int top;
    int data[MAX_SIZE];
} stack;


// FUNCTION PROTOTYPES

void initialize_q(queue *q);
int isFull_q(queue *q);
int isEmpty_q(queue *q);
void enqueue(queue *q, int x);
int dequeue(queue *q);
void initialize_s(stack *s);
int isFull_s(stack *s);
int isEmpty_s(stack *s);
void push(stack *s, int x);
int pop(stack *s);
void convertStringToLow(char str[]);

int main() {

    queue *q = (queue *)malloc(sizeof(queue));
    stack *s = (stack *)malloc(sizeof(stack));
    char text[50];
    int i = 0;

    initialize_q(q);
    initialize_s(s);

    printf("Enter a sentence to determine whether the sentence is polindrome or not: ");
    fgets(text, sizeof(text), stdin); // Take a sentence from keyboard

    convertStringToLow(text); // Converting all characters to be lower case

    printf("\nYour sentence is: ");
    puts(text);

    while (i < strlen(text)-1)
    {
        enqueue(q, (int)text[i]);   // Push and enqueue every character
        push(s, (int)text[i]);      // (int) is converting a char to be an int
        i++;
    }
    
    while (q->counter != 0)
    {
        if (dequeue(q) != pop(s))
        {
            printf("\nThe sentence is not polindrome!");
            return 0;
        }
    }
    
    printf("The sentence is polindrome!");

    return 0;
}

// QUEUE FUNCTIONS

void initialize_q(queue *q)
{
    q->counter = 0;
    q->rear = -1;
    q->front = 0;
}

int isFull_q(queue *q)
{
    if (q->counter == MAX_SIZE)
        return 1;
    else
        return 0;
}

int isEmpty_q(queue *q)
{
    if (q->counter == 0)
        return 1;
    else
        return 0;
}

void enqueue(queue *q, int x)
{
    if (isFull_q(q))
    {
        printf("\nQueue is full!");
    } else
    {
        q->rear++;
        q->counter++;
        if (q->rear == MAX_SIZE)
            q->rear = 0;
        q->data[q->rear] = x;
        
    }
}

int dequeue(queue *q)
{
    if (isEmpty_q(q))
    {
        printf("\nQueue is empty");
        return -100;
    } else
    {
        int x = q->data[q->front];
        q->front++;
        q->counter--;
        if (q->front == MAX_SIZE)
        {
            q->front = 0;
        }
        return x;
    }
}

// STACK FUNCTIONS

void initialize_s(stack *s)
{
    s->top = -1;
}

int isFull_s(stack *s)
{
    if (s->top == MAX_SIZE-1)
        return 1;
    else
        return 0;
}

int isEmpty_s(stack *s)
{
    if (s->top == -1)
        return 1;
    else
        return 0;
}

void push(stack *s, int x)
{
    if (isFull_s(s))
        printf("\nStack is full");
    else
        s->data[++s->top] = x;
}

int pop(stack *s)
{
    if (isEmpty_s(s))
    {
        printf("\nStack is empty");
    } else
    {
        int x = s->data[s->top--];
        return x;
    }
}

// Convert string to lowercase

void convertStringToLow(char str[])
{
    for (int i = 0; i < strlen(str); i++)
    {
        str[i] = tolower(str[i]);
    }
}