#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& nums, int goal) {
    int left = nums.size() - 1, right = left, res = 0, sum = nums[left];
    while (left >= 0) {
        if (sum >= goal && left <= right) {
            sum -= nums[right--];
            res += left + 1;
        } else if (left != 0) {
            sum += nums[--left];
        } else {
            break;
        }
    }
    return res;
}

class Solution {
   public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return solve(nums, goal) - solve(nums, goal + 1);
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0};
    int goal = 0;
    cout << Solution().numSubarraysWithSum(nums, goal) << endl;
    return 0;
}