#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*left;
    struct node*right;
};
struct node* Createnode(int data){
    struct node*n;
    n=(struct node*)malloc(sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL; 
    return n;
}
void inorder(struct node*root){
    if(root!=NULL){
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
    }
}
struct node*inorderPredecessor(struct node*root){
    root=root->left;
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
struct node*deletenode(struct node*root,int value){
    struct node*ipre;
    if(root==NULL){
        return NULL;
    }
    if(root->left==NULL && root->right==NULL){
        free(root);
        return NULL;
    }
    if(value<root->data){
        root->left=deletenode(root->left,value);
    }
    else if(value>root->data){
        root->right=deletenode(root->right,value);
    }
    else{
        ipre=inorderPredecessor(root);
        root->data=ipre->data;
        root->left=deletenode(root->left,ipre->data);
    }
    return root;
}
int main(){
    struct node*p;
    struct node*p1;
    struct node*p2;
    struct node*p3;
    struct node*p4;
    //          5
    //         /  \
    //        3    6
    //      /   \
    //     1     4
    p=Createnode(5);
    p1=Createnode(3);
    p2=Createnode(6);
    p3=Createnode(1);
    p4=Createnode(4);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
  
    inorder(p);
    deletenode(p,3);
    printf("\n");
    // printf("|Data is %d|\n",p->data);
    inorder(p);
    return 0;
}