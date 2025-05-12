#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void rvrse( vector<int>& v,int strt,int end){
    int i=strt;
    int j=end;
    while(i>j){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i--;
        j++;
    }
    
}
int main(){
    vector<int> v{1,6,2,3,7,4};
    int y=v.size();
    cout<<y<<endl;
    int k=6;
    if(k>=y){
        k=k%y;
    }
    rvrse( v,y-1,y-k);
    rvrse(v,y-k-1,0);
    rvrse(v,y-1,0);
    for(int i=0;i<y;i++){
        cout<<v[i]<<endl;
    }
}