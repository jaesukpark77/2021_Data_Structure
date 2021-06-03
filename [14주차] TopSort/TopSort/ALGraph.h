#pragma once
#include "List.h"
#include"graph.h"
#include <assert.h>

typedef List < int > IntList;
typedef ListIter < int > IntListIter;
class ALGraph : public graph {
public:
    ALGraph(int size) : graph(size)
    {
        vertexList = new IntList[n]; assert(vertexList);
    }
    friend class NeighborIter;
protected:
    IntList* vertexList;
};

class NeighborIter : public IntListIter {
public:
    NeighborIter(const ALGraph& G, int startVertex) :
        IntListIter(G.vertexList[startVertex], G.n)
    {
        assert(startVertex < G.n);
    }
};
