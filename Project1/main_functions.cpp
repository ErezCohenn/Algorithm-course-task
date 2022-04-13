#include "main_functions.h"

void runMstAlgorithms(int argc, char* argv[])
{
	WeightedGraph graph;

	Edge* edgeToDelete = nullptr;
	int resPrim, resKruskal, resKruskalAfterRemoveEdge;
	bool isGraphLinked;

	if (argc != 3)
	{
		printErrorInput();
	}

	makeGraphFromFileInput(argv[1], graph, edgeToDelete);

	resPrim = MST_algorithms::Prim(graph);

	resKruskal = MST_algorithms::Kruskal(graph);

	graph.removeEdge(edgeToDelete->vertex, edgeToDelete->twin->vertex);

	isGraphLinked = graph.isGraphLinked();

	if (isGraphLinked)
	{
		resKruskalAfterRemoveEdge = MST_algorithms::Kruskal(graph);
	}

	ofstream outputMST(argv[2]);

	if (!outputMST.is_open())
	{
		printErrorInput();
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
		cout << "No MST" << endl;
		outputMST << "No MST" << endl;
	}

	outputMST.close();
}

void makeGraphFromFileInput(const char inputFile[], WeightedGraph& graph, Edge*& edgeToDelete)
{
	int amountOfVertexes;
	int amountOfEdges;
	string userInput, line;
	string srcVertexStr, destVertexStr, weightStr;
	int srcVertex, destVertex, weight;
	int index;

	ifstream graphInput(inputFile);

	if (!graphInput.is_open())
	{
		cout << "Invalid input";
	}

	getline(graphInput, userInput);

	if (!isNumeric(userInput))
	{
		printErrorInput();
	}
	else
	{
		amountOfVertexes = convertStringToNumeric(userInput);
	}

	graph.makeEmptyGraph(amountOfVertexes);

	getline(graphInput, userInput);

	if (!isNumeric(userInput))
	{
		printErrorInput();
	}
	else
	{
		amountOfEdges = convertStringToNumeric(userInput);
	}

	for (int i = 0; i < amountOfEdges; i++)
	{
		if (graphInput.eof())
		{
			printErrorInput();
		}

		getline(graphInput, line);

		convertStringToEdge(line, amountOfVertexes, srcVertex, destVertex, weight);

		if (graph.isAdjacent(srcVertex, destVertex))
		{
			printErrorInput();
		}

		graph.addEdge(srcVertex, destVertex, weight);
	}

	if (graphInput.eof())
	{
		printErrorInput();
	}

	getline(graphInput, line);

	index = line.find(" ");
	srcVertexStr = line.substr(0, index);
	line = line.substr(index + 1);

	if (!isNumeric(srcVertexStr))
	{
		printErrorInput();
	}

	srcVertex = convertStringToNumeric(srcVertexStr);

	index = line.find("\n");
	destVertexStr = line.substr(0, index);

	if (!isNumeric(destVertexStr))
	{
		printErrorInput();
	}

	destVertex = convertStringToNumeric(destVertexStr);

	if (!graphInput.eof())
	{
		printErrorInput();
	}

	if (!graph.isAdjacent(srcVertex, destVertex))
	{
		printErrorInput();
	}

	edgeToDelete = graph.getEdge(srcVertex, destVertex);

	graphInput.close();
}

void printErrorInput()
{
	cout << "Invalid input";
	exit(1);
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
		printErrorInput();
	}

	srcVertex = convertStringToNumeric(srcVertexStr);

	if (!isValidVertex(srcVertex, amountOfVertexes))
	{
		printErrorInput();
	}

	// check valid destVertex
	index = line.find(" ");
	destVertexStr = line.substr(0, index);
	line = line.substr(index + 1);

	if (!isNumeric(destVertexStr))
	{
		printErrorInput();
	}

	destVertex = convertStringToNumeric(destVertexStr);

	if (!isValidVertex(destVertex, amountOfVertexes))
	{
		printErrorInput();
	}

	// check valid weight and Edge
	index = line.find("\n");
	weightStr = line.substr(0, index);

	if (!isNumeric(weightStr))
	{
		printErrorInput();
	}

	weight = convertStringToNumeric(weightStr);
}

bool isValidVertex(int vertex, int maxVertex)
{
	return (vertex >= 1 && vertex <= maxVertex);
}