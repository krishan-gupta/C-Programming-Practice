#include <stdio.h>
#define MAX 5

int deque[MAX];
int front = -1;
int rear = -1;

int isEmpty()
{
    if (front == -1)
    {
        return 1; // Returns True (1)
    }
    return 0; // Returns False (0)
}

int isFull()
{
    if (front == 0 && rear == MAX - 1)
    {
        return 1; // Returns True (1)
    }
    return 0; // Returns False (0)
}

void insertFront(int val)
{
    // Check if totally full OR just blocked at the front
    if (isFull() || front == rear + 1)
    {
        printf("Overflow: Cannot insert %d at front end.\n", val);
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
        deque[front] = val;
        printf("Inserted %d at front.\n", val);
    }
    else
    {
        front--;
        deque[front] = val;
        printf("Inserted %d at front.\n", val);
    }
}

void insertRear(int val)
{
    // Check if totally full OR just blocked at the rear
    if (isFull() || rear == MAX - 1)
    {
        printf("Overflow: Cannot insert %d at rear end.\n", val);
    }
    // Check if empty using our helper function
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
        deque[rear] = val;
        printf("Inserted %d at rear.\n", val);
    }
    // Normal insertion
    else
    {
        rear++;
        deque[rear] = val;
        printf("Inserted %d at rear.\n", val);
    }
}

void deleteFront()
{
    if (isEmpty())
    {
        printf("Underflow: Deque is empty.\n");
    }
    else
    {
        printf("Deleted %d from front.\n", deque[front]);
        // If there was only one element left
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front++;
        }
    }
}

void deleteRear()
{
    if (isEmpty())
    {
        printf("Underflow: Deque is empty.\n");
    }
    else
    {
        printf("Deleted %d from rear.\n", deque[rear]);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            rear--;
        }
    }
}

void display()
{
    if (isEmpty())
    {
        printf("Deque is empty.\n");
    }
    else
    {
        printf("Deque elements: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", deque[i]);
        }
        printf("\n");
    }
}

// Main function to test the Deque
int main()
{
    insertRear(10);
    insertRear(20);
    insertFront(5);
    display();

    deleteFront();
    display();

    deleteRear();
    display();

    return 0;
}