#include <iostream>
#include <vector>

using namespace std;

vector<int>::iterator findFirstPositive(vector<int>::iterator i_begin,vector<int>::iterator i_end){
    while(i_begin!=i_end){
        if(*i_begin > 0) break;
        i_begin++;
    }
    return i_begin;
}

int main(){
    int k;
    cin>>k;

    vector<int> vec_num;
    for(int i = 0;i<k;i++){
        int num;
        cin>>num;
        vec_num.push_back(num);
    }

    vector<int>::iterator i_first = vec_num.begin();
    vector<int>::iterator i_last = vec_num.end()--;
    int maxSum = 0;

    auto i = i_first;
    i =findFirstPositive(i,vec_num.end());
    if(i!=vec_num.end()){
        i_first = i;
        i_last = i_first;
        auto j = findFirstPositive(i_last,vec_num.end());
        int sum = 0;
        for(auto m = i_last+1;m!=j+1;m++) sum += *m;
        if(sum>0) i_last = j;
    }
    int sum = 0;
    for(auto j = i_first;j!=(i+1);j++) sum+=*j;
    if(sum>0) i_last = i;

    cout<<maxSum<<" "<<*i_first<<" "<<*i_last<<endl;
    return 0;
}