#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

string getFileName(string &s){
    string ret;
    int index = s.size()-1, blackPos = s.size();
    while(s[index] != '\\' && index>=0){
        ret=s[index]+ret;
        if(s[index]==' ') blackPos = index;
        index--;
    }
    int len = blackPos - index-1;
    if( len >= 16 )
        ret = ret.substr(len - 16);
    return ret;
}

struct File{
    string file;
    int id;
    File(string s,int a):file(s),id(a){}
};

void get8file(vector<string>& ret, map<string,int>& myMap,vector<File>& file){
    for(int i=0;i<8 && i<file.size();i++){
        for(int j=i+1;j<file.size();j++){
            if((myMap[file[j].file]>myMap[file[i].file] ) || (myMap[file[j].file] == myMap[file[i].file] && file[i].id >file[j].id))
                swap(file[j],file[i]);
        }
    }
    int index=0;
    while(index<8 && index<file.size()){
        ret.push_back(file[index].file);
        index++;
    }
}

int main(){
    string s;
    map<string,int> myMap;
    vector<File> myfile;
    int count = 0;
    while(getline(cin,s)){
        if(s.size()==0) break;
        string fileName = getFileName(s);
        if(myMap[fileName]==0) myfile.push_back(File(fileName,count++));
        myMap[fileName]++;
    }
    vector<string> ret;
    get8file(ret,myMap,myfile);
    for(int i=0;i<ret.size();i++)
        cout<<ret[i]<<" "<<myMap[ret[i]]<<endl;
    return 0;
}
