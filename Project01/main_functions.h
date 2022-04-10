#pragma once
#include "MST_algorithms.h"
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
void makeGraphFromFileInput(int argc, char* argv[], WeightedGraph& graph, Edge* edgeToDelete);
void printErrorInput();
bool isNumeric(const string& strToCheck);
int convertStringToNumeric(const string& strToConvert);
bool isValidVertex(int vertex, int maxVertex);
//int getEdgeFromFile(ifstream file)
