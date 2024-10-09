//
//  Solution1331.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 02/10/2024.
//
#include "solutions.h"

vector<int> Solution::arrayRankTransform(vector<int> &arr) {
    vector<int> sortedArr = {arr.begin(), arr.end()}; // copy vector and then sort smallest to largest
    sort(sortedArr.begin(), sortedArr.end());
    unordered_map<int, int> valueRanks; // holds the rank of any value that appears in the list
    for(int i = 0, rank = 1; i < sortedArr.size(); i++) {
        if(valueRanks.find(sortedArr[i]) == valueRanks.end()) { // only if value has not already been ranked
            valueRanks[sortedArr[i]] = rank;
            rank++;
        }
    }
    for(int i = 0; i < arr.size(); i++) { // loop original arr and replace values with their ranks
        arr[i] = valueRanks[arr[i]];
    }
    return arr;
}
