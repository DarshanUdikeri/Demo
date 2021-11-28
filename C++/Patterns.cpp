/*
#include<iostream>
using namespace std;

/*
int main(){
    int r,c;
    cout << "Enter the number of rows and columns: ";
    cin >> r >> c;
    for (int i=1;i<=r;i++){
        if(i==1 || i==r){
            for(int j=1;j<=c;j++){
                cout <<" *";
            }
        }
        else{
            for(int j=1;j<=c;j++){
            if(j==1 || j==c){
                cout << " *";
            }
            else{
                cout << "  ";
            }
        }
        }
        cout <<endl;
    }
}
*/
/*
int main(){
    int n;
    cout << "Enter the number of stars in the first row: ";
    cin >> n;
    for(int i=n;i>=1;i--){
        for(int j=1;j<=i;j++){
            cout << "*";
        }
        cout << endl;
    }
}
*/
/*
int main(){
    int n;
    cin >>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout << "*";
        }
        cout << endl;
    }
}
*/
/*
int factorial(int n){
        
        //cin >> n;
        int f=1;
        for(int i=1;i<=n;i++){
            f = f*i;
        }
        return f;
}
int main(){
    cout << factorial(6);
    return 0;
    
}

*/

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
