#include<stdio.h>
int main(){
    int arr[20],k,threshold;
    int n;
    printf("enter the number of elements in array");
    scanf("%d",&n);
    printf("enter the elements in array ");
    for(int i =0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("enter the value of k");
    scanf("%d",&k);
    printf("enter the value of threshold");
    scanf("%d",&threshold);
    int i=0;
    int count=0;
    while(i<=(n-k)){
        int avg=0;
        int l=1;
        int j=i;
        int sum=arr[j];
        
        nxt:
           sum=sum+arr[j+l];
           l++;
        if(l<k){
            goto nxt;
        }
        avg=sum/k;
        printf("%d \n",avg);
        if(avg>=threshold){
            count++;
        }
        
        i++;
            
    }
    printf("\n %d",count);
}