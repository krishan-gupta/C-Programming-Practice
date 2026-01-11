//armstrong number is a number which is equal to cube of each digit of a number

#include<stdio.h>
int main(){
    int num ,remain,new_num=0,temp;
    printf("Enter the number :");
    scanf("%d",&num);
    temp=num;
    while (temp>0) {
        remain = temp%10;
        temp = temp/10;
        new_num = new_num + remain*remain*remain;
    }
    (num == new_num) ? printf("Is a armstrong number.\n") : printf("Is not a armstrong number.\n");
}