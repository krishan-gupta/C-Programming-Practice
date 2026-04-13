#include <stdio.h>

#define MAX 100

// Function to check if safe to place queen
int isSafe(int board[MAX][MAX], int row, int col, int n)
{

    // Check column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col] == 1)
            return 0;
    }

    // Check upper-left diagonal
    int i = row - 1, j = col - 1;
    while (i >= 0 && j >= 0)
    {
        if (board[i][j] == 1)
            return 0;
        i--;
        j--;
    }

    // Check upper-right diagonal
    i = row - 1;
    j = col + 1;
    while (i >= 0 && j < n)
    {
        if (board[i][j] == 1)
            return 0;
        i--;
        j++;
    }

    return 1;
}

// Function to print solution
void printBoard(int board[MAX][MAX], int n)
{
    printf("\nSolution:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Backtracking function
void solve(int board[MAX][MAX], int row, int n)
{

    // Base case
    if (row == n)
    {
        printBoard(board, n);
        return;
    }

    // Try all columns
    for (int col = 0; col < n; col++)
    {

        if (isSafe(board, row, col, n))
        {

            // Place queen
            board[row][col] = 1;

            // Recurse
            solve(board, row + 1, n);

            // Backtrack
            board[row][col] = 0;
        }
    }
}

int main()
{
    int n = 4;
    int board[MAX][MAX] = {0};

    solve(board, 0, n);

    return 0;
}