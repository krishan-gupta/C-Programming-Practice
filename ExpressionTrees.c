#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

struct Node *buildTree(char postfix[])
{
    struct Node *stack[100];
    int top = -1;

    for (int i = 0; postfix[i] != '\0'; i++)
    {

        if (isalnum(postfix[i]))
        {
            stack[++top] = createNode(postfix[i]);
        }
        else if (isOperator(postfix[i]))
        {
            struct Node *right = stack[top--];
            struct Node *left = stack[top--];

            struct Node *node = createNode(postfix[i]);
            node->left = left;
            node->right = right;

            stack[++top] = node;
        }
    }

    return stack[top];
}

void inorder(struct Node *root)
{
    if (root == NULL)
        return;

    if (isOperator(root->data))
        printf("(");

    inorder(root->left);
    printf("%c", root->data);
    inorder(root->right);

    if (isOperator(root->data))
        printf(")");
}

void preorder(struct Node *root)
{
    if (root == NULL)
        return;

    printf("%c ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%c ", root->data);
}

int main()
{
    char postfix[] = "AB+C*";

    struct Node *root = buildTree(postfix);

    printf("Infix: ");
    inorder(root);

    printf("\nPrefix: ");
    preorder(root);

    printf("\nPostfix: ");
    postorder(root);

    return 0;
}

// Inorder => Infix
// Preorder => Prefix
// Postorder => Postfix
