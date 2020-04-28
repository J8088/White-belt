#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const string path_in = "input.txt";
    ifstream input(path_in);
    cout << fixed << setprecision(3);
    if (input) {
        double d;
        while (input >> d) {
            cout << fixed << setprecision(3);
            cout << d << endl;
        }
    }
    else
        cout << "error!" << endl;
    return 0;
}