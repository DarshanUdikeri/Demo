#include <iostream>
using namespace std;
struct treenode{
    int data;
    treenode *left;
    treenode *right;
};
class bt{
    treenode *root;
    public:
    bt(){
        root=NULL;
    }
    int isempty(){
        return (root==NULL);
    }
    void insert(int item);
    void display();
    void print(treenode *node);
    void inorder_seq();
    void inorder(treenode *);
    void postorder_seq();
    void postorder(treenode *);
    void preorder_seq();
    void preorder(treenode *);
    void display_leaf();
    void displeaf(treenode *);
};

void bt::insert(int item){
    treenode *p = new treenode;
    treenode *parent;
    p->data = item;
    p->left = NULL;
    p->right = NULL;
    parent = NULL;
    if(isempty()){
        root = p;
    }
    else{
        treenode *ptr;
        ptr = root;
        while(ptr!=NULL){
            parent = ptr;
            if(item>ptr->data){
                ptr = ptr->right;
            }
            else{
                ptr = ptr->left;
            }
        }
        if(item<parent->data){
            parent->left = p;
        }
        else{
            parent->right =p;
        }
    }
}

void bt::print(treenode *ptr){
    if(ptr!=NULL){
        print(ptr->left);
        cout<< " " << ptr->data << " ";
        print(ptr->right);
    }
}

void bt::display(){
    print(root);
}

void bt::inorder(treenode *ptr)
{
    if(ptr!=NULL){
        inorder(ptr->left);
        cout << " " << ptr->data << " ";
        inorder(ptr->right);
    }
}

void bt::inorder_seq()
{
    inorder(root);
}

void bt::postorder(treenode *ptr)
{
    if(ptr!=NULL){
        postorder(ptr->left);
        postorder(ptr->right);
        cout << " " << ptr->data << " ";
    }
}

void bt::postorder_seq()
{
    postorder(root);
}

void bt::preorder(treenode *ptr){
    if(ptr!=NULL){
        cout << " " << ptr->data << " ";
        preorder(ptr->left);
        preorder(ptr->right);
    }
}

void bt::preorder_seq(){
    preorder(root);
}

void bt::displeaf(treenode *ptr)
{
	if(ptr==NULL)
	{
		return;
	}
	inorder(ptr->left);
	if(ptr->left==NULL && ptr->right==NULL)
		cout<<ptr->data<<"";
	inorder(ptr->right);
}

void bt::display_leaf(){
    displeaf(root);
}


int main(){
    bt b;
    int a,num;
    
    while(a<7){
        cout << "\nEnter your choice: " << endl;
        cout << "1.Insert\n2.Print\n3.Inorder sequence\n4.Postorder sequence\n5.Preorder Sequence\n6.Display leaf\n7.Exit" << endl;
        cin >> a;
        switch(a){
            case 1:{
                cout << "Enter the element to be added: ";
                cin >> num;
                b.insert(num);
                cout << "Elements in the tree are: " << endl;
                b.display();
                break;
            }
            case 2:{
                b.display();
                break;
            }
            case 3:{
                b.inorder_seq();
                break;
            }
            case 4:{
                b.postorder_seq();
                break;
            }
            case 5:{
                b.preorder_seq();
                break;
            }
            case 6:{
                b.display_leaf();
            }
        }
    }
}