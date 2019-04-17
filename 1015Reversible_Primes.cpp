#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int getValueInDecimal(string &digits,int radix){
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
		int tmp = n;
		string strReverse;
		while(tmp>0){
			strReverse.append(to_string(tmp % d));
			tmp /= d;
		}
		int reverseN = getValueInDecimal(strReverse, d);

		if(isPrime(n)&&isPrime(reverseN))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;

		cin >> n;
	}

	return 0;
}

/*
the description of this question is ambiguous...the real meaning of it is:
1. n is a decimal number
2. we need to transfer n to radix d, then reverse it
3. get the decimal value of reversed number
4. judge if n and reverse number are both primes
*/