#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

struct Customer{
	int arriveSec;
	int pSec = 1;
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
		if(cTmp.arriveSec > (17*3600))		//customers who arrive after 17:00:00 will not be served and count
			continue;
		vec_customer.push_back(cTmp);
	}
	sort(vec_customer.begin(), vec_customer.end(), [](Customer &a, Customer &b) { return a.arriveSec > b.arriveSec; });
	int servedN = vec_customer.size();

	int waitTotal = 0;
	int sNow = 8 * 3600;
	int emptyWin = k;
	while(sNow <= (17 * 3600)){
		if(vec_customer.size() > k){											//there still are customers waiting to be served 
			for (int i = 0; i < k-emptyWin; i++)
			{
				Customer &cTmp = vec_customer[vec_customer.size() - 1 - i];
				cTmp.pSec--;
				if (cTmp.pSec == 0)
				{																//if service is finished,
					emptyWin++;													//count of empty window will increase
					vector<Customer>::iterator it = vec_customer.end() - 1 - i; //end erase this customer
					vec_customer.erase(it);										//
				}
			}

			while(emptyWin>0){
				Customer &cTmp = vec_customer[vec_customer.size() - 1 - k + emptyWin];		//get the customer who is new to be served
				waitTotal += sNow - cTmp.arriveSec;											//add his/her waiting time to total counter
				emptyWin--;	
			}
		}else				
			break;
		sNow++;
	}

	if(servedN == 0) cout << 0.0 << endl;
	else cout << setiosflags(ostream::fixed) << setprecision(1) << waitTotal / 60.0 / servedN << endl;
}