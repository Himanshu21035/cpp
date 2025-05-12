#include<iostream>
#include<utility>
using namespace std;
class Node{
    public:
    int val;
    Node* next;
    Node(int data){
        this->val=data;
        this->next=NULL;
    }
};

std::pair<Node*, Node*> findLoc(Node* Head, int value) {
    cout << "function called" << endl;

    // Check if the list is empty
    if (Head == nullptr) {
        return std::make_pair(nullptr, nullptr);
    }

    Node* temp = Head;
    Node* nxt = temp->next;
    Node* Loc = nullptr;
    Node* Locp = nullptr;

    // Special case: If the head node itself has the target value
    if (Head->val == value) {
        Loc = Head;
        return std::make_pair(Loc, nullptr); // No previous node for the head
    }

    // Traverse the list and find the node
    while (nxt != nullptr) {
        if (nxt->val == value) {
            Loc = nxt;      // The node containing the value
            Locp = temp;    // The predecessor node
            return std::make_pair(Loc, Locp);
        }
        temp = nxt;
        nxt = nxt->next;
    }

    // If the value wasn't found, return nullptr for both
    return std::make_pair(nullptr, nullptr);
}

Node* deleteNode(Node* Head,int value){
    std::pair<Node*, Node*> result = findLoc(Head,value);
    Node* loc=result.first;
    Node* locp=result.second;
    if(loc==nullptr){
        cout<<"element not in list"<<endl;
        return Head;
    }
    if(locp==nullptr){
        Head=Head->next;
        return Head;
    }
    else{
        locp->next=loc->next;
        return Head;
    }

}

void traverse(Node* temp){
    while(temp!=nullptr){
        cout<<temp->val<<endl;
        temp=temp->next;
    }
}
int main(){
    Node * a= new Node(5);
    Node* b=new Node(10);
    Node * c=new Node(20);
    Node* d=new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    traverse(a);
    a=deleteNode(a,20);
   
    traverse(a);
}