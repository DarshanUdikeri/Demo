

/*
int binary_search(int arr[],int key){
    int s=0,e=0;
    while(s<=e){
        int mid=(s+e)/2;
        if(arr[mid] == key){
            return mid;
        }
        else if(arr[mid] > key){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return -1;
}

int main(){
    int n,key;
    //cin >> n;
    int arr[] = {10,20,30,40,50};
    cout << "Key: ";
    cin >> key;
    cout << binary_search(arr,key) << endl;
}
*/
/*
              Selection Sort
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[j] < arr[i]){
                int temp;
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << arr[i] <<" ";
    }cout << endl;

}
*/

#include<iostream>
using namespace std;