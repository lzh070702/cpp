#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        auto left = plants.begin(), right = plants.end() - 1;
        int Alice = capacityA, Bob = capacityB, res = 0;
        while (left < right) {
            if (Alice < *left) {
                res++;
                Alice = capacityA;
            }
            Alice -= *left;
            left++;
            if (Bob < *right) {
                res++;
                Bob = capacityB;
            }
            Bob -= *right;
            right--;
        }
        if (left == right) {
            if (Alice >= Bob) {
                if (Alice < *left) {
                    res++;
                }
            } else {
                if (Bob < *right) {
                    res++;
                }
            }
        }
        return res;
    }
};

void test1() {
    vector<int> plants = {2, 2, 3, 3};
    int capacityA = 5, capacityB = 5;
    cout << Solution().minimumRefill(plants, capacityA, capacityB) << endl;
}

int main() {
    test1();
    return 0;
}