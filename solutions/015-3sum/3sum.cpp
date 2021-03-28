// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Notice that the solution set must not contain duplicate triplets.
//
//  
// Example 1:
// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Example 2:
// Input: nums = []
// Output: []
// Example 3:
// Input: nums = [0]
// Output: []
//
//  
// Constraints:
//
//
// 	0 <= nums.length <= 3000
// 	-105 <= nums[i] <= 105
//
//


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size = nums.size();
        for(int i = 0; i < size - 2; i++){
            // 先遍歷整個vector
            if(nums[i] > 0){
                // 如果第一個數字 > 0 就找不到數字了
                break;
            }
            if(i > 0 && nums[i] == nums[i - 1]){
                // 把重複的數字跳過
                continue;
            }
            // 雙重指標
            int l = i + 1;
            int r = size - 1;
            while(l < r){
                if(nums[l] + nums[r] + nums[i] > 0){
                    // 三個數字相加 > 0
                    // 代表右邊的數字太大
                    r--;
                }
                else if(nums[l] + nums[r] + nums[i] < 0){
                    // 三個數字相加 < 0
                    // 代表左邊的數字太小
                    l++;
                }
                else{
                    // 三個數字相加 = 0
                    // 將答案丟進去
                    ans.push_back({nums[i], nums[l], nums[r]});
                    // 移動指標
                    l++, r--;
                    while(l < r && nums[l] == nums[l - 1]){
                        // 重複的數字跳過
                        l++;
                    }
                    while(l < r && nums[r] == nums[r + 1]){
                        // 重複的數字跳過
                        r--;
                    }
                    
                }
            }
        }
        
        return ans;
    }
};
