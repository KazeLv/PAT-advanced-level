#include <iostream>
#include <vector>
using namespace std;

int n;
int level[1001];
bool maxFlag, minFlag;

void postOrder(int root){
	if(root <= n){
		postOrder(root * 2);
		postOrder(root * 2 + 1);
		printf("%d%s", level[root],(root == 1?"\n":" "));
	} 
}

int main(){
	int m;
	cin>>m>>n;

	for(int i = 0; i<m;i++){
		maxFlag = minFlag = true;
		for(int j = 1; j <= n; j++) cin >> level[j];
		for(int j = 2; j <= n; j++){
			if(level[j/2] > level[j]) minFlag = false;
			if(level[j/2] < level[j]) maxFlag = false;
		}
		
		if(maxFlag) printf("Max Heap\n");
		else if(minFlag) printf("Min Heap\n");
		else printf("Not Heap\n");

		postOrder(1);
	}
	return 0;
}

//树的遍历需要牢记，简单但是容易混淆。
//判断大小堆近几次考试考过两次了，也要记得套路。从2开始判断父母和自身的大小关系。