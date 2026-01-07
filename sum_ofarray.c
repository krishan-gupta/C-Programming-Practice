#include <stdio.h>

int main(){
    int size,sum=0;
    printf("Enter the number of elements :");
    scanf("%d",&size);
    int arr[size];

    for(int i=0;i<size;i++){
        printf("Enter the element %d:",i+1);
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<size;i++){
        sum = sum + arr[i];
    }
    printf("The sum of the elements are:%d",sum);
    return 0;
}
