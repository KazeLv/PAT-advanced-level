#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	int g1, g2;

	cin >> n>>m;
	map<int, vector<int>> map;
	for(int i = 0; i<n;i++){
		cin >> g1 >> g2;
		map[g1].push_back(g2);
		map[g2].push_back(g1);
	}

	int l;
	bool flag = true;
	for(int i = 0;i<m;i++){
		cin >> l;
		vector<int> list(l);
		int a[100000] = {0};
		for(int j = 0; j<l; j++){
			cin>>list[j];
			a[list[j]] = 1;
		}

		flag =true;
		for(int j = 0; j<l; j++){
			for(int k = 0; k<map[list[j]].size(); k++){
				if (a[map[list[j]][k]] == 1){
					flag = false;
					break;
				}
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

//使用find函数搜索map会超时，因此采用a数组，以货物ID为下标存储各种货物的情况；
//最后遍历清单每种货物的冲突数组，如果存在冲突物品则设flag为false