#include <stdio.h>
#include <stdlib.h>

// 1. Define the node structure
struct Node
{
    int data;
    struct Node *next;
};

// 2. Function to allocate memory and create a new node
struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// 3. Function to insert a node at the end of the list
void insertAtEnd(struct Node **head_ref, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *head = *head_ref;

    // If the list is empty, the new node becomes the head and points to itself
    if (head == NULL)
    {
        newNode->next = newNode;
        *head_ref = newNode;
        return;
    }

    // Traverse to the last node
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    // Update pointers to maintain the circular structure
    temp->next = newNode;
    newNode->next = head;
}

// 4. Function to insert a node at the beginning of the list
void insertAtBeginning(struct Node **head_ref, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *head = *head_ref;

    // If empty, the new node points to itself
    if (head == NULL)
    {
        newNode->next = newNode;
        *head_ref = newNode;
        return;
    }

    // Traverse to find the last node
    struct Node *temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }

    // Update pointers
    newNode->next = head;
    temp->next = newNode;
    *head_ref = newNode; // Move the head pointer to the new node
}

// 5. Function to delete a node by value
void deleteNode(struct Node **head_ref, int key)
{
    if (*head_ref == NULL)
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Node *head = *head_ref;
    struct Node *curr = head, *prev = NULL;

    // Case 1: If the list has only ONE node, and it holds the key
    if (curr->data == key && curr->next == head)
    {
        free(curr);
        *head_ref = NULL;
        return;
    }

    // Case 2: If the node to be deleted is the HEAD node
    if (curr->data == key)
    {
        struct Node *last = head;
        // Find the last node
        while (last->next != head)
        {
            last = last->next;
        }

        last->next = head->next;
        *head_ref = head->next;
        free(curr);
        return;
    }

    // Case 3: If the node to be deleted is elsewhere in the list
    do
    {
        prev = curr;
        curr = curr->next;
        if (curr->data == key)
        {
            prev->next = curr->next;
            free(curr);
            return;
        }
    } while (curr != head);

    // If the loop completes without returning, the key wasn't there
    printf("Node with data %d not found in the list.\n", key);
}

// 6. Function to search for a value in the list
int searchList(struct Node *head, int key)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return 0;
    }

    struct Node *temp = head;
    int position = 1;

    do
    {
        if (temp->data == key)
        {
            printf("Found %d at position %d.\n", key, position);
            return 1;
        }
        temp = temp->next;
        position++;
    } while (temp != head);

    printf("Value %d not found in the list.\n", key);
    return 0;
}

// 7. Function to traverse and display the list
void displayList(struct Node *head)
{
    struct Node *temp = head;

    // Handle empty list case
    if (head == NULL)
    {
        printf("The list is empty.\n");
        return;
    }

    printf("Circular Linked List: ");

    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);

    printf("(points back to %d)\n", head->data);
}

// 8. Main function to test everything
int main()
{
    struct Node *head = NULL;

    printf("--- Building the Circular Linked List ---\n");
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);
    displayList(head);

    printf("\n--- Inserting 10 at the beginning ---\n");
    insertAtBeginning(&head, 10);
    displayList(head);

    printf("\n--- Searching for values ---\n");
    searchList(head, 30);
    searchList(head, 100);

    printf("\n--- Deleting 30 (Middle Node) ---\n");
    deleteNode(&head, 30);
    displayList(head);

    printf("\n--- Deleting 10 (Head Node) ---\n");
    deleteNode(&head, 10);
    displayList(head);

    printf("\n--- Deleting 40 (End Node) ---\n");
    deleteNode(&head, 40);
    displayList(head);

    printf("\n--- Deleting 20 (Last remaining node) ---\n");
    deleteNode(&head, 20);
    displayList(head);

    return 0;
}