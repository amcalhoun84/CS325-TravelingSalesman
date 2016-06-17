#include "nearestneighbor.hpp"
#include "2opt.hpp"
#include "travelingSalesman.hpp"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

vector<int> bruteTour(adjacencyMatrix, numCities);

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout << "Usage: tsp-brute filename\n"
		return 1;
	}

	clock_t start, end;
	start = clock();

	vector<vector <int> > adjacencyMatrix;
	getInput(argv[1], adjacencyMatrix);
	int numCities = adjacencyMatrix.size();

	vector<int> tour = bruteTour(adjacencyMatrix, numCities);
	cout << "Brute Force Algorithm: " << endl;

	for(int i = 0; i < numCities-1; i++)
	{
		cout << tour[i] << '\t';
	}

	int cost = getCost(adjacencyMatrix, tour);

	cout << endl;

	int cost = getCost(adjacencyMatrix, tour);
	cout << "Total Cost: " << cost << endl;

	


}