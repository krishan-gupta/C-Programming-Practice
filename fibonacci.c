#include<stdio.h>
int main(){
    int size;
    printf("Enter the number of digits to be printed :-");
    scanf("%d",&size);
    int arr[size];
    arr[0]=0;
    arr[1]=1;
    for (int i=2 ; i<size ; i++){
        arr[i]=arr[i-1]+arr[i-2];
    }
    for (int i=0 ; i<size ;i++){
        printf("%d\t",arr[i]);
    }
    return 0 ;

}