#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }//input taken

    for( int i=n-1 ; i>=0 ; i--){
        int didswap=0;
        for( int j=0 ; j<=i-1 ;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j+1];
                arr[j+1]=arr[j];
                arr[j]= temp;
                didswap=1;
            }
        }
        if(didswap==0){
            break;
        }
        
    }
    
    //output taken
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
