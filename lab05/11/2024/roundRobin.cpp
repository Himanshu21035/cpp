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

void roundRobin(vector<process> &p,int timeQuantum){
    int size = p.size();
    int i = 0;
    int clk = 0;
    // priority_queue<process, vector<process>, comparePriority> pq;
    queue<process> pq;
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
        while(i<total&& p[j].arrivalTime<=clk+timeQuantum &&j<size){
            pq.push(p[j]);
            j++;
        }
        // printQueue(pq);
        if(!pq.empty()){
            process curr=pq.front();
            pq.pop();
            if(curr.burstTime>0){
                if(curr.burstTime-timeQuantum>=0){
                    curr.burstTime=curr.burstTime-timeQuantum;
                    cout<<curr.id<<"   "<<curr.burstTime<<"     "<<curr.arrivalTime<<endl;
                    i=i+timeQuantum;
                    clk=clk+timeQuantum;
                    // pq.push(curr);
                }
                else{
                    curr.burstTime--;
                    cout<<curr.id<<"   "<<curr.burstTime<<"     "<<curr.arrivalTime<<endl;
                    i++;
                    clk++;
                }
                if(curr.burstTime==0){
                    completionTime.push_back(make_pair(curr.id,clk));
                }
                else{
                    pq.push(curr);
                }
            }
        }
        // clk++;
        // i++;
    }
    for(const auto& p:completionTime){
        cout<<p.first<<" "<<p.second<<endl;
    }

}
int main(){
    vector<process> p;
    p.push_back(process('a', 5, 5, 2));
    p.push_back(process('b', 4, 6, 1));
    p.push_back(process('c', 3, 7, 3));
    p.push_back(process('d', 1, 9, 4));
    p.push_back(process('e', 2, 2, 5));
    p.push_back(process('f', 6, 3, 6));
    roundRobin(p,2);
    return 0;
}