//
//  Solution2696.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 07/10/2024.
//
#include "solutions.h"

int minLengthAttempt1(string s) {
    // This version was rushed to keep my streak late at night, no optimisation thought about
    int foundIndex;
    do {
        foundIndex = (int) s.find("AB");
        if(foundIndex == string::npos) {
            foundIndex = (int) s.find("CD");
        }
        if(foundIndex != string::npos) {
            s = s.substr(0, foundIndex) + s.substr(foundIndex + 2, s.length());
        }
    } while(foundIndex != string::npos);
    return (int) s.length();
}

int Solution::minLength(string s) {
    stack<char> stringStack;
    for(char c : s) {
        if(stringStack.empty()) {
            stringStack.push(c);
        } else if(stringStack.top() == 'A' && c == 'B') {
            stringStack.pop();
        } else if (stringStack.top() == 'C' && c == 'D') {
            stringStack.pop();
        } else {
            stringStack.push(c);
        }
    }
    return (int) stringStack.size();
}
