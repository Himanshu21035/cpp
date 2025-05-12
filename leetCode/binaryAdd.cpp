#include<iostream>
#include<vector>
#include<string>
using namespace std;
char And(char a, char b){
    char ans;
    if(a=='1'&&b=='1'){
        ans='1';
    }
    else{
        ans='0';
    }
    return ans;
}
char Or(char a, char b, char c){
    char ans;
    if(a=='0'&&b=='0'&&c=='0'){
        ans='0';
    }
    else{
        ans='1';
    }
    return ans;
}
char Xor(char a, char b){
    char ans;
    if(a==b){
        ans='0';
    }
    else{
        ans='1';
    }
    return ans;
}
string addBinary(string a,string b){
    string ans;
    char c,x,y,z,k,t;
    c='0';
    
    while(a.size()!=b.size()){
        if(a.size()<b.size()){
            a='0'+a;
        }
        else{
            b='0'+b;
        }
    }
    // cout<<a<<" "<<b<<endl;
    int s=a.size()-1;
    while(s>=0){
        x=Xor(a[s],b[s]);
        y=Xor(c,x);
        cout<<y<<"  "<<c<<endl;
        ans=y+ans;
        z=And(a[s],b[s]);
        k=And(a[s],c);
        t=And(b[s],c);
        c=Or(z,k,t);   
        s--;     
    }
    if(c=='1'){
        ans=c+ans;
    }
    
    return ans;

}
int main(){
    string s1,s2,answer;
    s1="1";
    s2="111";
    answer=addBinary(s1,s2);
    cout<<"Answer is: "<<answer;
}