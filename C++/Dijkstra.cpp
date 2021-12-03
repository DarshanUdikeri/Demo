 #include <limits.h>
#include <iostream>
using namespace std;
#define V 6

class Dijkstra{
	public:
	string city[V] = {"Nashik    ","Pune      ","Mumbai    ","Aurangabad","Solapur   ","Kolhapur  "};
	int minDistance(int dist[], bool set[]);
	int print(int dist[], int n);
	void dijkstra(int graph[V][V], int src);
};

int Dijkstra::minDistance(int dist[], bool set[])
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
		if (set[v] == false && dist[v] <= min)
			min = dist[v], min_index = v;

	return min_index;
}

int Dijkstra::print(int dist[], int n)
{
	cout << "Vertex        Distance from Source" << endl;
	for (int i = 0; i < V; i++){
		cout << city[i] << "\t\t" << dist[i] << endl;
	}
}

void Dijkstra::dijkstra(int graph[V][V], int src)
{
	int dist[V]; 
	bool set[V]; 
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, set[i] = false;

	dist[src] = 0;
	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, set);
		set[u] = true;
		for (int v = 0; v < V; v++)
			if (!set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
				dist[v] = dist[u] + graph[u][v];
	}
	print(dist, V);
}

int main()
{
	Dijkstra d;
	int graph[V][V] = {{0,6,3,0,0,0},
					   {6,0,2,5,0,0},
					   {3,2,0,3,4,0},
					   {0,5,3,0,2,3},
					   {0,0,4,2,0,5},
					   {0,0,0,3,5,0}};

	d.dijkstra(graph, 0);
	return 0;
}
