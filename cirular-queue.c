#include <stdio.h>
#define MAX 5

int cqueue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    if (front == (rear + 1) % MAX)
    {
        printf("Circular Queue Overflow \n");
        return;
    }

    int x;
    printf("Enter Element :- ");
    scanf("%d", &x);

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }
    cqueue[rear] = x;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue Underflow \n");
        return;
    }
    printf("Deleted Element is:- %d\n", cqueue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Queue Empty \n");
        return;
    }

    printf("Circular Queue Elements are:- ");

    int i = front;

    while (1)
    {
        printf("%d ", cqueue[i]);

        if (i == rear)
        {
            break;
        }

        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main()
{
    enqueue();
    enqueue();
    enqueue();
    display();
    dequeue();
    display();
}