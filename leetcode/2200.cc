#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
        int n = nums.size(), j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != key) {
                continue;
            }
            j = max(j, i - k);              
            while (j <= min(i + k, n - 1)) {
                res.push_back(j++);
            }
        }
        return res;
    }
};