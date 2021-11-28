#include<iostream>
using namespace std;
#define n 100

struct node{
    char data;
    node *left,*right;
    node* r();
};

class Stack{
    node *arr;
    int top;

    public:
    Stack(){
        node* arr[n];
        top =-1;
    }
    void push(node *t);
    void pop();
    bool isempty();
    int peep();
    void display();
};
void Stack::push(node *t){
    if(top==n-1){
        cout << "Stack overflow" << endl;
    }
    top++;
    arr[top] = t;
}

void Stack::pop(){
    if(top == -1){
        cout << "Stack underflow" << endl;
    }
    top--;
}

int Stack::peep(){
    if(top==-1){
        cout << "No elements in the stack" << endl;
    }
    return arr[top];
}

bool Stack::isempty(){
    return top==-1;
}

void Stack::display(){
	for(int i=0;i<=top;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
}

//Expression tree code starts 


class ET{
    char post[50];
    node *root;
    public:
    void input(int);
    node *getroot(){
        return root;
    }
    int validate(int);
    node *create();
    void inorder(node *t);
    void preorder(node *t);
    void postorder(node *t);
    node* inorder_nrec(node *t);
    node* postorder_nrec(node *t);
    node* preorder_nrec(node *t);
};

node* ET::preorder_nrec(node *t){
    node *p;
    if(t==NULL)
    {
        cout<<"Tree is empty";
    }
    p=t;
    do{
        while (p!=NULL)
        {
            cout<<" "<<p->data;
            s.push(p);
            p=p->left;
        }

        while(!isempty())
        {
           p=s.top();
           s.pop();
           p=p->right;
           while (p!=NULL)
           {
               cout<<" "<<p->data;
               s.push(p);
               p=p->left;
           }
           
        }
        
    }while(p!=NULL || top>0);
}

node* ET::postorder_nrec(node *t){
    node *p,*prev;
    if(t==NULL)
    {
        cout<<"Tree is empty";
    }
    push(t);
    while(!isempty())
    {
        p=s.top();
        s.pop();
        if(p->left==NULL && p->right==NULL)
        {
            prev=p;
            cout<<" "<<p->data;
        
        }
        else
        {
            if(p->right==prev || p->left==prev)
            {
                prev=p;
                cout<<" "<<p->data;
            }
            else{
                push(p);
                if(p->right)
                    push(p->right);
                if(p->left)
                    push(p->left);
            }
        }
    }
}

node* ET::inorder_nrec(node *t){
    node *p;
    if(t==NULL)
    {
        cout<<"Tree is empty";
    }
    p=t;
    do{
        while (p!=NULL)
        {
           s.push(p);
           p=p->left;
        }

        while(!isempty())
        {
           p=s.top();
           s.pop();
           cout<<" "<<p->data;
           p=p->right;
           while (p!=NULL)
           {
               s.push(p);
               p=p->left;
           }
           
        }
        
    }while(p!=NULL || top>0);
}

void ET::preorder(node *t){
    if(t!=NULL){
        cout << " " << t->data;
        preorder(t->left);
        preorder(t->right);
    }
}

void ET::postorder(node *t){
    if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        cout << " " << t->data;
    }
}

void ET::inorder(node *t){
    if(t!=NULL){
        inorder(t->left);
        cout << " " << t->data;
        inorder(t->right)
    }
}

node *ET::create(){
    int i=0;
    node *temp,*t2,*t1;
    Stack s;
    for(i=0;post[i] != '\0';i++){
        if(isalnum(post[i])){
            temp = new(node);
            temp->data = post[i];
            temp->left = temp->right = NULL;
            s.push(temp);
        }
        else{
        t2 = s.top();
        s.pop();
        t1 = s.top();
        s.pop();
        temp = new node;
        temp->data = post[i];
        temp->left = t1;
        temp->right= t2;
        s.push(temp);
    }
    }
}

void ET::input(int x){
    while(1){
        cout << "Enter the postfix expression: ";
        cin >> post;
        if(validate(x))
            break;
        else
            cout << "\nWrong expression. Enter again!";
    }
}

int ET::validate(int x){
    int i=0,opn=0,opt=0;
    for (i = 0; post[i] != '\0'; i++)
        {
            if (post[i] == '+' || post[i] == '-' || post[i] == '*' || post[i] == '/' || post[i] == '%' || post[i] == '^' || post[i] == '$')
                opt++;
            else
                opn++;
        }
        if (opt != (opn - 1))
            return 0;
        return 1;
}

int main(){
    ET b;
    int choice;
    string postfix;
    cout << "Enter the postfix expression: ";
    cin >>postfix;
    b.create(postfix);
    while(choice<7){
        cout << "\n1.Recursive Inorder\n2.Recursive PostOrder\n3.Recursive PreOrder\n4.Non-Recursive Inorder\n5.Non-Recursive PreOrder\n6.Non-Recursive PostOrder\n7.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice){
            case 1:{
                b.inorder(b.r());
                break;
            }
            case 2:{
                b.postorder(b.r());
                break;
            }
            case 3:{
                b.preorder(b.r());
                break;
            }
            case 4:{
                b.inorder_nrec(b.r());
                break;
            }
            case 5:{
                b.preorder_nrec(b.r());
                break;
            }
            case 6:{
                b.postorder_nrec(b.r());
                break;
            }
            case 7:{
                exit(0);
                break;
            }
            default:{
                cout << "Enter valid choice: ";
                break;
            }
        }
    }
}

