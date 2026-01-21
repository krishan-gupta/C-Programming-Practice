#include <stdio.h>
void swap(int *a, int *b){
    int temp= *a;
    *a=*b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1; 
    int temp;       
    
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }

    swap(&arr[i+1],&arr[high]);

    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = partition(arr, low, high);

        quickSort(arr, low, mid - 1);
        quickSort(arr, mid + 1, high);
    }
}


int main() {
    int arr[13]={30,30,30,45,45,45,20,20,20,55,55,86,92};

    quickSort(arr, 0, 12);

    printf("\nSorted array: ");
    for (int i = 0; i < 12; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
