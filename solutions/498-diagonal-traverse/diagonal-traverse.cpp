// Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.
//
//  
//
// Example:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
//
// Output:  [1,2,4,7,5,3,6,8,9]
//
// Explanation:
//
//
//
//  
//
// Note:
//
// The total number of elements of the given matrix will not exceed 10,000.
//


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return {};
        vector<int> result;
        vector<pair<int, int>> move_delta{{-1, 1}, {1, -1}};
        
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = 0, move = 0;
        for(int i = 0; i < rows * cols; i++){
            result.push_back(matrix[row][col]);
            row += move_delta[move].first;
            col += move_delta[move].second;
            
            if(row >= rows){
                row -= 1;
                col += 2;
                move = 1 - move;
            }
            if(col >= cols){
                col -= 1;
                row += 2;
                move = 1 - move;
            }
            if(row < 0){
                row += 1;
                move = 1 - move;
            }
            if(col < 0){
                col += 1;
                move = 1 - move;
            }
        }
        return result;
    }
};
