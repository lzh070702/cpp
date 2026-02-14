#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main(void) {
    int x = 7;
    float y = 3.0;
    auto p = [x, y](int a, int b) -> float { return x * y + a * b; };
    cout << p(10, 20) << endl;
    // struct {
    //     int _x;
    //     float _y;

    //     float operator()(int a, int b) const { return _x * _y + a * b; }
    // } p{x, y};
    // cout << p(10, 20) << endl;

    vector<int> v = {5, 3, 6, 2, 8, 9, 0, 7, 1, 2, 5, 0, 3, 4};
    sort(v.begin(), v.end(), [](int a, int b) { return a > b; });
    for (auto i : v) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}