#include<stdio.h>
int main(){
    int arr[]={10,10,20,30,40,50,30,40,50};
    int size = 9;
    int new[size];
    int n=0;
    for (int i=0 ; i<size ; i++){
        int isduplicate=0;

        for(int j=0;j<n;j++){
            if (arr[i]==new[j]){
                isduplicate=1;
                break;
            }
        }

        if (isduplicate==0){
                new[n]=arr[i];
                n++;
            }    
        
    }
    for (int k=0;k<n;k++){
        printf("%d\n",new[k]);
    }
}