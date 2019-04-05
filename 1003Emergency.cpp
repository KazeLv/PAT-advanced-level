#include <iostream>
#include <stack>

using namespace std;

typedef struct{
	int length;
	int teams;
	int *path;
}path;

bool exist(int &city,path &p){
	for(int i = 0;i<p.length;i++) 
		if(p.path[i] == city) return true;
	return false;
}

int main(){
    int nCities,nRoads;
    int nStart,nEnd;
    cin>>nCities>>nRoads>>nStart>>nEnd;     //read the first line for information

	stack<int> stack_path;

    int* nArrTeams = new int[nCities];      //store number of rescue teams of every city
    int **nArr2Map = new int*[nCities];     //store map in a 2-matrix
    for(int i = 0;i<nCities;i++){
        cin>>nArrTeams[i];
        nArr2Map[i] = new int[nCities]();   //construct map matrix and initiate to 0
    }

    int p1,p2,len;
    for(int i = 0;i<nRoads;i++){
        cin>>p1>>p2>>len;           //read and store roads information in map
        nArr2Map[p1][p2] = len;     //
    	nArr2Map[p2][p1] = len;     //
    }

	for(int i = 0;i<nCities;i++){
		if(nArr2Map[nStart][i]!=0){

		}
	}

    return 0;
}