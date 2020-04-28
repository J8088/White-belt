//ЕЖЕМЕСЯЧНЫЕ ДЕЛА!!

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

static vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static int cur_month;
static vector<string> month;

void add(int n, string action) //работает норм!
{
    month[n-1] += ' ';
    month[n-1] += action;

}

void next()
{
    cur_month += 1;
    cur_month %= 12;//ок
    if (days[cur_month] >= days[cur_month - 1])
        month.resize(days[cur_month], "");
    else
    {
        int d = days[cur_month - 1] - days[cur_month];
        for (int i = 0; i < d; ++i) {// тут жопа.
            string extra =  month[days[cur_month - 1] - d + i];
            month[days[cur_month] - 1] += extra;
        }
        month.resize(days[cur_month], "");
    }
}

void dump(int n)
{

    int c = count(begin(month[n - 1]), end(month[n - 1]), ' ');
    cout << c << month[n - 1] << endl;
}

int main()
{
    map<string,int> p = {{"ADD", 0}, {"NEXT", 1}, {"DUMP", 2}};
    int Q;
    cin >> Q;
    string command, action;
    int n, temp;
    cur_month = 0; //фиксируем январь!
    month.resize(days[cur_month]);
    for (int i = 0; i < Q; ++i) {
        cin >> command;
        temp = p[command];
        if ((temp == 0) || (temp == 2))
            cin >> n;
        if (temp == 0)
            cin >> action;
        switch (temp)
        {
            case 0:
                add(n, action);
                break;
            case 1:
                next();
                break;
            case 2:
                dump(n);
                break;
        }
    }
    return 0;
}