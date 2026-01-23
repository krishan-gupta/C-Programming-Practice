#include<stdio.h>

int printing(int *p , int n){
    for ( int i=0 ; i<n;i++){
        printf("%d\n",*(p+i));
    }
}

int main(){
    int arr[]={5,10,15,20,25,30};
    int n = sizeof(arr)/sizeof(arr[0]);
    printing(arr,n);
}
