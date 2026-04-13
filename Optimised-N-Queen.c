#include <stdio.h>

#define MAX 100

int board[MAX][MAX];

// Attack tracking arrays
int col[MAX] = {0};
int diag1[2 * MAX] = {0};
int diag2[2 * MAX] = {0};

// Print solution
void printBoard(int n)
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

// Backtracking
void solve(int row, int n)
{

    if (row == n)
    {
        printBoard(n);
        return;
    }

    for (int c = 0; c < n; c++)
    {

        if (col[c] == 0 &&
            diag1[row - c + n - 1] == 0 &&
            diag2[row + c] == 0)
        {

            // Place queen
            board[row][c] = 1;
            col[c] = 1;
            diag1[row - c + n - 1] = 1;
            diag2[row + c] = 1;

            solve(row + 1, n);

            // BACKTRACK
            board[row][c] = 0;
            col[c] = 0;
            diag1[row - c + n - 1] = 0;
            diag2[row + c] = 0;
        }
    }
}

int main()
{
    int n = 8;

    solve(0, n);

    return 0;
}