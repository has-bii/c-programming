#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACK_SIZE 10

typedef struct 
{
    int top;
    int data[STACK_SIZE];
} stack;

// Functions prototypes
void reset(stack *s);
int isFull(stack *s);
int isEmpty(stack *s);
void push(stack *s, int x);
int pop(stack *s);

// Main code
int main() {

    stack *s = (stack *)malloc(sizeof(stack));
    int i = 0;

    reset(s);

    char text[50] = "{text([string])}";

    while (i < strlen(text))
    {
        switch (text[i])
        {
        case '{':
            printf("%c", text[i]);
            push(s, (int)text[i]);
            break;
        
        case '[':
            printf("%c", text[i]);
            push(s, (int)text[i]);
            break;
        
        case '(':
            printf("%c", text[i]);
            push(s, (int)text[i]);
            break;
        
        case '}':
            printf("%c", text[i]);
            if ((char)pop(s) != '{')
            {
                printf("\nError detected. Expected {} sign!");
                return 0;
            }
            break;
        
        case ']':
            printf("%c", text[i]);
            if ((char)pop(s) != '[')
            {
                printf("\nError detected. Expected [] sign!");
                return 0;
            }
            break;
        
        case ')':
            printf("%c", text[i]);
            if ((char)pop(s) != '(')
            {
                printf("\nError detected. Expected () sign!");
                return 0;
            }
            break;
        
        default:
            break;
        }
        
        i++;
    }
    
    if (!isEmpty(s))
    {
        printf("\nError detected: At least one parenthesis is not closed!");
        return 0;
    }
    
    printf("\nNo error detected.");

    return 0;
}

// Functions

void reset(stack *s)
{
    s->top = -1;
}

int isFull(stack *s)
{
    if (s->top == STACK_SIZE-1)
        return 1;
    else
        return 0;
}

int isEmpty(stack *s)
{
    if (s->top == -1)
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
        s->data[++s->top] = x;
    }
}

int pop(stack *s)
{
    if (isEmpty(s))
    {
        printf("\nStack is empty");
    } else
    {
        int x = s->data[s->top--];
        return x;
    }
}