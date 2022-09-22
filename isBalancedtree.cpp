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
int height(Node*root){
    if(root==NULL){
        return 0;
    }
    int lh,rh;
    lh=height(root->left);
    rh=height(root->right);
    return max(lh,rh)+1;
}
bool isBalanced(Node*root){
    if(root==NULL){
        return true;
    }
    if(!isBalanced(root->left)){
        return false;
    }
     if(!isBalanced(root->right)){
        return false;
    }
    int lh,rh;
    lh=height(root->left);
    rh=height(root->right);
    if(abs(lh-rh)<=1){
        return true;
    }
    return false;
}
int Height(Node*root){
    if(root==NULL){
        return 0;
    }
    int lh=Height(root->left);
    int rh=Height(root->right);
    return max(lh,rh)+1;
}
bool isBalanceddd(Node*root,int* height){
    if(root==NULL){
        return true;
    }
    int lh=0,rh=0;
    lh=Height(root->left);
    rh=Height(root->right);
    if(isBalanceddd(root->left,&lh)==false){
        return false;
    }
    if(isBalanceddd(root->left,&lh)==false){
        return false;
    }
    *height=max(lh,rh)+1;
    if(abs(lh-rh)<=1){
        return true;
    }
    return false;
}
int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->left->left=new Node(3);
    // root->right=new Node(3);
    // root->left->left=new Node(4);
    // root->left->right=new Node(5);
    // root->right->left=new Node(6);
    // root->right->right=new Node(7);
    int height=0;
    if(isBalanceddd(root,&height)){
        cout<<"Balanced tree\n";
    }else{
        cout<<"UnBalanced tree\n";
    }
    return 0;
}