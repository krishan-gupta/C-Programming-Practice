#include<stdio.h>
#include<string.h>


int main(){
    char word[100];
    char pali[100];
    printf("Enter the word: ");
    scanf("%s",word);
    int len=strlen(word);
    for (int i=len-1, j=0 ; i>=0 && j<len ;i--,j++){
        pali[j]=word[i];
    }
    pali[len]='\0';
    
    if(strcmp(pali,word)==0){
        printf("It is Palindrome");
    }else{
        printf("It is not a Palindrome");
    }
}