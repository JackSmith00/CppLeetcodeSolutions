//
//  Solution241.h
//  LeetCode Solutions
//
//  Created by Jack Smith on 19/09/2024.
//

#pragma once
#include <iostream>
#include "TreeNode.h"
#include "Node.h"

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
    bool hasPathSum(TreeNode* root, int targetSum); // 112
    bool canArrange(vector<int>& arr, int k); // 1497
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder); // 106
    TreeNode* sortedArrayToBST(vector<int>& nums); // 108
    vector<int> arrayRankTransform(vector<int>& arr); // 1331
    int minSubarray(vector<int>& nums, int p); // 1590
    long long dividePlayers(vector<int>& skill); // 2491
    int minLength(string s); // 2696
    int minSwaps(string s); // 1963
    int minAddToMakeValid(string s); // 921
    int maxWidthRamp(vector<int>& nums); // 962
    TreeNode* buildTree105(vector<int>& preorder, vector<int>& inorder); // 105
    Node* connect(Node* root); // 116
    int smallestChair(vector<vector<int>>& times, int targetFriend); // 1942
    int findMaxConsecutiveOnes(vector<int>& nums); // 485
    int findNumbers(vector<int>& nums); // 1295
    vector<int> sortedSquares(vector<int>& nums); // 977
    int minGroups(vector<vector<int>>& intervals); // 2406
    long long maxKelements(vector<int>& nums, int k); // 2530
};
