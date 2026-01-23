#include <stdio.h>

int sum(int *a , int *b){
    return (*a+*b);
}

int main(){
    int a = 5;
    int b = 6;
    printf("The sum is %d",sum(&a,&b));
}