#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

bool isfa(string s){
    set<char> myset;
    for(int i=0;i<s.size();i++)
        myset.insert(s[i]);
    if(myset.size() == 1 || myset.size()==2 || myset.size() ==3 ||
	myset.size()==5 || myset.size() == 8 ||myset.size()==13|| myset.size()==21) return true;
    return false;
}

void getLenSubstr(const string&s, set<string>&ret,const int len){
    for(int i=0;i<=s.size()-len;i++){
        string ssbstr = s.substr(i,len);
        if(isfa(ssbstr)) ret.insert(ssbstr);
    }
}

void getSubstr(const string&s, set<string>&ret){
    for(int i=1;i<s.size();i++){
        getLenSubstr(s,ret,i);
    }
}

int main(){
    string s;
    while(cin>>s){
        set<string> ret;
        getSubstr(s,ret);
        for(set<string>::iterator it = ret.begin();it!= ret.end();it++){
            cout<<*it<<endl;
        }
    }
    return 0;
}
