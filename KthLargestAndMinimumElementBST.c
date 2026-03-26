#include <stdio.h>
#include <stdlib.h>

// BST Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

// Create Node
struct Node *createNode(int value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// Insert in BST
struct Node *insert(struct Node *root, int value)
{
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

// GLOBAL COUNT (important)
int count = 0;

// Kth Smallest
void kthSmallest(struct Node *root, int k)
{
    if (root == NULL)
        return;

    kthSmallest(root->left, k);

    count++;
    if (count == k)
    {
        printf("Kth Smallest = %d\n", root->data);
        return;
    }

    kthSmallest(root->right, k);
}

// Kth Largest
void kthLargest(struct Node *root, int k)
{
    if (root == NULL)
        return;

    kthLargest(root->right, k);

    count++;
    if (count == k)
    {
        printf("Kth Largest = %d\n", root->data);
        return;
    }

    kthLargest(root->left, k);
}

// MAIN FUNCTION
int main()
{
    struct Node *root = NULL;

    // Build BST
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    int k;

    // Kth Smallest
    printf("Enter k for Kth Smallest: ");
    scanf("%d", &k);

    count = 0; // IMPORTANT RESET
    kthSmallest(root, k);

    // Kth Largest
    printf("Enter k for Kth Largest: ");
    scanf("%d", &k);

    count = 0; // IMPORTANT RESET
    kthLargest(root, k);

    return 0;
}