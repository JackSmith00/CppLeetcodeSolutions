//
//  TreeNode.h
//  LeetCode Solutions
//
//  Created by Jack Smith on 25/09/2024.
//
#pragma once

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    friend std::ostream& operator<<(std::ostream& stream, TreeNode* treeNodePtr);
};
