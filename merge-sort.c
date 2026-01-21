//merge sort
#include <stdio.h>

/* Function to merge two sorted halves */
void merge(int arr[], int left, int right){
    int mid = (left+right)/2;
    int n1 = mid - left+1;
    int n2 = right - mid;
    int l[n1];
    int r[n2];

    for(int i=0;i<n1;i++){
        l[i]=arr[left+i];
    }

    for (int j=0;j<n2;j++){
        r[j]=arr[mid+j+1];
    }

    int i=0;
    int j=0;
    int k=left;

    while(i<n1 && j<n2){
        if(l[i]<=r[j]){
            arr[k]=l[i];
            i++;
        }else{
            arr[k]=r[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k]=l[i];
        i++;
        k++;
    }
    
    while(j<n2){
        arr[k]=r[j];
        j++;
        k++;
    }

}

/* Function to implement Merge Sort */
void mergeSort(int arr[], int left, int right)
{
    if (left < right){
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, right);
    }
}

/* Main function */
int main(){
    int arr[] = {8, 3, 5, 2, 7,2,5,6,8};
    int n = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, n - 1);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
