#include <iostream>
#include <iomanip>

using namespace std;

char result[3] = {'W','T','L'};

struct Bet
{
	char result;
	double odd;
};

Bet peekMostProfit(){
	double odds[3];
	double t, max;
	char res = result[0];
	cin >> max;
	for (int i = 1; i < 3;i++){
		cin >> t;
		if(t>max){
			max = t;
			res = result[i];
		}
	}
	return {res,max};
}

int main(){

	Bet bet1 = peekMostProfit();
	Bet bet2 = peekMostProfit();
	Bet bet3 = peekMostProfit();

	double profit = (bet1.odd * bet2.odd * bet3.odd * 0.65 - 1) * 2;
	cout << bet1.result << " " << bet2.result << " " << bet3.result << " ";
	cout << setiosflags(ostream::fixed) << setprecision(2) << profit;
	return 0;
}