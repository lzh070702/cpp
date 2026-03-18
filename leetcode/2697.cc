#include <iostream>
#include <string>

using namespace std;

class Solution {
   public:
    string makeSmallestPalindrome(string s) {
        auto left = s.begin(), right = s.end() - 1;
        while (left < right) {
            if (*left > *right) {
                *left = *right;
                *left = *right;
            } else if (*left < *right) {
                *right = *left;
            }
            left++;
            right--;
        }
        return s;
    }
};