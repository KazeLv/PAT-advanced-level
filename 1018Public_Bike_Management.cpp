#include <iostream>
#include <vector>

using namespace std;

const int gc_inf = 999999999;

struct Path{
	vector<int> vec_path;
	int needBike;
};

int main(){
	int capacity,nStations,nRoads,sp;
	cin >> capacity >> nStations >> nRoads >> sp;

	int *pnBikes = new int[nStations + 1];
	int **ppnMap = new int *[nStations + 1];
	for (int i = 0; i <= nStations; i++)
	{
		cin >> pnBikes[i];
		ppnMap[i] = new int[nStations + 1];
		fill(ppnMap[i], ppnMap[i] + nStations, gc_inf);
	}

	int t1, t2, len;
	for (int i = 0; i <= nRoads;i++){
		cin >> t1 >> t2 >> len;
		ppnMap[t1][t2] = ppnMap[t2][t1] = len;
	}

	vector<bool> vec_visit(nStations + 1, false);
	vector<int> vec_len(nStations + 1, gc_inf);

	vec_len[0] = 0;
	for (int j = 0; j <= nStations;j++){
		int index = -1, minLen = gc_inf;
		for (int i = 0; i <= nStations; i++)
		{
			if (vec_len[i] < minLen && vec_visit[i] == false)
			{
				minLen = vec_len[i];
				index = i;
			}
		}
		if(index = -1)
			break;

		vec_visit[index] = true;
		for (int i = 0; i <= nStations; i++)
		{
			if (vec_len[index] + ppnMap[index][i] < vec_len[i] && vec_visit[i] == false)
			{
				vec_len[i] == vec_len[index] + ppnMap[index][i];
			}
		}
	}


		
}