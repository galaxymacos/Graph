#pragma once

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class SparseGraph
{
	int vectex; 
	int edge = 0;
	bool directed;
	vector<vector<int>> g;

public:
	SparseGraph(int vectex,bool directed):vectex(vectex),directed(directed)
	{
		for(auto i = 0;i<vectex;i++)
		{
			g.emplace_back(vector<int>());
		}
	}

	int V() const { return vectex; }
	int E() const { return edge; }

	void addEdge(int v,int w)
	{
		assert(v >= 0 && v < vectex);
		assert(w >= 0 && w < vectex);
		g[v].push_back(w);
		if (v!=w&&!directed)		
			g[w].push_back(v);
		edge++;
	}

	bool hasEdge(int v,int w)
	{
		assert(v >= 0 && v < vectex);
		assert(w >= 0 && w < vectex);
		for (auto i : g[v])
		{
			if (i == w)
				return true;
		}
		return false;
	}

	void show() const
	{
		for (const auto& row:g)
		{
			for (auto j:row)
			{
				cout << j << " ";
			}
			cout << endl;
		}
	}

	class adjIterator
	{
		SparseGraph& G;
		int v;	// the point that you want to begin searching
		int index;
	public:
		adjIterator(SparseGraph &graph, int v):G(graph),v(v),index(0){}

		int begin()
		{
			index = 0;
			if (!G.g[v].empty())
				return G.g[v][index];
			return -1;
		}

		int next()
		{
			if(++index < int(G.g[v].size()))
			{
				return G.g[v][index];
			}
			return -1;
		}

		bool end() const
		{
			return index >= int(G.g[v].size());
		}
	};
};