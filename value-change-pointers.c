#include<stdio.h>

void change(int *a){
    *a = 10;
}

int main(){
    int a = 5;
    printf("The value of a before changing a: %d\n",a);
    change(&a);
    printf("The value of a after changing a: %d\n",a);
}