#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Period{
	int start;
	int end;
	int sum;
	int lenth;
};

bool cmp(const Period&p1,const Period &p2){
	if( (p1.sum/(double)p1.lenth) > (p2.sum/(double)p2.lenth ))
		return true;
	else if((p1.sum/(double)p1.lenth) < (p2.sum/(double)p2.lenth ))
		return false;
	else{
		if(p1.lenth>p2.lenth) return true;
		else if(p1.lenth<p2.lenth) return false;
		else{
			return p1.end < p2.end;
		}
	}
}

int main(){
	int n;
	cin>>n;
	int ii=1;
	while(ii<=n){
		int NumOfQua;
		int MinRequr;
		int MinSpot;
		vector<int>seq;
		vector<Period>result;
		
		cin>>NumOfQua>>MinRequr>>MinSpot;
		
		for(int i=0;i<NumOfQua;i++){
			int temp;
			cin>>temp;
			seq.push_back(temp);
		}
		cout<<"Result for run "<<ii<<":"<<endl;
		ii++;
		if(MinSpot>NumOfQua){
			continue;
		}
		int sum=0;
		for(int i=0;i<seq.size()-MinSpot+1;i++){
			if(i==0){
				for(int k=0;k<MinSpot-1;k++)
					sum+=seq[k];
			}
			else{
				sum=sum+seq[i+MinSpot-2]-seq[i-1];
			}
			
			int sumtemp=sum;
			for(int j=i+MinSpot-1;j<seq.size();j++){
				sumtemp+=seq[j];
				Period test;
				test.start=i;
				test.end=j;
				test.sum=sumtemp;
				test.lenth=j-i+1;
				result.push_back(test);
			}
		} 
		
		
		sort(result.begin(),result.end(),cmp);
		for(int i=0;i<result.size();i++){
			if(i<MinRequr){
				cout<<result[i].start+1<<"-"<<result[i].end+1<<endl;
			}
		}
	}
	return 0;
} 