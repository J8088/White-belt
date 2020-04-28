#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const string path = "input.txt";
    ifstream input(path);
    string line;
    if (input.is_open()){
        while (getline(input, line)) {
            cout << line << endl;
        }
    } else {
        cout << "error!" << endl;
    }
    return 0;
}