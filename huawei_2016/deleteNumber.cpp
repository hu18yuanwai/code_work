#include <iostream>
#include <algorithm>
using namespace std;

struct Number{
  int id;
  Number*next;
  Number(int num):id(num),next(NULL){}
};

int deleteLast(Number* head){
  if(head==NULL) return -1;
  int count=0;
  Number *cur=head,*pre;
  while(cur->next != cur){
    pre=cur;
    cur=cur->next;
    count++;
    if(count%2==0){
    	count=0;
    	pre->next=cur->next;
    	delete cur;
    	cur= pre->next;
    }
  }
  return cur->id;
}

int main(){
  int num;
  while(cin>>num){
    Number* help = new Number(-1);
    Number* cur =help;
    for(int i=0;i<num;i++){
      Number* newN = new Number(i);
      cur->next= newN;
      cur=cur->next;
    }
    cur->next = help->next;
    cur = help ->next;
    cout<< deleteLast(cur)<<endl;
  }
  return 0;
}
