#include<stdio.h>
int main(){
    int arr[20],n,a,b;
    printf("enter the number of elements");
    scanf("%d",&n);
    printf("enter the elements in array ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);

    }
    printf("enter the value of sum");
    scanf("%d",&a);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n&&j!=i;j++){
            if((arr[i]+arr[j])==a){
                printf("%d %d\n",arr[i],arr[j]);
            }
        }
    }
    return 0;
}