#include <vector>
#include <ctime>
using namespace std;

vector<int> twoOpt(vector<int> nnTour, vector<vector<int> > adjacencyMatrix, int numCities, clock_t timer);
vector<int> swapOpt(vector<int> nnTour, int swapFront, int swapEnd, int numCities);