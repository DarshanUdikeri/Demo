#include <iostream>
using namespace std;
#define n 20

class queue{
    int *arr;
    int front, back;
    public:
    queue(){
        arr = new int[n];
        front = back = -1;
    }

    void enqueue(int x){
        if(back==n-1){
            cout << "Queue overflow" ;
            return;
        }
        else{
            back ++;
            arr[back] = x;
        }
        if(front==-1){
            front++;
        }
    }

    void dequeue(){
        if(front == -1 || front>back){
            cout << "Queue underflow";
            return;
        }
        front++;
    }

    int peek(){
        if(front==-1 || front>back){
            return -1;
        }
        return arr[front];
    }

    bool empty(){
        if(front==-1 || front>back){
            return true;
        }
        return false; 
    }
};

int main(){
    queue q;
    int a, c=0;
    // cout << "Enter element to enqueue: ";
    // cin >> a;
    // q.enqueue(a);
    // q.enqueue(1);
    // q.enqueue(2);
    // q.enqueue(3);
    // q.enqueue(4);
    // q.enqueue(5);
    // cout << "Element popped: " << q.peek() << endl;
    // q.dequeue();

    // cout << "Element popped: " << q.peek() << endl;
    // q.dequeue();

    // cout << "Element popped: " << q.peek() << endl;
    // q.dequeue();

    // cout << "Element popped: " << q.peek() << endl;
    // q.dequeue();

    // cout << "Element popped: " << q.peek() << endl;
    // q.dequeue();

    // cout << q.empty() << endl;

    
    while(c<4){
        cout << "\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Exit" << endl;
        cout << "Enter choice: ";
        cin >> c;
        cout << endl;
        switch(c){
            case 1:{
                cout << "Enter element to enqueue: ";
                cin >> a;
                q.enqueue(a);
                break;
            }
            case 2:{
                cout << "Element popped: " << q.peek();
                q.dequeue();
                break;
            }
            case 3:{
                cout << "First Element: " << q.peek();
                break;
            }
        }
    }
}