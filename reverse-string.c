#include <stdio.h>
#include <string.h>

int main() {
    char word[] = "krishan";
    int n = strlen(word);
    int start=0;
    int end=n-1;
    char temp;

    while(start<end){
        temp = word[start];
        word[start]=word[end];
        word[end]=temp;

        start++;
        end--;
    }
    printf("%s\n", word);
    return 0;
}