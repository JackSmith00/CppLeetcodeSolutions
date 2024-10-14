//
//  CoutHelpers.h
//  LeetCode Solutions
//
//  Created by Jack Smith on 10/10/2024.
//
#pragma once

// for ease of printing binary trees in level order
ostream& operator<<(ostream& stream, TreeNode* treeNodePtr) {
    Solution s;
    vector<vector<int>> order = s.levelOrder(treeNodePtr);
    for(vector<int> level : order) {
        for(int node : level) {
            stream << node << ' ';
        }
    }
    return stream;
}

// for ease of printing a vector
template <typename T>
ostream& operator<<(ostream& stream, vector<T> v) {
    stream << "[";
    for(int i = 0; i < v.size()-1; i++) {
        stream << v[i] << ",";
    }
    stream << v[v.size()-1] << "]";
    return stream;
}
