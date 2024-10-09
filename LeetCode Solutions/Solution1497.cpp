//
//  Solution1497.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 01/10/2024.
//
#include "solutions.h"
#include <algorithm>

bool canArrangeFirstAttempt(vector<int> &arr, int k) {
    bool used[arr.size()];  // flags whether an element has already been used in another pairing
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = ((arr[i] % k) + k) % k; // set each element to its remainder, taking into account negative remainders
        used[i] = false; // current int is unused
    }
    
    for(int i = 0; i < arr.size(); i++) {
        if(used[i]) { // if current element has already been used in a pairing, skip
            continue;
        }
        int start = i; // to handle repeated values, prevents using them twice
        while(true) { // check all possible matchings, or return false
            auto matchingVal = find(arr.begin() + start, arr.end(), (k - arr[i]) % k); // find the next matching remainder
            if(matchingVal == arr.end()) { // match not found
                return false;
            } else {
                int usedIndex = matchingVal - arr.begin(); // index of matching value
                if(used[usedIndex]) { // skip already used values
                    start = usedIndex + 1;
                    continue;
                }
                used[i] = true; // match found, mark this value and other as used
                used[usedIndex] = true;
                break;
            }
        }
    }
    return true; // no invalid pairs, must be true
}

bool canArrangeAttempt2(vector<int> &arr, int k) {
    // this solution was created after reading the editorial
    unordered_map<int, int> remainderCount; // holds counts of each remainder
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = ((arr[i] % k) + k) % k; // this way of getting the remainder also handles negative remainders
        if(remainderCount.find(arr[i]) != remainderCount.end()) { // if remainder value is already tracked, increase count
            remainderCount[arr[i]] += 1;
        } else { // remainder is new, start tracking with count of 1
            remainderCount[arr[i]] = 1;
        }
    }
    for(int element : arr) { // loop each element and check there is a matching remainder value
        if(element == 0) { // special case for 0, don't search for k (ie. k-0), search for 0
            if(remainderCount[0] % 2 != 0) { // need an even count of 0 remainders to pair up
                return false;
            }
        } else if(remainderCount[element] != remainderCount[k - element]) { // make sure current remainder has an equal number of matching that are k - element
            return false;
        }
    }
    return true;
}

bool Solution::canArrange(vector<int> &arr, int k) {
    // this is an improved solution after reading other submissions, and having a better understanding of my approach
    // first part the same, count remainders and store in a hashmap
    unordered_map<int, int> remainderCount; // holds counts of each remainder
    for(int i = 0; i < arr.size(); i++) {
        arr[i] = ((arr[i] % k) + k) % k; // this way of getting the remainder also handles negative remainders
        if(remainderCount.find(arr[i]) != remainderCount.end()) { // if remainder value is already tracked, increase count
            remainderCount[arr[i]] += 1;
        } else { // remainder is new, start tracking with count of 1
            remainderCount[arr[i]] = 1;
        }
    }
    
    // here, instead of looping all elements (multiple checks of same remainders), check hashmap values
    for(auto remainder : remainderCount) {
        if(remainder.first == 0) { // special case for 0, don't search for k (ie. k-0), search for 0
            if(remainder.second % 2 != 0) { // need an even count of 0 remainders to pair up
                return false;
            }
        } else if(remainder.second != remainderCount[k - remainder.first]) { // make sure current remainder has an equal number of matching that are k - element
            return false;
        }
    }
    return true;
}

