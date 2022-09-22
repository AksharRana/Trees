#include<iostream>
#include<stack>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};
void zigzagtraversal(Node*root){
    stack<Node*>currlvl;
    stack<Node*>nextlvl;
    bool lefttoRight=true;
    currlvl.push(root);
    while(!currlvl.empty()){
        Node*temp=currlvl.top();
        currlvl.pop();
        if(temp){
            cout<<temp->data<<" ";
            if(lefttoRight){
                if(temp->left){
                nextlvl.push(temp->left);
                }
                 if(temp->right){
                nextlvl.push(temp->right);
                }
            }
            else{
                if(temp->right){
                    nextlvl.push(temp->right);
                }
                 if(temp->left){
                     nextlvl.push(temp->left);
                }
            }
        }
        if(currlvl.empty()){
            lefttoRight=!lefttoRight;
            swap(currlvl,nextlvl);
        }
    }
 }

int main(){
    Node*root=new Node(12);
    root->left=new Node(9);
    root->right=new Node(15);
    root->left->left=new Node(5);
    root->left->right=new Node(10);
    zigzagtraversal(root);
    return 0;
}