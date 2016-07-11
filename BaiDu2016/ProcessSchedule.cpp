#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Pro{
	int start;
	int run;
};

bool vecCmp(const Pro& p1, const Pro& p2){
	if(p1.start<p2.start) return true;
	else if(p1.start>p2.start) return false;
	else return p1.run<p2.run;
	
}


int main(){
	int num;
	while(cin>>num){
		if(num==0) continue;
		vector<Pro>Req;
		for(int i=0;i<num;i++){
			Pro temp;
			cin>>temp.start>>temp.run;
			Req.push_back(temp);
		}
		sort(Req.begin(),Req.end(),vecCmp);
		double sum=0;
		int timeLine=Req[0].start;
		for(int i=0;i<Req.size();i++){
			if(timeLine<=Req[i].start) timeLine=Req[i].start;
			else {
				sum+=timeLine-Req[i].start;
			}
			timeLine+=Req[i].run;
		}
		cout<<fixed<<setprecision(4)<<sum/(double)num<<endl;
	}
	return 0;
} 
