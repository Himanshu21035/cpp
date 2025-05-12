#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct Process{
    char name;
    int arrivalTime;
    int busrtTime;
    Process(char n,int a,int b): name(n),arrivalTime(a),busrtTime(b){}
};
struct compareArrival{
    bool operator()(const Process& p1,const Process& p2){
        return p1.arrivalTime>p2.arrivalTime;
    }
};
int main(){ 
    priority_queue<Process,vector<Process>,compareArrival>pq;
    pq.push(Process('a',0,2));
    pq.push(Process('b',4,3));
    pq.push(Process('c',1,1));
    pq.push(Process('d',2,4));
    pq.push(Process('e',6,5));
    cout<<"name"<<" Arrival"<<" Burst"<<" wait"<<" turnaround"<<endl;
    int cpuTime=pq.top().arrivalTime;
    while(!pq.empty()){
        cout<<pq.top().name<<"    "<<pq.top().arrivalTime<<"       "<<pq.top().busrtTime<<"    "<<cpuTime-pq.top().arrivalTime<<"       "<<cpuTime-pq.top().arrivalTime+pq.top().busrtTime<<endl;
        cpuTime=cpuTime+pq.top().busrtTime;
        pq.pop();
    }
}