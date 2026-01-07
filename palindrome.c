int main(){
    int n , orignal , remainder,new_num=0 ;
    printf("Enter the number:");
    scanf("%d",&n);
    orignal = n;
    while (n!=0){
        remainder = n%10;
        new_num = new_num*10 + remainder;
        n = n/10;
    }
    printf("%d",new_num);
    return 0 ;
}
