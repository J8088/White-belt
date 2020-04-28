#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    const string path_in = "input.txt";
    ifstream input(path_in);

/*    const string path_out = "output.txt";
    ofstream output(path_out);*/

    if (input)
    {
        int N, M;
        input >> N >> M;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                int a;
                input >> a;
                if (j != M - 1)
                    input.ignore(1);
                cout << setw(10);
                cout << a;
                if (j != M - 1)
                    cout << " ";
            }
            if (i != N - 1)
                cout << endl;
        }
    }
    else
        cout << "error!" << endl;
    return 0;
}