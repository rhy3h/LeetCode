// Given two binary strings a and b, return their sum as a binary string.
//
//  
// Example 1:
// Input: a = "11", b = "1"
// Output: "100"
// Example 2:
// Input: a = "1010", b = "1011"
// Output: "10101"
//
//  
// Constraints:
//
//
// 	1 <= a.length, b.length <= 104
// 	a and b consist only of '0' or '1' characters.
// 	Each string does not contain leading zeros except for the zero itself.
//
//


class Solution {
public:
    string addBinary(string a, string b) {
        string result = "";
        int indexA = a.length()-1, indexB = b.length()-1;
        
        int countDigit = 0;
        while(indexA >= 0 || indexB >= 0 || countDigit > 0){
            if(indexA >= 0){
                countDigit += (int)(a[indexA] - '0');
                indexA--;
            }
            if(indexB >= 0){
                countDigit += (int)(b[indexB] - '0');
                indexB--;
            }
            if(countDigit == 0){
                result = "0" + result;
            }
            if(countDigit == 1){
                result = "1" + result;
                countDigit = 0;
            }
            if(countDigit == 2){
                result = "0" + result;
                countDigit = 1;
            }
            if(countDigit == 3){
                result = "1" + result;
                countDigit = 1;
            }           
        }
        
        return result;
    }
};
