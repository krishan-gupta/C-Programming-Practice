#include <stdio.h>

int maxProfit = 0;

// Backtracking function
void knapsack(int index, int n, int weight[], int value[], int capacity, int currWeight, int currValue)
{

    // Base case
    if (index == n)
    {
        if (currValue > maxProfit)
            maxProfit = currValue;
        return;
    }

    // 1. Don't take item
    knapsack(index + 1, n, weight, value, capacity, currWeight, currValue);

    // 2. Take item (if possible)
    if (currWeight + weight[index] <= capacity)
    {
        knapsack(index + 1, n, weight, value, capacity,
                 currWeight + weight[index],
                 currValue + value[index]);
    }
}

int main()
{

    int n = 3;
    int weight[] = {1, 2, 3};
    int value[] = {10, 15, 40};
    int capacity = 5;

    knapsack(0, n, weight, value, capacity, 0, 0);

    printf("Maximum Profit = %d\n", maxProfit);

    return 0;
}
