#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

bool read(vector< vector<int> > &board){
  for(int i=0;i<board.size();i++){
    for(int j=0;j<board.size();j++){
      cin>>board[i][j];
    }
  }
  return true;
}

void print(vector< vector<int> > &board){
  for(int i=0;i<board.size();i++){
    for(int j=0;j<board[0].size();j++){
      if(j!=0) cout<<" ";
      cout<<board[i][j];
    }
    if(i!=8) cout<<endl;
  }
}

bool checkRow(vector< vector<int> >& board,int x,int y){
  vector<int>hash(9,0);
  for(int i=0;i<board.size();i++){
    if(board[i][y]!=0){
      if(hash[ board[i][y]-1]==1) return false;
      else hash[ board[i][y]-1]=1;
    }
  }
  return true;
}

bool checkCol(vector< vector<int> >& board,int x,int y){
  vector<int>hash(9,0);
  for(int i=0;i<board[0].size();i++){
    if(board[x][i]!=0){
      if(hash[ board[x][i]-1 ]==1) return false;
      else hash[ board[x][i]-1 ]=1;
    }
  }
  return true;
}

bool checkBox(vector< vector<int> >& board,int x,int y){
  vector<int>hash(9,0);
  x=x-x%3;
  y=y-y%3;
  int de[9][2]={{0,0},{0,1},{0,2},{1,0},{1,1},{1,2},{2,0},{2,1},{2,2}};
  for(int i=0;i<9;i++){
    if(board[x+de[i][0]][y+de[i][1]]!=0){
      if(hash[board[x+de[i][0]][y+de[i][1]]-1]==1) return false;
      else hash[board[x+de[i][0]][y+de[i][1]]-1]=1;
    }
  }
  return true;
}


bool IsValid(vector< vector<int> > &board,int i,int j){
  if(!checkRow(board,i,j)) return false;
  else if(!checkCol(board,i,j)) return false;
  else if(!checkBox(board,i,j)) return false;
  return true;
}

void back(vector< vector<int> > &board,vector< vector<int> > &temp,int i,int j){
  if(i>=temp.size()) {
    for(int k=0;k<board.size();k++){
      for(int w=0;w<board[0].size();w++){
        board[k][w]=temp[k][w];
      }
    }
    return;
  }

  if(temp[i][j]!=0){
      back(board,temp,i+(j+1)/temp[0].size(),(j+1)%temp[0].size());
  }
  else{
    for(int k=1;k<=9;k++){
      temp[i][j]=k;
      if(IsValid(temp,i,j)){
        back(board,temp,i+(j+1)/temp[0].size(),(j+1)%temp[0].size());
      }
    }
    temp[i][j]=0;
  }
}

int main(){
  vector< vector<int> > board (9, vector<int>(9));
  if(read(board)){
    vector< vector<int> > ret (board);
    back(board,ret,0,0);
    print(board);
  }
  return 0;
}
