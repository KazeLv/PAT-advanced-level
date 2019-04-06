#include <iostream>
#include <queue>

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

	queue<int> que_traverse;
	queue<int> que_leafCount;

	//traverse tree in level sequence
	que_traverse.push(1);
	while(!que_traverse.empty()){
		int len = que_traverse.size();										//store number of nodes in this level
		int iter;
		que_leafCount.push(0);
		for(int i = 0;i<len;i++){
			iter = que_traverse.front();
			que_traverse.pop();
			if(tree.nodes[iter].firstChild==0) que_leafCount.back()++;		//hasn't child,count of leaf nodes increase
			else{
				que_traverse.push(tree.nodes[iter].firstChild);				//push all child to que_traverse for next level
				iter = tree.nodes[iter].firstChild;							//
				while(tree.nodes[iter].nextSibling!=0){						//
					que_traverse.push(tree.nodes[iter].nextSibling);		//
					iter = tree.nodes[iter].nextSibling;					//
				}
			}
		}
	}
	
	while(!que_leafCount.empty()){
		cout<<que_leafCount.front();
		que_leafCount.pop();
		if(!que_leafCount.empty()) cout<<" ";
	}
    return 0;
}

/*
seceed once!
based on a child-sibling tree,traverse the tree in level sequence(based on queue)
*/