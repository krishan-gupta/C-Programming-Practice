#include<stdio.h>

int max(int *a, int *b){
    int max = (*a>*b)? (*a) : (*b);
    return max;
}

int main(){
    int a = 5;
    int b = 10;
    printf("The max value amongst a and b is: %d \n",max(&a,&b));
}