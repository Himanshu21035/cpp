#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

struct process{
    char id;
    int arrivalTime;
    int burstTime;
    int priority;
    process(char i, int a, int b, int p): id(i), arrivalTime(a), burstTime(b), priority(p){}
};

struct comparePriority{
    bool operator()(process const& p1, process const& p2){
        if(p1.priority==p2.priority){
            return p1.arrivalTime>p2.arrivalTime;
        }   
        return p1.priority<p2.priority;
    }
};
void priorityPreemptive(vector<process> &p){
    int size = p.size();
    int i = 0;
    int clk = 0;
    priority_queue<process, vector<process>, comparePriority> pq;
    sort(p.begin(), p.end(), [](process const& p1, process const& p2){
        return p1.arrivalTime<p2.arrivalTime;
    });
    int total = 0;
    int j=0;
    for(process pr:p){
        total+=pr.burstTime;
    }
    cout<<"Name"<<"Burst"<<"Arrival"<<endl;
    vector<pair<char,int>> completionTime;
    while(i<total){
        if(i<total&& p[j].arrivalTime<=clk){
            pq.push(p[j]);
            j++;
        }

        if(!pq.empty()){
            process curr=pq.top();
            pq.pop();
            if(curr.burstTime>0){
                curr.burstTime--;
                cout<<curr.id<<"   "<<curr.burstTime<<"     "<<curr.arrivalTime<<endl;
                if(curr.burstTime==0){
                    completionTime.push_back(make_pair(curr.id,clk+1));
                }
                else{
                    pq.push(curr);
                }
            }
        }
        clk++;
        i++;
    }
    for(const auto& p:completionTime){
        cout<<p.first<<" "<<p.second<<endl;
    }

}
int main(){
    vector<process> p;
    p.push_back(process('a', 0, 10, 2));
    p.push_back(process('b', 3, 7, 1));
    p.push_back(process('c', 7, 1, 3));
    p.push_back(process('d', 8, 3, 4));
    priorityPreemptive(p);
    return 0;
}