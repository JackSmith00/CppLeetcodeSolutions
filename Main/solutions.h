//
//  Solution241.h
//  LeetCode Solutions
//
//  Created by Jack Smith on 19/09/2024.
//

#pragma once
#include <iostream>
#include "TreeNode.h"

using namespace std;

class Solution {
    public:
    vector<string> uncommonFromSentences(string s1, string s2); // 884
    vector<int> diffWaysToCompute(string expression); // 241
    string shortestPalindrome(string s); // 214
    int minExtraChar(string s, vector<string>& dictionary); // 2707
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2); // 3043
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries); // 1310
    int longestSubarray(vector<int>& nums); // 2419
    int findMinDifference(vector<string>& timePoints); // 539
    string mergeAlternately(string word1, string word2); // 1768
    string largestNumber(vector<int>& nums); // 179
    bool canConstruct(string ransomNote, string magazine); // 383
    vector<int> preorderTraversal(TreeNode* root); //144
    vector<int> inorderTraversal(TreeNode* root); // 94
    vector<int> postorderTraversal(TreeNode* root); // 145
    vector<vector<int>> levelOrder(TreeNode* root); // 102
    int maxDepth(TreeNode* root); // 104
    bool isSymmetric(TreeNode* root); // 101
};
