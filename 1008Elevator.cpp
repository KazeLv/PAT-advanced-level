#include <iostream>
#include <vector>

#define COST_UP 6
#define COST_DOWN 4
#define TIME_STAY 5

using namespace std;

int main() {
	vector<int> vec_list;
	int n, t;
	cin >> n;

	for (int i = 0; i < n; i++) {			//read request list in specified order
		cin >> t;
		vec_list.push_back(t);
	}

	int pos = 0;
	int time = 0;
	for (auto iter = vec_list.cbegin(); iter != vec_list.cend(); iter++) {
		if (*iter > pos) time += (*iter - pos)*COST_UP;
		else time += (pos - *iter)*COST_DOWN;
		time += TIME_STAY;
		pos = *iter;
	}

	cout << time << endl;

	return 0;
}

/*
easy case, but i still made a mistake...
be cautious! 
*/