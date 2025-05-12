#include<iostream>
#include<vector>
using namespace std;
long long int findExpoTrad(int n,int pow){
    long long int ptr=1;
    for(int i=0;i<pow;i++){
        ptr*=n;
    }
    return ptr;
}
long long int findExpo(int n,int pow){
    if(pow==0) return 1;
    if(pow%2==0){
        int half= findExpo(n,pow/2);
        return half*half;
    }
    else{
        int half= findExpo(n,(pow-1)/2);
        return half*half*n;
    }
}
int main() {
    int n = 2;
    int pow = 10;

    cout << n << "^" << pow << " = " << findExpo(n, pow) << endl;
    
    return 0;
}