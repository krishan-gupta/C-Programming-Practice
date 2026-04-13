#include <stdio.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

// Check if queue is full
int isFull()
{
    return (front == (rear + 1) % MAX);
}

// Check if queue is empty
int isEmpty()
{
    return (front == -1);
}

// Enqueue operation
void enqueue(int value)
{
    if (isFull())
    {
        printf("Queue is Full\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

// Dequeue operation
void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
    {
        // Only one element
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

// Peek operation
void peek()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
    }
    else
    {
        printf("Front element: %d\n", queue[front]);
    }
}

// Display queue
void display()
{
    if (isEmpty())
    {
        printf("Queue is Empty\n");
        return;
    }

    int i = front;
    printf("Queue elements: ");

    while (1)
    {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }

    printf("\n");
}

// Main function
int main()
{
    int value;
    printf("Enter value: ");
    scanf("%d", &value);
    enqueue(value);
    enqueue(value);
    enqueue(value);
    dequeue();
    peek();
    display();
    return 0;
}