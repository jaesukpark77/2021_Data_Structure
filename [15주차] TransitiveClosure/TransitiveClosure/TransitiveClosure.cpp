//전자정보공학부 IT융합과 20170586 박재석
#include <iostream>
#include <fstream>
#include "UAMGraph.h"

using namespace std;

int main()
{
	cout << "전자정보공학부 IT융합과 20170586 박재석\n" << endl;
	const char* inFileName = "graph2.dat";
	// read graph from a file
	// first entry is size of graph

	ifstream ifs(inFileName);
	assert(ifs);
	int n;
	ifs >> n;
	uAMGraph G(n);
	cout << "Created graph; n = " << G.vertexSize() << endl;
	int u, v;
	while (ifs >> u) {
		ifs >> v;
		G.addEdge(u-1, v-1);
	}
	cout << "Edges in graph: m = " << G.edgeSize() << endl;
	int step;
	for (step = 0; step < n; step++)
		for (u = 0; u < n; u++)
			for (v = 0; v < n; v++)
				if (G.edgeMember(u, step) && G.edgeMember(step, v))
					G.addEdge(u, v);
	// print results
	for (u = 0; u < n; u++) {
		cout << u << "\t: ";
		for (v = 0; v < n; v++)
			cout << (G.edgeMember(u, v) ? "T " : "F ");
		cout << endl;
	}
	return 0;
}

