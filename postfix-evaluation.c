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

int main()
{
    char exp[100];
    printf("Enter Postfix Evaluation:- ");
    scanf("%s", exp);
    int i = 0;

    while (exp[i] != '\0')
    {
        char ch = exp[i];

        if (isdigit(ch))
        {
            push(ch - '0');
        }
        else
        {
            int b = pop();
            int a = pop();
            switch (ch)
            {
            case '+':
                push(a + b);
                break;
            case '-':
                push(a - b);
                break;
            case '*':
                push(a * b);
                break;
            case '/':
                push(a / b);
                break;
            }
        }
        i++;
    }

    printf("Final answer = %d", pop());
}