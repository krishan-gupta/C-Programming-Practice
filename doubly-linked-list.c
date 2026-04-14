#include <stdio.h>
#include <stdlib.h>

// Node Structure
struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

// --- INSERTION FUNCTIONS ---

void insertAtBeginning(struct Node **head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = *head;
    newNode->prev = NULL;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}

void insertAtEnd(struct Node **head, int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = *head;
    newNode->data = val;
    newNode->next = NULL;
    if (*head == NULL)
    {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtPosition(struct Node **head, int val, int pos)
{
    if (pos <= 1)
    {
        insertAtBeginning(head, val);
        return;
    }
    struct Node *temp = *head;
    for (int i = 1; temp != NULL && i < pos - 1; i++)
        temp = temp->next;
    if (temp == NULL)
    {
        insertAtEnd(head, val);
        return;
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
}

// --- DELETION FUNCTIONS ---

void deleteFromBeginning(struct Node **head)
{
    if (*head == NULL)
        return;
    struct Node *temp = *head;
    *head = (*head)->next;
    if (*head != NULL)
        (*head)->prev = NULL;
    free(temp);
}

void deleteFromEnd(struct Node **head)
{
    if (*head == NULL)
        return;
    struct Node *temp = *head;
    if (temp->next == NULL)
    {
        *head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp);
}

void deleteFromPosition(struct Node **head, int pos)
{
    if (*head == NULL)
        return;
    struct Node *temp = *head;
    if (pos == 1)
    {
        deleteFromBeginning(head);
        return;
    }
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    if (temp == NULL)
        return;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    free(temp);
}

// --- UTILITY FUNCTIONS ---

int search(struct Node *head, int key)
{
    int pos = 1;
    while (head != NULL)
    {
        if (head->data == key)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

void display(struct Node *head)
{
    printf("List: NULL <-> ");
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int countNodes(struct Node *head)
{
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void update(struct Node *head, int pos, int newVal)
{
    struct Node *temp = head;
    for (int i = 1; temp != NULL && i < pos; i++)
        temp = temp->next;
    if (temp != NULL)
        temp->data = newVal;
}

void sortList(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *i, *j;
    int temp;
    for (i = head; i->next != NULL; i = i->next)
    {
        for (j = i->next; j != NULL; j = j->next)
        {
            if (i->data > j->data)
            {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

// --- MAIN CODE ---

int main()
{
    struct Node *head = NULL;

    printf("--- Testing Insertion ---\n");
    insertAtBeginning(&head, 30);   // 30
    insertAtBeginning(&head, 10);   // 10, 30
    insertAtEnd(&head, 50);         // 10, 30, 50
    insertAtPosition(&head, 20, 2); // 10, 20, 30, 50
    display(head);

    printf("\nSize of list: %d\n", countNodes(head));

    printf("\n--- Testing Search & Update ---\n");
    int s = search(head, 30);
    if (s != -1)
        printf("Value 30 found at position: %d\n", s);
    update(head, 4, 40); // Change 50 to 40
    display(head);

    printf("\n--- Testing Sort ---\n");
    insertAtBeginning(&head, 100);
    printf("Before Sort: ");
    display(head);
    sortList(head);
    printf("After Sort:  ");
    display(head);

    printf("\n--- Testing Deletion ---\n");
    deleteFromBeginning(&head);
    deleteFromEnd(&head);
    deleteFromPosition(&head, 2);
    display(head);

    return 0;
}