#include <stdio.h>

int subset[100]; // to store current subset

void subsetSum(int arr[], int n, int index, int current_sum, int target, int size)
{

    // Case 1: Found solution
    if (current_sum == target)
    {
        printf("Subset: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", subset[i]);
        }
        printf("\n");
        return;
    }

    // Case 2: Stop conditions
    if (index == n || current_sum > target)
    {
        return;
    }

    // TAKE element
    subset[size] = arr[index];
    subsetSum(arr, n, index + 1, current_sum + arr[index], target, size + 1);

    // DON'T TAKE element
    subsetSum(arr, n, index + 1, current_sum, target, size);
}

int main()
{

    int arr[] = {3, 4, 5, 2};
    int n = 4;
    int target = 7;

    subsetSum(arr, n, 0, 0, target, 0);

    return 0;
}