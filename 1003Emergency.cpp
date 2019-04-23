#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Way {
	int m_nLength;
	int m_nRescues;
};

const int inf = 999999999;

int main() {
	int nCities, nRoads;
	int nStart, nEnd;
	cin >> nCities >> nRoads >> nStart >> nEnd;     //read the first line for information

	int **ppnMap = new int*[nCities];
	int *pnRescues = new int[nCities];
	vector<bool> vec_visit;
	for (int i = 0; i < nCities; i++) {				//construct standard map of graph
		ppnMap[i] = new int[nCities];
		for (int j = 0; j < nCities; j++) {
			if (i == j) ppnMap[i][j] = 0;
			else ppnMap[i][j] = inf;
		}
		vec_visit.push_back(false);
		cin >> pnRescues[i];
	}

	for (int i = 0; i < nRoads; i++) {
		int ter1, ter2, len;						//add roads to map
		cin >> ter1 >> ter2 >> len;
		ppnMap[ter1][ter2] = len;
		ppnMap[ter2][ter1] = len;
	}

	int *pnDis = new int[nCities];
	int *pnMostRescues = new int[nCities];
	int *pnShortestNum = new int[nCities];

	fill(pnDis,pnDis+nCities,inf);
	copy(pnRescues,pnRescues+nCities,pnMostRescues);
	fill(pnShortestNum,pnShortestNum+nCities,0);

	pnDis[nStart] = 0;
	pnShortestNum[nStart] = 1;
	for(int i = 0; i < nCities ; i++){
		int minCity = -1, shortestRoad = inf;
		for(int j = 0; j < nCities; j++){
			if(vec_visit[j] == false && pnDis[j] < shortestRoad){
				minCity = j;
				shortestRoad = pnDis[j];
			}
		}
		if(minCity == -1) break;

		vec_visit[minCity] = true;
		for(int k = 0; k < nCities; k++){
			if(vec_visit[k]==false &&ppnMap[minCity][k]!=inf){
				if(shortestRoad + ppnMap[minCity][k] < pnDis[k]){
					pnDis[k] = shortestRoad + ppnMap[minCity][k];
					pnShortestNum[k] = pnShortestNum[minCity];
					pnMostRescues[k] = pnMostRescues[minCity] + pnRescues[k];
				}
				else if (shortestRoad + ppnMap[minCity][k] == pnDis[k]){
					pnShortestNum[k] = pnShortestNum[k]+pnShortestNum[minCity];
					if(pnMostRescues[minCity] + pnRescues[k] > pnMostRescues[k]){
						pnMostRescues[k] = pnMostRescues[minCity] + pnRescues[k];
					}
				}
			}
		}
	}

	cout<<pnShortestNum[nEnd]<<" "<<pnMostRescues[nEnd];

	for (int i = 0; i < nCities; i++) delete[] ppnMap[i];			//free memory
	delete[] ppnMap;												//
	delete[] pnRescues;												//
	delete[] pnDis;
	delete[] pnMostRescues;
	delete[] pnShortestNum;

	return 0;
}

/* 
complete by changed dijkstra algorithm
add array for the number of shortest ways and array for mostRescues
update data when find a shortest way or equal way 
*/