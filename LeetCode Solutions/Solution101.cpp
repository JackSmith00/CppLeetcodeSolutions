//
//  Solution101.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 29/09/2024.
//
#include "solutions.h"

bool recursiveIsSymmetricApproach(TreeNode* leftNode, TreeNode* rightNode) {
    if(!leftNode && !rightNode) { // if there are no child nodes, root is symmetrical by default
        return true;
    } else if (!leftNode || !rightNode) { // if there is a left node and no right node, cannot be symmetrical
        return false;
    }
    // if left value matches right, and left node's left child matches right nodes right and vice versa, they are symmetrical
    return leftNode->val == rightNode->val && recursiveIsSymmetricApproach(leftNode->left, rightNode->right) && recursiveIsSymmetricApproach(leftNode->right, rightNode->left);
}

bool iterativeIsSymmetricApproach(TreeNode* root) {
    if(!root->left && !root->right) { // if there are no child nodes, symmetrical by default
        return true;
    } else if(!root->left || !root->right) { // only 1 child node, cannot be symmetrical
        return false;
    }
    queue<TreeNode*> checkNext; // holds nodes to check next in order
    checkNext.push(root->left); // add left node then right
    checkNext.push(root->right);
    TreeNode* left; // this node could be replaced by reusing root - kept for better readability
    TreeNode* right;
    while(!checkNext.empty()) {  // continue while there are more checks to complete
        left = checkNext.front(); // next left node
        checkNext.pop(); // remove from queue
        right = checkNext.front(); // next right node
        checkNext.pop(); // remove from queue
        
        if(left->val != right->val) { // if values don't match, not symmetrical
            return false;
        }
        
        if(left->left && right->right) { // if there is a left node on left and right node on right, add to check next
            checkNext.push(left->left);
            checkNext.push(right->right);
        } else if (left->left || right->right) { // there is no left node to match right side or vice versa (no symmetry)
            return false;
        }
        
        // repeat above for right/left node
        if(left->right && right->left) {
            checkNext.push(left->right);
            checkNext.push(right->left);
        } else if(left->right || right->left) {
            return false;
        }
    }
    return true; // if no asymmetry was found and no more nodes to check, must be symmetrical
}

bool Solution::isSymmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    return iterativeIsSymmetricApproach(root);
}
