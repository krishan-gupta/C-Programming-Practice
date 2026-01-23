#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort(int *arr,int n){
    int i,j = 0;
    for( int i=0 ; i<n-1 ; i++){
        for(int j=0 ; j<n-1 ; j++){
            if( *(arr+j)> *(arr+j+1)){
                swap((arr+j),(arr+j+1));
            }
        }
    }
}



int main(){
    int arr[]={10,15,9,8,4,5,2,88,100};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,n);
    for(int i=0 ; i<n; i++){
        printf("%d\n",arr[i]);
    }

}
