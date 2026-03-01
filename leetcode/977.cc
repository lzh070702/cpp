#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        int i = 0, j = --n;
        for (; n >= 0; n--) {
            int x = nums[i] * nums[i];
            int y = nums[j] * nums[j];
            if (x > y) {
                res[n] = x;
                i++;
            }else{
                res[n] = y;
                j--;
            }
        }
        return res;
    }
};

void print(vector<int> nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = {-7, -3, 2, 3, 11};
    print(nums);
    vector<int> res = Solution().sortedSquares(nums);
    print(res);
    return 0;
}