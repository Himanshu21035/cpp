#include<iostream>
#include<queue>
// #include<math.h>
#include<vector>
using namespace std;
struct Process{
    char name;
    int arrivalTime;
    int burstTime;
    Process(char n,int a, int b): name(n), arrivalTime(a),burstTime(b){}
};
struct compareArrival{
    bool operator()(const Process& p1,const Process& p2){
        return p1.arrivalTime>p2.arrivalTime;
    }
};

int main(){
    priority_queue<Process,vector<Process>,compareArrival>pq;
    pq.push(Process('a',1,2));
    pq.push(Process('b',2,5));
    pq.push(Process('c',5,10));
    pq.push(Process('d',4,8));
    pq.push(Process('e',3,1));
    cout<<"name"<<" Arrival"<<" Burst"<<endl;
    while(!pq.empty()){
        cout<<pq.top().name<<"    "<<pq.top().arrivalTime<<"       "<<pq.top().burstTime<<endl;
        pq.pop();
    }
}