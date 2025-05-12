#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void reverseList(ListNode* &ls) {
    ListNode* prev = nullptr;
    ListNode* nxt = ls;
    while (nxt != nullptr) {
        ListNode* sub = nxt->next;
        nxt->next = prev;
        prev = nxt;
        nxt = sub;
    }
    ls = prev;
}
ListNode* addTwoNumbers(ListNode* l1,ListNode* l2){
    ListNode* result= new ListNode(0);
    reverseList(l1);
    reverseList(l2);
    ListNode* temp=l1;
    ListNode* temp1=l2;
    ListNode* res=result;
    int carry=0;
    while(temp!=nullptr&&temp1!=nullptr){
        ListNode* nw=new ListNode((temp->val+temp1->val+carry)%10);
        res->next=nw;
        res=res->next;        
        carry=(temp->val+temp1->val+carry)/10;
        temp=temp->next;
        temp1=temp1->next;
    }
    if(temp!=nullptr){
        while(temp!=nullptr){
        ListNode* nw=new ListNode((temp->val+carry)%10);
        res->next=nw;
        res=res->next;
        carry=(temp->val+carry)/10;
        temp=temp->next;
        }
    }
    else if(temp1!=nullptr){
        while(temp1!=nullptr){
            ListNode* nw=new ListNode((temp1->val+carry)%10);
            res->next=nw;
            res=res->next;
            carry=(temp1->val+carry)/10;
            temp1=temp1->next;
            }
    }
    if(carry!=0){
        ListNode* nw=new ListNode(carry);
        res->next=nw;
    }
    reverseList(result->next);
    return result->next;
}


int main() {
    // Example linked list 1: 2 -> 4 -> 3 (represents 243)
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(9);
    l1->next->next = new ListNode(9);

    // Example linked list 2: 5 -> 6 -> 4 (represents 465)
    ListNode* l2 = new ListNode(0);
    l2->next = new ListNode(0);
    l2->next->next = new ListNode(1);

    // Add the two numbers
    ListNode* result = addTwoNumbers(l1, l2);

    // Print the result list (should represent 807: 7 -> 0 -> 8)
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}