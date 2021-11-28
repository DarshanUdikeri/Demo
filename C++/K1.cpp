#include <iostream>
using namespace std;
#define I 65535

class kruskals{
    
    int edge[3][9] = {{1,1,2,2,3,4,4,5,5},
                      {2,6,3,7,4,5,7,6,7},
                      {25,5,12,10,18,16,14,20,18}};
    int set[8] = {-1};
    int included[9] = {0};
    int t[2][6];
    public:
    int find(int);
    void Union(int, int);

};

int kruskals::find(int u){
    int x = u;
    while(set[x] > 0){
        x = set[x];
    }
    return x;
}

void kruskals::Union(int u,int v){
    if(set[u] < set[v]){
        set[u] += set[v];
        set[v] = u;
    }
    else{
        set[v] += set[u];
        set[u] = v;
    }
}

int main(){
    int edge[3][9] = {{1,1,2,2,3,4,4,5,5},
                      {2,6,3,7,4,5,7,6,7},
                      {25,5,12,10,18,16,14,20,18}};
    int set[8] = {-1};
    int included[9] = {0};
    int t[2][6];
    kruskals K;
    int i=0,j,k,n=7,e=9,min,u,v;
    while(i<n-1){
        min = I;
        for(j=0;j<e;j++){
            if(included[j]==0 && edge[2][j]<min){
                min = edge[2][j];
                k=j;
                u = edge[0][j];
                v = edge[1][j];
            }
        }
        if(K.find(u)!=K.find(v)){
            t[0][i] = u;
            t[1][i] = v;
            K.Union(K.find(u),K.find(v));
            i++;
        }
        included[i] = 1;
    }

    for(int m=0;m<4;m++){
        for(int o=0;o<10;o++){
            cout << t[m][o];
        }
    }
}