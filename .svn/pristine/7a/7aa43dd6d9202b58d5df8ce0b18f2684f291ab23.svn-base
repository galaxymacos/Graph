#pragma once

#include <string>
#include <fstream>
#include <sstream>
#include <cassert>

using namespace std;

template <typename Graph>
class ReadGraph
{
public:
	ReadGraph(Graph& graph, const string& filename)
	{
		ifstream file(filename);
		string line;
		int V, E;
		assert(file.is_open());

		assert(getline(file, line));
		stringstream size_container(line);
		size_container >> V >> E;
		assert(V == graph.V());

		for (int i = 0; i < E; i++)
		{
			getline(file, line);
			stringstream v_e_container(line);
			int a, b;
			v_e_container >> a >> b;
			assert(a >= 0 && a < V);
			assert(b >= 0 && b < V);
			graph.addEdge(a, b);
		}
	}
};
