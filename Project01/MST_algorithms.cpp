#include "MST_algorithms.h"

int MST_algorithms::Prim(const WeightedGraph& graph)
{
    int* parent = new int(graph.getGraphSize());
    int* minWeight = new int(graph.getGraphSize());
    bool* vertexInMst = new bool(graph.getGraphSize());
    MinHeap priority_queue;
        
    if (graph.getGraphSize() <= 0)
    {
        cout << "The graph is empty!";
        exit(1);
    }
    
    initializePrim(minWeight, parent, vertexInMst, graph.getGraphSize());
     
    priority_queue.Build(minWeight, graph.getGraphSize());

    while (!priority_queue.isEmpty())
    {
        Pair minVertex = priority_queue.DeleteMin();
        vertexInMst[minVertex.data - 1] = true;

        AdjacentList adjVertex = graph.getAdjList(minVertex.data  - 1);
        Edge* adjEdge = adjVertex.getHead();

        while (adjEdge != nullptr)
        {
            if (!vertexInMst[adjEdge->vertex - 1] && adjEdge->edgeWeight < minWeight[adjEdge->vertex - 1])
            {
                minWeight[adjEdge->vertex - 1] = adjEdge->edgeWeight;
                parent[adjEdge->vertex - 1] = minVertex.data;
                priority_queue.DecreaseKey(priority_queue.getIndex(adjEdge->vertex - 1), minWeight[adjEdge->vertex - 1]);
            }

            adjEdge = adjEdge->next;
        }
    }
    
    return countMSTWeight(minWeight, graph.getGraphSize());

    
}

void MST_algorithms::initializePrim(int minWeight[], int parent[], bool vertexInMst[], int size)
{
    int straterVertex = rand() % size; // the first vertex to start the algorithm (V0)
    
    for (int i = 0; i < size; i++)
    {
        if (i == straterVertex)
        {
            minWeight[straterVertex] = 0;
        }
        else // minWeight initialize to infinity
        {
            minWeight[i] = INT32_MAX;
        } 

        parent[i] = -1; // if parent[i] == -1 then i has no parent (nil)
        vertexInMst[i] = false;
    }
}

int MST_algorithms::countMSTWeight(int EdgeWeights[], int size)
{
    int totalWeight;
    
    if (size < 1)
    {
        cout << "wrong input";
        exit(1);
    }

    totalWeight = EdgeWeights[0];

    for (int i = 1; i < size; i++)
    {
        totalWeight += EdgeWeights[i];
    }

    return totalWeight;
}
