#pragma once

#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class DenseGraph
{
	int n, m;
	bool directed;
	vector<vector<bool>> g;

public:
	DenseGraph(int n, bool directed): n(n), m(0), directed(directed)
	{
		for (auto i = 0; i < n; i++)
		{
			g.emplace_back(vector<bool>(n, false));
		}
	}

	int V() const { return n; }
	int E() const { return m; }

	void addEdge(int v, int w)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		if (hasEdge(v, w))
			return;
		g[v][w] = true;
		if (!directed)
			g[w][v] = true;
		m++;
	}

	bool hasEdge(int v, int w)
	{
		assert(v >= 0 && v < n);
		assert(w >= 0 && w < n);
		return g[v][w];
	}

	void show()
	{
		for (auto i : g)
		{
			for (const auto j : i)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}

	class adjIterator
	{
		DenseGraph& G;
		int v;
		int index;
	public:
		adjIterator(DenseGraph& graph, int v): G(graph), v(v), index(0)
		{
		}

		int begin()
		{
			index = -1;
			return next();
		}

		int next()
		{
			for(index+=1;index<G.V();index++)
			{
				if (G.g[v][index])
					return index;
			}
			return -1;
		}

		bool end() const
		{
			return index >= int(G.V());
		}
	};
};
