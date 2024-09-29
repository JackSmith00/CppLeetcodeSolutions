//
//  Solution145.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 26/09/2024.
//
#include "solutions.h"

vector<int> recursivePostorderApproach(TreeNode* root) {
    if(!root) {
        return {};
    }
    vector<int> output;
    if(root->left) {
        vector<int> leftOutput = recursivePostorderApproach(root->left);
        output.insert(output.end(), leftOutput.begin(), leftOutput.end());
    }
    if(root->right){
        vector<int> rightOutput = recursivePostorderApproach(root->right);
        output.insert(output.end(), rightOutput.begin(), rightOutput.end());
    }
    output.push_back(root->val);
    return output;
}

vector<int> iterativePostorderApproach(TreeNode* root) {
    stack<TreeNode*> toDoNext;  // holds next node to check
    TreeNode* previousNode = nullptr; // check if right node has been checked already
    vector<int> output;
    while(root || !toDoNext.empty()) {  // continue if node exists, or there are more remaining
        if(root) {  // current node exists
            toDoNext.push(root);  // do this node later and move left
            root = root->left;
        } else { // null node
            root = toDoNext.top(); // go to first node on todo list
            if(root->right && root->right != previousNode) {  // if there is a right node that hasn't just been checked
                root = root->right;
            } else {  // no right node or it has already been traversed
                output.push_back(root->val);  // add current val
                toDoNext.pop(); // remove this node from todo (done)
                previousNode = root;  // this is now the last checked node, dont come back here
                root = nullptr; // moves back to top of the stack on next itteration
            }
        }
            
    }
    return output;
}

vector<int> Solution::postorderTraversal(TreeNode* root) {
    return iterativePostorderApproach(root);
}
