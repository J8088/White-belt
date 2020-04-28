#include<iostream>
#include <map>
#include <set>
#include <vector>
#include <exception>
#include <sstream>
#include<string>
#include<algorithm>
#include<iomanip>

using namespace std;

// Реализуйте функции и методы классов и при необходимости добавьте свои

class Date {


public:

    Date()
    {
        year = 0;
        month = 0;
        day = 0;
    }

    Date(int year_new, int month_new, int day_new)
    {
        map<int,int> er = {{0,5}, {1,5}};
        if ((month_new > 12) || (month_new < 1))
        {
            er[0] = month_new;
            throw er;
        }
        if ((day_new > 31) || (day_new < 1))
        {
            er[1] = day_new;
            throw er;
        }
        year = year_new;
        month = month_new;
        day = day_new;
    }

    int GetYear() const { return year; }
    int GetMonth() const { return month; }
    int GetDay() const { return day; }


private:
    int year;
    int month;
    int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() == rhs.GetYear())
    {
        if (lhs.GetMonth() == rhs.GetMonth())
            return (lhs.GetDay() < rhs.GetDay());
        else
            return (lhs.GetMonth() < rhs.GetMonth());
    }
    else
        return (lhs.GetYear() < rhs.GetYear());
}

bool operator==(const Date& lhs, const Date& rhs) {
    return ((lhs.GetYear() == rhs.GetYear()) &&
            (lhs.GetMonth() == rhs.GetMonth()) &&
            (lhs.GetDay() == rhs.GetDay()));
}

class Database {
private:
    map<Date, set<string>> events;
public:
    void AddEvent(const Date& date, const string& event)
    {
        if (event != "")
            events[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event) {
        try {
            if (events.at(date).find(event) != events.at(date).end())//true, если есть; false -нет
            {
                events[date].erase(event);
                return 1; //найдено и удалено
            } else
                return 0; //не найдено
        }
        catch (exception &) {
            return 0;
        }
    }

    int  DeleteDate(const Date& date)
    {
        try {
            int N = events.at(date).size();
            events.erase(date);
            return N;
        }
        catch (exception&)
        {
            return 0;
        }
    }

   set<string> Find(const Date& date) const
   {
       try {
           return events.at(date);
       }
       catch (exception&)
       {
           return set<string>();
       }
   }

    void Print() const
    {
        for (auto i : events)
        {
            for (auto j : i.second)
            {
                cout << setfill('0');
                cout << setw(4) << i.first.GetYear() << "-" << setw(2) <<
                     i.first.GetMonth() << "-" << setw(2) << i.first.GetDay();
                cout << " " << j << endl;
            }
        }
    }

    //вспомогательный метод для парсинга
    void isSign(stringstream& stream, char c) {
        char p = stream.peek();
        if ((c == '-') && (p == c))
            stream.ignore(1);
        if ((c == EOF) && (p != c))
            throw exception();
    }

    //вспомогательный метод для парсинга
    void isNumber(stringstream& stream, int& a) {
        char p;
        p = stream.peek();
        if ((isdigit(p)) || (p == '-'))
            stream >> a;
        else
            throw exception();
    }



    Date Parse(string s)
    {
        stringstream stream(s);
        int year, month, day;
        char c1, c2;
        try {
            isNumber(stream, year);
            isSign(stream, '-');
            isNumber(stream, month);
            isSign(stream, '-');
            isNumber(stream, day);
            isSign(stream, EOF);
            return Date(year,month,day);
        }
        catch (exception&)
        {
            return Date();
        }
    }
};

int main() {
        Database db;
        vector<string> std_com = {"Add", "Del", "Find", "Print"};
        string input, data, command;

        while (getline(cin, input)) {

            if ((input == " ") || (input == ""))  continue;
            vector<string> commands(3);
            stringstream stream(input);
            int i = 0;
            while (getline(stream, data, ' '))
                commands[i++] = data;
            command = commands[0];

            if (count(std_com.begin(), std_com.end(), command) == 0) {
                cout << "Unknown command: " << command << endl;
                continue;//return 0;
            }

            if (command == "Print") {
                db.Print();
            } else {
                Date d;
                try {
                    d = db.Parse(commands[1]);
                }
                catch (map<int, int> er) {
                    if (er[0] != 5)
                        cout << "Month value is invalid: " << er[0] <<endl;
                    if (er[1] != 5)
                        cout << "Day value is invalid: " << er[1] << endl;
                    continue;//return 0;
                }
                if (d == Date()) {
                    cout << "Wrong date format: " << commands[1] << endl;
                    continue;//return 0;
                }
                if (command == "Add") {
                    if (commands[2] == "")
                    {
                       cout << "Wrong date format: " << commands[1] << endl;
                        continue;//return 0;
                    }
                    else
                        db.AddEvent(d, commands[2]);
                } else if (command == "Find") {
                    set<string> ev = db.Find(d);
                    for (auto i : ev)
                        cout << i << endl;
                } else if (command == "Del") {
                    if (commands[2] == "") {
                        int N = db.DeleteDate(d);
                        cout << "Deleted " << N << " events" << endl;
                    } else {
                        if (db.DeleteEvent(d, commands[2]))
                            cout << "Deleted successfully" << endl;
                        else {
                            cout << "Event not found" << endl;
                        }
                    }
                }
            }
        }
    return 0;
}

//работает неправильно с датой 1-1---1  !!!
//крутые тесты https://www.coursera.org/learn/c-plus-plus-white/programming/sO7Vq/final-naia-zadacha-kursa/discussions/threads/ARzcF3yVEeiR-RKlTIHM3g
//смотреть их внимательно, начиная с 76 output