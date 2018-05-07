#pragma once

#include <iostream>
#include <cassert>
using namespace std;

template <typename Graph>
class Component
{
	Graph& G;
	bool* visited;
	int* id;
	int currentID = 0;

	void dfs(int v) const	// find the vectexs that are connected to v
	{
		visited[v] = true;	// v is connected to v absolutely
		id[v] = currentID;

		typename Graph::adjIterator adj(G, v);	// look for the nearest vectexs of v
		for (int i = adj.begin(); !adj.end(); i = adj.next())
		{
			if (!visited[i])			// prevent the situation where a -> b and b -> a and so on...
				dfs(i);				// find the adjacent vectexs of the current adjacent vectex(i) of v
		}
	}

public:
	explicit Component(Graph& graph): G(graph)
	{
		visited = new bool[G.V()]{false};
		id = new int[G.V()]{-1};

		for (int i = 0; i < G.V(); i++) // to each vectex, try to find the vectexs that are connected to it
		{
			if (visited[i])	// if this vectex already has some vectexs connecting to it, jump to look for the next vectex
				continue;
			dfs(i);			// find the vectexs that are connected to i
			currentID++;		// to separate each connected component
		}
	}

	~Component()
	{
		delete[] visited;
		delete[] id;
	}

	int count() const
	{
		return currentID;
	}

	bool isConnect(int v, int w) const
	{
		assert(v >= 0 && v < G.V());
		assert(w >= 0 & w < G.V());
		return id[v] == id[w];
	}
};
