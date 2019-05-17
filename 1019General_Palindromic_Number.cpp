#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int nDecimal, nBase;
	vector<int> vecTarget;

	cin >> nDecimal >> nBase;

	while(nDecimal>0){
		vecTarget.push_back(nDecimal % nBase);
		nDecimal /= nBase;
	}

	reverse(vecTarget.begin(), vecTarget.end());

	int i = 0;
	bool isPal = true;
	while(i<=vecTarget.size()/2){
		if (vecTarget[i] != vecTarget[vecTarget.size()-1-i]){
			isPal = false;
			break;
		}
		i++;
	}

	if(isPal){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	for (int i = 0; i < vecTarget.size();i++){
		cout << vecTarget[i];
		if(i!=vecTarget.size()-1){
			cout << " ";
		}
	}
	cout << endl;

	return 0;
}

