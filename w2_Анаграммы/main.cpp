//Справочник столиц!!!
#include <iostream>
#include <map>
#include <string>

using namespace std;

static map<string, string> capital;

void do_change_capital(const string& s1, const string& s2)
{
    if (capital[s1] == "")
    {
        capital[s1] = s2;
        cout << "\nIntroduce new country " << s1 << " with capital " << s2;
    }
    else if (capital[s1] == s2)
        cout << "\nCountry " << s1 << " hasn't changed its capital";
    else
    {
        cout << "\nCountry " << s1 << " has changed its capital from " << capital[s1] << " to " << s2;
        capital[s1] = s2;
    }
}

void do_rename(const string& s1, const string& s2)
{
    if ((capital[s1] == "") || (s1 == s2) || (capital[s2] != "")) {
        cout << "\nIncorrect rename, skip";
        if (capital[s1] == "")
            capital.erase(s1);
    }
    else
    {
        capital[s2] = capital[s1];
        cout << "\nCountry " << s1 << " with capital " <<
             capital[s1] << " has been renamed to " << s2;
        capital.erase(s1);
    }


}

void do_about(const string& s1)
{

    if (capital[s1] == "") {
        cout << "\nCountry " << s1 << " doesn't exist";
        capital.erase(s1);
    }
    else
        cout << "\nCountry " << s1 << " has capital " << capital[s1];
}

void do_dump()
{
    if (capital.size() == 0)
        cout << "\nThere are no countries in the world";
    else {
        cout << "\n";
        for (auto c : capital) {
            cout << c.first << "/" << c.second << " ";
        }
    }
}


int main() {
    int Q;
    cin >> Q;
    string command, s1, s2;
    for (int i = 0; i < Q; ++i) {
        cin >> command;
        if (command == "CHANGE_CAPITAL")
        {
            cin >> s1 >> s2;
            do_change_capital(s1, s2);
        }
        else if (command == "RENAME")
        {
            cin >> s1 >> s2;
            do_rename(s1, s2);
        }
        else if (command == "ABOUT")
        {
            cin >> s1;
            do_about(s1);
        }
        else if (command == "DUMP")
            do_dump();
    }
    return 0;
}