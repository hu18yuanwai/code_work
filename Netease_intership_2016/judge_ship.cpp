#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

/*
bool greater_pair(int g1,int g2,vector<vector<int> > &records){
	if(find_pair(g1,g2,records))
		return true;

	for(int i=0;i<records.size();i++){
		if(records[i][0]==g1){
			if(greater_pair(records[i][1],g2,records))
				return true;
		}
	}
	return false;
}*/

bool find_pair(int g1,int g2,vector<vector<int> > &records,int start,int end){
	int left=start,right=end;
	while(left<=right){
		int mid=(left+right)/2;
		if(records[mid][0]==g1 && records[mid][1]==g2)
			return true;
		else if(records[mid][0]<g1)
			 left=mid+1;
		else
			right=mid-1;
	}
	return false;
}

bool greater_pair(int g1,int g2,vector<vector<int> > &records){
	stack<int> myStack;
	map<int,bool>mark;
	myStack.push(g1);
	while(!myStack.empty()){
		int a = myStack.top();
		myStack.pop();
		mark[a]=true;
		if(find_pair(a,g2,records,0,records.size()-1))
			return true;
		for(int i=0;i<records.size();i++){
			if(records[i][0]==a && mark[records[i][1]]==false){
				myStack.push(records[i][1]);
			}
		}
	}
	return false;
}

static bool mycmp(const vector<int> &a,const vector<int> &b){
	return a[0]<b[0];
}

int cmp(int g1, int g2, vector<vector<int> > records, int n) {
	sort(records.begin(),records.end(),mycmp);
	if(greater_pair(g1,g2,records)) return 1;
	else if(greater_pair(g2,g1,records)) return -1;
	return 0;
}

int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0) break;
		vector<vector<int> >records;
		for(int i=0;i<n;i++){
			int a,b;
			cin>>a>>b;
			vector<int>temp;
			temp.push_back(a);
			temp.push_back(b);
			records.push_back(temp);
		}
		int g1,g2;
		cin>>g1>>g2;
		cout<<cmp(g1,g2,records,n)<<endl;
	}
}