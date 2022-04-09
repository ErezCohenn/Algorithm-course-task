#include "MST_algorithms.h"

int* MST_algorithms::Prim(WeightedGraph& graph)
{
    int* parent = new int(graph.getGraphSize());
    int* minWeight = new int(graph.getGraphSize());
    bool* vertexInMst = new bool(graph.getGraphSize());
    MinHeap priority_queue;
    
    if (graph.getGraphSize() <= 0)
    {
        return nullptr;
    }

    minWeight[0] = 0; // vertex 1 is the first vertex to start the algorithm
    parent[0] = -1; // vertex 1 has no parent

    for (int i = 1; i < graph.getGraphSize(); i++)
    {
        minWeight[i] = INT32_MAX; // minWeight initialize to infinity
        parent[i] = -1;
    }

    priority_queue.Build(minWeight, graph.getGraphSize());

    while (!priority_queue.isEmpty())
    {
        Pair minVertex = priority_queue.DeleteMin();
        vertexInMst[minVertex.data - 1] = true;

        AdjacentList* adjVertex = graph.getAdjList(minVertex.data  - 1);
        Edge* adjEdge = adjVertex->getHead();

        while (adjEdge != nullptr)
        {
            if (!vertexInMst[adjEdge->vertex - 1] && adjEdge->edgeWeight < minWeight[adjEdge->vertex - 1])
            {
                minWeight[adjEdge->vertex - 1] = adjEdge->edgeWeight;
                parent[adjEdge->vertex - 1] = minVertex.data;
                priority_queue.DecreaseKey(adjEdge->vertex - 1, minWeight[adjEdge->vertex - 1]); // the index of v is need to update: מצביע הדדי?
            }
        }
    }

    return parent;
}
