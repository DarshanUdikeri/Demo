#include<iostream>
using namespace std;
#define V 6
#define I 65535
// extern int V = 6;

class MST{
    public:
    void create_graph();
    int minkey(int key[],bool mstset[]);
    void printMST(int parent[],int graph[][V]);
    void primMST(int graph[][V]);
};

//int key holds the cost value
//bool mstset holds whether the vertex is visited or not
//initially int min is initiated as infinity
//minkey returns the vertex with minimum cost which is not present in mstset
int MST::minkey(int key[], bool mstset[]){
    int min = 2147483647;
    int min_index;

    for(int v=0;v < V;v++){
        if(mstset[v] == false && key[v] < min){
            min = key[v], min_index = v;
        }
    }
    return min_index;
}

void MST::printMST(int parent[], int graph[][V]){
    cout << "Edge \tWeight\n";
    for(int i=1;i<V;i++){
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

void MST::primMST(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mstset[V];

    for(int i=0;i<V;i++){
        key[i] = 2147483647, mstset[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int count=0; count<V-1; count++){
        int u = minkey(key,mstset);
        mstset[u] = true;
        for(int v=0; v<V; v++){
            if(graph[u][v] && mstset[v] == false && graph[u][v] < key[v]){
                parent[v] = u, key[v] = graph[u][v];
            }
        }
    }
    printMST(parent,graph);
}

void MST::create_graph(){
    // extern V;
    cout << "Enter the number of rows of adjacency matrix: " << endl;
}

int main(){
    int graph[][V] = { {0,1,0,9,0,2},
                       {1,0,3,0,0,0},
                       {0,3,0,6,0,0},
                       {9,0,6,0,4,5},
                       {0,0,0,4,0,7},
                       {2,0,0,5,7,0} };
    MST g;
    g.primMST(graph);
}