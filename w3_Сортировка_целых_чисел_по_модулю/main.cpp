#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> A;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(begin(A), end(A), [](int x, int y) {return abs(x) < abs(y); });
    for (const auto& a : A) {
        cout << a << " ";
    }
    return 0;
}