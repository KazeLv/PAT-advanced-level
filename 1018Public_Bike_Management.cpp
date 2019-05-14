// #include <iostream>
// #include <vector>

// using namespace std;

// const int gc_inf = 999999999;

// struct Path{
// 	vector<int> vec_path;
// 	int needBike;
// };

// int main(){
// 	int capacity,nStations,nRoads,sp;
// 	cin >> capacity >> nStations >> nRoads >> sp;

// 	int *pnBikes = new int[nStations + 1];
// 	int **ppnMap = new int *[nStations + 1];
// 	for (int i = 0; i <= nStations; i++)
// 	{
// 		cin >> pnBikes[i];
// 		ppnMap[i] = new int[nStations + 1];
// 		fill(ppnMap[i], ppnMap[i] + nStations, gc_inf);
// 	}

// 	int t1, t2, len;
// 	for (int i = 0; i <= nRoads;i++){
// 		cin >> t1 >> t2 >> len;
// 		ppnMap[t1][t2] = ppnMap[t2][t1] = len;
// 	}

// 	vector<bool> vec_visit(nStations + 1, false);
// 	vector<int> vec_len(nStations + 1, gc_inf);

// 	vec_len[0] = 0;
// 	for (int j = 0; j <= nStations;j++){
// 		int index = -1, minLen = gc_inf;
// 		for (int i = 0; i <= nStations; i++)
// 		{
// 			if (vec_len[i] < minLen && vec_visit[i] == false)
// 			{
// 				minLen = vec_len[i];
// 				index = i;
// 			}
// 		}
// 		if(index = -1)
// 			break;

// 		vec_visit[index] = true;
// 		for (int i = 0; i <= nStations; i++)
// 		{
// 			if (vec_len[index] + ppnMap[index][i] < vec_len[i] && vec_visit[i] == false)
// 			{
// 				vec_len[i] == vec_len[index] + ppnMap[index][i];
// 			}
// 		}
// 	}	
// }

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int inf = 99999999;
int cmax, n, sp, m;
int minNeed = inf, minBack = inf;
int e[510][510], dis[510], weight[510];
bool visit[510];
vector<int> pre[510], path, temppath;
void dfs(int v)
{
	temppath.push_back(v);
	if (v == 0)
	{
		int need = 0, back = 0;
		for (int i = temppath.size() - 1; i >= 0; i--)
		{
			int id = temppath[i];
			if (weight[id] > 0)
			{
				back += weight[id];
			}
			else
			{
				if (back > (0 - weight[id]))
				{
					back += weight[id];
				}
				else
				{
					need += ((0 - weight[id]) - back);
					back = 0;
				}
			}
		}
		if (need < minNeed)
		{
			minNeed = need;
			minBack = back;
			path = temppath;
		}
		else if (need == minNeed && back < minBack)
		{
			minBack = back;
			path = temppath;
		}
		temppath.pop_back();
		return;
	}
	for (int i = 0; i < pre[v].size(); i++)
		dfs(pre[v][i]);
	temppath.pop_back();
}
int main()
{
	fill(e[0], e[0] + 510 * 510, inf);
	fill(dis, dis + 510, inf);
	scanf("%d%d%d%d", &cmax, &n, &sp, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &weight[i]);
		weight[i] = weight[i] - cmax / 2;
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		scanf("%d", &e[a][b]);
		e[b][a] = e[a][b];
	}
	dis[0] = 0;
	for (int i = 0; i <= n; i++)
	{
		int u = -1, minn = inf;
		for (int j = 0; j <= n; j++)
		{
			if (visit[j] == false && dis[j] < minn)
			{
				u = j;
				minn = dis[j];
			}
		}
		if (u == -1)
			break;
		visit[u] = true;
		for (int v = 0; v <= n; v++)
		{
			if (visit[v] == false && e[u][v] != inf)
			{
				if (dis[v] > dis[u] + e[u][v])
				{
					dis[v] = dis[u] + e[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}
				else if (dis[v] == dis[u] + e[u][v])
				{
					pre[v].push_back(u);
				}
			}
		}
	}
	dfs(sp);
	printf("%d 0", minNeed);
	for (int i = path.size() - 2; i >= 0; i--)
		printf("->%d", path[i]);
	printf(" %d", minBack);
	return 0;
}