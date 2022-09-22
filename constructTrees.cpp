#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int data;
    Node*left;
    Node*right;
    Node(int val){
        data=val;
    }
};
vector<Node*> constructTrees(int start,int end){
    vector<Node*> trees;
    if(start>end){
        trees.push_back(NULL);
        return trees;
    }
    for(int i=start;i<=end;i++){
        vector<Node*>leftsubtrees=constructTrees(start,i-1);
        vector<Node*>rightsubtrees=constructTrees(i+1,end);
        
        for(int j=0;j<leftsubtrees.size();j++){
            Node*left=leftsubtrees[j];
            for(int k=0;k<rightsubtrees.size();k++){
                Node*right=rightsubtrees[k];
                Node*node=new Node(i);
                node->left=left;
                node->right=right;
                trees.push_back(node);
            }
        }
    }
    return trees;
}
void preorder(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
int main(){
    vector<Node*>totalTrees=constructTrees(1,3);
    for(int i=0;i<totalTrees.size();i++){
        cout<<(i+1)<<" : ";
        preorder(totalTrees[i]);
        cout<<endl;
    }
    return 0;
}
