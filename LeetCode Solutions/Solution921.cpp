//
//  Solution921.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 09/10/2024.
//
#include "solutions.h"

int Solution::minAddToMakeValid(string s) {
    int availableOpens = 0; // holds number of open parenthesis that could be closed by closing parenthesis
    int unpairedCloseds = 0; // counts closed parenthesis that arent matched to an open (need an insert before)
    for(char c : s) {
        if(c == '(') {
            availableOpens++;
        } else {
            if(availableOpens > 0) { // available opens remaining - pair up (no insert needed)
                availableOpens--;
            } else {
                unpairedCloseds++; // closing parenthesis can't be matched to open
            }
        }
    }
    return availableOpens + unpairedCloseds; // inserts required = remaining open parenthesis at the end, and unpaired closed throughout
}
