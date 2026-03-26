#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
    int height;
};

int height(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    return node->height;
}

struct node *createnode(int value)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->height = 1;

    return newnode;
}

int getbalance(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }

    return height(node->left) - height(node->right);
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

struct node *rightrotate(struct node *y)
{
    struct node *x = y->left;
    struct node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

struct node *leftrotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL)
    {
        return createnode(key);
    }

    if (key < node->data)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->data)
    {
        node->right = insert(node->right, key);
    }
    else
    {
        return node;
    }

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getbalance(node);

    // LL
    if (balance > 1 && key < node->left->data)
        return rightrotate(node);

    // RR
    if (balance < -1 && key > node->right->data)
        return leftrotate(node);

    // LR
    if (balance > 1 && key > node->left->data)
    {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    // RL
    if (balance < -1 && key < node->right->data)
    {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

int main()
{
    struct node *node = NULL;
    node = insert(node, 10);
    node = insert(node, 20);
    node = insert(node, 30);
    node = insert(node, 40);

    inorder(node);
}