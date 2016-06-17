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

int main(int argc, char* argv[])
{
	if(argc != 2)
	{
		cout << "Usage: tsp filename\n";
		return 1;
	}

	double start, end; 
	start = clock();

	vector<vector<int> > adjacencyMatrix;
	getInput(argv[1], adjacencyMatrix);
	int numCities = adjacencyMatrix.size();

	vector<int> tour = nnTour(adjacencyMatrix, numCities);
	cout << "Nearest neighbor: " << endl;

	for(int i = 0; i < numCities-1; i++)
	{
		cout << tour[i] << '\t';
	}

	cout << endl;

	int cost = getCost(adjacencyMatrix, tour);
	cout << "Total cost: " << cost << endl;

	vector<int> twoOptTour = twoOpt(tour, adjacencyMatrix, numCities, start);
	vector<int> twoOptTour2 = twoOpt(twoOptTour, adjacencyMatrix, numCities, start);

	ofstream outputFile;
	string inputFile = argv[1];
	inputFile += ".tour";
	outputFile.open(inputFile.c_str());

	cost = getCost(adjacencyMatrix, twoOptTour2);
	outputFile << cost << endl;

	cout << "After pairwise comparison" << endl;
	for(int i=0; i < numCities; i++)
	{

		std::cout << twoOptTour2[i] << '\t';
		outputFile << twoOptTour2[i] << '\n';
	}

	cout << endl;


	outputFile.close();

	end = clock();
	end -= start;

	end /= CLOCKS_PER_SEC;

	
	cout << "Total cost: " << cost << endl;
	cout << "Total Time in Seconds: " << end << endl;

	return 0;

}