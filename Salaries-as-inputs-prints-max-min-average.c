#include<stdio.h>
// You are using GCC
void inputSalaries(int salaries[] ,int  n){
    for (int i=0;i<n;i++){
        scanf("%d",&salaries[i]);
    }
}

void displaySalaries(int salaries[] ,int n){
    for (int i=0;i<n;i++){
        printf("Employee %d: %d\n",i+1,salaries[i]);
    }
}

double calculateAverage(int salaries[] ,int n){
    double sum=0;
    for (int i=0;i<n;i++){
        sum = sum + salaries[i];
    }
    return sum/n ;
}

int  findMaxSalary(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int findMinSalary(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

int main(){
    int n;
    scanf("%d", &n);

    int salaries[n];

    inputSalaries(salaries, n);
    displaySalaries(salaries, n);
    
    printf("\nAverage Salary: %.2f\n", calculateAverage(salaries, n));
    printf("Highest Salary: %d\n", findMaxSalary(salaries, n));
    printf("Lowest Salary: %d\n", findMinSalary(salaries, n));

    return 0;
}
