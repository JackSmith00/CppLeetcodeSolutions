//
//  Solution1768.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 24/09/2024.
//

#include "solutions.h"

string Solution::mergeAlternately(string word1, string word2) {
    string output = word1 + word2;
    
    for(int i = 0; i < min(word1.length(), word2.length()); i++) {
        output[i*2] = word1[i]; // 0-0, 1-2, 2-4, 3-6
        output[i*2 + 1] = word2[i]; // 0-1, 1-3, 2-5, 3-7
    }
    
    if(word1.length() > word2.length()) {
        for(int i = (int) word2.length(); i < word1.length(); i++) {
            output[i + word2.length()] = word1[i];
        }
    } else if (word2.length() > word1.length()) {
        for(int i = (int) word1.length(); i < word2.length(); i++) {
            output[i + word1.length()] = word2[i];
        }
    }
    return output;
}
