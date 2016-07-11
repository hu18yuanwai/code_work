#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main(){
  int m,n;
  while(cin>>m>>n){
    vector<int>score(m);
    for(int i=0;i<score.size();i++){
      cin>>score[i];
    }
 
    for(int i=0;i<n;i++){
      char instruction;
      int num1,num2;
      cin>>instruction>>num1>>num2;
      if(instruction=='Q'){
        int maxN = -1;
       
          for(int i=min(num1,num2)-1;i<=max(num1,num2)-1;i++){
            if(score[i]>maxN) maxN=score[i];
          }
    
        cout<<maxN<<endl;
      }
      else if(instruction=='U'){
        score[num1-1]=num2;
      }
    }
  }
  return 0;
}