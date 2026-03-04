#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void enqueue(struct node **front, struct node **rear)
{
    struct node *newnode = malloc(sizeof(struct node));
    int x;
    printf("Enter the data to enter:- ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = NULL;

    if (*front == NULL)
    {
        *front = *rear = newnode;
    }
    else
    {
        (*rear)->next = newnode;
        *rear = newnode;
    }
}

void dequeue(struct node **front, struct node **rear)
{
    if (*front == NULL)
    {
        printf("Queue Empty \n");
        return;
    }

    printf("Deleted data is %d\n", (*front)->data);
    (*front) = (*front)->next;

    if (*front == NULL)
    {
        *rear = NULL;
    }
}

void display(struct node **front)
{
    struct node *temp = *front;
    if (*front == NULL)
    {
        printf("Queue Empty \n");
        return;
    }
    printf("Queue is:- \n");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct node *front = NULL;
    struct node *rear = NULL;
    enqueue(&front, &rear);
    enqueue(&front, &rear);
    enqueue(&front, &rear);
    display(&front);
    dequeue(&front, &rear);
    display(&front);
}
