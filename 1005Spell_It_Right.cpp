#include <iostream>
#include <string>
#include <stack>

using namespace std;

unsigned long long addDigits(string &strNum){
    unsigned long long res = 0;
    for(int i = 0;i<strNum.length();i++){
        res += strNum[i]-'0';
    }
    return res;
}

void printDigits(unsigned long long &num){
    unsigned long long t = num;
    string str_digits[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
    stack<string> stack_res;

    if(t == 0) stack_res.push(str_digits[t%10]);
    while(t>0){
        stack_res.push(str_digits[t%10]);
        t /= 10;
    }

    string str;
    while(!stack_res.empty()){
        str = stack_res.top();
        stack_res.pop();
        cout<<str;
        
        if(!stack_res.empty()) cout<<" ";
    }
    cout<<endl;
}

int main(){
    string strNum;
    cin>>strNum;

    unsigned long long res = addDigits(strNum);

    printDigits(res);
    return 0;
}

/*
Resolve the problem of digit overflow by reading to string
*/