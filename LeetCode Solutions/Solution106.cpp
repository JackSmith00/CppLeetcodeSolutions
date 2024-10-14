//
//  Solution106.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 01/10/2024.
//
#include "solutions.h"

TreeNode* Solution::buildTree(vector<int>& inorder, vector<int>& postorder) {
    if(inorder.empty()) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(postorder[postorder.size()-1]); // root node will be the end of the postorder
    
    auto rootIndexInorder = find(inorder.begin(), inorder.end(), root->val); // index of root inorder (splits left nodes from right)
    
    // handle left nodes
    vector<int> tempInorder = {inorder.begin(), rootIndexInorder}; // found to the left of root inorder
    vector<int> tempPostorder = {postorder.begin(), postorder.begin()+tempInorder.size()}; // start of the postorder, same length as inorder
    root->left = buildTree(tempInorder, tempPostorder); // recursively build left nodes
    
    // handle right nodes
    tempInorder = {rootIndexInorder + 1, inorder.end()}; // inorder to the right of the root
    tempPostorder = {postorder.begin()+tempPostorder.size(), postorder.end()-1}; // postorder from the end of the left nodes to the end -1 for root
    root->right = buildTree(tempInorder, tempPostorder); // recursively build right
    
    return root;
}
