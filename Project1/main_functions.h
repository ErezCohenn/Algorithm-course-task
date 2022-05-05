#pragma once
#include "MST_algorithms.h"
#include "Edge.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "Graph.h"

using std::endl;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::getline;

void runMstAlgorithms(int argc, char* argv[]);
void makeGraphFromFileInput(ifstream& graphInput, WeightedGraph& graph, Edge*& edgeToDelete);
bool isNumeric(const string& strToCheck);
int convertStringToNumeric(const string& strToConvert);
void convertStringToEdge(string& line, int amountOfVertexes, int& srcVertex, int& destVertex, int& weight);
bool isValidVertex(int vertex, int maxVertex);
void removeEdgeFromGraphEdgesArr(vector<Edge*>& edgesArray, Edge* edgeToDelete);