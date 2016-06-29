#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int lst(string&s, vector<vector<int> >&dp){
	string reverses="";
	for(int i=s.size()-1;i>=0;i--)
		reverses+=s[i];
	cout<<reverses<<endl;
	for(int i=1;i<=s.size();i++){
		for(int j=1;j<=s.size();j++){
			if(s[i-1]==reverses[j-1])
				dp[i][j]=dp[i-1][j-1]+1;
			else
				dp[i][j]=(dp[i-1][j]>dp[i][j-1]?dp[i-1][j]:dp[i][j-1]);
		}
	}
	return dp[s.size()][s.size()];
}

int main(){
	string s;
	while(cin>>s){
		int len=s.size();
		vector<vector<int> >dp(len+1,vector<int>(len+1,0));
		cout<<len-lst(s,dp)<<endl;
	}
	return 0;
}