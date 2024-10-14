//
//  Solution485.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 11/10/2024.
//
#include "solutions.h"

int Solution::findMaxConsecutiveOnes(vector<int>& nums) {
    int maxConsec = 0;
    int currConsec = 0;
    for(int x : nums) {
        if(x == 1) {
            currConsec++;
            maxConsec = max(maxConsec, currConsec);
        } else {
            currConsec = 0;
        }
    }
    
    return maxConsec;
}
