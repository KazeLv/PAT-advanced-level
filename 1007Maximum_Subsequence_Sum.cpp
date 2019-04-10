#include <iostream>
#include <vector>

using namespace std;

struct SubSum {
	int begin;
	int end;
	int sum;
};

int main() {
	int k;
	cin >> k;

	vector<int> vec_num;
	for (int i = 0; i < k; i++) {
		int num;
		cin >> num;
		vec_num.push_back(num);
	}

	vector<int> vec_posIndex;
	if (vec_num[0] > 0) vec_posIndex.push_back(0);
	for (int i = 1; i < vec_num.size(); i++) 
		if ((vec_num[i] >= 0) && (vec_num[i - 1] < 0)) vec_posIndex.push_back(i);        //find the begin of every subsequence whose elements are all positive

	vector<SubSum> vec_sum;
	if (vec_posIndex.empty()) {                           //if there is no positive number in sequence,add a extra case to vec_sum to output
		SubSum extra{ 0,vec_num.size() - 1,0 };
		vec_sum.push_back(extra);
	}
	for (int j = 0; j < vec_posIndex.size(); j++) {
		int index = vec_posIndex[j];
		int i = index;
		int maxEnd = index;
		int sum = vec_num[i++];
		int maxSum = sum;
		while (i < vec_num.size()) {                        //for every head of positive number, find their max subsequence that begins from themselfs
			sum += vec_num[i];
			if (sum > maxSum) {
				maxSum = sum;
				maxEnd = i;
			}
			i++;
		}
		SubSum subSum{ index,maxEnd,maxSum };
		vec_sum.push_back(subSum);
	}

	int maxSubBegin = vec_sum[0].begin;
	int maxSubEnd = vec_sum[0].end;
	int maxSubSum = vec_sum[0].sum;
	for (int i = 1; i < vec_sum.size(); i++) {               //pick the max subsequence of all
		if (vec_sum[i].sum > maxSubSum) {
			maxSubBegin = vec_sum[i].begin;
			maxSubEnd = vec_sum[i].end;
			maxSubSum = vec_sum[i].sum;
		}
	}
	cout << maxSubSum << " " << vec_num[maxSubBegin] << " " << vec_num[maxSubEnd] << endl;

	
	return 0;
}

/*
i guess there is better approach to deal with this kind of question.
i've tried three different stratege,but failed to find a more efficient way.
spend too much time.And this is a brute force algorithm with time complexity O(n^2).
by the way, be careful of edge conditions
*/