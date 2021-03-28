// Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
//
// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
//
//  
// Example 1:
// Input: x = 123
// Output: 321
// Example 2:
// Input: x = -123
// Output: -321
// Example 3:
// Input: x = 120
// Output: 21
// Example 4:
// Input: x = 0
// Output: 0
//
//  
// Constraints:
//
//
// 	-231 <= x <= 231 - 1
//
//


class Solution {
public:
    int reverse(int x) {
        // 紀錄是否負數
        bool negative = false;
        // 要用 long 存
        // 因為 INT_MIN 轉成正的
        // 會 > INT_MAX
        long num = x;
        if(num < 0){ 
            // 先將負數轉成正的
            // 計算速度會比較快
            negative = true;
            num *= -1;
        }
        // 因為反轉後 有可能超過 int 大小
        // 所以利用 long 去將數字反轉
        long ans = 0;
        while(num != 0){
            ans = ans * 10 + num % 10;
            num /= 10;
        }
        // 因為題目要求 > int 的範圍
        // 就 return 0
        if(ans > INT_MAX){
            return 0;
        }
        return negative ? (-1 * ans): ans;
    }
};
