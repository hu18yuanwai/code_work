#include <iostream>
#include <bitset>
#include <string>
#include <sstream>
using namespace std;


string Decode(string in) {
	while(in[0] == '0' && in.size() > 1) {
		in = in.substr(1);
	}
	int str_len = in.size();
	if(!(str_len == 1 ||str_len == 2 || str_len == 4 || str_len == 6 || str_len == 8) )
		return "false";
	for(int i = 0; i < str_len; i ++) {
		if(!(('0' <= in[i] && in[i] <= '9') || ('a' <= in[i] && in[i] <= 'f') || ('A' <= in[i] && in[i] <= 'F')))
			return "false";
	}
	long long original = stoull(in, nullptr, 16);         // the original dec number of in string
	int result;                                           //the returned result represented by valid bits
	if(str_len == 2 || str_len == 1) {
		bitset<8> bit(original);
		in =  bit.to_string();
		if(in[0] != '0') {
			return "false";
		}
		result = original;
		if(result < 0 || result > 127) return "false";    // ensure the result is in the correct range
	} else if (str_len == 4) {
		bitset<16> bit(original);
		in =  bit.to_string();
		if(in[0] == '0' || in[1] == '0' || in[2] == '1' || in[8] == '0' || in[9] == '1') {
			return "false";
		}
		string result_str ;                               // the binary string of valid bits
		result_str += string(in,3,5);
		result_str += string(in,10,6);
		result = stoi(result_str, nullptr, 2);            // transanfer the valid bits to the dec number
		if(result < 128 || result > 2047) return "false"; // ensure the result is in the correct range
	} else if (str_len == 6) {
		bitset<24> bit(original);
		in =  bit.to_string();
		if(in[0] == '0' || in[1] == '0' || in[2] == '0' || in[3] == '1' || in[8] == '0' || in[9] == '1' || in[16] == '0' || in[17] == '1') {
			return "false";
		}
		string result_str ;
		cout << in << endl;
		result_str += string(in,4,4);
		result_str += string(in,10,6);
		result_str += string(in,18,6);
		result = stoi(result_str, nullptr, 2);
		if(result < 2048 || result > 65535) return "false";	
	} else if (str_len == 8) {
		bitset<32> bit(original);
		in =  bit.to_string();
		if(in[0] == '0' || in[1] == '0' || in[2] == '0' || in[3] == '0' || in[4] == '1' || in[8] == '0' || in[9] == '1' || in[16] == '0' || in[17] == '1' || in[24] == '0' || in[25] == '1') {
			return "false";
		}
		string result_str ;
		result_str += string(in,5,3);
		result_str += string(in,10,6);
		result_str += string(in,18,6);
		result_str += string(in,26,6);
		result = stoi(result_str, nullptr, 2);
		if(result < 65536 || result > 1114111) return "false";
	}
	
	stringstream ss;
	ss << result;
	return ss.str();
}

int main() {
	string _in;
	
	cin >> _in;
	string res = Decode(_in);
	cout << res << endl;
	
	return 0;
}
