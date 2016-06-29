#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
	int num;
	while(cin>>num){
		if(num<=0) continue;
		vector<int>data;
		int num1=0,num2=0;
		for(int i=0;i<num;i++){
			int a;
			cin>>a;
			data.push_back(a);
		}

		sort(data.begin(),data.end());

		int numOfMin=0,numOfMax=0;
		int i=0;
		while(i<num && data[i]==data[0]){
			numOfMin++;
			i++;
		}

		i=num-1;
		while(i>=0 && data[i]==data[num-1]){
			numOfMax++;
			i--;
		}

		if(data[0]==data[num-1])
			num2=(numOfMin-1)*numOfMin/2;
		else
			num2=numOfMin*numOfMax;

		map<int,int>countMin;
		vector<int>difference;
		int minDiffer=INT_MAX;
		for(i=0;i<num-1;i++){
			int dif=data[i+1]-data[i];
			difference.push_back(dif);
			if(minDiffer>dif)
				minDiffer=dif;
			countMin[dif]++;
		}

		if(minDiffer!=0)
			num1=countMin[minDiffer];
		else{
			for(i=0;i<difference.size();){
				if(difference[i]==0){
					int countZero=0;
					while(i<difference.size() && difference[i]==0){
						countZero++;
						i++;
					}
					num1+=(countZero+1)*countZero/2;
				}
				else
					i++;
			}
		}
		cout<<num1<<" "<<num2<<endl;
	}
	return 0;
}
