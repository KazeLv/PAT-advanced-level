#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin >> n;

	vector<int> word(n+1);
	for(int i = 1; i<= n; i++) cin >> word[i];
	for(int i = 1; i <= n; i++){
		for(int j = i+1; j<=n;j++){
			vector<int> liar, human(n+1, 1);
			human[i] = human[j] = -1;
			for(int k = 1; k<=n;k++){
				if(word[k] * human[abs(word[k])] < 0) liar.push_back(k);
			}
			if(liar.size() == 2 && (human[liar[0]]+human[liar[1]] == 0)){
				cout<<i<<" "<<j<<endl;
				return 0;
			}
		}
	}

	cout << "No Solution"<< endl;
	return 0;
}