//
//  Solution108.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 01/10/2024.
//
#include "solutions.h"

TreeNode* Solution::sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0) {
        return nullptr; // if list is empty, return null node
    }
    int midpoint = (int)nums.size() / 2; // midpoint of the vector to be the parent node
    TreeNode* root = new TreeNode(nums[midpoint]);
    vector<int> subVector(nums.begin(), nums.begin() + midpoint); // left nodes in a vector
    root->left = sortedArrayToBST(subVector); // create structure from left node
    subVector = {nums.begin()+midpoint + 1, nums.end()}; // right nodes in a vector (exclude the midpoint)
    root->right = sortedArrayToBST(subVector); // create structure from the right node
    return root; // return root
}
