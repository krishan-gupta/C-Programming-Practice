#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }//input taken

    for( int i=0 ; i<=n-1 ;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp =arr[j-1];
            arr[j-1]= arr[j];
            arr[j]=temp;
            j--;
        }
    }
    
    //output taken
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
