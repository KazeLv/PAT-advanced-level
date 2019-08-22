#include <iostream>
#include <vector>
using namespace std;

int e[1001][1001];

int main(){
	int n, m;
	cin>>n>>m;

	int v1, v2;
	for(int i = 0; i< m; i++){
		cin>>v1>>v2;
		e[v1][v2] = 1;
	}

	vector<int> ans;
	int k;
	cin>>k;
	for(int i = 0;i < k ;i++){
		vector<int> permu(n);
		for(int j = 0; j < n; j++) cin>>permu[j];
		for(int j = n-1; j > 0;j--){
			if(e[permu[j]][permu[j-1]] != 0){
				ans.push_back(i);
				break;
			}
		}
	}

	for(int i = 0; i<ans.size();i++) printf("%d%s",ans[i],(i==ans.size()-1?"\n":" "));
	return 0;
}