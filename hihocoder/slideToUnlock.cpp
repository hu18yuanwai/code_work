#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

int mark[10][10],vis[10],ans,num[10];
vector< vector<int> > mymap;

void initial(){
	memset(mark, 0, sizeof(mark));
	mark[1][3] = 2, mark[1][7] = 4, mark[1][9] = 5;
	mark[2][8] = 5, mark[3][7] = 5, mark[3][9] = 6;
	mark[4][6] = 5, mark[7][9] = 8;
	for(int i = 1; i<=9; i++)
		for(int j = i+1; j<=9; j++)
			mark[j][i] = mark[i][j];
	memset(vis, 0, sizeof(vis));
	memset(num, 0, sizeof(num));
	ans=0;
	mymap.clear();
}

bool check(){
	for(int i=0;i<mymap.size();i++){
		bool find = false;
		for(int j=1;j<9 && num[j+1]!=0;j++){
			if( num[j] == mymap[i][0] && num[j+1] == mymap[i][1])
				find =true;
			if( num[j] == mymap[i][1] && num[j+1] == mymap[i][0])
				find = true;
 		}
 		if(find == false) return false;
	}
	return true;
}

void dfs(int cnt){
	if(cnt>=5 && check()){
		ans++;
	}

	for(int i=1;i<=9;i++){
		if(!vis[i]){
			if(mark[i][num[cnt-1]] && !vis[mark[i][num[cnt-1]]])
				continue;
			num[cnt] = i;
			vis[i] = 1;
			dfs(cnt+1);
			vis[i] = 0;
			num[cnt] = 0;
		}
	}
}

int main(){
	int test;
	cin>>test;
	while(test--){
		initial();
		int spit;
		cin>>spit;
		for(int i=0;i<spit;i++){
			int a,b;
			cin>>a>>b;
			vector<int> temp;
			temp.push_back(a);
			temp.push_back(b);
			mymap.push_back(temp);
		}
		dfs(1);
		cout<<ans<<endl;
	}
}