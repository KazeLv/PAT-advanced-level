#include <iostream>
#include <string>
#include <cmath>

using namespace std;

long long getValueInDecimal(string &digits, long long radix)
{
	long long res = 0;
	for (string::size_type i = 0; i < digits.size(); i++)
	{
		char curDigit = digits[digits.size() - 1 - i];
		char cZero = (curDigit >= '0' && curDigit <= '9') ? '0' : 'a' - 10;
		res += (curDigit - cZero) * pow(radix, i);
	}
	return res;
}

long long getRadixByDecimal(string &digits, long long value)
{
	char maxDigit = digits[0];											//find the max number of all digits
	for (string::size_type i = 1; i < digits.size(); i++)								//
		if (digits[i] > maxDigit)										//
			maxDigit = digits[i];										//
	char cZero = (maxDigit >= '0' && maxDigit <= '9') ? '0' : 'a' - 10; //the max digit plus one is the minimum of possible radixes
	long long radix = maxDigit - cZero + 1;									//
	if(radix<2) radix = 2;

	bool flag = false;
	long long left = radix;													//find the radix by binary search
	long long right = (value > 1 ? value : 1) + 1;
	long long mid;
	while(left<=right) {
		mid = (left + right) / 2;
		long long tmp = getValueInDecimal(digits, mid);
		if(tmp == value){
			flag = true;
			break;
		}
		else if (tmp>value||tmp<0)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return flag ? mid : -1;
}

int main()
{
	string n1, n2;
	int tag;
	long long radix_told;
	cin >> n1 >> n2 >> tag >> radix_told;

	string value_told = (tag == 1 ? n1 : n2);
	string value_another = (tag == 1 ? n2 : n1);

	long long value_10 = getValueInDecimal(value_told, radix_told);

	long long radix_another = getRadixByDecimal(value_another, value_10);
	if (radix_another == -1)
	{
		cout << "Impossible" << endl;
	}
	else
	{
		cout << radix_another << endl;
	}
	return 0;
}

/*
remember two things:
1. if report a message of time over, change search algorithm.(binary search, for example)
2. any question about numeric calculation, use long long!!!! or you will get ERROR because of overflow!!!
*/