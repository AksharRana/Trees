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
Node* LCA(Node*root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1||root->data==n2){
        return root;
    }
    Node*left=LCA(root->left,n1,n2);
    Node*right=LCA(root->right,n1,n2);
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    return root;
}
int distance(Node*root,int k,int dist){
    if(root==NULL){
        return -1;
    }
    if(root->data==k){
        return dist ;
    }
    int d=distance(root->left,k,dist+1);
    if(d!=-1){
        return d;
    }
    return distance(root->right,k,dist+1);
}
int distbtwnodes(Node*root,int n1,int n2){
    Node*lca=LCA(root,n1,n2);
    int d1=distance(lca,n1,0);
    int d2=distance(lca,n2,0);
    return d1+d2;
}
int main(){
  /*     5
        /  \
       3    6
      / \    \
     2   4    7
     */
    Node*root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(6);
    root->left->left=new Node(2);
    root->left->right=new Node(4);
    root->right->right=new Node(7);
    cout<<distbtwnodes(root,2,7);
    return 0;
}