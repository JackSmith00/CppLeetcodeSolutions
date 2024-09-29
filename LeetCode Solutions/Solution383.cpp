//
//  Solution383.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 24/09/2024.
//
#include "solutions.h"
#include <map>

bool Solution::canConstruct(string ransomNote, string magazine) {
    map<char, int> availableLetters; // to hold available letters and a count of occurances
    for(char c : magazine) {  // add letters from magazine to available
        if(availableLetters.find(c) == availableLetters.end()) {
            availableLetters.insert({c, 1}); // new letter
        } else {
            availableLetters[c]++; // existing letter
        }
    }
    for(char c : ransomNote) {  // check if letters are available for ransom note
        if(availableLetters.find(c) == availableLetters.end() || availableLetters[c] == 0) {
            return false; // letter never appeared, or has been used up
        } else {
            availableLetters[c]--; // use letter, decrease available
        }
    }
    return true; // ransom note has all letters required
}
