#include<iostream>
#include<sstream>

using namespace std;

int main(){
    int a,b,iSum;
    bool flag=true;

    cin>>a>>b;
    iSum=a+b;
    if(iSum<0){
        flag=false;
        iSum*=-1;
    }

    stringstream ss;
    ss<<iSum;

    string strSum;
    ss>>strSum;

    int i=strSum.length();
    i-=3;
    while(i>0){
        strSum.insert(i,",");
        i-=3;
    }

    if(!flag) cout<<"-";
    cout<<strSum<<endl;
    return 0;
}