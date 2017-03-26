#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void back(vector<int>& f,int start, vector<int>temp,stack<int>& st){
    if(start == f.size() && temp.size() == f.size()){
        for(int i=0;i<temp.size();i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return;
    }

    if(start<f.size()){
        st.push(f[start]);
        back(f,start+1,temp,st);
        st.pop();
    }
    if(!st.empty()){
        int a = st.top();
        temp.push_back(a);
        st.pop();
        back(f,start,temp,st);
        st.push(a);
    }
}

int main(){
    vector<int> f = {1,2,3};
    vector<int> temp;
    stack<int> st;
    back(f,0,temp,st);
    return 0;
}
