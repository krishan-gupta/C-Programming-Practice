#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void push(struct node **top)
{
    struct node *newnode;
    int x;
    newnode = malloc(sizeof(struct node));
    printf("Enter Element:- ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = *top;
    *top = newnode;
}

void pop(struct node **top)
{
    if (*top == NULL)
    {
        printf("Stack Underflow \n");
        return;
    }

    printf("Deleted Element is %d\n", (*top)->data);

    struct node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

void display(struct node **top)
{
    struct node *temp = *top;
    if (temp == NULL)
    {
        printf("Empty Stack\n");
        return;
    }
    printf("Stack Elements are:-");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void peek(struct node **top)
{
    if (*top == NULL)
    {
        printf("Empty Stack\n");
        return;
    }

    printf("The top most element is %d", (*top)->data);
}

int main()
{
    struct node *top = NULL;
    push(&top);
    push(&top);
    push(&top);
    pop(&top);
    display(&top);
    peek(&top);
}