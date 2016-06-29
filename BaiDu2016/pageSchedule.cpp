#include <iostream>
#include <set>

struct req{
	int id;
	int timeTamp;
};

bool cmp(const req& a,const req& b)const{
		return a.timeTamp>b.timeTamp;
}


int main(){
	int cache_size;
	while(cin>>cache_size){
		int num;
		cin>>num;
		set<req,cmp> mycache;
		int fail=0;
		for(int i=0;i<num;i++){
			int requstId;
			cin>>requstId;
			if(set.size()<cache_size){
				req curReq(requstId,i);
				mycache.insert(curReq);
			}
			else{
				if()
			}
		}

	}
}