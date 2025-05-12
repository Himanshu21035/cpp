#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* left;
    Node* right;
    Node(int v){
        this->val=v;
        this->left=this->right=nullptr;
    }
};
class BST{
private:
    void traverseBST(Node* root){
        if(root==nullptr){
            return;
        }
        else{
            traverseBST(root->left);
            cout<<root->val<<" ";
            traverseBST(root->right);
        }
    }
public:
    Node* root;
    void traverseInorder(){
        if(root==nullptr){
            return;
        }
        else{
            traverseBST(root->left);
            cout<<root->val<<" ";
            traverseBST(root->right);
        }
    }
    void traversePost(){
        if(root==nullptr){
            return;
        }
        else{
            traverseBST(root->left);
            
            traverseBST(root->right);
            cout<<root->val<<" ";
        } 
    }
    void traversePre(){
        if(root==nullptr){
            return;
        }
        else{
            cout<<root->val<<" ";
            traverseBST(root->left);            
            traverseBST(root->right);
        } 
    }
    BST(){
        this->root=nullptr;
    }
    void addBST(int val){
        if(root==nullptr){
            Node* x =new Node(val);
            root=x;
        }
        else{
           Node* curr=root;
           Node* aft=nullptr;
           if(val==curr->val){
            return;
           }
        //    else if(val<curr->val){
        //     aft=curr;
        //     curr=curr->left;
        //    }
        //    else{
        //     aft=curr;
        //     curr=curr->right;
        //    }
           while(curr!=nullptr){
            if(val==curr->val){
                return;
            }
            else if(val<curr->val){
                aft=curr;
                curr=curr->left;
            }
            else{
                aft=curr;
                curr=curr->right;
            }
           }
           Node* y= new Node(val);
           if(val<aft->val){
            aft->left=y;
           }
           else{
            aft->right=y;
           }
        }
        
    }
    void traverse(){
        traverseBST(root);
    }
    void deleteNode(int val){
        if(root==nullptr){
            cout<<"empty tree"<<endl;

        }
        Node* ptr=root;
        Node* par=nullptr;
        Node* leftChild=nullptr;
        Node* rightChild=nullptr;
        if(val==root->val){
            leftChild=root->left;
            rightChild=root->right;
        }
        else if(val!=root->val){
            if(val<root->val){
                ptr=root->left;
                par=root;
            }
            else{
                ptr=root->right;
                par=root;
            }
            while(ptr!=nullptr && val!=ptr->val){
               if(val<ptr->val){
                par=ptr;
                ptr=ptr->left;                
            }
            else{
                par=ptr;
                ptr=ptr->right;                
            } 
            }
            if(ptr==nullptr){
                cout<<"element not found"<<endl;
            }
            else{
                leftChild=ptr->left;
                rightChild=ptr->right;
            }
        }
        if(leftChild==nullptr || rightChild==nullptr){
            if(leftChild!=nullptr){
                if(ptr==par->left){
                    par->left=leftChild;
                }
                else{
                    par->right=leftChild;
                }
            }
            else{
                if(ptr==par->left){
                    par->left=rightChild;
                }
                else{
                    par->right=rightChild;
                }
            }
        }
        else{
            Node* suc=ptr->right;
            Node* parsuc=ptr;
            while(suc->left!=nullptr){
                parsuc=suc;
                suc=suc->left;
            }
            int replace=suc->val;
            deleteNode(suc->val);
            ptr->val=replace;
        }
    }
};
int main(){
    BST b;
    b.addBST(60);
    b.addBST(25);
    b.addBST(75);
    b.addBST(66);
    b.addBST(15);
    b.addBST(50);
    b.addBST(33);
    b.addBST(26);
    b.addBST(44);
    // b.traverse();
    // b.deleteNode(25);
    // cout<<""<<endl;
    // b.traverse();
    b.traverseInorder();
    cout<<endl;
    b.traversePost();
    cout<<endl;
    b.traversePre();
}