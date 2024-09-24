//
//  Solution3043.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 24/09/2024.
//

#include "solutions.h"
#include <unordered_set>

// this solution converts ints to string to retrieve digits - better approach would be to divide by 10 - same effect in reverse
int Solution::longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
    unordered_set<string> hashSet;  // to hold possible prefixes from first array
    for(int item : arr1) {
        string intString = to_string(item); // string of int to access digit by digit
        for(int i = 1; i <= intString.length(); i++){
            hashSet.insert(intString.substr(0, i));  // add all prefixes to hashset
        }
    }
    int longest = 0;  // longest prefix length
    for(int item : arr2) {
        int length = 0;  // current prefix length
        string intString = to_string(item);
        for(int i = 1; i <= intString.length(); i++) {  // loop digits from second array item
            if(hashSet.count(intString.substr(0, i))) {
                length++;  // matching prefix found, increase length
            } else {
                break; // stop checking longer prefixes as there is already no match
            }
        }
        longest = max(longest, length); // if current length is longer, assign this as the longest
    }
    return longest;
}
