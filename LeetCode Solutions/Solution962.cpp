//
//  Solution962.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 10/10/2024.
//
#include "solutions.h"

int maxWidthRamp(vector<int> &nums) {
    // initial Attempt - timed out
    int ramp = 0;
    for(int i = 0, j = (int) nums.size()-1; i <= j;) {
        if(j-i <= ramp) {
            i++;
            j = (int) nums.size()-1;
            continue;
        }
        if(nums[i] <= nums[j]) {
            ramp = j - i;
            i++;
            j = (int) nums.size()-1;
        } else {
            j--;
        }
    }
    return ramp;
}

int Solution::maxWidthRamp(vector<int> &nums) {
    // after researching monotonic stacks and looking at editorial
    stack<int> monotonicIndexStack;
    monotonicIndexStack.push(0);
    
    // create stack from begining of decreasing values to check against later
    for(int i = 1; i < nums.size(); i++) {
        if(nums[i] < nums[monotonicIndexStack.top()]) {
            monotonicIndexStack.push(i);
        }
    }
    
    int ramp= 0; // max size of ramp
    for(int j = (int)nums.size()-1; !monotonicIndexStack.empty() && j >= monotonicIndexStack.top();) { // stack is not empty and j > i
        if(nums[monotonicIndexStack.top()] <= nums[j]) { // valid ramp
            ramp = max(ramp, j-monotonicIndexStack.top());
            monotonicIndexStack.pop(); // move to next item in stack (next biggest closest to begining)
        } else {
            j--; // no more ramps possible from this end point, move back
        }
    }
    
    return ramp;
}
