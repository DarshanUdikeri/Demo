#include<iostream>
using namespace std;
#define MAX 10

class heap{
    int a[15];
    int n;
    public:
    void input();
    void heapsort();
    void heapify(int,int);
};

void heap::input(){
    cout << "Enter the number of elements to be inserted: ";
    cin >> n;
    cout << "\nEnter the elements: " << endl;
    for(int i=0; i<=n-1 ;i++){
        cin >> a[i];
    }
}

void heap::heapsort(){
    int t;

    // i = n/2 -1 because first non-leaf node starts from it 
    // heapify from i to n
    for(int i=n/2 -1; i>=0; i--){
        heapify(n,i);
    }
    cout << "New Heap" << endl;
    for(int c=0;c<n;c++){
        cout << a[c] << "\t";
    }
    
    // heapify down
    // replacing the root(largest) number with the last place in array 
    // for getting sorted array
    // again heapify from 0 to i
    for(int i=n-1;i>=0;i--){
        {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        }
        heapify(i,0);
    }
    cout << "\nSorted Heap" << endl;
    for(int c=0;c<n;c++){
       cout << a[c] << "\t"; 
    }
    cout << endl;
}

void heap::heapify(int n,int root){
    int lgt = root;
    int left = 2*root+1;
    int right = 2*root+2;
    
    // if left child is valid node and largest then store it as largest
    if(left < n && a[left] > a[lgt]){
        lgt = left;
    }
    
    // if right child is valid node and largest then store it as largest
    if(right < n && a[right] > a[lgt]){
        lgt = right;
    }
    
    // if the largest node found is not root then swap
    if(lgt != root){
        {
            int t = a[root];
            a[root] = a[lgt];
            a[lgt] = t;
        }
        // recursive heapify from lgt to size(n)
        heapify(n, lgt);
    }
}

int main(){
    int n,root=0;
    heap h;
    // int a[MAX];
    h.input();
    h.heapsort();
    h.heapify(n,root);
}