#include<bits/stdc++.h>
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
class Info{
    public:
    int size;
    int min;
    int max;
    int ans;
    bool IsBST;
};
Info largestBSTinBT(Node*root){
    if(root==NULL){
        return{0,INT_MAX,INT_MIN,0,true};
    }
    if(root->left==NULL&&root->right==NULL){
        return{1,root->data,root->data,1,true};
    }

    Info left=largestBSTinBT(root->left);
    Info right=largestBSTinBT(root->right);

    Info curr;
    curr.size=1+max(left.size,right.size);

    if(left.IsBST&&right.IsBST&&left.max<root->data&&right.min>root->data){
        curr.ans=curr.size;
        curr.min=min(left.min,min(right.min,root->data));
        curr.max=max(left.max,max(right.max,root->data));
        curr.IsBST=true;
        return curr;
    }
    curr.ans=max(left.ans,right.ans);
    curr.IsBST=false;
    return curr;
}
int main(){
    Node*root=new Node(15);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(2);
    cout<<"largest size of BST in BT is : "<<largestBSTinBT(root).ans;
    return 0;
}