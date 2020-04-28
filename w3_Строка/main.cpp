#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class ReversibleString
{
private:
    string s;
public:

    ReversibleString() {}
    ReversibleString(string str) { s = str; }

    void Reverse()
    {
        string c = "";
        for (int i = s.size(); i > 0; --i)  c += s[i-1];
        s = c;
    }

    string ToString() const { return s; }
};

int main() {
    ReversibleString s("live");
    s.Reverse();
    cout << s.ToString() << endl;

    s.Reverse();
    const ReversibleString& s_ref = s;
    string tmp = s_ref.ToString();
    cout << tmp << endl;

    ReversibleString empty;
    cout << '"' << empty.ToString() << '"' << endl;

    return 0;
}