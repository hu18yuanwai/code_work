#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * 返回git树上两点的最近分割点
     *
     * @param matrix 接邻矩阵，表示git树，matrix[i][j] == '1' 当且仅当git树中第i个和第j个节点有连接，节点0为git树的跟节点
     * @param indexA 节点A的index
     * @param indexB 节点B的index
     * @return 整型
     */
     bool notfind(int num, vector<int>&path){
         for(int i=0;i<path.size();i++) {
             if(path[i] == num) return true;
         }
         return false;
     }

     bool dfs(vector<string>& matrix, int node,int index,vector<int>& path){
         path.push_back(node);
         cout<<"visit "<<node<<endl;
         if(node == index){
             return true;
         }
         string s = matrix[node];
         for(int i=0;i<s.size();i++){
             if(s[i]=='1' && !notfind(i,path)) {
                 bool t=dfs(matrix,i,index,path);
                 if(t) return true;
                 else
                    path.pop_back();
             }
         }
         return false;
     }

     int getNode(vector<int>& pathA, vector<int>& pathB){
        int lenA = pathA.size(),lenB =pathB.size();
        if(lenA == 1 || lenB == 1) return pathA[0];
        if( lenA>lenB){
            if(pathA[lenB-1] == pathB[lenB-1]) return pathA[lenB-1];
        }
        if(lenB>lenA){
            if(pathA[lenA-1] == pathB[lenA-1]) return pathA[lenA-1];
        }

        if(lenA == lenB) if(pathA[lenA-1] == pathB[lenA-1]) return pathA[lenA-1];
        for(int i=0;i<pathA.size()-1 && pathB.size()-1;i++){
            if(pathA[i]==pathB[i] && pathA[i+1]!=pathB[i+1])
                return pathA[i];
        }
        return -1;
     }
	void print(vector<int> path){
		for(int i=0;i<path.size();i++)
			cout<<path[i]<<" ";
		cout<<endl;
	}

    int getSplitNode(vector<string> matrix, int indexA, int indexB) {
        vector<int> pathA,pathB;
        dfs(matrix,0,indexA,pathA);
        dfs(matrix,0,indexB,pathB);
        print(pathA);
        print(pathB);
        return getNode(pathA,pathB);
    }
};

int main(){
    Solution so;
    vector<string> matrix;
    int indexA,indexB;
    for(int i=0;i<5;i++){
        string s;
        cin>>s;
        matrix.push_back(s);
    }
    while(1){
    cin>>indexA>>indexB;
    cout<<so.getSplitNode(matrix,indexA,indexB)<<endl;
}
    return 0;
}

/*
01011
10100
01000
10000
10000

*/
