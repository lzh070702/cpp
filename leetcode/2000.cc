#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string reversePrefix(string word, char ch) {
        int left = 0, right = 0;
        while (right < word.size()) {
            if (word[right] == ch) {
                break;
            }
            right++;
        }
        if (right == word.size() && word[--right] != ch) {
            return word;
        }
        while (left < right) {
            word[left] = word[left] ^ word[right];
            word[right] = word[left] ^ word[right];
            word[left] = word[left] ^ word[right];
            left++;
            right--;
        }
        return word;
    }
};