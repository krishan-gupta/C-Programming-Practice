// Program that takes a array filter even number from them and then print it in reverse form 
#include <stdio.h>

int main() {
    int size ;
    int n=0 ;

    printf("Enter the size of arr :\n");
    scanf("%d",&size);

    //size of array
    int arr[size];
    int r_arr[size];

    //taking values in array
    printf("Input Array Elements are: \n");
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    //Filtered Array Elements are

    printf("Array Elements are: \n");
    for(int i=0; i<size ;i++){
        if(arr[i]%2==0){
            printf("%d\t",arr[i]);
            r_arr[n]=arr[i];
            n++;
        }
    }
    //printing reverse
    printf("\nReverse Array Elements are: \n");
    for (int i=n ; i>0 ;i-- ){
        printf("%d\t",r_arr[i-1]);
    }
    return 0;
}
