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
int isBST(struct node*root){
    static struct node*prev=NULL;
    if(root!=NULL){
        if(!isBST(root->left)){
            return 0;
        }
        if(prev!=NULL && root->data<=prev->data){
            return 0;
        }
        prev=root;
        return isBST(root->right);
    }
    else{
        return 1;
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
    p2=Createnode(2);
    p3=Createnode(1);
    p4=Createnode(4);
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;
    inorder(p);
    printf("\n");
    if(isBST(p)){
        printf("Yes it is BST\n");
    }
    else{
        printf("It is not a BST\n");
    }
    return 0;
}