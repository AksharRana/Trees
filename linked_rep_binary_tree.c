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
int main(){
    struct node*p;
    struct node*p1;
    struct node*p2;
    p=Createnode(2);
    p1=Createnode(1);
    p2=Createnode(4);
    p->left=p1;
    p->right=p2;
    return 0;
}