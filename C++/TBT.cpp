#include <iostream>
using namespace std;

struct node{
    char data;
    node *left;
    node *right;
    bool lthread;
    bool rthread;
}; 

class TBT{
    private:
    node *head, *root;
    node *makenode();
    public:
    TBT();
    void addnode();
    void inorder();
    void preorder();
};

node *TBT::makenode(){
    node *t = new(node);
    t->left = t->right = NULL;
    t->lthread = t->rthread = true;   //True == No child
    cout << "Enter the root data: " << endl;
    cin >> t->data;
    return t;
}

TBT::TBT(){
    root = NULL;
    head = new(node);
    head->left = head;
    head->right = head;
    head->lthread = head->rthread = true;
    head->data = '$';
}

void TBT::addnode(){
    node *temp, *parent = root;
    if(root == NULL){
        root = makenode();
        root->left = head;
        root->right = head;
        head->left = root;
        head->lthread = false;
        cout << "Root " << root->data << " is successfully created!!" << endl;
    }
    else{
        int n;
        while(true){
            cout << "Current node: " << parent->data << endl;
            cout << "1.Create/Move to left\n2.Create/Move to right\n3.Exit" << endl;
            cout << "Enter choice: " ;
            cin >> n;
            if(n==1){
                if(parent->lthread == true){
                    temp = makenode();
                    temp->left = parent->left;
                    temp->right = parent;
                    parent->left = temp;
                    parent->lthread = false;
                    cout << "Node " << temp->data << " is succesfully created!!" << endl;
                    break;
                }
                else{
                    parent = parent->left;
                }
            }
            else if(n == 3){
                break;
            }
            else{
                if(parent->rthread == true){
                    temp = makenode();
                    temp->right = parent->right;
                    temp->left = parent;
                    parent->right = temp;
                    parent->rthread = false;
                    cout << "Node " << temp->data << " is successfully created!!" << endl;
                    break;
                }
                else{
                    parent = parent->right;
                }
            }
        }
    }
}

void TBT::inorder(){
    node *temp = root;
    if(root == NULL){
        cout << "Tree is empty" << endl;
    }
    else{
        while(temp->lthread != true){
            temp = temp->left;
        }

        while(temp != head){
            cout << temp->data << " ";
            if(temp->rthread == true){
                temp = temp->right;
            }
            else{
                temp = temp->right;
                while(temp->lthread != true){
                    temp = temp->left;
                }
            }
        }
    }
}

void TBT::preorder(){
    node *temp = root;
    if(root == NULL){
        cout << "Tree is empty" << endl;
    }
    else{
        while(temp->lthread != true){
            cout << temp->data << " ";
            temp = temp->left;
        }
        cout << temp->data << " ";
        while(temp->right != head){
            if(temp->rthread == true){
                temp = temp->right;
                temp = temp->right;
                cout << temp->data << " ";
            }
            else{
                while(temp->lthread != true){
                    temp = temp->left;
                    cout << temp->data << " ";
                }
            }
        }
    }
}

int main(){
    TBT tree;
    int choice=0;
    while(choice < 4){
        cout << "1.Add Node\n2.Inorder Traversal\n3.Preorder traversal\n4.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
        switch(choice){
            case 1:{
                tree.addnode();
                break;
            }
            case 2:{
                cout << "Inorder traversal: ";
                tree.inorder();
                cout << endl;
                break;
            }
            case 3:{
                cout << "Preorder traversal: ";
                tree.preorder();
                cout << endl;
                break;
            }
        }
    }
    return 0;
}