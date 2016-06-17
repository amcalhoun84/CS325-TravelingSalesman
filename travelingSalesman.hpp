#ifndef TRAVELINGSALESMAN_HPP
#define TRAVELINGSALESMAN_HPP

#include "nearestneighbor.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <sstream>
#include <vector>

struct City
{
	int id,
		x,
		y;

};

void getInput(string fileName, vector<vector<int> > &adjMatrix);

#endif 