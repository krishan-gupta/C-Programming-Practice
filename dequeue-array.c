#include <stdio.h>
#define MAX 5

int dequeue[MAX];
int front = -1;
int rear = -1;

void insert_rear()
{
    int x;
    if (rear == MAX - 1) // ✅ Correct: no space at rear end
    {
        printf("Overflow\n");
        return;
    }
    printf("Enter the number to insert at rear :- ");
    scanf("%d", &x);

    if (front == -1) // ✅ Empty queue
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    dequeue[rear] = x;
}

void insert_front()
{
    int x;
    if (front == 0)
    {
        printf("Overflow (No space at the beginning)\n");
        return;
    }

    printf("Enter the number to insert at front :- ");
    scanf("%d", &x);

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        front--;
    }
    dequeue[front] = x;
}

void delete_front()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted Element from front is :- %d\n", dequeue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void delete_rear()
{
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("Deleted Element from rear is :- %d\n", dequeue[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear--;
    }
}

void display()
{
    if (front == -1)
    {
        printf("Deque Empty\n");
        return;
    }
    printf("Elements of Queue are:- ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d ", dequeue[i]);
    }
    printf("\n");
}

int main()
{
    insert_front(); // Now works!
    insert_rear();
    insert_front();
    insert_rear();
    display();
    delete_front();
    delete_rear();
    display();

    return 0;
}
