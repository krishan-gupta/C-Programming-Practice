#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Global pointers for the queue
struct Node *front = NULL;
struct Node *rear = NULL;

// Function to add an element to the circular queue
void enqueue(int value)
{
    // Create a new node
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    // Check if memory allocation failed
    if (newNode == NULL)
    {
        printf("Memory allocation failed! Queue is full.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    // If the queue is empty
    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
        newNode->next = front; // Point back to itself to make it circular
    }
    else
    {
        // Add to the end and update the rear pointer
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Link the new rear back to the front
    }
    printf("Enqueued: %d\n", value);
}

// Function to remove an element from the circular queue
void dequeue()
{
    // Check for underflow
    if (front == NULL)
    {
        printf("Queue Underflow! The queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    int dequeuedValue = temp->data;

    // If there is only one node in the queue
    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        // Move front to the next node and update the rear's next pointer
        front = front->next;
        rear->next = front;
    }

    free(temp); // Free the memory of the removed node
    printf("Dequeued: %d\n", dequeuedValue);
}

// Function to display the elements in the circular queue
void display()
{
    // Check if empty
    if (front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }

    struct Node *temp = front;
    printf("Circular Queue: ");

    // Traverse the queue until we reach the front again
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != front);

    printf("(back to front)\n");
}

// Function to get the front element without removing it
void peek()
{
    if (front == NULL)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Front element is: %d\n", front->data);
    }
}

// Main function to test the queue
int main()
{
    printf("--- Circular Queue Operations ---\n");

    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    peek();

    dequeue();
    display();

    enqueue(40);
    enqueue(50);
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue(); // This should trigger Underflow

    return 0;
}