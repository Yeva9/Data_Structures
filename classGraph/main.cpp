#include "Graph.hpp"

int main()
{
	Graph G(10);

	//G.Print();

	G.AddEdge(0,1);
	G.AddEdge(0,9);
	G.AddEdge(1,2);
	G.AddEdge(2,0);
	G.AddEdge(2,3);
	G.AddEdge(10,3);

	G.Print();
	
	G.DFS(0,9);
	G.BFS(0,9);
//	G.Print();


	return 0;
}
