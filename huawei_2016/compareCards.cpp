#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s[]={"3","4","5","6","7","8","9","10","J","Q","K","A","2","joker","JOKER"};

void splitCard(string&s, char splitChar,vector<string>& ret){
    int pos = 0;
    string temp="";
    while(pos<s.size()){
        if(s[pos]!=splitChar)
            temp=temp+s[pos];
        else{
            ret.push_back(temp);
            temp="";
        }
        pos++;
    }
    ret.push_back(temp);
}

int find_index(string ss){
    for(int i=0;i<15;i++)
        if(ss.compare(s[i])==0) return i;
    return -1;
}

int cmp(vector<string>& cards1,vector<string>& cards2){
    if(cards1.size() != cards2.size()){
        if(cards1.size()==2 || cards2.size()==2){
            if(cards1[0]=="joker" && cards1[1]=="JOKER") return 1;
            else return -1;
        }
        if(cards1.size() ==4 || cards2.size()== 4){
            return cards1.size()==4?1:-1;
        }
        return 2;
    }
    else{
        int index1= find_index(cards1[0]);
        int index2= find_index(cards2[0]);
        //cout<<cards1[0]<<" "<<cards2[0]<<endl;
        //cout<<index1<<" "<<index2<<endl;
        if(index1>index2) return 1;
        else if(index1<index2) return -1;
        else return 0;
    }
}

int main(){
    string s;
    while(getline(cin,s)){
        vector<string> twoCards,cards1,cards2;
        splitCard(s,'-',twoCards);
        splitCard(twoCards[0],' ',cards1);
        splitCard(twoCards[1],' ',cards2);
        int signa = cmp(cards1,cards2);
        if(signa==2) cout<<"ERROR"<<endl;
        else if(signa==1) cout<<twoCards[0]<<endl;
        else cout<<twoCards[1]<<endl;
    }
    return 0;
}
