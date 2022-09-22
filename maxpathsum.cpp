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
int maxpathsumUtil(Node*root,int&ans){
    if(root==NULL){
        return 0;
    }
    int left=maxpathsumUtil(root->left,ans);
    int right=maxpathsumUtil(root->right,ans);
    int Nodemax=max(max(root->data,root->data+left+right),max(root->data+right,root->data+left));
    ans=max(ans,Nodemax);
    int singlepathsum=max(root->data,max(root->data+left,root->data+right));
    return singlepathsum;
}
int maxPathsum(Node*root){
    int ans=INT_MIN;
    maxpathsumUtil(root,ans);
    return ans;
}
int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->right->right=new Node(5);
    cout<<maxPathsum(root);
}