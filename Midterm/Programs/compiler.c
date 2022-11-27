#include <stdio.h>
#define STACK_SIZE 20

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

    char key;
    char openParenthese;

    FILE *fptr;

    if ((fptr = fopen("code.txt", "r")) == NULL)
        printf("There isn't any files.");
    else 
    {
        while (!feof(fptr))
        {
            key = getc(fptr);

            switch (key)
            {
            case '}':
                openParenthese = (char)pop(&s);
                if (openParenthese != '{')
                    printf("ERROR: {}");
                return 0;
                break;
            
            case ']':
                openParenthese = (char)pop(&s);
                if (openParenthese != '[')
                    printf("ERROR: []");
                return 0;
                break;
            
            case ')':
                openParenthese = (char)pop(&s);
                if (openParenthese != '(')
                    printf("ERROR: ()");
                return 0;
                break;
            
            default:
                if (key == '(' || key == '{' || key == '[')
                    push(&s, (int)key);
                break;
            }
        }
        
        fclose(fptr);

        if (s.top != -1)
            printf("There is at least one parenthese opened");
        else
            printf("No error");
    }

    return 0;
}