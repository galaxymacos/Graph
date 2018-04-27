#pragma once
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

template <class Graph>
class ShortestPath
{
	Graph& G;
	int s;
	bool* visited;
	int* from;
	int* ord; // calculate the distance between the element to the original element

public:
	ShortestPath(int s, Graph& graph): G(graph), s(s)
	{
		visited = new bool[graph.V()]{false};
		from = new int[graph.V()]{-1};
		ord = new int[graph.V()]{-1};

		visited[s] = true;
		ord[s] = 0;

		queue<int> q;
		q.push(s);

		while (!q.empty())
		{
			int current_element = q.front();
			q.pop();
			typename Graph::adjIterator adj(graph, current_element);
			for (int i = adj.begin(); !adj.end(); i = adj.next())
			{
				if (!visited[i])
				{
					visited[i] = true;
					from[i] = current_element;
					ord[i] = ord[current_element] + 1;
					q.push(i);
				}
			}
		}
	}

	bool hasPath(int w) const
	{
		assert(w >= 0 && w < G.V());
		return visited[w];
	}

	void path(int w, vector<int>& vec) const
	{
		assert(w >= 0 && w < G.V());
		stack<int> s;
		while (w != -1)
		{
			s.push(w);
			w = from[w];
		}
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
		for (int i = 0; i < vec.size(); i++)
		{
			cout << vec[i];
			if (i == vec.size() - 1)
			{
				cout << endl;
			}
			else
			{
				cout << "->";
			}
		}
	}

	int length(int w) const
	{
		assert(w >= 0 && w < G.V());
		return ord[w];
	}
};
