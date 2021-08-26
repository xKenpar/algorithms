#include "bits/stdc++.h"
using namespace std;

bool visited[10005];
vector<vector<int> > nodes(10005);
queue<int> bfsQueue;

void BFS(int x)
{
	bfsQueue.push(x);
	visited[x] = true;
	
	while(!bfsQueue.empty())
	{
		int current = bfsQueue.front();
		bfsQueue.pop();
		cout<<current<<" ";

		for(int i = 0;i<nodes[current].size();i++)
			if(!visited[nodes[current][i]])
			{
				visited[nodes[current][i]] = true;
				bfsQueue.push(nodes[current][i]);
			}
	}
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
	
	BFS(0);
}
