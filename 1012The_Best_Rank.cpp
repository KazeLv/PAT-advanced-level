#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Grade{
	int C;
	int Math;
	int English;
	int Average;
};

istream& operator>>(istream &is, Grade &g){
    is >> g.C >> g.Math >> g.English;
    g.Average = (g.C + g.Math + g.English) / 3;
	return is;
}

using namespace std;

int main(){
	int n,m;
	cin >> n >> m;

    map<string, Grade> map_id_grades;
    map<string, Grade> map_id_ranks;

    int index = 0;
    string strID;
    Grade gTmp;
    while(index < n){
        cin >> strID;
        cin >> gTmp;
        map_id_grades[strID] = gTmp;	//insert grade data to map
        map_id_ranks[strID] = gTmp;
        index++;
    }

	//rank students' grades according to their respective disciplines
    int rankC = 0, rankM = 0, rankE = 0, rankA = 0;
    int lastC = -1, lastM = -1, lastE = -1, lastA = -1;
    int score = 100;
    while (score >= 0)
    {
        for (auto iter = map_id_grades.begin(); iter != map_id_grades.end(); iter++)
        {
            if (iter->second.C == score){
				if(lastC == score) map_id_ranks[iter->first].C = rankC++;
                else {
					map_id_ranks[iter->first].C = ++rankC;
                    lastC = score;
                }
			}
            if (iter->second.Math == score) {
                if (lastM == score) map_id_ranks[iter->first].Math = rankM++;
                else
                {
                    map_id_ranks[iter->first].Math = ++rankM;
                    lastM = score;
                }
			}
            if (iter->second.English == score)
            {
                if (lastE == score)
                    map_id_ranks[iter->first].English = rankE++;
                else
                {
                    map_id_ranks[iter->first].English = ++rankE;
                    lastE = score;
                }
            }
            if (iter->second.Average == score)
            {
                if (lastA == score)
                    map_id_ranks[iter->first].Average = rankA++;
                else
                {
                    map_id_ranks[iter->first].Average = ++rankA;
                    lastA = score;
                }
            }
        }
        score--;
    }

	//handle same rank problem

    //respond check request
    index = 0;
	while(index < m){
        cin >> strID;
        auto iter = map_id_ranks.find(strID);
		if(iter!=map_id_ranks.end()){				//存在指定学生数据，输出最高排名
            int min = iter->second.Average;
            char subject = 'A';
            if(iter->second.C < min) {
                min = iter->second.C;
                subject = 'C';
            }
            if (iter->second.Math < min) {
                min = iter->second.Math;
                subject = 'M';
            }
            if (iter->second.English < min) {
                min = iter->second.English;
                subject = 'E';
            }

            cout << min << " " << subject << endl;
        }else{
            cout << "N/A" << endl;
        }
        index++;
    }

    return 0;
}