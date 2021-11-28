#include<iostream>
using namespace std;
#define MAX 10

class heap{
    int a[15];
    int n;
    public:
    heap();
    void heapsort();
    void heapify(int arr[],int,int);
};

heap::heap(){
    a[0] = 12;
    a[1] = 24;
    a[2] = 73;
    a[3] = 42;
    a[4] = 61;
    a[5] = 58;
    n = 6;
}

void heap::heapsort(){
    int t;
    for(int i=n/2 -1; i>=0; i--){
        heapify(a,n,i);
    }
    cout << "New Heap" << endl;
    for(int c=0;c<n;c++){
        cout << a[c] << "\t";
    }
    for(int i=n-1;i>=0;i--){
        {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        }
        heapify(a,i,0);
    }
    cout << "\nSorted Heap" << endl;
    for(int c=0;c<n;c++){
       cout << a[c] << "\t"; 
    }
    cout << endl;
}

void heap::heapify(int a[],int size,int root){
    int lgt = root;
    int left = 2*root+1;
    int right = 2*root+2;
    if(left < size && a[left] > a[lgt]){
        lgt = left;
    }
    if(right < size && a[right] > a[lgt]){
        lgt = right;
    }
    if(lgt != root){
        {
            int t = a[root];
            a[root] = a[lgt];
            a[lgt] = t;
        }
        heapify(a,size, lgt);
    }
}

int main(){
    int size,root=0;
    heap h;
    int a[MAX];
    // cout << "Enter the elements: ";
    // for(int i=0;i<=MAX;i++){
    //     cin >> a[i];
    // }
    h.heapsort();
    h.heapify(a, size,root);
}