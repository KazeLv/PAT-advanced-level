#include <iostream>
#include <string>
#include <stack>

using namespace std;

unsigned int addDigits(unsigned long long &num){
    unsigned long long t = num;
    unsigned long long res = 0;
    while(t>0){
        res += t % 10;
        t /= 10;
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
    unsigned long long number;
    cin>>number;

    unsigned long long res = addDigits(number);

    printDigits(res);
    return 0;
}

/*
first try,use unsigned long long to read N.But there still is one fault.
i guess it can be handled by reading to string
*/