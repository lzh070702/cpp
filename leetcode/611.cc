#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
   public:
    int triangleNumber(vector<int>& nums) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0){
                continue;
            }
            int k = i + 2;
            for (int j = i + 1; j < nums.size(); j++) {
                while (k < nums.size() && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                 ans += k - j - 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {2, 2, 3, 4};
    cout << Solution().triangleNumber(nums) << endl;
    return 0;
}