#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    else
    {
        printf("Deleted Element is %d\n", stack[top]);
        top--;
    }
}

void push()
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        int x;
        printf("Enter element to push:- ");
        scanf("%d", &x);
        stack[++top] = x;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack Empty");
        return;
    }
    printf("Top Most Element is %d\n", stack[top]);
}

void display()
{
    if (top == -1)
    {
        printf("Stack Empty");
        return;
    }
    printf("Stack Elements:- ");
    for (int i = top; i >= 0; i--)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main()
{
    push();
    push();
    push();
    push();
    push();
    push();
    pop();
    display();
    peek();
}