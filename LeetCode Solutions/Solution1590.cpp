//
//  Solution1590.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 03/10/2024.
//
#include "solutions.h"

int Solution::minSubarray(vector<int>& nums, int p) {
    // solution created following editorial guidance
    int sum = 0; // sum nums to see if already divisible by p
    for(int x : nums) {
        sum += x;
    }
    int target = sum % p; // number to remove from array to become divisible by p
    if(target == 0) { // already divisible by p
        return 0;
    }
    unordered_map<int, int> modMap; // stores remainder needed and index of occurance
    modMap[0] = -1; // case where no remainder is needed, in which case length is current index + 1 (uses -1 here for future calc)
    sum = 0; // reset sum to be used again cumulatively
    int minLen = (int) nums.size(); // minLen initially is full length of nums
    for(int i = 0; i < nums.size(); i++) {
        sum = (sum + nums[i]) % p; // sum nums and find remainder
        int needed = (sum - target + p) % p; // needed is current sum difference with the target (0 when target is met)
        if(modMap.find(needed) != modMap.end()) {
            minLen = min(minLen, i - modMap[needed]); // solution found, update minLen if smaller than current record
        }
        modMap[needed] = i; // update index in needed for reference with future numbers
    }
    if(minLen == nums.size()) { // no subarray found
        return -1;
    }
    return minLen;
}
