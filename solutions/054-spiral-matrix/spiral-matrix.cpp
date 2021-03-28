// Given an m x n matrix, return all elements of the matrix in spiral order.
//
//  
// Example 1:
//
//
// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
//
// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//
//
//  
// Constraints:
//
//
// 	m == matrix.length
// 	n == matrix[i].length
// 	1 <= m, n <= 10
// 	-100 <= matrix[i][j] <= 100
//
//


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        vector<int> result;
        
        int rows = matrix.size(), cols = matrix[0].size();
        int up = 0, down = rows - 1, left = 0, right = cols - 1;
        while(true){
            for(int j = left; j <= right; j++)
                result.push_back(matrix[up][j]);
            up++;
            if(up > down)
                break;
            
            for(int i = up; i <= down; i++)
                result.push_back(matrix[i][right]);
            right--;
            if(left > right)
                break;
            
            for(int j = right; j >= left; j--){
                result.push_back(matrix[down][j]);
            }
            down--;
            if(up > down)
                break;
            
            for(int i = down; i >= up; i--){
                result.push_back(matrix[i][left]);
            }
            left++;
            if(left > right)
                break;
        }
        return result;
    }
};
