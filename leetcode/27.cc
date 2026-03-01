#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i : nums) {
            if (i != val) {
                nums[k++] = i;
            }
        }
        return k;
    }
};

void print(vector<int> nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int val = 2;
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int k = Solution().removeElement(nums, val);
    cout << k << endl;
    print(nums);
    return 0;
}