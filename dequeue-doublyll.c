#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void insert_front()
{
    struct node *newnode;
    int value;

    printf("Enter the value to insert at start\n");
    scanf("%d", &value);

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = front;

    if (front == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        front->prev = newnode;
        front = newnode;
    }
}

void insert_rear()
{
    struct node *newnode;
    int value;

    printf("Enter the value to insert at rear\n");
    scanf("%d", &value);

    newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->next = NULL;
    newnode->prev = rear;

    if (rear != NULL)
    {
        rear->next = newnode;
    }
    else
    {
        front = newnode;
    }

    rear = newnode;
}

void delete_front()
{
    struct node *temp;

    if (front == NULL)
    {
        printf("Underflow\n");
        return;
    }

    temp = front;
    printf("Deleted %d\n", temp->data);

    front = front->next;

    if (front != NULL)
    {
        front->prev = NULL;
    }
    else
    {
        rear = NULL;
    }

    free(temp);
}

void delete_rear()
{
    struct node *temp;

    if (rear == NULL)
    {
        printf("Underflow\n");
        return;
    }

    temp = rear;
    printf("Deleted = %d\n", temp->data);

    rear = rear->prev;

    if (rear != NULL)
    {
        rear->next = NULL;
    }
    else
    {
        front = NULL;
    }

    free(temp);
}

void display()
{
    struct node *temp = front;

    if (front == NULL)
    {
        printf("Queue Empty\n");
        return;
    }

    printf("Queue Elements\n");

    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    insert_front();
    insert_front();
    insert_front();
    insert_rear();
    insert_rear();
    insert_rear();
    display();
}