#include <iostream>
#include <string>
#include <iomanip>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct Record{
	int month;
	int day;
	int hour;
	int minute;
	bool online;

	bool operator<(Record &other){
		if(this->day < other.day){
			return true;
		}else if(this->day == other.day){
			if(this->hour < other.hour){
				return true;
			}else if(this->hour == other.hour){
				if(this->minute<other.minute){
					return true;
				}
			}
		}
		return false;
	}
};

struct Bill{
	string name;
	vector<pair<Record, int>> records;
};

vector<string> Split(string str,string pattern){
	vector<string> result;
	string::size_type pos;

	str.append(pattern);
	int size = str.size();
	int index = 0;
	while (index < size)
	{
		pos = str.find(pattern, index);
		if (pos < size)
		{
			result.push_back(str.substr(index, pos - index));
			index = pos + pattern.size();
		}
	}

	return result;
}

istream &operator>>(istream &is,Record& record){
	string time, state;
	is >> time >> state;
	vector<string> time_split = Split(time, ":");

	record.month = stoi(time_split[0]);
	record.day = stoi(time_split[1]);
	record.hour = stoi(time_split[2]);
	record.minute = stoi(time_split[3]);
	record.online = (state == "on-line");

	return is;
}

int main(){
	vector<int> vec_hour_toll;								//store toll for every period in whole day
	map<string, vector<Record>> map_id_record;				//store records in a personal unit
	map<string, vector<pair<Record, Record>>> map_id_pairs;	//store records pair

	int m;

	int toll;
	for (int i = 0;i<24; i++){
		cin >> toll;
		vec_hour_toll.push_back(toll);
	}

	int nRecord;
	cin >> nRecord;

	string strName;
	Record record;
	for (int i = 0; i < nRecord; i++){				//read all records to map
		cin >> strName >> record;
		map_id_record[strName].push_back(record);
	}
	m = record.month;

	//find all pairs of records
	for(auto item:map_id_record){
		vector<Record> &vec_recTmp = item.second;
		sort(vec_recTmp.begin(),vec_recTmp.end(), [](Record &a, Record &b) { return a < b; });		//sort records for everybody

		for (auto i = vec_recTmp.begin() + 1; i != vec_recTmp.end(); i++)
		{
			if((*(i - 1) < *i) && ((i - 1)->online == true && i->online == false)){
				map_id_pairs[item.first].push_back(pair<Record, Record>(*(i-1), *i));
			}
		}
	}

	//output bill
	for(auto item:map_id_pairs){
		cout << item.first << " " << setfill('0') << setw(2) << m << endl;
		double totalMoney = 0;
		for (auto i = item.second.begin(); i != item.second.end();i++){
			Record recFirst = i->first;
			Record recSecond = i->second;
			cout << setfill('0') << setw(2) << recFirst.day << ":" << setfill('0') << setw(2) << recFirst.hour << ":" << setfill('0') << setw(2) << recFirst.minute << " ";
			cout << setfill('0') << setw(2) << recSecond.day << ":" << setfill('0') << setw(2) << recSecond.hour << ":" << setfill('0') << setw(2) << recSecond.minute << " ";
			//calculate time and money
			int min = 0;
			int money = 0;					//unit of cent
			while(recFirst<recSecond){
				min++;
				money += vec_hour_toll[recFirst.hour];
				recFirst.minute++;
				recFirst.hour += recFirst.minute / 60;
				recFirst.minute %= 60;
				recFirst.day += recFirst.hour / 24;
				recFirst.hour %= 24;
			}
			cout << min << " $" << setiosflags(ostream::fixed) << setprecision(2) << double(money) / 100 << endl;

			//accumulate total bill
			totalMoney += money / 100.0;
		}
		cout << "Total amount: $" << setiosflags(ostream::fixed) << setprecision(2) << totalMoney << endl;
	}

	return 0;
}