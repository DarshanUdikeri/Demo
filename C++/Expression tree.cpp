#include<iostream>
#include<stack>
using namespace std;

struct Node
{
    char data;
    Node *left, *right;
};
class Expression
{
    char prefix[50], postfix[50], infix[50];
    Node *root;
    int top;

public:
    void input(int);
    Node *getroot()
    {
        return root;
    }
    int validate(int);
    Node *create_Post();
    void inorderRec(Node *);
    void preorderRec(Node *);
    void postorderRec(Node *);
    void inorderwithoutRec(Node *);
    void preorderwithoutRec(Node *);
    void postorderwithoutRec(Node *);
};
int Expression::validate(int x)
{
    int i = 0, opn = 0, opt = 0;
    if (x == 0)
    {
        for (i = 0; prefix[i] != '\0'; i++)
        {
            if (prefix[i] == '+' || prefix[i] == '-' || prefix[i] == '*' || prefix[i] == '/' || prefix[i] == '%' || prefix[i] == '^' || prefix[i] == '$')
                opt++;
            else
                opn++;
        }
        if (opt != (opn - 1))
            return 0;
            
        return 1;
    }
    else
    {
        for (i = 0; postfix[i] != '\0'; i++)
        {
            if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '%' || postfix[i] == '^' || postfix[i] == '$')
                opt++;
            else
                opn++;
        }
        if (opt != (opn - 1))
            return 0;
        return 1;
    }
}
void Expression::input(int x)
{
    while (1)
    {
        cout << "\nEnter postfix Expression: ";
        cin >> postfix;
        if (validate(x))
            break;
        else
            cout << "\nWrong Expression. Enter Again.";
    }
}
Node *Expression::create_Post()
{
    int i = 0;
    Node *temp, *t1, *t2;
    stack<Node *> s;
    for (; postfix[i] != '\0'; i++)
    {
        if (isalnum(postfix[i]))  // check if postfix alpha numeric .whether it ranges in the alphabetic and numeric range
        {
            temp = new Node;
            temp->data = postfix[i];
            temp->left = temp->right = NULL;
            s.push(temp);
        }
        else
        {
            t2 = s.top();
            s.pop();
            t1 = s.top();
            s.pop();
            temp = new Node;
            temp->data = postfix[i];
            temp->left = t1;
            temp->right = t2;
            s.push(temp);
        }
    }
    temp = s.top();
    s.pop();
    return temp;
}
void Expression::inorderRec(Node *t)
{
    if (t != NULL)
    {
        inorderRec(t->left);
        cout << " " << t->data;
        inorderRec(t->right);
    }
}
void Expression::preorderRec(Node *t)
{
    if (t != NULL)
    {
        cout << " " << t->data;
        preorderRec(t->left);
        preorderRec(t->right);
    }
}
void Expression::postorderRec(Node *t)
{
    if (t != NULL)
    {
        postorderRec(t->left);
        postorderRec(t->right);
        cout << " " << t->data;
    }
}
void Expression::inorderwithoutRec(Node *t)
{
    Node *temp = t;
    stack<Node *> s;
    while (temp != NULL)
    {
        s.push(temp);
        temp = temp->left;
    }
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        cout << " " << temp->data;
        temp = temp->right;
        while (temp != NULL)
        {
            s.push(temp);
            temp = temp->left;
        }
    }
}
void Expression::preorderwithoutRec(Node *t)
{
    Node *temp = t;
    stack<Node *> s;
    while (temp != NULL)
    {
        cout << " " << temp->data;
        s.push(temp);
        temp = temp->left;
    }
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        temp = temp->right;
        while (temp != NULL)
        {
            cout << " " << temp->data;
            s.push(temp);
            temp = temp->left;
        }
    }
}
void Expression::postorderwithoutRec(Node *t)
{
   

    Node *P, *previous;
    stack<Node *> S;
    if (t == NULL)
    {
        cout << "Tree Is Empty\n";
    }
    S.push(t);
    while (!S.empty())
    {
        P = S.top();
        S.pop();
        if (P->right == NULL && P->left == NULL)
        {
            previous = P;
            cout << " " << P->data;
        }
        else
        {
            if (P->right == previous || P->left == previous)
            {
                previous = P;
                cout << " " << P->data;
            }
            else
            {
                S.push(P);
                if (P->right)
                    S.push(P->right);
                if (P->left)
                    S.push(P->left);
            }
        }
    }
}
int main()
{
    int choice;
    Expression et;
    Node *t;
    
    cout << "\nPlease enter the postfix string: ";
    et.input(1);
    t = et.create_Post();
    while (1)
    {
        cout << "\n\nExpression Tree operations";
        cout << "\n1.Recursive Inorder Traversal";
        cout << "\n2.Recursive Preorder Traversal";
        cout << "\n3.Recursive Postorder Traversal";
        cout << "\n4.Non-Recursive Inorder Traversal";
        cout << "\n5.Non-Recursive Preorder Traversal";
        cout << "\n6.Non-Recursive Postorder Traversal";
        cout << "\n7. Exit the program";
        cout << "\nEnter your choice:- ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nInorder traversal with recursion:";
            et.inorderRec(t);
            break;
        case 2:
            cout << "\nPreorder traversal with recursion:";
            et.preorderRec(t);
            break;
        case 3:
            cout << "\nPostorder traversal with recursion:";
            et.postorderRec(t);
            break;
        case 4:
            cout << "\nInorder traversal without recursion:";
            et.inorderwithoutRec(t);
            break;
        case 5:
            cout << "\nPreorder traversal without recursion:";
            et.preorderwithoutRec(t);
            break;
        case 6:
            cout << "\nPostorder traversal without recursion:";
            et.postorderwithoutRec(t);
            break;
        case 7:
            
            cout << "Program Ended";
            exit(0);
        default:
            cout << "\nWrong choice. Enter Choice Again";
        }
    }
    return 0;
}