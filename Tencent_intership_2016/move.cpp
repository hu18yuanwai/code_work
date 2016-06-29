#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

void switch_(string &s){
	for(int i=0;i<s.size();i++){
		if(islower(s[i])){
			int j=i;
			while(j>=1 && isupper(s[j-1])){
				swap(s[j],s[j-1]);
				j--;
			}
		}
		else
			continue;
	}
}

int main(){
	string s;
	while(cin>>s){
		switch_(s);
		cout<<s<<endl;
	}
	return 0;
}