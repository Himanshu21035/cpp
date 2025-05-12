#include<stdio.h>
int majority(int arr[], int n, int k){
    int count = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i] == k) count++;
        if(count > n/2) return 1;
    }
    return 0;
}
int main(){
    int n;
    printf("Enter  no. of elements in array : ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter all elements in array : ");
    for(int i=0 ; i<n ; i++) scanf("%d",&arr[i]);
    int k;
    printf("Enter a element to check whether it is majority element or not : ");
    scanf("%d",&k);
    int ans = majority(arr,n,k);
    if(ans==1) printf("Given element is majority element!!");
    else printf("Given element is not majority element!!");
}