#include <iostream>
using namespace std;
#define n 100


class Stack{
    int *arr;
    int top;

    public:
    Stack(){
        arr = new int[n];
        top =-1;
    }
    void push(int x);
    void pop();
    bool isempty();
    int peep();
    void display();
};
void Stack::push(int x){
    if(top==n-1){
        cout << "Stack overflow" << endl;
    }
    top++;
    arr[top] = x;
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

int main(){
    int i,x;
    Stack st;
    while(i<5){
        cout << "Enter your choice: " << endl;
        cout << "1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit" << endl;
        cin >> i;
        switch(i){
            case 1:{
                cout << "Enter the element to be pushed: " << endl;
                cin >> x;
                st.push(x);
                break;
            }
            case 2:{
                cout << "Element popped: " <<st.peep() << endl;
                st.pop();
                break;
            }
            case 3:{
                cout << "Element in the top: " << st.peep() << endl;
                break;
            }
            case 4:{
            	st.display();
            	break;
            }
        }
    }
}
