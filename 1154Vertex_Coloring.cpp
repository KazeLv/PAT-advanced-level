#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct node{int first, second;};

int main(){
	int n, m, k;
	cin >> n >> m;

	vector<node> e(m);
	for(int i = 0; i < m; i++)
		cin >> e[i].first >> e[i].second;
	
	cin >> k;
	vector<int> c(n);
	set<int> setcolor;
	bool flag;
	for(int i = 0; i < k; i++){
		flag = true;
		for(int j = 0; j < n; j++){
			cin >> c[j];
		}

		for(int j = 0;j < m; j++){
			if(c[e[j].first] == c[e[j].second]){
				flag = false;
				break;
			}
		}

		setcolor.clear();
		if(flag == false) printf("No\n");
		else{
			setcolor.insert(c.begin(), c.end());
			printf("%d-coloring\n", setcolor.size());
		}
	}
	return 0;
}