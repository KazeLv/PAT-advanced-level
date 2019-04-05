#include <iostream>

using namespace std;

typedef struct node{
	int firstChild;
	int nextSibling;
}treeNode;

typedef struct{
	int number;
	treeNode *nodes;
}Tree;


int main(){
    int n,m;
	cin>>n>>m;

	Tree tree{n,nullptr};
	if(n!=0) tree.nodes = new treeNode[n+1](); //construct root node (n+1,because root is 01)
	else return 0;

	int id,k;
	int firstChild;
	for(int i = 0;i<m;i++){
		cin>>id>>k;
		if(k==0) continue;
		cin>>firstChild;
		tree.nodes[id].firstChild = firstChild;
		int index = firstChild;
		for(int j = 0;j<k-1;j++){
			cin>>tree.nodes[index].nextSibling;
			index = tree.nodes[index].nextSibling;
		}
	}

	
    return 0;
}