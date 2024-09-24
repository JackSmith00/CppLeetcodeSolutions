//
//  Solution179.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 24/09/2024.
//
#include "solutions.h"

// ATTEMPT 1 --------------------------------------------------

bool shortestIsBiggerFirst(string& shortest, string& longest) {
    for(int shortestI = 0, longestI = 0; shortestI < shortest.length() || longestI < longest.length(); shortestI++, longestI++) {
        if(shortestI == shortest.length()) {
            // once shortest has been looped, restart index counter
            shortestI = 0;
        } else if (longestI == longest.length()) {
            longestI--;
        }
        
        if (shortest[shortestI] != longest[longestI]) {
            // if there is no match, return if shortest is bigger
            return shortest[shortestI] > longest[longestI];
        }
    }
    // all digits match, compare matching digit
    return shortest[shortest.length()-1] > longest[longest.length()-1];
}

bool comparePosition(const int& num1, const int& num2) {
    string num1String = to_string(num1);
    string num2String = to_string(num2);
    
    if(num1String.length() == num2String.length()) {
        // if numbers are same digit length, return largest
        return num1 > num2;
    }
    // numbers arent same number of digits
    else if (num1String.length() < num2String.length()) {
        // true when num1 is best first
        return shortestIsBiggerFirst(num1String, num2String);
    } else {
        // true when num1 is best first
        return !shortestIsBiggerFirst(num2String, num1String);
    }
}

string attempt1largestNumber(vector<int>& nums) {
    string output = "";
    sort(nums.begin(), nums.end(), comparePosition);
    for(int num : nums) {
        output += to_string(num);
    }
    if(output.starts_with("0")) return "0";
    return output;
}

// ATTEMPT 2 --------------------------------------------------

bool compareDigitsOrder(const int& num1, const int& num2) {
    return to_string(num1) + to_string(num2) > to_string(num2) + to_string(num1);
}

string Solution::largestNumber(vector<int>& nums) {
    string output = "";
    sort(nums.begin(), nums.end(), compareDigitsOrder);
    for(int num : nums) {
        output += to_string(num);
    }
    if(output.starts_with('0')) { return "0"; }
    return output;
}
