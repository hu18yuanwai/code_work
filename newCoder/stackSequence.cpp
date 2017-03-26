class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size()) return false;
        stack<int> mysta;
        int i = 0, j =0;
        while(j<popV.size()){
            while(mysta.empty() || mysta.top()!=popV[j]){
                if(j>=popV.size()) break;
                mysta.push(pushV[i++]);
            }
            if(mysta.top()!=popV[j]) break;
            mysta.pop();
            j++;
        }
        if(mysta.empty() && j>= popV.size())
            return true;
        return false;
    }
};


class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size()!=popV.size()) return false;

    }
};
