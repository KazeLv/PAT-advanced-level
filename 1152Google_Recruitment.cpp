#include <iostream>
#include <string>

using namespace std;

bool isPrime(int num){
	if(num==0||num==1) return false;
	for(int i = 2; i * i <= num; i++)
		if(num % i == 0) return false;
	return true;
}

int main(){
	int l, k;
	string s;
	cin >> l >> k >> s;

	for(int i = 0 ; i <= l - k; i++){
		string t = s.substr(i, k);
		int num = stoi(t);

		if(isPrime(num)){
			cout << t;
			return 0;
		}
	}
	cout << "404" << endl;

	return 0;
}