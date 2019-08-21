#include <iostream>
#include <vector>
#include <set>
using namespace std;

int g[201][201];

int main(){
	int n, m, k;
	cin>>n>>m;
	int v1,v2,e;
	for(int i = 0; i<m;i++){
		cin>>v1>>v2>>e;
		g[v1][v2] = g[v2][v1] = e;
	}

	int ans = 99999999, index = 0;
	vector<int> dist;
	int visit[201] ;
	cin >> k;
	int num, sum;
	bool flag;
	for (int i = 1; i <= k; i++){
		sum = 0; flag = false;
		cin>>num;
		set<int> s;
		vector<int> v(num);
		for(int j = 0; j<num ;j++){
			cin>>v[j];
			s.insert(v[j]);
		}
		for(int j = 0; j< num-1;j++){
			if(g[v[j]][v[j+1]] == 0) flag = true;
			sum+=g[v[j]][v[j+1]];
		}
		if(flag) printf("Path %d: NA (Not a TS cycle)\n",i);
		else if(v[0]!=v[num-1] || s.size()!=n) printf("Path %d: %d (Not a TS cycle)\n",i,sum);
		else if(num!=n+1){
			printf("Path %d: %d (TS cycle)\n",i,sum);
			if(sum < ans){
				ans = sum;
				index = i;
			}
		}else{
			printf("Path %d: %d (TS simple cycle)\n",i,sum);
			if(sum < ans){
				ans = sum;
				index = i;
			}
		}
	}
	printf("Shortest Dist(%d) = %d\n",index,ans);
	return 0;
}

//简单环路 == 遍历所有点且路径点数为n+1
//图论问题，寻找边界点是关键