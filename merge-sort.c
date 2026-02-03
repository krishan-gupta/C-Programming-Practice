#include <stdio.h>

void merge(int arr[], int low, int mid, int high)
{
    int temp[high - low + 1];
    int left = low;
    int right = mid + 1;
    int k = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
            temp[k++] = arr[left++];
        else
            temp[k++] = arr[right++];
    }

    while (left <= mid)
        temp[k++] = arr[left++];

    while (right <= high)
        temp[k++] = arr[right++];

    for (int i = 0; i < k; i++)
        arr[low + i] = temp[i];
}


void mS(int arr[], int low, int high){
    if (low >= high){
        return;
    }

    int mid = (low + high) / 2;
    mS(arr, low, mid);
    mS(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

void mergeSort(int arr[], int n){
    mS(arr, 0, n - 1);
}


int main(){
    int arr[] = {8, 3, 5, 2, 7,2,5,6,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr,n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}

