#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


class Gift {
public:
    int getValue(vector<int> gifts, int n) {
    	if(gifts.size()==0 || n<=0 || gifts.size()!=n) return 0;
        int curNum=gifts[0];
        int count=1;
        for(int i=1;i<n;i++){
        	if(curNum==gifts[i])
        		count++;
        	else{
        		count--;
        		if(count==0){
        			curNum=gifts[i];
        			count=1;
        		}
        	}
        }

        count=0;
        for(int i=0;i<n;i++){
        	if(curNum==gifts[i])
        		count++;
        }
        if(2*count>n)
        	return curNum;
        else 
        	return 0;
    }
};

int main(){
	Gift gift;
	vector<int>money;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		money.push_back(temp);
	}
	cout<<gift.getValue(money,n)<<endl;
	return 0;
}