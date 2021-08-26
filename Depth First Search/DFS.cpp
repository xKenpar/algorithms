#include "bits/stdc++.h"
using namespace std;

bool visited[10005];
vector<vector<int> > nodes(10005);

void DFS(int x)
{
	visited[x] = true;
	cout<<x<<" ";
	
	for(int i = 0;i<nodes[x].size();i++)
		if(!visited[nodes[x][i]])
			DFS(nodes[x][i]);
			
}

void addEdge(int x, int y){
	nodes[x].push_back(y);
	nodes[y].push_back(x);
}
int main()
{
	/*
		GRAPH
		0-1
		0-2
		0-3
		0-6
		1-4
		1-5
		2-3
		2-7
		3-6
	*/
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(0, 3);
	addEdge(0, 6);
	addEdge(1, 4);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(2, 7);
	addEdge(3, 6);
	
	DFS(0);
}
