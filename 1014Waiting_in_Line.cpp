#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

const int timeClose = 540;
int nResult[1001];

struct Customer{
	int id;
	int time;
};

int main(){
	int n, m, k, q;
	cin >> n >> m >> k >> q;

	vector<queue<Customer>> vec_queues(n);		//initiate n queues for windows
	queue<Customer> que_wait;					//customers waiting outside yellow lines

	int tmp;
	for (int i = 0; i < k;i++){
		cin >> tmp;
		que_wait.push(Customer{i + 1, tmp});
	}

	int timeNow = 0;
	while(timeNow <= timeClose){				//simulate the flow of time
		int cnt = 0;							//count of avaliable position inside yellow lines
		for (int i = 0; i < n;i++){
			if(!vec_queues[i].empty())
			{
				vec_queues[i].front().time--;
				if(vec_queues[i].front().time == 0){
					nResult[vec_queues[i].front().id] = timeNow;
					vec_queues[i].pop();
				}
			}
			cnt += m - vec_queues[i].size();
		}

		while(cnt>0&&!que_wait.empty()){
			Customer cTmp = que_wait.front();
			que_wait.pop();

			int shortestWindow = 0;
			int shortestLen = vec_queues[shortestWindow].size();
			for (int i = 1; i < n; i++){
				if(vec_queues[i].size()<shortestLen){
					shortestWindow = i;
					shortestLen = vec_queues[i].size();
				}
			}
			vec_queues[shortestWindow].push(cTmp);
			cnt--;
		}
		timeNow++;
	}

	//bank close, customers who still waiting will get "sorry"
	for (int i = 0; i < n; i++){
		while(!vec_queues[i].empty()){
			Customer cTmp = vec_queues[i].front();
			vec_queues[i].pop();
			nResult[cTmp.id] = -1;
		}
	}

	while(!que_wait.empty()){
		Customer cTmp = que_wait.front();
		que_wait.pop();
		nResult[cTmp.id] = -1;
	}

	//response to requests
	int target;
	for (int i = 0; i < q;i++){
		cin >> target;
		if(nResult[target]==-1){
			cout << "Sorry" << endl;
		}else{
			int h = nResult[target] / 60 + 8;
			int m = nResult[target] % 60;
			cout << setfill('0') << setw(2) << h;
			cout<<":";
			cout << setfill('0') << setw(2) << m<<endl;
		}
	}
}