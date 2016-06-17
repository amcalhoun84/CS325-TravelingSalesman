#include "2opt.hpp"
#include "travelingSalesman.hpp"
#include "nearestneighbor.hpp"

using namespace std;

vector<int> twoOpt(vector<int> nnTour, vector<vector<int> > adjacencyMatrix, int numCities, clock_t timer)
{
	int size = nnTour.size();
	bool improve = false;

	vector<int> solutionTour = nnTour;
	clock_t maxTime = CLOCKS_PER_SEC * 15;
	clock_t loopTime;
	clock_t curTime;
	while(!improve && timer < maxTime)
	{
		int bestDistance = getCost(adjacencyMatrix, solutionTour);
		for(int i = 1; i < size - 2; i++)
		{
			for(int k = i+1; k < size - 1; k++)
			{
				vector<int> newTour = swapOpt(solutionTour, i, k, numCities);
				int newDistance = getCost(adjacencyMatrix, newTour);

				// improvements found, go back
				if(newDistance < bestDistance)
				{
					improve = false;
					solutionTour = newTour;
					bestDistance = newDistance;
				}

				curTime = clock();
				loopTime = curTime - timer;
				if(loopTime > maxTime)
				{
					cout << "Time in Seconds: " << double((loopTime / CLOCKS_PER_SEC)) << endl;
					return solutionTour;
				}
			}
		}

		improve = true;
	}

	cout << "Time in Seconds: " << double((loopTime / CLOCKS_PER_SEC)) << '\n';
		return solutionTour;

}

// 2-Opt Explanation: https://en.wikipedia.org/wiki/2-opt

/* 2optSwap(route, i, k) 
{
       1. take route[1] to route[i-1] and add them in order to new_route
       2. take route[i] to route[k] and add them in reverse order to new_route
       3. take route[k+1] to end and add them in order to new_route
       return new_route;

   }
   */

vector<int> swapOpt(vector<int> nnTour, int swapFront, int swapEnd, int numCities)
{
	int size = nnTour.size();
	vector<int> newTour = nnTour;

	for(int i = 0; i < swapFront - 1; i++)
	{
		newTour[i] = nnTour[i];
	}

	int dec = 0;
	for(int i = swapFront; i <= swapEnd; i++)
	{
		newTour[i] = nnTour[swapEnd - dec];
		dec++;
	}

	for(int i = swapEnd+1; i < size; i++)
	{
		newTour[i] = nnTour[i];

	}

	return newTour;
}