#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


static map<string, vector<string>> roots;
static map<string, int> bus_number;

bool cmp(const string& bus1, const string& bus2) {
   return bus_number[bus1] < bus_number[bus2];
}

void Print_all_buses(const vector<string>& buses)
{
    for (auto b : buses)
        cout << b << " ";
    cout << endl;
}

void Print_not_all_buses(const vector<string>& buses, string bus)
{
    for (auto b : buses)
        if (b != bus)
            cout << b << " ";
    if ((buses.size() == 1) && (buses[0] == bus))
        cout << "no interchange";
    cout << endl;
}

void Buses_for_stop(string stop, bool par, string ex)
{
    vector<string> buses;
    for (auto b : roots)
        for (auto s : b.second)
            if (s == stop)
                buses.push_back(b.first);
    if (buses.size() != 0) {
        sort(begin(buses), end(buses), cmp);
        if (par == 0)
            Print_all_buses(buses);
        else
            Print_not_all_buses(buses, ex);
    } else
        cout << "No stop\n";
}

void Stops_for_bus(string bus)
{
    if (roots[bus].size() != 0) {
        for (auto stop : roots[bus]) {
            cout << "Stop " << stop << ": ";
            Buses_for_stop(stop, 1, bus);
        }
    } else {
        roots.erase(bus);
        cout << "No bus" << endl;
    }

}

void All_buses()
{
    if (roots.size() == 0)
        cout << "No buses" << endl;
    else {
        for (auto b : roots) {
            cout << "Bus " << b.first << ":";
            for (auto c : b.second)
                cout << " " << c;
            cout << endl;
        }
    }

}



int main() {
    int Q, n, k = 0;
    cin >> Q;
    string command, bus, stop;
    for (int i = 0; i < Q; ++i) {
        cin >> command;
        if (command == "NEW_BUS")
        {
            cin >> bus >> n;
            vector<string> stops;
            string c;
            for (int j = 0; j < n; ++j) {
                cin >> c;
                stops.push_back(c);
            }
            roots[bus] = stops;
            bus_number[bus] = k++;
        }
        else if (command == "BUSES_FOR_STOP")
        {
            cin >> stop;
            Buses_for_stop(stop, 0, "");

        }
        else if (command == "STOPS_FOR_BUS")
        {
            cin >> bus;
            Stops_for_bus(bus);
        }
        else if (command == "ALL_BUSES")
            All_buses();
    }

    return 0;
}