#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getValueInDecimal(string &digits, int radix)
{
	int res = 0;
	for (string::size_type i = 0; i < digits.size(); i++)
	{
		char curDigit = digits[digits.size() - 1 - i];
		char cZero = (curDigit >= '0' && curDigit <= '9') ? '0' : 'a' - 10;
		res += (curDigit - cZero) * pow(radix, i);
	}
	return res;
}

int getRadixByDecimal(string &digits, int value)
{
	char maxDigit = digits[0];											//find the max number of all digits
	for (string::size_type i = 1; i < digits.size(); i++)								//
		if (digits[i] > maxDigit)										//
			maxDigit = digits[i];										//
	char cZero = (maxDigit >= '0' && maxDigit <= '9') ? '0' : 'a' - 10; //the max digit plus one is the minimum of possible radixes
	int radix = maxDigit - cZero;										//

	if (getValueInDecimal(digits, radix) > value) 						//smallest radix will get a bigger result ,impossible
		return -1;

	int left = radix + 1;												//find the radix by binary search
	int right = (value > 1 ? value : 1) + 1;
	int mid;
	while(left<=right) {
		mid = (left + right) / 2;
		int tmp = getValueInDecimal(digits, mid);
		if(tmp == value)
			break;
		else if (tmp>value||tmp<0)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return mid;
}

int main()
{
	string n1, n2;
	int tag, radix_told;
	cin >> n1 >> n2 >> tag >> radix_told;

	string value_told = (tag == 1 ? n1 : n2);
	string value_another = (tag == 1 ? n2 : n1);

	int value_10 = getValueInDecimal(value_told, radix_told);

	int radix_another = getRadixByDecimal(value_another, value_10);
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