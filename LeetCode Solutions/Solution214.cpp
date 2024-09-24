//
//  Solution214.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 20/09/2024.
//

#include "solutions.h"

string bruteForceApproach(string s) {
    if(s.length() < 2) {
        // check for empty strings and strings with 1 char only (default palindrome)
        return s;
    }

    for(int middleIndex = (int)s.length()/2; middleIndex > 0; middleIndex--) { // loop until palindrome found
        string endString = s.substr(middleIndex, s.length());
        string startString = s.substr(0, middleIndex);
        reverse(startString.begin(), startString.end());
        
        if(endString.substr(1, startString.length()) == startString) { // true when symmetrical whith shared midpoint
            startString = endString.substr(1, endString.length()); // copy end for mirroring, without shared midpoint
            reverse(startString.begin(), startString.end());
            return startString + endString;
        } else if(endString.substr(0, startString.length()) == startString) { // true when symmetrical between 2 letters
            startString = endString; // copy end for mirroring
            reverse(startString.begin(), startString.end());
            return startString + endString;
        }
    }
    // no palindrome found
    string startString = s.substr(1, s.length());
    reverse(startString.begin(), startString.end());
    return startString + s;
}

int lpsLength(string lpsString) {
    vector<int> lps(lpsString.length(), 0); // store length records
    for(int i = 0, j = 1; j < lpsString.length();) { // loop through entire string
        if(lpsString[i] == lpsString[j]) {
            // when letters match increase the match length stored
            // move on to next pair of i and j
            lps[j] = ++i;
            j++;
        } else if(i != 0){
            // mismatch with i not 0, move i back to previous match occurance and try again
            i = lps[i-1];
        } else {
            // no match with i at start, move j on and look again
            j++;
        }
    }
    return lps[lps.size()-1];
}

string Solution::shortestPalindrome(string s) {
    string reverseString = s;
    reverse(reverseString.begin(), reverseString.end());
    int lpsIndex = lpsLength(s + "#" + reverseString);  // search for matching pattern - break string with # to prevent length increasing from the prefix to the suffix -> "aaa" would be "aaaaaa" = 6 length but should be aaa#aaa = 3
    
    reverseString = s.substr(lpsIndex, s.length());
    reverse(reverseString.begin(), reverseString.end());
    return reverseString + s;
}
