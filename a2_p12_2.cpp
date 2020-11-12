//Implementation of Topological Sort
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class Graph{
	int V;
	list<int> *adj;
	void topoSortUtil(int v, bool visited[], stack<int>& Stack);
public:
	Graph(int V);
	void addEdge(int v, int w);
	void topoSort();
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int> [V]; 
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w);
}	

void Graph::topoSortUtil(int v, bool visited[], stack<int>& Stack){
	visited[v] = true;
	list<int>::iterator i;
	for(i=adj[v].begin(); i != adj[v].end(); i++)
		if(!visited[*i])
			topoSortUtil(*i, visited, Stack);
	Stack.push(v);	
}


void Graph::topoSort(){
	stack<int> Stack;
	bool *visited = new bool[V];
	for(int i=0; i<V; i++)
		visited[i] = false;
	for(int i=0; i<V; i++)
		if(visited[i] == false)
			topoSortUtil(i, visited, Stack);
		while(Stack.empty() == false){
			cout << Stack.top() << " ";
			Stack.pop();
		}
}


int main(){
	Graph g(6);
	g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
    g.topoSort();
	return 0;
}