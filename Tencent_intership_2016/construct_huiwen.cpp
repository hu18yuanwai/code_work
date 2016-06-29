#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#define INT_MAX 2147483647

bool is_P(string s){
	if(s.size()<=1) return true;
	int i=0,j=s.size()-1;
	while(i<=j){
		if(s[i]!=s[j]) return false;
		i++;
		j--;
	}
	return true;
}

void back(string s,int num,int &min){
	if(num>=min) return;
	for(int i=0;i<s.size();i++){
		string ss=s;
		ss=ss.erase(i,1);
		if(is_P(ss)){
			min=num;
			return;
		}
	}

	for(int i=0;i<s.size();i++){
		string ss=s;
		ss=ss.erase(i,1);
		back(ss,num+1,min);
	}
}

int main(){
	string s;
	while(cin>>s){
		int min=INT_MAX;
		if(is_P(s)) cout<<0<<endl;
		else{
			back(s,1,min);
			cout<<min<<endl;
		}
	}
	return 0;
}