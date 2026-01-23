#include<stdio.h>

void reverse(int *p , int n){
    int *start= p;
    int *end = p+ n-1;
    int temp;

    while (start<end){
        temp = *start;
        *start = *end;
        *end= temp;

        start++;
        end--;
    }
}

int main() {
    int arr[] = {5, 10, 15, 20, 25, 30, 35};
    int n = sizeof(arr) / sizeof(arr[0]);

    reverse(arr, n);

    for (int i = 0; i < n; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}