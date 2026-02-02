#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }//input taken

    for(int i=0;i<n;i++){
        int min= i;
        for(int j=i;j<=n-1;j++){
            if(arr[j]<arr[min]){
                min = j;
            }
        }
        int temp = arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }

    //output taken
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}