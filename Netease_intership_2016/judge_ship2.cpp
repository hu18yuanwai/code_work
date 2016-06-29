#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>
using namespace std;

bool greater_pair(int g1,int g2,map<int,vector<int> >& myMap){
	stack<int>myStack;
	map<int,bool>visit;
	myStack.push(g1);
	while(!myStack.empty()){
		int g1=myStack.top();
		myStack.pop();
		visit[g1]=true;
		for(int i=0;i<myMap[g1].size();i++){
			if(myMap[g1][i]==g2) return true;
			else{
				if(visit[myMap[g1][i]]==false)
					myStack.push(myMap[g1][i]);
			}
		}
	}
	return false;
}

int cmp(int g1, int g2, vector<vector<int> > records, int n) {
	map<int,vector<int> >myMap;
	for(int i=0;i<records.size();i++){
		myMap[records[i][0]].push_back(records[i][1]);
	}
	if(greater_pair(g1,g2,myMap)) return 1;
	else if(greater_pair(g2,g1,myMap)) return -1;
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