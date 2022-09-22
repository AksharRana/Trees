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
int main(){
    struct node*p;
    struct node*p1;
    struct node*p2;
    struct node*p3;
    struct node*p4;
    p=Createnode(4);
    p1=Createnode(1);
    p2=Createnode(6);
    p3=Createnode(5);
    p4=Createnode(2);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    inorder(p);
    return 0;
}