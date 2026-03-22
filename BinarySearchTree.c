#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node *insert(struct node *root, int value)
{
    if (root == NULL)
    {
        return createnode(value);
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }

    return root;
}

// inorder prints the sorted order
void inorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d  ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    printf("%d  ", root->data);
}

struct node *search(struct node *root, int key)
{
    if (root == NULL || root->data == key)
    {
        return root;
    }

    if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}

struct node *findmin(struct node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

struct node *deletenode(struct node *root, int key)
{
    if (root == NULL)
    {
        return root;
    }
    if (key < root->data)
    {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = deletenode(root->right, key);
    }

    // node found
    else
    {
        if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            struct node *temp = findmin(root->right);
            root->data = temp->data;
            root->right = deletenode(root->right, temp->data);
        }
    }

    return root;
}
int main()
{
    struct node *root = createnode(20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 60);
    insert(root, 70);
    insert(root, 80);

    inorder(root);
}