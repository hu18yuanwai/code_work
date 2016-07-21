#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

class Cache{
public:
	Cache(int a):capcity(a){
		mymap.clear();
		cache.clear();
	}
	
	void add(string s,int i){
		if(cache.size()<capcity){
			mymap[s]=i;
			cache[i]=s;
		}
		else{
			map<int,string>::iterator it = cache.begin();
			mymap.erase(it->second);
			cache.erase(it);
			mymap[s]=i;
			cache[i]=s;
		}
	}

	void touch(string s,int i){
		cache.erase(mymap[s]);
		mymap[s]=i;
		cache[i]=s;
	}

	void request(string s,int i){
		if(mymap.count(s)){
			touch(s,i);
			cout<<"Cache"<<endl;
		}
		else{
			add(s,i);
			cout<<"Internet"<<endl;
		}
	}

private:
	int capcity;
	map<string,int> mymap;
	map<int,string> cache;
};

int main(){
	int test,cache_size;
	cin>>test>>cache_size;
	Cache mycache(cache_size);

	int i=0;
	while(i<test){
		string s;
		cin>>s;
		mycache.request(s,i);
		i++;
	}
	return 0;
}