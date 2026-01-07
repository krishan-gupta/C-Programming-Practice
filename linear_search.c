#include<stdio.h>
int main(){
    int n ;
    printf("Enter number of elements in array:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d of array:",i+1);
        scanf("%d",&arr[i]);
    }
    int target,found=0 ;
    printf("Enter target number :\n");
    scanf("%d",&target);
    for(int j=0;j<n;j++){
        if(arr[j]==target){
            printf("Target found at index %d\n",j);
            found=1;
            break;
        }
    }
    if (found==0){
        printf("No elements found");
    }else{
        printf("Element found");
    }
    return 0;
}
