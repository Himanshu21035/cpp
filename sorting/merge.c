// mergeSort
#include<stdio.h>
void merge(int arr[],int low,int mid,int high){
    int n1=mid-low+1;
    int n2=high-mid;
    int left[n1],right[n2];
    for (int i=0;i<n1;i++){
        left[i]=arr[low+i];
    }
    for(int j=0;j<n2;j++){
        right[j]=arr[mid+j+1];
    }
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }

}
void mergeSort(int arr[],int low,int high){
    if(low<high){
        int mid=low+(high-low)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int arr[20],n;
    printf("enter the size");
    scanf("%d",&n);
    printf("enter the elements of array");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

}