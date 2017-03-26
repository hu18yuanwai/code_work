#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool match(const string &a, const string &b){
	if(a.size()!=b.size()) return false;
	int len = a.size();
	for(int i=0;i<len;i++){
		if((a.substr(0,i) == b.substr(len-i)) && (a.substr(i) == b.substr(0,len-i) )){
			return true;
		}
	}
	return false;
}

void creatGraph( vector<vector<int> >& g, vector<string>& words){
	for(int i=0;i<words.size();i++){
		for(int j=i+1;j<words.size();j++){
			if(match(words[i],words[j])){
				g[i][j]=1;
			}
		}
	}
}

void dfs(vector<vector<int> >& g,int start,vector<bool>& isVist){
	for(int i=0; i< g[i].size();i++){
		if(g[start][i] && !isVist[i]){
			isVist[i]=true;
			dfs(g,i,isVist);
		}
	}
}

int main()
{
	int N;
	cin>>N;
	string str;
	vector<string>ve;
	int count=0;
	while(N--)
	{
		cin>>str;
		ve.push_back(str);
	}
	N = ve.size();
	vector< vector< int> >wordGraph(N,vector<int>(N,0));
	creatGraph(wordGraph,ve);
	vector<bool> isVist(N,false);
	for(int i=0;i<N;i++){
		if(!isVist[i]){
			isVist[i] = true;
			count++;
			dfs(wordGraph,i,isVist);
		}
	}
	cout<<count<<endl;
}
