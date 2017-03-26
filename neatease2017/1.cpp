#include <iostream>
#include <vector>
using namespace std;

vector<int > range(string num, int pos) {
    vector<int > t;
    if(pos >= num.length()) {
        t.push_back(0);
    }
    else if(num[num.length() - 1 - pos] == 'X') {
        for(int i = 1;i < 10;i ++) {
            t.push_back(i);
        }
    }
    else {
        t.push_back(num[num.length() - 1 - pos] - '0');
    }
    return t;
}

long long calc(string add1, string add2, string sum1, int mask) {
    long long sumf = 1;
    for(int i = 0;i < 4;i ++) {
        int cross = 0;
        int last_add = 0;
        int cur_add = ((mask & (1 << i)) > 0 ) * 10;
        if(i > 0) {
            last_add += ((mask & (1 << (i - 1))) > 0);
        }
        int countf = 0;
        vector<int > pos1 = range(add1, i);
        vector<int > pos2 = range(add2, i);
        vector<int > pos3 = range(sum1, i);
        for(int j = 0;j < pos1.size();j ++) {
            for(int jj = 0; jj < pos2.size();jj ++) {
                for(int jjj = 0; jjj < pos3.size();jjj ++) {
                    if(pos1[j] + pos2[jj] + last_add - pos3[jjj] - cur_add == 0) {
                        countf ++;
                    }
                }
            }
        }
        sumf *= countf;
        if(sumf == 0) {
            return sumf;
        }
    }
    return sumf;
}


int main() {
    int T;
    cin >> T;
    while (T -- ) {
        string add1, add2, sum1;
        cin >> add1 >> add2 >> sum1;
        if(add1.length() < add2.length()) swap(add1, add2);
        long long tot_range = 0;
        for(int i = 0;i < 8 ;i ++) {
            tot_range += calc(add1, add2, sum1 ,i);
        }
        cout << tot_range << endl;
    }
    return 0;
}
