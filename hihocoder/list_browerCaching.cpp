#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
using namespace std;

struct Req{
	string s;
	Req* next;
	Req(string ss):s(ss),next(NULL){}
};

class Cache{
public:
	Cache(int a):capcity(a),size(0){
		mymap.clear();
		pre = new Req("");
		cur=pre;
	}

	void add(string &s){
		if(size<capcity){
			Req *newReq = new Req(s);
			cur->next=newReq;
			cur=cur->next;
			size++;
		}
		else{
			Req *newReq = new Req(s);
			cur->next=newReq;
			cur=cur->next;

			Req *temp =pre->next;
			pre->next = temp->next;
			mymap[temp->s]=false;
			delete temp;
		}
		mymap[s]=true;
	}

	void touch(string s){
		if(cur->s != s){
			Req* p =pre,*it =pre->next;
			while(it!=cur && it->s!=s){
				p=it;
				it=it->next;
			}
			p->next=it->next;
			it->next = NULL;
			cur->next = it;
		}
	}

	void request(string s){
		if(mymap[s]==false){
			add(s);
			cout<<"Internet"<<endl;
		}
		else{
			touch(s);
			cout<<"Cache"<<endl;
		}
	}

private:
	int capcity;
	int size;
	map<string,bool> mymap;
	Req* pre;
	Req* cur;
};

int main(){
	int test,cache_size;
	cin>>test>>cache_size;
	Cache mycache(cache_size);

	while(test--){
		string s;
		cin>>s;
		mycache.request(s);
	}
	return 0;
}