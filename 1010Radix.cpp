#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int getValueInDecimal(string& digits,int radix){
	int res = 0;
	for(int i = 0;i<digits.size();i++){
		char curDigit = digits[digits.size()-1-i];
		char cZero = (curDigit>='0'&&curDigit<='9')?'0':'a'-10;
		res += (curDigit-cZero)*pow(radix,i);
	}
	return res;
}

int getRadixByDecimal(string &digits, int value){
	int radix = 2;
	if(getValueInDecimal(digits,radix)>value) return -1;
	while(getValueInDecimal(digits,radix)<value) radix++;
	return radix;
}

int main(){
	string n1, n2;
	int tag, radix_told;
	cin >> n1 >> n2 >> tag >> radix_told;

	string value_told = (tag == 1 ? n1 : n2);
	string value_another = (tag == 1 ? n2 : n1);

	int value_10 = getValueInDecimal(value_told,radix_told);

	int radix_another = getRadixByDecimal(value_another,value_10);
	if(radix_another == -1){
		cout << "Impossible" << endl;
	}else{
		cout << radix_another << endl;
	}

	//Impossible
	return 0;
}