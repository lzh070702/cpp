#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int>& nums, int k) {
    int left = nums.size() - 1, right = left, res = 0, cnt = nums[left] % 2;
    while (left >= 0) {
        if (cnt >= k && left <= right) {
            cnt -= nums[right--] % 2;
            res += left + 1;
        } else if (left != 0) {
            cnt += nums[--left] % 2;
        } else {
            break;
        }
    }
    return res;
}

class Solution {
   public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k + 1);
    }
};

int main() {
    vector<int> nums = {2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;
    cout << Solution().numberOfSubarrays(nums, k) << endl;
    return 0;
}