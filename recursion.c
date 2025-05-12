#include<stdio.h>
int apsum(int n){
   // int =a;
    if(n==0){
        return 0;
    }
    else{
        return apsum(n/2)+1;
    }
}
int main(){
    int a,d,n;
    // printf("enter the value of a");
    // scanf("%d",&a);
    // printf("enter the value of d");
    // scanf("%d",&d);
    printf("enter the value of n");
    scanf("%d",&n);
    //int l=a+(n-1)*d;
   int b= apsum(n);
   d=5/2;
   printf("%d, %d ",b,d);


}