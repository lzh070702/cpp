#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p = m + n - 1;
        m--;
        n--;
        while (m != -1 && n != -1) {
            if (nums1[m] > nums2[n]) {
                nums1[p--] = nums1[m--];
            } else {
                nums1[p--] = nums2[n--];
            }
        }
        if (n == -1) {
            return;
        }
        while (n != -1) {
            nums1[p--] = nums2[n--];
        }
    }
};

void print(vector<int> nums) {
    for (auto i : nums) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums1 = {0}, nums2 = {1};
    int m = 0, n = 1;
    print(nums1);
    print(nums2);
    Solution().merge(nums1, m, nums2, n);
    print(nums1);
    return 0;
}