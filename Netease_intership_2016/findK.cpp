#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

int partition(vector<int>&a,int start,int end){
	int index=start;//+((int)(rand()))%(start-end+1);
	swap(a[index],a[end]);
	int big = start-1;
	for(int i=start;i<end;i++){
		if(a[i]>a[end]){
			big++;
			if(big!=i) swap(a[big],a[i]);
		}
	}
	big++;
	swap(a[big],a[end]);
	return big;
}

int findKth_recursive(vector<int>&a,int start,int end,int k){
	if(start>end || start<0 || end>=a.size() || k<0 || k> a.size())
		return -1;
	int big=partition(a,start,end);
	if(k-1== big) return a[big];
	else if(k-1 > big) 
		return findKth_recursive(a,big+1,end,k);
	else
		return findKth_recursive(a,start,big-1,k);
}

int findKth(vector<int> a, int n, int K) {
	return findKth_recursive(a,0,n-1,K);
}

int main(){
	while(1){
		int n;
		cin>>n;
		if(n==0) break;
		vector<int>a;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			a.push_back(temp);
		}
		int K;
		cin>>K;
		cout<<"The K number is: "<<findKth(a,n,K)<<endl;
	}
	return 0;
}