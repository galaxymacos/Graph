#include <iostream>
#include <vector>
#include "SparseGraph.h"
#include "DenseGraph.h"
#include "ReadGraph.h"
#include <ctime>
#include "Component.h"
#include "Path.h"
#include "Shortest.h"
using namespace std;

template<class graph>
void testGraph();

int main(int argc, char* argv[])
{
	const string filename = "data.txt";
	SparseGraph g1(6, false);
	ReadGraph<SparseGraph>(g1, filename);
	Component<SparseGraph> component1(g1);
	Path<SparseGraph> dfs(g1, 0);
	dfs.showPath(4);
	ShortestPath<SparseGraph> bfs(0, g1);
	bfs.showPath(4);

	cout << endl;

	DenseGraph g2(6, false);
	ReadGraph<DenseGraph>(g2, filename);
	Component<DenseGraph> component2(g2);

	system("pause");
}

template<class graph>
void testGraph()
{
	srand(time(nullptr));
	const auto point = 20;
	const auto edge = 100;
	graph g1(20, false);
	for(auto i = 0;i<edge;i++)
	{
		int a = rand() % point;
		int b = rand() % point;
		g1.addEdge(a, b);
	}


	for(int v = 0;v<point;v++)
	{
		cout << v << " : ";
		typename graph::adjIterator adj(g1, v);
		for(int w = adj.begin();!adj.end();w=adj.next())
		{
			cout << w << " ";
		}
		cout << endl;
	}

	
}
