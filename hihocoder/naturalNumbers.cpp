#include <iostream>
#include <string>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;

vector<long long> f;

void initial(){
	f.push_back(0);
	f.push_back(10);
	long long  pre=10,temp = 90, num = 2;
	while(1){
		if(LLONG_MAX-pre<temp*num)
			break;
		long long sum = pre+temp*num;
		f.push_back(sum);
		pre= sum;
		if(LLONG_MAX/10<temp) break;
		temp= temp*10;
		num++;
	}
}

long long solution(long long N){
	if(N<10) return N-1;

	int n=0;
	for(int i= 0;i<f.size()-1;i++){
		if(N==f[i] || N==f[i+1]) return 9;
		else if (f[i]<N && N<f[i+1]){
			n=i;
			break;
		}
	}

	long long interval = N - f[n];
	
	long long num = (long long)pow(10,n)-1+(interval+n)/(n+1);

	long long a = interval%(n+1);
	if(a==0) a=n+1;
	while(a<n+1){
		num=num/10;
		a++;
	}
	return num%10;
}

int main(){
	long long N;
	initial();
	while(cin>>N){
		if(N==0) cout<<0<<endl;
		else
			cout<<solution(N+1)<<endl;
	}
}