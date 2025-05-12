#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct process{
    char name;
    int arrivalTime;
    int burstTime;
    process(char n,int a,int b): name(n),arrivalTime(a),burstTime(b){}
};
struct compareSJF{    //custom comparator
    bool operator()(const process& p1,const process& p2){
        if(p1.burstTime!=p2.burstTime){
            return p1.burstTime>p2.burstTime;
        }
        return p1.arrivalTime>p2.arrivalTime;
    }
};
void SJFscheduling(vector<process>& p){
    int clock=0;
    int count=p.size();

    priority_queue<process,vector<process>,compareSJF> pq;
    sort(p.begin(),p.end(),[](const process& p1,const process& p2){
        return p1.arrivalTime<p2.arrivalTime;
    });
    int i=0;
    while(i<count||!pq.empty()){
        while(i<count&&p[i].arrivalTime<=clock){
            pq.push(p[i]);
            i++;
        }
        if(!pq.empty()){
            process pro=pq.top();
            pq.pop();            
            cout<<"Name: "<<pro.name<<", arrival: "
            <<pro.arrivalTime<<", burst  "
            <<pro.burstTime<<", waiting"
            <<clock-pro.arrivalTime<<", turn"
            <<clock-pro.arrivalTime+pro.burstTime<<endl;
            clock+=pro.burstTime;
        }
        else{
            clock++;
        }
    }
}
int main(){
    vector<process> pro={
        process('a',0,10),
        process('b',3,7),
        process('c',7,1),
        process('d',8,3)
    };
    SJFscheduling(pro);
}