#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Customer{
	int arriveSec;
	int serveSec;
};

int main(){
	int n, k;
	cin >> n >> k;

	vector<Customer> vec_customer;
	for (int i = 0; i < n; i++){
		Customer cTmp;
		int h, m, s;
		scanf("%d:%d:%d %d", &h, &m, &s, &cTmp.serveSec);
		cTmp.arriveSec = h * 3600 + m * 60 + s;
		cTmp.serveSec *= 60;
		if(cTmp.arriveSec > (17*3600))		//customers who arrive after 17:00:00 will not be served and count
			continue;
		vec_customer.push_back(cTmp);
	}
	sort(vec_customer.begin(), vec_customer.end(), [](Customer &a, Customer &b) { return a.arriveSec < b.arriveSec; });
	vector<int> vec_window_finish(k, 3600 * 8);
	double waitTotal = 0.0;
	for (int i = 0; i < vec_customer.size(); i++){
		int iTmp = 0, minFinish = vec_window_finish[0];
		for (int j = 0; j < vec_window_finish.size(); j++){
			if(vec_window_finish[j]<minFinish){
				iTmp = j;
				minFinish = vec_window_finish[j];
			}
		}
		
		if(vec_customer[i].arriveSec >= vec_window_finish[iTmp]){
			vec_window_finish[iTmp] = vec_customer[i].arriveSec + vec_customer[i].serveSec;
		}else{
			waitTotal += vec_window_finish[iTmp] - vec_customer[i].arriveSec;
			vec_window_finish[iTmp] += vec_customer[i].serveSec;
		}
	}

	if (vec_customer.size() == 0)
		cout << "0.0" << endl;
	else
		cout << setiosflags(ostream::fixed) << setprecision(1) << waitTotal / 60 / vec_customer.size() << endl;
}

/*
got a new way to solve simulation problem 
*/