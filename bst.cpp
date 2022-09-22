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
Node* searchBST(Node*root,int key)
{
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    if(root->data>key){
        return searchBST(root->left,key);
    }
    return searchBST(root->right,key);
}
void inorder(Node*root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
Node*inordersucc(Node*root){
    Node*curr=root;
    while(curr&&curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}
Node*deleteinBST(Node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data>key){
        root->left=deleteinBST(root->left,key);
    }
    else if(root->data<key){
        root->right=deleteinBST(root->right,key);
    }
    else{
        if(root->left==NULL){
            Node*temp=root->right;
            free(root);
            return temp;
        }
        if(root->right==NULL){
            Node*temp=root->left;
            free(root);
            return temp;
        }
        Node*temp=inordersucc(root->right);
        root->data=temp->data;
        root->right=deleteinBST(root->right,temp->data);
    }
    return root;
}
int main(){
    Node*root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(5);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(6);
    // if(searchBST(root,5)==NULL){
    //     cout<<"key doesn't exists\n";
    // }
    // else{
    //     cout<<"key exists\n";
    // }

    inorder(root);
    cout<<endl;
    root=deleteinBST(root,2);
    inorder(root);
    return 0;
}