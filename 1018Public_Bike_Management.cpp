#include <iostream>
#include <vector>

using namespace std;

const int gc_inf = 999999999;

int capacity, nStations, nRoads, sp;
int ppnMap[501][501];
int pnBikes[501];
int shortestLen = gc_inf;
vector<vector<int>> vec_shortestWays;

void BFS(vector<bool> vec_visit, vector<int> vec_path, int len);

int main()
{
	cin >> capacity >> nStations >> sp >> nRoads;

	fill(ppnMap[0], ppnMap[0] + nStations + 1, gc_inf);
	ppnMap[0][0] = 0;
	for (int i = 1; i <= nStations; i++)
	{
		cin >> pnBikes[i];
		fill(ppnMap[i], ppnMap[i] + nStations + 1, gc_inf);
		ppnMap[i][i] = 0;
	}

	int t1, t2, len;
	for (int i = 0; i < nRoads;i++){
		cin >> t1 >> t2 >> len;
		ppnMap[t1][t2] = ppnMap[t2][t1] = len;
	}

	vector<bool> vec_visit(nStations + 1, false);
	vector<int> vec_path;

	vec_visit[0] = true;
	vec_path.push_back(0);
	len = 0;

	BFS(vec_visit, vec_path, len);

	int leastBike = gc_inf;
	int bestWay = 0;
	int index = 0;
	do{
		int nBike = 0;
		int nStation = 0;
		for (int i = 1; i < vec_shortestWays[index].size();i++){
			nBike += pnBikes[vec_shortestWays[index][i]];
			nStation++;
		}
		int needBike = nStation * capacity / 2 - nBike;
		if(needBike<leastBike){
			leastBike = needBike;
			bestWay = index;
		}
		index++;
	} while (index < vec_shortestWays.size());

	cout << leastBike << " ";
	for (int i = 0; i < vec_shortestWays[bestWay].size();i++){
		cout << vec_shortestWays[bestWay][i];
		if (i != vec_shortestWays[bestWay].size()-1){
			cout << "->";
		}else
			cout << " ";
	}
	cout << shortestLen << endl;
}

void BFS(vector<bool> vec_visit, vector<int> vec_path, int len){
	int addr = vec_path.back();
	for (int i = 0; i <= nStations;i++){
		if(vec_visit[i] == false && ppnMap[addr][i] != gc_inf){
			len += ppnMap[addr][i];
			vec_path.push_back(i);
			if(len < shortestLen){
				if(i == sp){
					vec_shortestWays.clear();
					vec_shortestWays.push_back(vec_path);
					shortestLen = len;
				}else{
					vec_visit[i] = true;
					BFS(vec_visit, vec_path, len);
				}
			}else if(len == shortestLen && i == sp){
				vec_shortestWays.push_back(vec_path);
			}
		}
	}
}