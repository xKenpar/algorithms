#include "bits/stdc++.h"
using namespace std;

bool visited[10005];
vector<vector<int> > nodes(10005);
stack<int> ans;

void DFS(int x)
{
	visited[x] = true;

	for(int i = 0; i < nodes[x].size(); i++)
		if(!visited[nodes[x][i]])
			DFS(nodes[x][i]);
	
    ans.push(x);
}

void topologicalSort(int n)
{
    for(int i = 0; i < n; i++)
		if(!visited[i])
			DFS(i);
    
    while(!ans.empty())
	{
		cout<<ans.top()<<" ";
		ans.pop();
	}
}

void addEdge(int x, int y){
	nodes[x].push_back(y);
}

int main()
{
	/*
		GRAPH
		0-1
		0-2
		1-2
        1-5
        2-3
        5-3
        5-4
        6-1
        6-5
	*/
	addEdge(0, 1);
	addEdge(0, 2);
	addEdge(1, 2);
	addEdge(1, 5);
	addEdge(2, 3);
	addEdge(5, 3);
	addEdge(5, 4);
	addEdge(6, 1);
	addEdge(6, 5);
    topologicalSort(7);
}
