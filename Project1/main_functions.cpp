#include "main_functions.h"

void runMstAlgorithms(int argc, char* argv[])
{
	WeightedGraph graph;
	vector<Edge*> graphEdgesArray;
	vector<Edge*> MstArray;
	Edge* edgeToDelete = nullptr;
	int resPrim, resKruskal, resKruskalAfterRemoveEdge;
	bool isGraphLinked;
	ifstream graphInput(argv[1]);
	ofstream outputMST(argv[2]);

	try
	{
		if (argc != 3)
		{
			throw "invalid input";
		}

		if (!outputMST.is_open() || !graphInput.is_open())
		{
			throw "invalid input";
		}

		makeGraphFromFileInput(graphInput, graph, edgeToDelete);
		isGraphLinked = graph.isGraphLinked();

		if (!isGraphLinked)
		{
			throw "No MST";
		}

		graphEdgesArray = graph.getEdgesArr();
		QuickSort::quickSort(graphEdgesArray, 0, graphEdgesArray.size() - 1);

		resPrim = MST_algorithms::Prim(graph);

		resKruskal = MST_algorithms::Kruskal(graph, graphEdgesArray, MstArray);

		if (MST_algorithms::isEdgeInMst(edgeToDelete, MstArray))
		{
			removeEdgeFromGraphEdgesArr(graphEdgesArray, edgeToDelete);
			graph.removeEdge(edgeToDelete->vertex, edgeToDelete->twin->vertex);

			isGraphLinked = graph.isGraphLinked();

			if (isGraphLinked)
			{
				MstArray.clear();
				resKruskalAfterRemoveEdge = MST_algorithms::Kruskal(graph, graphEdgesArray, MstArray);
			}
		}
		else
		{
			isGraphLinked = true;
			resKruskalAfterRemoveEdge = resKruskal;
		}

		cout << "Kruskal " << resKruskal << endl << "Prim " << resPrim << endl;
		outputMST << "Kruskal " << resKruskal << endl << "Prim " << resPrim << endl;

		if (isGraphLinked)
		{
			cout << "Kruskal2 " << resKruskalAfterRemoveEdge << endl;
			outputMST << "Kruskal2 " << resKruskalAfterRemoveEdge << endl;
		}
		else
		{
			throw "No MST";
		}
	}
	catch (char const* message)
	{
		cout << message << endl;
		outputMST << message << endl;
		graphInput.close();
		outputMST.close();
		exit(1);
	}
}

void makeGraphFromFileInput(ifstream& graphInput, WeightedGraph& graph, Edge*& edgeToDelete)
{
	int amountOfVertexes;
	int amountOfEdges;
	string userInput, line;
	string srcVertexStr, destVertexStr, weightStr;
	int srcVertex, destVertex, weight;
	int index;


	getline(graphInput, userInput);

	if (!isNumeric(userInput))
	{
		throw "invalid input";
	}
	else
	{
		amountOfVertexes = convertStringToNumeric(userInput);
	}

	graph.makeEmptyGraph(amountOfVertexes);

	getline(graphInput, userInput);

	if (!isNumeric(userInput))
	{
		throw "invalid input";
	}
	else
	{
		amountOfEdges = convertStringToNumeric(userInput);
	}

	for (int i = 0; i < amountOfEdges; i++)
	{
		if (graphInput.eof())
		{
			throw "invalid input";
		}

		getline(graphInput, line);

		convertStringToEdge(line, amountOfVertexes, srcVertex, destVertex, weight);

		if (graph.isAdjacent(srcVertex, destVertex))
		{
			throw "invalid input";
		}

		graph.addEdge(srcVertex, destVertex, weight);
	}

	if (graphInput.eof())
	{
		throw "invalid input";
	}

	getline(graphInput, line);

	index = line.find(" ");
	srcVertexStr = line.substr(0, index);
	line = line.substr(index + 1);

	if (!isNumeric(srcVertexStr))
	{
		throw "invalid input";
	}

	srcVertex = convertStringToNumeric(srcVertexStr);

	index = line.find("\n");
	destVertexStr = line.substr(0, index);

	if (!isNumeric(destVertexStr))
	{
		throw "invalid input";
	}

	destVertex = convertStringToNumeric(destVertexStr);

	if (!graphInput.eof())
	{
		throw "invalid input";
	}

	if (!graph.isAdjacent(srcVertex, destVertex))
	{
		throw "invalid input";
	}

	edgeToDelete = graph.getEdge(srcVertex, destVertex);

	graphInput.close();
}

bool isNumeric(const string& strToCheck)
{
	if (strToCheck.size() > 0 && strToCheck[0] != '-' && (strToCheck[0] < '0' || strToCheck[0] > '9'))
	{
		return false;
	}
	if ((strToCheck.size() < 2 && strToCheck[0] == '-') || (strToCheck.size() < 1))
	{
		return false;
	}
	for (int i = 1; i < strToCheck.size(); i++)
	{
		if (strToCheck[i] < '0' || strToCheck[i] > '9')
		{
			return false;
		}
	}

	return true;
}

int convertStringToNumeric(const string& strToConvert)
{
	return atoi(strToConvert.c_str());
}

void convertStringToEdge(string& line, int amountOfVertexes, int& srcVertex, int& destVertex, int& weight)
{
	string srcVertexStr, destVertexStr, weightStr;
	int index;

	// check valid srcVertex
	index = line.find(" ");
	srcVertexStr = line.substr(0, index);
	line = line.substr(index + 1);

	if (!isNumeric(srcVertexStr))
	{
		throw "invalid input";
	}

	srcVertex = convertStringToNumeric(srcVertexStr);

	if (!isValidVertex(srcVertex, amountOfVertexes))
	{
		throw "invalid input";
	}

	// check valid destVertex
	index = line.find(" ");
	destVertexStr = line.substr(0, index);
	line = line.substr(index + 1);

	if (!isNumeric(destVertexStr))
	{
		throw "invalid input";
	}

	destVertex = convertStringToNumeric(destVertexStr);

	if (!isValidVertex(destVertex, amountOfVertexes))
	{
		throw "invalid input";
	}

	// check valid weight and Edge
	index = line.find("\n");
	weightStr = line.substr(0, index);

	if (!isNumeric(weightStr))
	{
		throw "invalid input";
	}

	weight = convertStringToNumeric(weightStr);
}

bool isValidVertex(int vertex, int maxVertex)
{
	return (vertex >= 1 && vertex <= maxVertex);
}

void removeEdgeFromGraphEdgesArr(vector<Edge*>& edgesArray, Edge* edgeToDelete)
{
	bool found = false;

	for (int i = 0; i < edgesArray.size() && !found; i++)
	{
		if (edgesArray[i]->vertex == edgeToDelete->vertex && edgesArray[i]->twin->vertex == edgeToDelete->twin->vertex)
		{
			edgesArray.erase(edgesArray.begin() + i);
			found = true;
		}
	}
}
