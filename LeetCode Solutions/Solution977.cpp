//
//  Solution977.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 11/10/2024.
//
#include "solutions.h"

vector<int> Solution::sortedSquares(vector<int> &nums) {
    for(int i = 0; i < nums.size(); i++) {
        nums[i] *= nums[i]; // replace each num with its square
    }
    
    vector<int> output(nums.size()); // new vector to hold output
    
    for(int i = (int) nums.size()-1, p1 = 0, p2 = i; i >= 0; i--) { // loop backwards through output
        if(nums[p1] > nums[p2]) { // set current i in output to largest num (either at the start or end of nums)
            output[i] = nums[p1++]; // start was largest, increase pointer
        } else {
            output[i] = nums[p2--]; // end was largest, decrease pointer
        }
    }
    
    return output;
}
