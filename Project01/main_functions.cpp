#include "main_functions.h"

void runMstAlgorithms(int argc, char* argv[])
{
	WeightedGraph graph;
	Edge* edgeToDelete = nullptr;
	int resPrim, resKruskal;

	if (argc != 3)
	{
		printErrorInput();
	}
	
	makeGraphFromFileInput(argv[1], graph, edgeToDelete);

	graph.printGraph();

	
	resPrim = MST_algorithms::Prim(graph);

	//MST_algorithms::Kruskal(graph);

	ofstream outputMST(argv[2]);

	if (!outputMST.is_open())
	{
		printErrorInput();
	}

	outputMST << "Prim <" << resPrim << ">" << endl;

	outputMST.close();
	


}

void makeGraphFromFileInput(char inputFile[], WeightedGraph& graph, Edge* edgeToDelete)
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
		cout << "Failed to open the input file";
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

	graph.MakeEmptyGraph(amountOfVertexes);

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

		if (graph.IsAdjacent(srcVertex, destVertex))
		{
			printErrorInput();
		}

		graph.AddEdge(srcVertex, destVertex, weight);
	}

	if (graphInput.eof())
	{
		printErrorInput();
	}

	getline(graphInput, line);

	index = line.find(" ");
	srcVertexStr = line.substr(0, index);
	line = line.substr(index + srcVertexStr.size());

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

	if (!graph.IsAdjacent(srcVertex, destVertex))
	{
		printErrorInput();
	}

	edgeToDelete = graph.getEdge(srcVertex, destVertex);

	graphInput.close();
}

void printErrorInput()
{
	cout << "wrong input";
	exit(1);
}

bool isNumeric(const string& strToCheck)
{
	for (int i = 0; i < strToCheck.size(); i++)
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
	
	index = line.find(" ");
	srcVertexStr = line.substr(0, index);
	line = line.substr(index + srcVertexStr.size());

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
	line = line.substr(index + destVertexStr.size());

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