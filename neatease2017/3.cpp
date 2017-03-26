#include <map>
#include <vector>
#include <iostream>
using namespace std;

map<int , int > store_state[25];
string name_list[25];
int upgrade_time[25];
vector<int > cost[25];
vector<int > upgrade[25];
int vector_upgrade_route[25];
int main() {
    int T;
    cin >> T;
    while(T -- ){
        int N, S;
        cin >> N >> S;
        for(int i = 0;i <= N;i ++) {
            store_state[i].clear();
            upgrade[i].clear();
            cost[i].clear();
        }
        int max_upgrade = 0;
        store_state[0][0] = 0;
        for(int i = 0;i < N;i ++ ){
            cin >> name_list[i];
            cin >> upgrade_time[i];
            int tot_cost = 0;
            int tot_upgrade = 0;
            for(auto it= store_state[i].begin();it != store_state[i].end();it ++) {
                store_state[i+1][it->first] = it->second;
                max_upgrade = max(max_upgrade, store_state[i + 1][it->first]);
            }
            for(int j = 1;j <= upgrade_time[i];j ++) {
                int cc, uu;
                cin >> uu >> cc;
                tot_cost += cc;
                tot_upgrade += uu;
                cost[i].push_back(tot_cost);
                upgrade[i].push_back(tot_upgrade);
                for(auto it = store_state[i].begin(); it != store_state[i].end(); it ++) {
                    if(it->first + tot_cost <= S) {
                        store_state[i + 1][it->first + tot_cost] = max(store_state[i + 1][it->first + tot_cost], it->second + tot_upgrade);
                        max_upgrade = max(max_upgrade, store_state[i + 1][it->first + tot_cost]);
                    }
                }
            }
        }
        int final_cost;
        for(auto it = store_state[N].begin(); it != store_state[N].end();it ++) {
            if(it->second == max_upgrade) {
                final_cost = it->first;
                break;
            }
        }
        int final_max_upgrade = max_upgrade;
        for(int i = N - 1;i >= 0;i --) {
            if(store_state[i].count(final_cost)) {
                if(store_state[i][final_cost] == final_max_upgrade) {
                    vector_upgrade_route[i] = 0;
                    continue;
                }
            }
            for(int j = 0;j < upgrade_time[i];j ++) {
                if(store_state[i].count(final_cost - cost[i][j])) {
                    if(store_state[i][final_cost - cost[i][j]] == final_max_upgrade - upgrade[i][j]){
                        vector_upgrade_route[i] = j + 1;
                        final_max_upgrade -= upgrade[i][j];
                        final_cost -= cost[i][j];
                        break;
                    }
                }
            }
        }
        cout << max_upgrade << endl;
        for(int i = 0;i < N;i ++) {
            cout << name_list[i] << "+" << vector_upgrade_route[i] << endl;
        }

    }

}
