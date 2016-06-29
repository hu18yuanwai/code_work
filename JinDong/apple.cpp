 #include <iostream>
using namespace std;

int test(int num,int n){
	int remind = num*n+1;
	for(int i=2;i<=n;i++){
		if(remind%(n-1)!=0)
			return -1;
		else
			remind=remind*n/(n-1)+1;
	}
	return remind;
}

 int getInitial(int n) {
 	int i=0;
 	while(1){
 		int a=test(i,n);
 		if(a!=-1)
 			return a;
 		i++;
 	}
 }

 int main(){
 	while(1){
 		int a;
 		cin>>a;
 		cout<<getInitial(a)<<endl;
 	}
 }