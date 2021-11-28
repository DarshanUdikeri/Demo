#include<iostream>
using namespace std;

struct node{
    int data;
    node *left, *right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

class BST{
    public:
    node *insert(node *,int);
    void inorder(node *);

};

node *BST::insert(node *root,int data){
    if(root == NULL){
        return new node(data); 
    }
    if(data < root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
    return root;
}

void BST::inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    BST b;
    b.insert(root,5);
    b.insert(root,4);
}