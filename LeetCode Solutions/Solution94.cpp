//
//  Solution94.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 25/09/2024.
//
#include "solutions.h"

vector<int> recursiveInorderApproach(TreeNode* root) {
    if(!root) {
        return {};
    }
    vector<int> output = recursiveInorderApproach(root->left); // get all left values
    output.push_back(root->val); // get root value
    vector<int> rightOutput = recursiveInorderApproach(root->right); // get all right values
    output.insert(output.end(), rightOutput.begin(), rightOutput.end());
    return output;
}

vector<int> iterativeInorderApproach(TreeNode* root) {
    if(!root) {
        return {};
    }
    stack<TreeNode*> toDoNext; // holds next node to check
    vector<int> output;
    while(root || !toDoNext.empty()) { // continue while node exists or there are more left to check
        if(root) { // if current node exists
            toDoNext.push(root); // add to do later and move left
            root = root->left;
        }
        else { // current node is null
            root = toDoNext.top(); // go back to root
            output.push_back(root->val); // add to list
            toDoNext.pop(); // remove (don't check twice)
            root = root->right; // move to right hand nodes
        }
    }
    return output;
}

vector<int> Solution::inorderTraversal(TreeNode* root) {
    return iterativeInorderApproach(root);
}
