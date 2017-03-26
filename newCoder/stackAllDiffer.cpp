#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

void dp (int * p, int s, int e, stack<int> & stack, int * q, int ss, vector<vector<int>> & res) {
	if (s == e && ss == e) {
		res.push_back({});
		for (int i = 0; i < ss; ++ i) {
			res[res.size() - 1].push_back(q[i]);
		}

	}
	if (s != e) {
		stack.push(p[s]);
		dp (p, s + 1, e, stack, q, ss, res);
		stack.pop();
	}

	if (! stack.empty()) {
		q[ss] = stack.top();
		stack.pop();
		dp (p, s, e, stack, q, ss + 1, res);
		stack.push(q[ss]);
	}
}

int main (int argc, char * const argv[]) {
	int n;
	cin >> n;
	int * p = new int [n], * q = new int [n];
	for (int i = 0; i < n; ++ i) {
		cin >> p[i];
	}
	stack<int> s;
	vector<vector<int>> res;
	dp (p, 0, n, s, q, 0, res);

	struct Comp {
		bool operator () (const vector<int> & a, const vector<int> &b) {
			if (a.size () != b.size()) {
				return a.size () < b.size();
			}
			for (int i = 0; i < a.size(); ++ i) {
				if (a[i] != b[i]) {
					return a[i] < b[i];
				}
			}
			return false;
		}
	} comp;
	sort (res.begin(), res.end(), comp);

	struct bComp {
		bool operator () (const vector<int> & a, const vector<int> &b) {
			if (a.size () != b.size()) {
				return false;
			}
			for (int i = 0; i < a.size(); ++ i) {
				if (a[i] != b[i]) {
					return false;
				}
			}
			return true;
		}
	} bcomp;

	auto it = unique(res.begin(), res.end(), bcomp);
	res.resize(distance (res.begin(), it));

	for (auto x : res) {
		for (auto & val : x) {
			cout << val << " ";
		}
		cout << endl;
	}
	delete [] p;
	delete [] q;
	return 0;
} 
