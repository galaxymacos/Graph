#pragma once
#include <cassert>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

template <typename Graph>
class Path
{
	Graph& G;
	int s; // source
	bool* visited;
	int* from;

	void dfs(int v) const
	{
		visited[v] = true;
		typename Graph::adjIterator adj(G, v);
		for (int i = adj.begin(); !adj.end(); i = adj.next())
		{
			if (!visited[i])
			{
				from[i] = v;
				dfs(i);
			}
		}
	}

public:
	Path(Graph& graph, int s): G(graph), s(s)
	{
		assert(s >= 0 && s<G.V());
		visited = new bool[G.V()]{false};	// every point is not visited
		from = new int[G.V()]{-1};		// every point is isolated
		from[s] = s;
		dfs(s);
	}

	~Path()
	{
		delete[] visited;
		delete[] from;
	}

	bool hasPath(int w) const
	{
		assert(w >= 0 && w < G.V());
		return visited[w];
	}

	void path(int w, vector<int>& vec) const 
	{
		assert(w >= 0 && w < G.V());
		stack<int> s;	// since the vectre we get is from destination to origin, we use a 
		while (from[w] != w)		// use from[w] to find the previous vectre of w
		{
			s.push(w);
			w = from[w];
		}
		s.push(w);
		vec.clear();
		while (!s.empty())
		{
			vec.emplace_back(s.top());
			s.pop();
		}
	}

	void showPath(int w) const
	{
		vector<int> vec;
		path(w, vec);
		for (int i = 0; i < int(vec.size()); i++)
		{
			cout << vec[i];
			if (i == int(vec.size() - 1))
			{
				cout << endl;
			}
			else
			{
				cout << "->";
			}
		}
	}
};
