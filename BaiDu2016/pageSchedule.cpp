#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
	int cache_size;
	while(cin>>cache_size){
		int ReqNum;
		deque<int>cache;
		cin>>ReqNum;
		int fail=0;
		for(int i=0;i<ReqNum;i++){
			int  reqId;
			cin>>reqId;
			deque<int>::iterator iter = find(cache.begin(),cache.end(),reqId);
			if(iter== cache.end()){
				fail++;
				if(cache.size()>=cache_size){
					cache.pop_front();
				}
				cache.push_back(reqId);
			}
			else{
				continue;	
			}
		}
		cout<<fail<<endl;
	}
}