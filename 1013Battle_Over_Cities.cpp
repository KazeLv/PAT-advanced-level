#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;

	int **ppnMap = new int *[n + 1]; 		//create map and initiate elements to 0
	for (int i = 1; i <= n; i++){
		ppnMap[i] = new int[n]();
	}
	// for (int i = 1; i <= n; i++){		//initiate map's elements to -1(means no way)
	// 	for (int j = 1; j <= n; j++){
	// 		ppnMap[i][j] = -1;
	// 	}
	// }

	int c1, c2;
	for (int i = 0; i < m; i++){
		cin >> c1 >> c2;
		ppnMap[c1][c2] = 1;
		ppnMap[c2][c1] = 1;
	}

	int lost;
	for (int i = 0; i < k; i++){
		cin >> lost;
		for (int j = 1; j <= n;j++){
			if(ppnMap[lost][j] == 1)
			{
				ppnMap[lost][j] = -1;
				ppnMap[j][lost] = -1;
			}
		}

		vector<bool> vec_visit(n + 1, false);
		stack<int> stack_visit;
		int cnt = 0;								//count of connected subgraph
		for (int j = 1; j <= n; j++){
			if(vec_visit[j]==false){
				//BFS traverse
				stack_visit.push(j);
				while(!stack_visit.empty()){
					int city = stack_visit.top();
					stack_visit.pop();
					vec_visit[city] = true;
					for (int k = 1; k <= n; k++){
						if(ppnMap[city][k] == 1 && vec_visit[k]==false){
							stack_visit.push(k);
						}
					}
				}
				cnt++;
			}
		}
		cout << cnt - 2 << endl;

		for (int j = 1; j <= n; j++)
		{
			if (ppnMap[lost][j] == -1)
			{
				ppnMap[lost][j] = 1;
				ppnMap[j][lost] = 1;
			}
		}
	}
		return 0;
}