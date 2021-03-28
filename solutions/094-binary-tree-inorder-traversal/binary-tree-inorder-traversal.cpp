// Given the root of a binary tree, return the inorder traversal of its nodes' values.
//
//  
// Example 1:
//
//
// Input: root = [1,null,2,3]
// Output: [1,3,2]
//
//
// Example 2:
//
//
// Input: root = []
// Output: []
//
//
// Example 3:
//
//
// Input: root = [1]
// Output: [1]
//
//
// Example 4:
//
//
// Input: root = [1,2]
// Output: [2,1]
//
//
// Example 5:
//
//
// Input: root = [1,null,2]
// Output: [1,2]
//
//
//  
// Constraints:
//
//
// 	The number of nodes in the tree is in the range [0, 100].
// 	-100 <= Node.val <= 100
//
//
//  
//
// Follow up:
//
// Recursive solution is trivial, could you do it iteratively?
//
//  
//


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode *root) {
        /*
        左->中->右，中間拜訪根節點
        因此要先往最左節點前進
        將中間經過的根節點存再一個stack裡
        到沒有左節點時
        將存在stack裡的根節點取出
        拜訪右節點
        */
        vector<int> ans;
        if(!root)
            return ans;
        
        stack<TreeNode *> S;
        TreeNode *current = root;
        while(current || !S.empty()){
            if(current){
                S.push(current);
                current = current->left;
            }
            else{
                TreeNode *node = S.top();
                ans.push_back(node->val);
                S.pop();
                current = node->right;
            }
        }
        return ans;
    }
};
