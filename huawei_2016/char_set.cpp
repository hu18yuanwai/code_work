#include <iostream>
#include <algorithm>
#include <map> 
#include <string>
using namespace std;

int main(){
  string s;
  while(cin>>s){
    map<char,int> hasChar;
    for(int i=0;i<s.size();i++){
    	hasChar[s[i]]++;
	}
	string ret;
	
	for(int i=0;i<s.size();i++){
		if(hasChar[s[i]]){
			ret=ret+s[i];
			hasChar[s[i]]=0;
		}
	}
	cout<<ret<<endl;
  }
  return 0;
}
