// quicksort
#include<stdio.h>
int partitionIndex(int arr[],int low,int high){
int pivot=low;
int l=low+1;
int h=high;
while(l<=h){
    while(arr[l]<=arr[pivot]){
        l++;
    }
    while(arr[h]>arr[pivot]){
        h--;
    }
    if(l<h){
        int temp=arr[l];
        arr[l]=arr[h];
        arr[h]=temp;
    }
}
int temp=arr[h];
arr[h]=arr[pivot];
arr[pivot]=temp;
return h;

}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=partitionIndex(arr,low,high);
        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}
int main(){
    int arr[10],n;
    printf("enter the size of array");
    scanf("%d",&n);
    printf("enter the values");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("sorted array");
    quicksort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}