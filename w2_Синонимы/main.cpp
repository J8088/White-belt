#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

static set<set<string>> dic;
static map<string, int> cnt;

int main() {
    int Q;
    cin >> Q;
    string command, s1, s2;
    for (int i = 0; i < Q; ++i) {
        cin >> command;
        if (command == "ADD")
        {
            set<string> temp;
            cin >> s1 >> s2;
            temp.insert(s1);
            temp.insert(s2);
            if (dic.count(temp) == 0)
            {
                cnt[s1]++;
                cnt[s2]++;
            }
            dic.insert(temp);
        }
        else if (command == "COUNT")
        {
            cin >> s1;
            cout << cnt[s1] << endl;
        }
        else if (command == "CHECK")
        {
            set<string> temp;
            cin >> s1 >> s2;
            temp.insert(s1);
            temp.insert(s2);
            if (dic.count(temp) == 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;

        }
    }

    return 0;
}