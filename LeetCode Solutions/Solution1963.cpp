//
//  Solution1963.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 08/10/2024.
//
#include "solutions.h"
#include <deque>

int Solution::minSwaps(string s) {
    int availableOpenBracket = 0; // counts unswapped [
    for(char c : s) {
        if(c == '[') {
            availableOpenBracket++; // unused [
        } else if(availableOpenBracket > 0) { // c == ']', check if there is a matching '[' and pair up
            availableOpenBracket--;
        }
        // c == ']' but there is no matching '[' yet, this will be added to avaliable and remain at the end of the loop as a need to swap
    }
    return (availableOpenBracket + 1) / 2; // +1 handles cases where swaps is odd due to rounding down result
}
