//
//  Solution2419.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 24/09/2024.
//
#include "solutions.h"

int Solution::longestSubarray(vector<int>& nums) {
    int maxVal = nums[0];
    int length = 1;
    int competingLength = 1;
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] > maxVal) {
            maxVal = nums[i];
            length = 1;
            competingLength = 1;
        } else if(nums[i] == maxVal) {
            if(nums[i - 1] != maxVal) {
                competingLength = 1;
            } else {
                competingLength += 1;
            }
            length = max(length, competingLength);
        }
    }
    return length;
}
