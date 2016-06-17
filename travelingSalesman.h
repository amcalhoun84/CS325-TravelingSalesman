#include "nearestneighbor.hpp"
#include "travelingSalesman.hpp"


void getInput(string fileName, vector<vector<int> > &adjacencyMatrix)
{
	vector<City> cityList;
	ifstream inputFile;
	string readLine;
	inputFile.open(fileName.c_str());
	while(getline(inputFile, readLine))
	{
		istringstream iss(readLine);
		City inputCity;
		iss >> inputCity.id;
		iss >> inputCity.x;
		iss >> inputCity.y;

		cityList.push_back(inputCity);
	}

	inputFile.close();

	int numCities = cityList.size();
	adjacencyMatrix.resize(numCities, vector<int>(numCities, -1));

	for(int i = 0; i < numCities; i++)
	{
		for(int j = 0; j < numCities; j++)
		{
			// distance formula, rounded to nearest integer -- d = sqrt(((x2-x1) + (y2-y1))^2)
			adjacencyMatrix[i][j] = round(sqrt(pow((cityList[i].x - cityList[j].x), 2) + pow((cityList[i].y - cityList[j].y), 2)));
		}
	}
}