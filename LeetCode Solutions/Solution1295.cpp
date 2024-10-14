//
//  Solution1295.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 11/10/2024.
//
#include "solutions.h"

int Solution::findNumbers(vector<int> &nums) {
    int count = 0;
    for(int x : nums) {
        int digits = 1;
        while (x / 10 > 0) {
            x /= 10;
            digits++;
        }
        if(digits % 2 == 0) {
            count++;
        }
    }
    return count;
}
