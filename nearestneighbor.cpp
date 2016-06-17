// nearest neighbors: https://en.wikipedia.org/wiki/Nearest_neighbour_algorithm

#include "travelingSalesman.hpp"
#include "nearestneighbor.hpp"
using namespace std;

vector<vector<int> > randomAdjacencyMatrix(int numCities)
{
	vector<vector<int> > adjacencyMatrix;
	adjacencyMatrix.resize(numCities, vector<int>(numCities, 0));
	int randomNumber;

	for(int i=0; i<numCities; i++)
	{
		for(int j=0; j<=i; j++)
		{
			randomNumber = rand() % 200 + 1;
			if(i==j)
				randomNumber = -1;
			adjacencyMatrix[i][j] = randomNumber;
			adjacencyMatrix[j][i] = randomNumber;
		}
	}

	return adjacencyMatrix;
}

vector<int> nnTour(vector<vector<int> > adjacencyMatrix, int numCities)
{
	int currentCity, nextCity, minDistance;
	vector<int> tour;
	tour.resize(numCities + 1, -1);

	currentCity = 0;
	for(int i=0; i<numCities; i++)
	{
		minDistance = numeric_limits<int>::max();
		tour[i] = currentCity;
		for(int j=0; j<numCities; j++)
		{
			if(j != currentCity && adjacencyMatrix[currentCity][j] < minDistance && !(find(tour.begin(), tour.end(), j) != tour.end()))
			{
				minDistance = adjacencyMatrix[currentCity][j];
				nextCity = j;
			}
		}

		currentCity = nextCity;
	}

	tour[numCities] = 0;
	return tour;
}

int getCost(vector<vector<int> > adjacencyMatrix, vector<int> tour)
{
	int cost, totalCost;
	int tourLength = tour.size();
	int currentCity, nextCity;

	totalCost = 0;

	for(int i=0; i < tourLength-1; i++)
	{
		currentCity = tour[i];
		nextCity = tour[i+1];
		cost = adjacencyMatrix[currentCity][nextCity];
		totalCost += cost;
	}

	return totalCost;
}