#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int bt[1001];
int n;
bool flagMax = true, flagMin = true;

void dfs(int index){
	if(index * 2 > n){
		if(index <= n){
			for(int i = 0;i < v.size(); i++)
				printf("%d%s", v[i] , (i == v.size() - 1 ? "\n":" "));
		}
	}else{
		v.push_back(bt[index * 2 + 1]);
		dfs(index * 2 + 1);
		v.pop_back();
		v.push_back(bt[index * 2]);
		dfs(index * 2);
		v.pop_back();
	}
}

int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> bt[i];
	
	v.push_back(bt[1]);
	dfs(1);

	for(int i = 2; i <= n; i++){
		if(bt[i/2] > bt[i]) flagMin = false;
		if(bt[i/2] < bt[i]) flagMax = false;
	}

	if(flagMin) cout << "Min Heap";
	else cout << (flagMax ? "Max Heap" : "Not Heap");
	return 0;
}