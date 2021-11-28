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
    node *insertBST(node*,int);
    void inorder(node *);
    void preorder(node *);
    void postorder(node *);
    node *search(node*, int);
    node *Delete(node*,int);
    node *inorderSucc(node *);
    void disleaf(node *);
    void mirror(node *);
    node *copy(node *);
};

node *BST::copy(node *root){
    /*
    if(root==NULL){
        return;
    }
    */
    node *n;
    n->data = root->data;
    n->left = copy(root->left);
    n->right = copy(root->right);
    return n;
}

void BST::mirror(node *root){
    if(root == NULL){
        return;
    }
    else{
        node *temp;
        mirror(root->left);
        mirror(root->right);
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void BST::disleaf(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    if(root->left == NULL && root->right == NULL){
        cout << root->data << " "; 
    }
    inorder(root->right);
}

void BST::postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " "; 
}

void BST::preorder(node *root){
    if(root == NULL){
        return; 
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

node *BST::inorderSucc(node *root){
    node* curr = root;
    while(curr->left && curr->right == NULL){
        curr = curr->left;
    }
    return curr;
}


node *BST::Delete(node *root, int key){
    if(key < root->data){
        root->left = Delete(root->left,key);
    }
    else if(key > root->data){
        root->right = Delete(root->right,key);
    }
    else{
        if(root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }
        node *temp = inorderSucc(root->right);
        root->data = temp->data;
        root->right = Delete(root->right,temp->data);
    }
    return root;
}

node *BST::search(node *root, int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data == key){
        return root;
    }
    if(root->data > key){
        return search(root->left,key);
    }
    return search(root->right,key);
}

node *BST::insertBST(node *root, int data){
    if(root == NULL){
        return new node(data); 
    }
    if(data < root->data){
        root->left = insertBST(root->left,data);
    }
    else{
        root->right = insertBST(root->right,data);
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
    node *root = NULL;
    int a, num;
    while(a<10){
        cout << "1.Insert\n2.Delete\n3.Inorder\n4.Preorder\n5.Postorder\n6.Search\n7.Display leaf nodes\n8.Mirror of tree\n9.Copy tree\n10.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> a;
        switch(a){
        case 1:{
            cout << "Enter the integer to insert: " << endl;
            cin >> num;
            root = b.insertBST(root,num);
            b.inorder(root);
            break;
        }
        case 2:{
            cout << "Enter the integer to delete:  " << endl;
            cin >> num;
            b.Delete(root,num);
            break;
        }
        case 3:{
            cout << "Inorder Traversals: " << endl;
            b.inorder(root);
            break;
        }
        case 4:{
            cout << "Preoder Traversals: " << endl;
            b.preorder(root);
            break;
        }
        case 5:{
            cout << "Postorder Traversals: " << endl;
            b.postorder(root);
            break;
        }
        case 6:{
            cout << "Enter the integer to search: " << endl;
            cin >> num;
            b.search(root,num);
            break;
        }
        case 7:{
            b.disleaf(root);
            break;
        }
        case 8:{
            b.mirror(root);
            break;
        }
        case 9:{
            b.copy(root);
            break;
        }
        default:
            cout << "Enter a valid choice";
            break;
        }
    }
}                        