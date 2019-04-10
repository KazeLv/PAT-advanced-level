#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Way {
	int m_nLength;
	int m_nRescues;
};

vector<Way> vec_ways;

//recursion to find all ways from start to end
void findWay(int **ppnMap, vector<bool> vec_visit, int *pnRescues, int nCities, int nStart, int nEnd, int nLen, int nRescues) {
	for (int i = 0; i < nCities; i++) {
		if (ppnMap[nStart][i] != -1 && vec_visit[i] == false) {
			vector<bool> vec_tVisit = vec_visit;					//copy visit[] for rescursion need
			vec_tVisit[i] = true;
			int totalLen = nLen + ppnMap[nStart][i];
			int totalRescues = nRescues + pnRescues[i];
			if (i == nEnd) {
				Way way{ totalLen, totalRescues };
				vec_ways.push_back(way);
			}
			else {
				findWay(ppnMap, vec_tVisit, pnRescues, nCities, i, nEnd, totalLen, totalRescues);
			}
		}
	}
}

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
			else ppnMap[i][j] = -1;
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

	vec_visit[nStart] = true;
	findWay(ppnMap, vec_visit, pnRescues, nCities, nStart, nEnd, 0, pnRescues[nStart]);		//find all ways from start to end

	vector<Way> vec_shortestWays;															//find shortest way(s)
	int shortestLen = vec_ways[0].m_nLength;												//
	for (vector<int>::size_type i = 0; i < vec_ways.size(); i++)							//
		if (vec_ways[i].m_nLength < shortestLen) shortestLen = vec_ways[i].m_nLength;		//

	for (vector<int>::size_type i = 0; i < vec_ways.size(); i++)							//
		if (vec_ways[i].m_nLength == shortestLen) vec_shortestWays.push_back(vec_ways[i]);	//

	int mostRescues = vec_shortestWays[0].m_nRescues;														//get maximum rescue in shoetest ways
	for (vector<int>::size_type i = 0; i < vec_shortestWays.size(); i++)									//
		if (vec_shortestWays[i].m_nRescues > mostRescues) mostRescues = vec_shortestWays[i].m_nRescues;		//

	cout << vec_shortestWays.size() << " " << mostRescues << endl;

	for (int i = 0; i < nCities; i++) delete ppnMap[i];			//free memory
	delete ppnMap;												//
	delete pnRescues;											//

	return 0;
}

/* 
complete partly.
there is a segmentation fault returned by PTA and i have no idea about the reason
this is a find-way algorithm(Dijkstra can only find one way)
*/