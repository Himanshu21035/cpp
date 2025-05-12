#include<iostream>
using namespace std;
class queue{
    public:
    int front;
    int rear;
    int arr[30];
    queue(){
        front=0;
        rear=-1;
    }
};
int push(int val,queue* q){
    if(q->rear>=10){
        cout<<"queue is full"<<endl;
        return -1;
    }
    else{
        q->rear=q->rear+1;
        q->arr[q->rear]=val;
    }
}
int pop(queue* q){
    if(q->rear==-1){
        cout<<"Queue is empty"<<endl;
    }
    else{
        q->front=q->front+1;
    }
}
int main(){
    queue q=queue();
    push(10,&q);
    push(20,&q);
    push(30,&q);
    pop(&q);
    // cout<<q.front<<endl;
    for(int i=q.front;i<=q.rear;i++){
        cout<<q.arr[i]<<endl;
    }
}