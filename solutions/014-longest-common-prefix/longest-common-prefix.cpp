// Write a function to find the longest common prefix string amongst an array of strings.
//
// If there is no common prefix, return an empty string "".
//
//  
// Example 1:
//
//
// Input: strs = ["flower","flow","flight"]
// Output: "fl"
//
//
// Example 2:
//
//
// Input: strs = ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.
//
//
//  
// Constraints:
//
//
// 	0 <= strs.length <= 200
// 	0 <= strs[i].length <= 200
// 	strs[i] consists of only lower-case English letters.
//
//


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        string ans;
        
        // 取第一個元素的長度
        for(int i = 0; i < strs[0].length(); i++){
            // 遍歷整個vector
            for (auto & s : strs) {
                // 判斷字是否相同
                // 不同就
                // return ans
                if(s.length() <= i || s[i] != strs[0][i])
                    return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};
