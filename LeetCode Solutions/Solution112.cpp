//
//  Solution112.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 30/09/2024.
//
#include "solutions.h"

bool Solution::hasPathSum(TreeNode* root, int targetSum) {
    if(!root) { // null node, cannot reach target on this path, return false
        return false;
    }
    
    if(targetSum - root->val == 0) { // target reached at this node
        if(!root->left && !root->right) { // only successfull if leaf node is reached
            return true;
        }
    }
    
    // continue to check next nodes to left and right
    return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
}
