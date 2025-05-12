#include<stdio.h>
int main(){
    int arr[]={4,3,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=1;i<n;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            int temp=arr[j-1];
            arr[j-1]=arr[j];
            arr[j]=temp;
            j--;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}