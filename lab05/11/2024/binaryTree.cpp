#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node(int data) {
        this->val = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

class BST {
private:
    void traverseBST(Node* root) {
        if (root == nullptr) return;
        traverseBST(root->left);
        cout << root->val << " ";
        traverseBST(root->right);
    }

public:
    Node* root;

    BST() {
        root = nullptr;
    }

    void addNode(int val) {
        // If tree is empty, create the root node
        if (root == nullptr) {
            root = new Node(val);
        } else {
            // Insert node at the correct position
            Node* current = root;
            Node* parent = nullptr;

            while (current != nullptr) {
                parent = current;

                if (val < current->val) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }

            // Now, create a new node and attach it to the parent node
            Node* newNode = new Node(val);

            if (val < parent->val) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }
    }

    void traverse() {
        traverseBST(root);
    }
};

int main() {
    BST bst;
    bst.addNode(50);
    bst.addNode(30);
    bst.addNode(70);
    bst.addNode(20);
    bst.addNode(40);
    bst.addNode(80);

    bst.traverse();
}
