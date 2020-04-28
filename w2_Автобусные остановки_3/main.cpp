#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

static map<set<string>, int> root;

int main() {
    int Q, N, k = 0;
    cin >> Q;
    for (int i = 0; i < Q; ++i) {
        cin >> N;
        set<string> stops;
        string s;
        for (int j = 0; j < N; ++j) {
            cin >> s;
            stops.insert(s);
        }
        if (root[stops] == 0) {
            root[stops] = ++k;
            cout << "New bus " << k << endl;
        }
        else
            cout << "Already exists for " << root[stops] << endl;
    }
    return 0;
}