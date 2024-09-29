//
//  Solution104.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 29/09/2024.
//
#include "solutions.h"

int Solution::maxDepth(TreeNode* root) {
    if(!root) {  // if empty (no depth)
        return 0;
    }
    return max(maxDepth(root->left), maxDepth(root->right)) + 1; //return deepest branch length +1 for this node
}
