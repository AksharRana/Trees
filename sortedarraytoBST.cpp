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
Node*sortedarraytoBST(int arr[],int start,int end){
    if(start>end){
        return NULL;
    }
    int mid=(start+end)/2;
    Node*root=new Node(arr[mid]);
    root->left=sortedarraytoBST(arr,start,mid-1);
    root->right=sortedarraytoBST(arr,mid+1,end);
    return root;
}
void preorderprint(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorderprint(root->left);
    preorderprint(root->right);
}
int main(){
    int arr[]={10,20,30,40,50};
    Node*root=sortedarraytoBST(arr,0,4);
    preorderprint(root);
    return 0;
}