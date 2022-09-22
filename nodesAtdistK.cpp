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
void printsubtreenodes(Node*root,int K){
    if(root==NULL||K<0){
        return;
    }
    if(K==0){
        cout<<root->data<<" ";
        return;
    }
    printsubtreenodes(root->left,K-1);
    printsubtreenodes(root->right,K-1);
}
int nodesatK(Node*root,Node*target,int K){
    if(root==NULL){
        return -1;
    }
    if(root==target){
        printsubtreenodes(root,K);
        return 0;
    }
    int dl=nodesatK(root->left,target,K);
    if(dl!=-1){
        if(dl+1==K){
             cout<<root->data<<" ";
        }else{
            printsubtreenodes(root->right,K-dl-2);
        }
        return 1+dl;
    }
    int dr=nodesatK(root->right,target,K);
    if(dr!=-1){
        if(dr+1==K){
             cout<<root->data<<" ";
        }else{
            printsubtreenodes(root->left,K-dr-2);
        }
        return 1+dr;
    }
    return -1;
}
int main(){
    Node*root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    nodesatK(root,root->left,1);
    return 0;

} 