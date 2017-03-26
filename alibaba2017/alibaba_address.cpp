#include <iostream>
#include <string>
#include <vector>
using namespace std;

void dfs(string& s, int start, int partNum, string ip, vector<string>& result) {
    int length = s.size();
    if (partNum == 4 && start == length){
        ip.resize(ip.size() - 1);
        result.push_back(ip);
        return;
    }
	if ( length - start < 4 - partNum  || length - start > (4-partNum) * 3 ) {
        return;
    }
    int num = 0;
    for (int i=start; i<start+3; i++){
        num = num * 10 + s[i] - '0';
        if (num<256){
            ip+=s[i];
            dfs(s, i+1, partNum+1, ip+'.', result);
        }
        if (num == 0) {
            break;
        }
    }

}

int index(string str) {
	int index = 0;
	for(;index < str.size(); index ++) {
		if(str[index] == '.')
			return index;
	}
}

vector<string> partition(string str) {
	vector<string> result;
	for(int i = 0; i < 3;i ++) {
		int idx = index(str);
		int len = str.size();
		result.push_back(string(str,0,idx));
		string tmp = string(str,idx+1,len-idx);
		str = tmp;
	}
	result.push_back(str);
	return result;
}

bool isNotPravite(string str) {
	vector<string> ipstr = partition(str);
	vector<int> ip;
	for(int i = 0; i < 4; i ++) {
		int cur = stoi(ipstr[i],nullptr,10);
		ip.push_back(cur);
	}
	if(ip[0] == 10) {
		return false;
	}
	if(ip[0] == 172 && (ip[1] >= 16 && ip[1] <= 31) ) {
		return false;
	}
	if(ip[0] == 192 && ip[1] == 168) {
		return false;
	}
	return true;
}

vector<string> decide(string s) {
    vector<string> result_with_private;
    string ip;
    dfs(s, 0, 0, ip, result_with_private);

	vector<string> result;
	for(const auto &item : result_with_private) {
		if(isNotPravite(item)) {
			result.push_back(item);
		}
	}
	return result;
}

int main() {
	string in;
	cin >> in;
	vector<string> res = decide(in);
	for(auto &item : res) {
		cout << item << endl;
	}
}
