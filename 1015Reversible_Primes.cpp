#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int getValueInRadix(string &digits,int radix){
	int value = 0;
	char cZero = (radix <= 10) ? '0' : 'a';
	for (int i = 0; i < digits.size(); i++)
	{
		value += (digits[digits.size() - i - 1] - cZero) * pow(radix, i);
	}
	return value;
}

bool isPrime(int value){
	if (value == 0 || value == 1)
		return false;
	
	bool res = true;
	for (int i = 2; i < value / 2;i++){
		if(value%i==0){
			res = false;
			break;
		}
	}

	return res;
}

int main(){
	int n, d;
	cin >> n;
	while(n>=0){
		cin >> d;
		string strN = to_string(n);						//get original number in 10 radix
		int n_10 = getValueInRadix(strN, d);			//

		string strReverse = to_string(n_10);			//get reverse number
		reverse(strReverse.begin(), strReverse.end());	//
		int reverseN = getValueInRadix(strReverse,10);	//

		if(isPrime(n_10)&&isPrime(reverseN))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		cin >> n;
	}

	return 0;
}