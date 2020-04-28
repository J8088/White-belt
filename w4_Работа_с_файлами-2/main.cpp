#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    const string path_in = "input.txt";
    ifstream input(path_in);
    const string path_out = "output.txt";
    ofstream output(path_out);
    string line;
    if (input)
        while (getline(input, line))
            output << line << endl;
        else
        output << "error!" << endl;
    return 0;
}