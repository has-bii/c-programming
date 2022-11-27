#include <stdio.h>
#include <ctype.h>
#define STACK_SIZE 3

typedef struct
{
    int top;
    int data[STACK_SIZE];
} stack;

void initialize(stack *s)
{
    s->top = -1;
}

void push(stack *s, int x)
{
    if (s->top == STACK_SIZE-1)
        printf("\nStack is full.");
    else
        s->data[++s->top] = x;
}

int pop(stack *s)
{
    if (s->top == -1)
    {
        printf("\nStack is empty.");
        return -100;
    } else 
        return s->data[s->top--];
    
}

int main()
{
    stack s;
    initialize(&s);

    char exp[20];
    char *e = exp;

    int number;
    int n1, n2, n3;

    printf("Enter an experssion: ");
    scanf("%s", exp);

    while (*e != '\0')
    {
        switch (*e)
        {
        case '+':
            n1 = pop(&s);
            n2 = pop(&s);
            n3 = n2 + n1;

            push(&s, n3);
            break;
        
        case '-':
            n1 = pop(&s);
            n2 = pop(&s);
            n3 = n2 - n1;

            push(&s, n3);
            break;
        
        case '*':
            n1 = pop(&s);
            n2 = pop(&s);
            n3 = n2 * n1;

            push(&s, n3);
            break;
        
        case '/':
            n1 = pop(&s);
            n2 = pop(&s);
            n3 = n2 / n1;

            push(&s, n3);
            break;
        
        default:

            if (isdigit(*e))
            {
                number = *e-48;
                push(&s, number);
            }
            break;
        }
        
        e++;
    }
    
    printf("The result is %d", pop(&s));

    return 0;
}