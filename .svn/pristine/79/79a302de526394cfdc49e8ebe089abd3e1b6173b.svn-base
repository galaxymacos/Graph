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
	int cCount;

	void dfs(int v) const
	{
		visited[v] = true;
		id[v] = cCount;
		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next())
		{
			if (!visited[i])
				dfs(i);
		}
	}

public:
	explicit Component(Graph& graph): G(graph),cCount(0)
	{
		visited = new bool[G.V()]{false};
		id = new int[G.V()]{-1};

		for (int i = 0; i < G.V(); i++)
		{
			if (!visited[i])
			{
				dfs(i);
				cCount++;
			}
		}
	}

	~Component()
	{
		delete[] visited;
		delete[] id;
	}

	int count() const
	{
		return cCount;
	}

	bool isConnect(int v, int w) const
	{
		assert(v >= 0 && v < G.V());
		assert(w >= 0 & w < G.V());
		return id[v] == id[w];
	}
};
