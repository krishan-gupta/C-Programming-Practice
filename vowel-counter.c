#include <stdio.h>
#include <string.h>
#include<ctype.h>

int main() {
    int count= 0 , words=0;
    char str[100] ;
    printf("Enter the string : ");
    fgets(str,sizeof(str),stdin);
    for( int i=0; i<strlen(str) ;i++){
        if (isalpha(str[i])){
            words++;
        }
        if(str[i]=='A'||str[i]=='a'||str[i]=='e'||str[i]=='E'||str[i]=='I'||str[i]=='i'||str[i]=='O'||str[i]=='o'||str[i]=='U'||str[i]=='u'){
            printf("%c",str[i]);
            count++;
        }
    }
    printf("\nTotal words are: %d",words);
    printf("\nCount is :%d",count);
}