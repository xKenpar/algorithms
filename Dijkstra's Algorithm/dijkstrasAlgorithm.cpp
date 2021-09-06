#include "bits/stdc++.h"
using namespace std;

vector<int> dist(10005, INT_MAX);
vector<vector<pair<int,int> > > nodes(10005);
priority_queue<pair<int,int> > pq;

void dijkstra(int start)
{
	dist[start] = 0;
	pq.push({0,start});

	while(!pq.empty()){
		pair<int,int> current = pq.top();
		pq.pop();

		for(int i = 0; i < nodes[current.second].size(); i++)
		{
			if( dist[ nodes[current.second][i].second ] > current.first + nodes[current.second][i].first)
			{
				dist[ nodes[current.second][i].second ] = current.first + nodes[current.second][i].first;
				pq.push({dist[ nodes[current.second][i].second ], nodes[current.second][i].second});
			}
		}
	}
    
}

void addEdge(int x, int y, int dist)
{
	nodes[x].push_back({dist, y});
}
int main()
{
	/*
		GRAPH
		0-1 3
		0-2 1
		0-3 4
		0-6 2
		1-4 6
		1-5 2
		2-3 1
		2-7 4
		3-6 7
	*/
	addEdge(0, 1, 3);
	addEdge(0, 2, 1);
	addEdge(0, 3, 4);
	addEdge(0, 6, 2);
	addEdge(1, 4, 6);
	addEdge(1, 5, 2);
	addEdge(2, 3, 1);
	addEdge(2, 7, 4);
	addEdge(3, 6, 7);
	
	dijkstra(0);

	for(int i = 0;i < 10005; i++){
		if(dist[i]==INT_MAX)	
			continue;
		cout<<i<<". Nodes Shortest Path Length : "<<dist[i]<<endl;
	}
}
