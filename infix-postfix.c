#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow");
    }
    else
    {
        stack[++top] = x;
    }
}

char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int precedence(char x)
{
    if (x == '^')
    {
        return 3;
    }
    if (x == '*' || x == '/')
    {
        return 2;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char exp[100];
    printf("Enter expression :- ");
    scanf("%s", exp);

    for (int i = 0; exp[i] != '\0'; i++)
    {
        char ch = exp[i];

        if (isalnum(ch))
        {
            printf("%c", ch);
        }
        else if (ch == '(')
        {
            push(ch);
        }
        else if (ch == ')')
        {
            while (stack[top] != '(')
            {
                printf("%c", pop());
            }
            pop();
        }
        else
        {
            while (top != -1 && precedence(stack[top]) >= precedence(ch))
            {
                printf("%c", pop());
            }
            push(ch);
        }
    }

    while (top != -1)
    {
        printf("%c", pop());
    }

    return 0;
}