#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of integers:- \n");
    scanf("%d",&n);
    int *p;
    
    p = (int *)malloc(n*(sizeof(int)));
    if (p == NULL) {
        printf("Memory allocation failed");
        return 0;
    }

    printf("Enter the numers \n");
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    printf("The numbers are:- \n");
    for (int j=0;j<n;j++){
        printf("%d ",p[j]);
    }
    free(p);
}