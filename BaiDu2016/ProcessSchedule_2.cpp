#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

struct Pro{
	int start;
	int run;
	bool operator<(const Pro& p2) const{
		if(run>p2.run ) return true;
		else if(run<p2.run) return false;
		else return start>p2.start;
	}
};

bool queCmp(const Pro& p1, const Pro& p2){
	if(p1.run<p2.run ) return true;
	else if(p1.run>p2.run) return false;
	else return p1.start<p2.start;
}

bool vecCmp(const Pro& p1, const Pro& p2){
	return p1.start<p2.start;
}


int main(){
	int num;
	while(cin>>num){
		vector<Pro>Req;
		priority_queue<Pro>queReq;
		for(int i=0;i<num;i++){
			Pro temp;
			cin>>temp.start>>temp.run;
			Req.push_back(temp);
		}
		sort(Req.begin(),Req.end(),vecCmp);
		int timeLine=0;
		int runline=1;
		double sum=0.0;
		int index=0;
		while(1){
			if(queReq.empty())
				runline=timeLine;
			while(Req[index].start==timeLine){
				queReq.push(Req[index]);
				index++;
			}
			if(runline==timeLine && ! queReq.empty()){
				Pro runPro= queReq.top();
				queReq.pop();
				sum=sum+(runline-runPro.start);
				//cout<<"at time "<<timeLine<< " Process "<<runPro.start<<" "<<runPro.run<<endl; 
				runline+=runPro.run; 
			}
			++timeLine;
			if(index>=Req.size() && queReq.empty())
				break;
		}
		cout<<sum<<endl;
		cout<<fixed<<setprecision(4)<<sum/(double)num<<endl;
	}
	return 0;
} 
