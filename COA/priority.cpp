#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Node {
public:
    int arrival;
    int burst;
    int priority;
    char name;
    Node* next;
    Node(int a, int b, int p, char n) {
        this->arrival = a;
        this->burst = b;
        this->priority = p;
        this->name = n;
        this->next = nullptr;
    }
};

class Queue {
public:
    vector<Node> v;
    int front;
    int back;

    Queue() {
        front = 0;
        back = 0;
    }

    void addToQueue(Node& n) {
        v.push_back(n);
        back++;
    }

    void deleteFromQ() {
        if (front < back) {
            v.erase(v.begin());
        }
        else{
            cout<<"Queue is empty:"<<endl;
        }
    }

    void printQueue() {
        for (int i = front; i < back; i++) {
            cout << "Arrival: " << v[i].arrival
                 << ", Burst: " << v[i].burst
                 << ", Priority: " << v[i].priority
                 << ", Name: " << v[i].name << endl;
        }
    }

    // void sortQueue() {
    //     int n = v.size();
    //     bool swapped;
    //     for (int i = front; i < n - 1; i++) {
    //         swapped = false;
    //         for (int j = front; j < n - i - 1; j++) {
    //             if (v[j].priority < v[j + 1].priority) {
    //                 swap(v[j], v[j + 1]);
    //                 swapped = true;
    //             }
    //         }
    //         if (!swapped) break;
    //     }
    // }
    void sortQueue() {
    sort(v.begin(), v.end(), [](const Node &a, const Node &b) {
        if (a.arrival != b.arrival)
            return a.arrival < b.arrival;  // Sort by arrival time first
        return a.priority > b.priority;  // Higher priority first
    });
}

    void implement() {
        
        int count = v[0].arrival + v[0].burst;
        cout << v[0].name << " " << v[0].arrival << endl;
        
        deleteFromQ();   
        sortQueue();     
        printQueue();
        while(v.size()>0){
            cout<<v[front].name<<" "<<count-v[front].arrival<<endl;
            count+=v[front].burst;
            deleteFromQ();

        }
    }
};

class PriorityBased {
public:
    Node* head;
    Node* tail;
    bool timeSwap;

    PriorityBased() {
        head = nullptr;
        tail = nullptr;
        timeSwap = true;
    }

    void addProcess(int a, int b, int p, char n) {
        Node* newNode = new Node(a, b, p, n);
        if (head == nullptr && tail == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void sortList() {
        Node* temp;
        Node* temp1;
        bool swapped;
        if (head == nullptr) return;
        do{
            swapped=false;
            temp=head;
            while(temp!=nullptr && temp->next!=nullptr){
                if(temp->arrival>temp->next->arrival){
                    swap(temp->arrival,temp->next->arrival);
                    swap(temp->burst,temp->next->burst);
                    swap(temp->priority,temp->next->priority);
                    swap(temp->name,temp->next->name);
                    swapped=true;
                }
                temp=temp->next;
            }
        }while(swapped);
    }
    Queue q;
    void putInQ(){
        Node* temp=head;
        while(temp!=nullptr){
            q.addToQueue(*temp);
            temp=temp->next;
        }
    }
    void printList(){
        Node* temp=head;
        while(temp!=nullptr){
            cout << "Arrival: " << temp->arrival
                 << ", Burst: " << temp->burst
                 << ", Priority: " << temp->priority
                 << ", Name: " << temp->name << endl;
                 temp=temp->next;
        }

    }
};

int main() {
    PriorityBased p;
    p.addProcess(1, 3, 2, 'a');
    p.addProcess(0, 5, 3, 'b');
    p.addProcess(4, 4, 1, 'd');
    p.addProcess(2, 6, 5, 'c');
    p.addProcess(6, 2, 4, 'e');
    cout<<"Before sorting: "<<endl;
    p.printList();
    p.sortList();
    cout<<"After sorting: "<<endl;
    p.printList();
    p.putInQ();
    cout<<"Queue before implementation: "<<endl;
    p.q.printQueue();
    p.q.implement();
    return 0;
}
