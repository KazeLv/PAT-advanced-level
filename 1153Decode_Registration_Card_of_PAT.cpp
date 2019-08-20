#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

struct node{
	string s;
	int i;
};
bool cmp(const node& a, const node& b){
	return a.i == b.i ? a.s < b.s : a.i > b.i;
}
int main(){
	int n, m;
	int type;
	string term;
	cin >> n >> m;
	vector<node> v(n);
	for(int i = 0;i < n; i++) 
		cin >> v[i].s >>v[i].i;
	for(int i = 1; i <= m; i++){
		cin >> type >> term;
		printf("Case %d: %d %s\n", i, type, term.c_str());
		int num = 0, sum = 0;
		vector<node> ans;
		if(type == 1){
			for(int j = 0;j < n; j++)
				if(v[j].s[0] == term[0]) ans.push_back(v[j]);
		}else if(type == 2){
			for(int j = 0; j < n; j++){
				if(v[j].s.substr(1,3) == term){
					num++;
					sum += v[j].i;
				}
			}
			if(num != 0) printf("%d %d\n", num, sum);
		}else if(type == 3){
			unordered_map<string, int> m;
			for(int j = 0; j < n; j++){
				if(v[j].s.substr(4,6) == term) m[v[j].s.substr(1,3)]++;
			}
			for(auto i:m) ans.push_back({i.first, i.second});
		}
		
		sort(ans.begin(),ans.end(),cmp);
		for(int j = 0; j < ans.size(); j++){
			printf("%s %d\n", ans[j].s.c_str(), ans[j].i);
		}
		if(((type == 1 || type == 3)&&ans.size()==0)||(type == 2 && num == 0)) printf("NA\n");
	}
	return 0;
}