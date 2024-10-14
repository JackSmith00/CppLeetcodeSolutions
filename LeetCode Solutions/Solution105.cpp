//
//  Solution105.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 10/10/2024.
//
#include "solutions.h"

TreeNode* Solution::buildTree105(vector<int> &preorder, vector<int> &inorder) {
    if(preorder.empty()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(preorder[0]); // root is at the start of the preorder
    
    auto rootIndexInorder = find(inorder.begin(), inorder.end(), root->val); // find index of root inorder (splits left nodes from right)
    
    // handle left nodes
    vector<int> tempInorder = {inorder.begin(), rootIndexInorder}; // inorder to the left of root
    vector<int> tempPreorder = {preorder.begin()+1, preorder.begin()+1+tempInorder.size()}; // preorder from 2nd element, matching length of tempInorder
    root->left = buildTree105(tempPreorder, tempInorder);
    
    // handle right nodes
    tempInorder = {rootIndexInorder+1, inorder.end()}; // inorder from right of root (non inclusive so +1)
    tempPreorder = {preorder.end()-tempInorder.size(), preorder.end()}; // preorder to end, matching length of tempInorder
    root->right = buildTree105(tempPreorder, tempInorder);
    
    return root;
}
