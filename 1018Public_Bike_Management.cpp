#include <iostream>

using namespace std;

int main(){
	int capacity,nStations,nRoads,sp;
	cin >> capacity >> nStations >> nRoads >> sp;

	int *pnBikes = new int[nStations + 1];
	int **ppnMap = new int *[nStations + 1];
	for (int i = 0; i <= nStations; i++)
	{
		cin >> pnBikes[i];
		ppnMap[i] = new int[nStations + 1];
		fill(ppnMap[i], ppnMap[i] + nStations, INFINITY);
	}

	int t1, t2, len;
	for (int i = 0; i <= nRoads;i++){
		cin>>t1>>t2>>len;
		ppnMap[t1][t2] = ppnMap[t2][t1] = len;
	}
	
}