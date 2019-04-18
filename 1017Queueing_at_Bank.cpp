#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Customer{
	int arriveSec;
	int pSec = 1;
	int leaveSec = 0;
};

int main(){
	int n, k;
	cin >> n >> k;

	vector<Customer> vec_customer;
	for (int i = 0; i < n; i++){
		Customer cTmp;
		int h, m, s;
		scanf("%d:%d:%d %d", &h, &m, &s, &cTmp.pSec);
		cTmp.arriveSec = h * 3600 + m * 60 + s;
		cTmp.pSec *= 60;
		if(cTmp.arriveSec>(17*3600+1))
			continue;
		vec_customer.push_back(cTmp);
	}
	sort(vec_customer.begin(), vec_customer.end(), [](Customer &a, Customer &b) { return a.arriveSec < b.arriveSec; });

	int servedN = vec_customer.size();

	Customer *serving = new Customer[k];

	int waitTotal = 0;
	int sNow = 8 * 3600;

	vector<int>::size_type index = 0;
	while(index < vec_customer.size()){
		for (int i = 0; i < k; i++){
			serving[i].pSec--;
			if(serving[i].pSec==0 && !vec_customer.empty()){
				
				serving[i] = vec_customer.back();
				vec_customer.pop_back();
			}
		}
	}
}