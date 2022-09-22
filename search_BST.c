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

struct node* searchKey(struct node*root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    else if(root->data>key){
        return searchKey(root->left,key);
    }
    else{
        return searchKey(root->right,key);
    }
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
    struct node*ptr=searchKey(p,4);
    if (ptr==NULL)
    {
        printf("No such key is present in the tree\n");
    }
    else{
        printf("Yes %d is present in the tree\n",ptr->data);
    }
    return 0;
}
