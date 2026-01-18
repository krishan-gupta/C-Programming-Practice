#include <stdio.h>

int main() {
    int arr[] = {1,2,3,4,2,2,4,5,6,7,3,2,6,8,8,6,6,8,9,5,4,6,4,9};
    
    int total_len = (sizeof(arr) / sizeof(arr[0]));
    int dup[total_len]; 
    int k = 0; 
    for (int i = 0; i < total_len; i++) {
        int is_dup = 0;
        for (int j = 0; j < k; j++) {
            if (arr[i] == dup[j]) {
                is_dup = 1;
                break;
            }
        }

        if (is_dup == 1) {
            continue; 
        } else {
            dup[k] = arr[i]; 
            k++;
        }
    }

    for (int i = 0; i < k; i++) {
        printf("%d ", dup[i]);
    }

    return 0;
}



/*
#include<stdio.h>
int len(arr);
int main(){
    int arr[] = {1,2,3,4,2,2,4,5,6,7,3,2,6,8,8,6,6,8,9,5,4,6,4,9};
    //elements are now stored in the array 
    int dup[len(arr)] ;
    for (int i=0 ; i<len(arr);i++){
        for (int j=0 ; j<len(dup) ;j++){
            if (arr[i]==arr[j]){
                continue;
            }else{
                arr[i]=arr[j];
            }
        }
    }
    for (int i=0 ;i<len(dup);i++){
        printf("%d",dup[i])
    }
}

int len(x){
    int n = (sizeof(x))/(sizeof(x[0])) ;
    return n;
}
    */