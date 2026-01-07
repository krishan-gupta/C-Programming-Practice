#include<stdio.h>
int main(){
    int n ,low , high,target,found=0 ;
    printf("Enter number of elements in array:\n");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d of array:",i+1);
        scanf("%d",&arr[i]);
    }
    printf("Enter the Target number: \n");
    scanf("%d",&target);
    low = 0;
    high = n-1 ;
    while(low<=high){
        int mid = (high + low)/2;
        if (arr[mid]==target){
            printf("Element found at index %d",mid);
            found =1;
            break;
        }
        else if(target<arr[mid]){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    if (found==0){
        printf("Element not found");
    }
    return 0;
}
