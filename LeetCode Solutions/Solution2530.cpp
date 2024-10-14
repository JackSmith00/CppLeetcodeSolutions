//
//  Solution2530.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 14/10/2024.
//
#include "solutions.h"

long long Solution::maxKelements(vector<int> &nums, int k) {
    priority_queue<int> largestNums; // hold numbers in decsending order at all times (largest-smallest)
    
    for(int x : nums) { // add all nums to queue
        largestNums.push(x);
    }
    
    long long score = 0; // output score, initially 0
    
    for(int i = 0; i < k; i++) { // loop k times
        int curr = largestNums.top(); // take the largest num possible
        largestNums.pop(); // remove from queue for now
        
        score += curr;
        
        curr = ceil(curr / 3.0f);
        
        largestNums.push(curr); // add updated value back to queue
    }
    
    return score;
}
