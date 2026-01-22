#include<stdio.h>

void swap(int *a , int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int main(){
    int a= 5;
    int b= 7;
    printf("Value of a=%d and b=%d before swapping \n",a,b);
    swap(&a,&b);
    printf("Value of a=%d and b=%d after swapping",a,b);
}