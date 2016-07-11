#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;

bool dfs(int a,vector<vector<int> >& g,vector<bool>& hasChar){
	stack<int> myStack;
	myStack.push(a);
	vector<bool>visit(26,false);
	while(!myStack.empty()){
		int a = myStack.top();
		myStack.pop();
		visit[a]=true;
		for(int i=0;i<26;i++){
			if(g[a][i]==1 && visit[i]==false)
				myStack.push(i);
		}
	}
	for(int i=0;i<26;i++)
		if(visit[i]!=hasChar[i])
			return false;
	return true;
}

bool is_liangtong(vector<vector<int> >& g,vector<bool>& hasChar){
	for(int i=0;i<26;i++){
		if(dfs(i,g,hasChar))
			return true;
	}
	return false;
}

int main(){
	int num;
	while(cin>>num){
		vector<vector<int> >g(26,vector<int>(26,0));
		vector<int> inDegree(26,0);
		vector<int> outDegree(26,0);
		vector<bool> hasChar(26,false);
		for(int i=0;i<num;i++){
			string temp;
			cin>>temp;
			int startNum = (temp[0]-'a');
			int endNum = (temp[temp.size()-1]-'a');
			g[startNum][endNum]=1;
			inDegree[endNum]++;
			outDegree[startNum]++;
			hasChar[endNum]=true;
			hasChar[startNum]=true;
		}

		int count=0;
		bool is_jielong=true;
		for(int i=0;i<26;i++){
			int diff= abs(inDegree[i]-outDegree[i]);
			if(diff==1){
				count++;
				if(count>2)	is_jielong=false;
			}
			else if(diff>1)
				is_jielong=false;

		}

		if(!is_liangtong(g,hasChar)) is_jielong=false;

		cout<<(is_jielong?"Yes":"No")<<endl;
	}
	return 0;
}