#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct RecordTime{
    int h;
    int m;
    int s;

    bool operator>(RecordTime &t){
        if(this->h>t.h) return true;
        else if(this->h<t.h) return false;
        else{
            if(this->m>t.m) return true;
            else if(this->m<t.m) return false;
            else{
                if(this->s>t.s) return true;
                else return false;
            }
        }
    }
    
    bool operator<(RecordTime &t){
        if(this->h<t.h) return true;
        else if(this->h>t.h) return false;
        else{
            if(this->m<t.m) return true;
            else if(this->m>t.m) return false;
            else{
                if(this->s<t.s) return true;
                else return false;
            }
        }
    }
};

//split string by pattern and return all substring in a vector
vector<string> split(string str,string pattern){
    vector<string> result;
    string::size_type pos;

    str+=pattern;                   //add pattern to tail for split position finding
    int size = str.size();

    int index = 0;
    while(index<size){
        pos = str.find(pattern,index);
        if(pos<size){
            result.push_back(str.substr(index,pos-index));
            index = pos + pattern.size();
        }
    }
    return result;
}

//override >> operator for cin and time
istream &operator>>(istream& is,RecordTime& t){           
    string str_time;        
    is>>str_time;
    vector<string> vec_time = split(str_time,":");
    stringstream ss;
    ss<<vec_time[0]<<" "<<vec_time[1]<<" "<<vec_time[2];
    ss>>t.h>>t.m>>t.s;
    return is;
}

int main(){
    int n;
    string person_unlock,person_lock;
    RecordTime time_lock,time_unlock;
    cin>>n;
    if(n == 0) return 0;
    cin>>person_unlock>>time_unlock>>time_lock;     //initiate the first record to be lock and unlock person
    person_lock = person_unlock;                    //

    string id;
    RecordTime time_in,time_out;         
    for(int i = 0; i < n-1; i++){
        cin>>id>>time_in>>time_out;
        if(time_in<time_unlock){
            time_unlock = time_in;
            person_unlock = id;
        }
        if(time_out>time_lock){
            time_lock = time_out;
            person_lock = id;
        }
    }  

    cout << person_unlock << " " << person_lock << endl;
    return 0;
}

/*
1. add pattern to tail of string can make it easy to split(no special operation for last substring)
2. time is a original type, and there are many types have already been defined,so it will be better that designate new class with special name(such as capitalization)
3. the compiler PAT uses will report error when return nothing to a function that returns integer;
*/