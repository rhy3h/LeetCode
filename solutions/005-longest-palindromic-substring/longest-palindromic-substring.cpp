// Given a string s, return the longest palindromic substring in s.
//
//  
// Example 1:
//
//
// Input: s = "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: s = "cbbd"
// Output: "bb"
//
//
// Example 3:
//
//
// Input: s = "a"
// Output: "a"
//
//
// Example 4:
//
//
// Input: s = "ac"
// Output: "a"
//
//
//  
// Constraints:
//
//
// 	1 <= s.length <= 1000
// 	s consist of only digits and English letters (lower-case and/or upper-case),
//


class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, length = 0;
        auto get_length = [&](int l, int r){
            // 從中間往旁邊擴張
            // 如果兩旁的字不相同
            // 就代表不是回文字串
            while(l >= 0 && r < s.length() && s[l] == s[r]){
                l--;
                r++;
            }
            return r - l - 1;
        };
        
        for(int i = 0; i < s.length(); i++){
            // 因為考慮到偶數
            // 所以是奇偶比大小
            int current = max(get_length(i, i), get_length(i, i+1));
            if(current > length){
                length = current;
                start = i - (length-1) / 2;
            }
        }
        
        return s.substr(start, length);
    }
};
