#include<iostream>
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
void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void flatten(Node*root){
    if(root==NULL||(root->left==NULL&&root->right==NULL)){
        return;
    }
    if(root->left!=NULL){
        flatten(root->left);
        Node*temp=root->right;
        root->right=root->left;
        root->left=NULL;
        Node*t=root->right;
        while(t->right!=NULL){
            t=t->right;
        }
        t->right=temp;
    }
    flatten(root->right);
}
   /*      4
         /   \ 
        9      5
      /   \     \
     1    3      6
   */     
int main(){
    Node*root=new Node(4);
    root->left=new Node(9);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);
    flatten(root);
    inorder(root);
    return 0;
}