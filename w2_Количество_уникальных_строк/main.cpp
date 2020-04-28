#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<string> str;
    string s;
    for (int i = 0; i < N; ++i) {
        cin >> s;
        str.push_back(s);
    }
    set<string> c(begin(str), end(str));
    cout << c.size() << endl;
    return 0;
}