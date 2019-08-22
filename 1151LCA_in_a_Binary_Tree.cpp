#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> pos;
vector<int> in, pre;

void lca(int rootPre, int left, int right, int u, int v){
	if(left > right) return;
	int rootIn =pos[pre[rootPre]], uIn = pos[u], vIn = pos[v];

	if(uIn == rootIn) printf("%d is an ancestor of %d.\n", u, v);
	else if(vIn == rootIn) printf("%d is an ancestor of %d.\n", v, u);
	else if(uIn < rootIn && vIn < rootIn) lca(rootPre + 1, left, rootIn - 1, u, v);
	else if(uIn > rootIn && vIn > rootIn) lca(rootPre + 1 +(rootIn - left), rootIn + 1, right, u, v);
	else printf("LCA of %d and %d is %d.\n",u ,v, in[rootIn]);
}

int main(){
	int m, n;
	cin>>m>>n;
	in.resize(n + 1); pre.resize(n + 1);
	int u, v;
	for(int i = 1; i<=n;i++) {
		cin>>in[i];
		pos[in[i]] = i;
	}
	for(int i = 1; i<=n;i++) cin>>pre[i];
	for(int i = 0; i<m;i++){
		cin>>u>>v;
		if(pos[u] == 0 && pos[v] == 0) printf("ERROR: %d and %d are not found.\n", u, v);
		else if(pos[u] == 0 || pos[v] == 0) printf("ERROR: %d is not found.\n", (pos[u] == 0 ? u: v));
		else lca(1, 1, n, u, v);
	}
	return 0;
}

//于其之后遍历寻找坐标，不如直接构造一个值到坐标的映射，空间换时间且易于理解