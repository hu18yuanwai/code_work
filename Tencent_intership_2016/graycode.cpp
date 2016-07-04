#include <iostream>
#include <string>
#include <vector>
using namespace std;

class GrayCode {
public:
    vector<string> getGray(int n) {
        vector<string>ret;
        if(n==0) return ret;
        else if(n==1){
        	ret.push_back("0");
        	ret.push_back("1");
        	return ret;
        }
        else{
        	vector<string>temp=getGray(n-1);
        	for(int i=0;i<temp.size();i++){
        		ret.push_back(("0"+temp[i]));
        	}
        	for(int i=0;i<temp.size();i++){
        		ret.push_back("1"+temp[temp.size()-1-i]);
        	}
        	return ret;
        }
    }
};

int main(){
	int n;
	GrayCode mycode;
	cin>>n;
	vector<string> ss;
	ss = mycode.getGray(n);
	for(int i=0;i<ss.size();i++)
		cout<<ss[i]<<endl;
	return 0;
}