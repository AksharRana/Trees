#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        left=NULL;
        right=NULL;
    }
};
int calcHeight(Node*root){
    if(root==NULL){
        return 0;
    }
    int lHeight=(calcHeight(root->left));
    int rHeight=(calcHeight(root->right));
    return max(lHeight,rHeight)+1;
}
// O(N^2) time complexity
int calcdiameter(Node*root){
    if(root==NULL){
        return 0;
    }
    int lHeight=calcHeight(root->left);
    int rHeight=calcHeight(root->right);
    int currdiameter=lHeight+rHeight+1;
    int ldiameter=calcdiameter(root->left);
    int rdiameter=calcdiameter(root->right);
    return max(currdiameter,max(ldiameter,rdiameter));
}
// O(N) time complexity
int calcdiameterrr(Node*root,int* Height){
     if(root==NULL){
        *Height=0;
        return 0;
    }
    int lh=0,rh=0;
    int ld=calcdiameterrr(root->left,&lh);
    int rd=calcdiameterrr(root->right,&rh);
    int currDiameter=lh+rh+1;
    *Height=max(lh,rh)+1;
    return max(currDiameter,max(ld,rd));
}
int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);
    root->right->left=new Node(6);
    root->right->right=new Node(7);
    // cout<<calcdiameter(root);
    int height=0;
    cout<<calcdiameterrr(root,&height);
    return 0;
}