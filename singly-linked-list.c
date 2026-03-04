#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display_ll(struct node *head)
{
    struct node *temp;
    temp = head;
    if (head == NULL)
    {
        printf("Empty List");
        return;
    }
    printf("Linked List :- \n");
    while (temp != NULL)
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}

void insert_begin(struct node **head)
{
    int x;
    struct node *newnode = malloc(sizeof(struct node));
    printf("Enter data :- ");
    scanf("%d", &x);
    newnode->data = x;
    newnode->next = *head;
    *head = newnode;
}

void insert_end(struct node **head)
{
    struct node *newnode = malloc(sizeof(struct node));
    struct node *temp;
    int x;
    printf("Enter data :- ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = NULL;

    if (*head == NULL)
    {
        *head = newnode;
        return;
    }

    temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newnode;
}

void count_nodes(struct node *head)
{
    int count = 0;
    struct node *temp;

    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total Number of Nodes are :- %d\n", count);
}

void delete_begin(struct node **head)
{
    if (*head == NULL)
    {
        printf("Empty List");
        return;
    }

    struct node *temp = *head;

    *head = (*head)->next;
    printf("Deleted element is :- %d\n", temp->data);

    free(temp);
}

void delete_end(struct node **head)
{
    if (*head == NULL)
    {
        printf("List Empty");
        return;
    }

    if ((*head)->next == NULL)
    {
        printf("Deleted Element is %d", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }

    struct node *temp, *prev;
    temp = *head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted element is :- %d", temp->data);
    prev->next = NULL;
    free(temp);
}

void insert_pos(struct node **head)
{
    struct node *temp, *newnode;
    int x, pos;
    printf("Enter the position :- ");
    scanf("%d", &pos);
    printf("Enter the data :- ");
    scanf("%d", &x);

    newnode = malloc(sizeof(struct node));
    newnode->data = x;

    if (pos == 1)
    {
        newnode->next = *head;
        *head = newnode;
        return;
    }

    temp = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void delete_pos(struct node **head)
{
    struct node *temp, *del;
    int pos;
    printf("Enter position:- ");
    scanf("%d", &pos);

    if (*head == NULL)
    {
        printf("List Empty");
        return;
    }

    if (pos == 1)
    {
        del = *head;
        *head = (*head)->next;
        printf("Deleted Element is :- %d", del->data);
        free(del);
        return;
    }

    temp = *head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }

    del = temp->next;
    temp->next = del->next;
    printf("Deleted Element is %d", del->data);
    free(del);
}
int main()
{
    struct node *head = NULL;
    insert_end(&head);
    insert_end(&head);
    insert_end(&head);
    insert_end(&head);
    insert_end(&head);
    display_ll(head);
    count_nodes(head);
    insert_pos(&head);
    display_ll(head);
    delete_pos(&head);
    display_ll(head);
    return 0;
}