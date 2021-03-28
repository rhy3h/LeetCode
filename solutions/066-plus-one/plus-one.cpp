// Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
//  
// Example 1:
//
//
// Input: digits = [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
//
//
// Example 2:
//
//
// Input: digits = [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
//
//
// Example 3:
//
//
// Input: digits = [0]
// Output: [1]
//
//
//  
// Constraints:
//
//
// 	1 <= digits.length <= 100
// 	0 <= digits[i] <= 9
//
//


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> plusOne;
        
        int index = digits.size()-1, digitSum = 1;
        
        while(index >= 0){
            digitSum += digits[index];
            plusOne.insert(plusOne.begin(), digitSum % 10);
            digitSum /= 10;
            index--;
        }
        if(digitSum > 0)
            plusOne.insert(plusOne.begin(), digitSum % 10);
        return plusOne;
    }
};
