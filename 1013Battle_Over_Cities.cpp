#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool visit[1000];

void DFS(int city,int n,int **ppnMap){
	visit[city] = true;
	for (int i = 1; i <= n;i++){
		if(visit[i]==false && ppnMap[city][i] == 1){
			DFS(i, n, ppnMap);
		}
	}
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;

	int **ppnMap = new int *[n + 1]; 				//create map and initiate elements to 0
	for (int i = 1; i <= n; i++){
		ppnMap[i] = new int[n]();
	}

	int c1, c2;
	for (int i = 0; i < m; i++){
		cin >> c1 >> c2;
		ppnMap[c2][c1] = ppnMap[c1][c2] = 1;
	}

	int lost;
	for (int i = 0; i < k; i++){
		cin >> lost;

		fill(visit, visit + 1000, false);
		visit[lost] = true;
		//stack<int> stack_visit;
		int cnt = 0;								//count of connected subgraph
		
		for (int j = 1; j <= n; j++)
		{
			if(visit[j]==false){
				//BFS traverse
				// stack_visit.push(j);
				// while(!stack_visit.empty()){
				// 	int city = stack_visit.top();
				// 	stack_visit.pop();
				// 	visit[city] = true;
				// 	for (int k = 1; k <= n; k++){
				// 		if(ppnMap[city][k] == 1 && visit[k]==false){
				// 			stack_visit.push(k);
				// 		}
				// 	}
				// }

				//DFS traverse
				DFS(j, n, ppnMap);
				cnt++;
			}
		}
		cout << cnt - 1 << endl;
	}
		return 0;
}

/* 
tip: facing problem about connected subgraph, setting the vertex's visit value as true before searching can be same as delete it 

problem: get "time over" with BFS, but DFS can meet the time limit...i guess the reason is BFS use std::queue or std::stack, which will take more time on operations than simple array
*/