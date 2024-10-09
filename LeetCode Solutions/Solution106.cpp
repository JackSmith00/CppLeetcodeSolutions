//
//  Solution106.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 01/10/2024.
//
#include "solutions.h"

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.size() == 1 ) {
        return new TreeNode(inorder[0]);
    } else if (inorder.empty()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode();
    root->val = postorder.back();
    postorder.pop_back();
    root->right = new TreeNode(postorder.back());
    
    // unfinished
    
    return root;
}
