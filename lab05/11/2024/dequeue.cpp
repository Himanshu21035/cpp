
#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* prev;
    Node* next;
    Node(int v){
        this->val=v;
        this->next=nullptr;
        this->prev=nullptr;
    }
};
class queue{
    public:
    Node* left=nullptr;
    Node* right=nullptr;
};
void pushAtFront(queue* q,int val){
    if(q->left==nullptr && q->right==nullptr){
        Node * x=new Node(val);
        // x->prev=nullptr;
        // x->next=nullptr;
        q->left=x;
        q->right=x;
    }
    else{
        Node* x= new Node(val);
        x->next=q->left;
        x->prev=nullptr;
        x->next->prev=x;
        q->left=x;
    }
}
void pushAtBack(queue*q,int val){
    if(q->left==nullptr && q->right==nullptr){
        Node * x=new Node(val);
        // x->prev=nullptr;
        // x->next=nullptr;
        q->left=x;
        q->right=x;
    }
    else{
        Node * x=new Node(val);
        x->prev=q->right;
        x->next=nullptr;
        q->right->next=x;
        q->right=x;
    }
}
void popAtFront(queue* q){
    if(q->left==nullptr && q->right==nullptr){
        cout<<"queue is empty";
    }
    if(q->left==q->right){
        q->left=nullptr;
        q->right=nullptr;
    }
    else{
        q->left->next->prev=nullptr;
        q->left=q->left->next;
    }
}
void popFromBack(queue*q){
    if(q->left==nullptr && q->right==nullptr){
        cout<<"queue is empty";
    }
    if(q->left==q->right){
        q->left=nullptr;
        q->right=nullptr;
    }
    else{
        q->right->next=nullptr;
        q->right=q->right->prev;
    }
}
void traverse(queue * q){
    Node* temp=q->left;
    while(temp!=nullptr){
        cout<<temp->val<<endl;
        
        temp=temp->next;
        // cout<<temp;
    }
}
void traverseBack(queue*q){
    Node* temp=q->right;
    while(temp!=nullptr){
        cout<<temp->val<<endl;
        temp=temp->prev;
    }
}
int main(){
    queue q;
    pushAtBack(&q,120);
    pushAtBack(&q,30);
    pushAtBack(&q,30);
    pushAtBack(&q,30);
    pushAtBack(&q,30);
    pushAtFront(&q,40);
    popFromBack(&q);
    popFromBack(&q);
    traverse(&q);
    cout<<"========";
    traverseBack(&q);
}