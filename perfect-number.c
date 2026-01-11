//Perfect Number is a number which is equal to the sum of its divisors
#include<stdio.h>
int main(){
    int num ,sum=0;
    printf("Enter the number :- \n");
    scanf("%d",&num);
    for(int i =1 ;i<num;i++){
        if (num%i==0){
            sum = sum +i ;
        }
    }
    (num == sum) ? printf("%d is a perfect number.\n", num) : printf("%d is not a perfect number.\n", num);
  
}