#include<stdio.h>

int addnum(int a , int b);

int main(){
    printf("%d",addnum(5,6));
    return 0;
}

int addnum(int a , int b ){
    int result = a+b;
    return result ; 
}