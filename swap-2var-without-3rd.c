#include<stdio.h>
int main(){
    int a,b;
    printf("Enter the value of a :- \n");
    scanf("%d",&a);
    printf("Enter the value of b :- \n");
    scanf("%d",&b);
    printf("The value of a and b before swapping are respectively %d and %d \n",a,b);
    a = a+b;
    b = a-b ;
    a = a - b;
    printf("The value of a and b after swapping are respectively %d and %d",a,b);
}