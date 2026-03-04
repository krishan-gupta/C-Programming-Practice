#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int x;
    if (rear == MAX - 1)
    {
        printf("Queue Overflow \n");
        return;
    }

    printf("Enter Element :- ");
    scanf("%d", &x);

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }

    queue[rear] = x;
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Underflow \n");
        return;
    }
    printf("Deleted Element is:- %d\n", queue[front]);
    front++;
}

void peek()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Empty \n");
        return;
    }

    printf("The Front Most Element is :- %d\n", queue[front]);
}

void display()
{
    if (front == -1 || front > rear)
    {
        printf("Queue Empty \n");
        return;
    }

    printf("Queue Elements are :-\n");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    printf("\n");
}

int main()
{
    enqueue();
    enqueue();
    enqueue();
    display();
    peek();
    dequeue();
    display();
}