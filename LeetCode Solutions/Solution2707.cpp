//
//  Solution2707.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 23/09/2024.
//

#include "solutions.h"
#include <unordered_set>

int Solution::minExtraChar(string s, vector<string>& dictionary) {
    unordered_set<string> dictSet(dictionary.begin(), dictionary.end());  // words to check for
    vector<int> dp(s.length() + 1, 0); // to hold results (+1 for storing empty string result 0)
    for(int i = (int)s.length()-1; i >= 0; i--) { // loop start positions from end to start
        dp[i] =  dp[i+1] + 1; // current remaining words is 1 larger than previous smallest due to extra letter
        for(int j = i; j < s.length(); j++) {
            // search exery string from current search start to the end
            if(dictSet.count(s.substr(i, j-i+1))){
                // when a substring is found, replace lowest score at i when lower than previous lowest remaining to reach the end index
                dp[i] = min(dp[i], dp[j+1]);
            }
        }
    }
    return dp.front(); // returns the lowest score from the start of the string
}
