#ifndef NEARESTNEIGHBOR_H
#define NEARESTNEIGHBOR_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<int> > randomAdjacencyMatrix(int numberCities); // produce a randomzied city list.
vector<int> nnTour(vector<vector<int> > adjacencyMatrix, int numCities);
int getCost(vector<vector<int> > adjacencyMatrix, vector<int> tour);

#endif // NEARESTNEIGHBOR_H
