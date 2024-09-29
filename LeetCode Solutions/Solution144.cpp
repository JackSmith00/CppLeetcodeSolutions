//
//  Solution144.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 25/09/2024.
//
#include "solutions.h"

vector<int> recursiveApproach(TreeNode* root) {
    if(!root) { // if root is nullptr, return empty vector
        return {};
    }
    vector<int> output = {root->val};  // first add root val to output
    if(root->left) {
        vector<int> leftOutput = recursiveApproach(root->left);
        output.insert(output.end(), leftOutput.begin(), leftOutput.end()); // add any values from left tree next
    }
    if(root->right) {
        vector<int> rightOutput = recursiveApproach(root->right);
        output.insert(output.end(), rightOutput.begin(), rightOutput.end());  // finally, add any values from right tree
    }
    return output;  // return complete tree
}

vector<int> iterativeApproach(TreeNode* root) {
    if(!root) {
        return {}; // return empty vector if root is nullptr
    }
    vector<int> output = {root->val}; // add root to output (preorder)
    stack<TreeNode*> toDoNext;
    if(root->right) { // if there are nodes on the right, do these later
        toDoNext.push(root->right);
    }
    root = root->left; // move to left node
    while(root || !toDoNext.empty()) { // continue whilst current node exists, or if there are nodes remaining in toDoNext
        if(!root) { // current node is empty
            root = toDoNext.top(); // move to next node toDo
            toDoNext.pop(); // remove node from toDoNext stack
        } else { // node exists
            output.push_back(root->val);  // add this node to output (preorder)
            if(root->right){ // if there are nodes on the right, do these later
                toDoNext.push(root->right);
            }
            root = root->left; // move to left node
        }
        
    }
    return output;
}

vector<int> Solution::preorderTraversal(TreeNode* root) {
    return iterativeApproach(root);
}
