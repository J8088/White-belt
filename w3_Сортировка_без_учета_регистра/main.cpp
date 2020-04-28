#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <stdio.h>


using namespace std;

bool equals( string s1, string s2 )
{
    transform( s1.begin(), s1.end(), s1.begin(), ::toupper );
    transform( s2.begin(), s2.end(), s2.begin(), ::toupper );
    return (  s1 < s2 );
}


int main() {
    int N;
    cin >> N;
    vector<string> str;
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        str.push_back(s);
    }
    sort(str.begin(), str.end(), equals);
    for (auto s : str)
        cout << "\n" << s;

    return 0;
}