#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node(int val){
        data = val;
        next = NULL;
    }
};

void insert_tail(node* &head, int val){
    node *n = new node(val);
    if(head == NULL){
        head = n;
        return;
    }
    
    
    node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = n;
}

void display(node *head){
    node *temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert_head(node* &head, int val){
    node *n = new node(val);
    n->next = head;
    head = n;
}

bool search(node *head, int key){
    node *temp = head;
    while(temp != NULL){
        if(temp->data == key){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int main(){
    node *head = NULL;
    insert_tail(head,1);
    insert_tail(head,2);
    insert_tail(head,3);
    insert_tail(head,4);
    insert_head(head,5);
    display(head);
    cout << search(head, 4) << endl;
}