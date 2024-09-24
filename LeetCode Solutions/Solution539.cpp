//
//  findMinDifference.hpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 24/09/2024.
//
#include "solutions.h"

int Solution::findMinDifference(vector<string>& timePoints) {
    vector<int> timePointMins(timePoints.size(), 0);
    for(int i = 0; i < timePoints.size(); i++) {
        timePointMins[i] = (stoi(timePoints[i].substr(0, 2)) * 60) + stoi(timePoints[i].substr(3, 5));
    }
    
    int minMins = 1440; // 24 hr
    
    for(int i = 0; i < timePointMins.size() - 1; i++) {
        for(int j = i + 1; j < timePointMins.size(); j++) {
            if(timePointMins[i] == timePointMins[j]) {
                return 0;
            } else {
                minMins = min(minMins, min((max(timePointMins[i], timePointMins[j]) - min(timePointMins[i], timePointMins[j])), (1440 + min(timePointMins[i], timePointMins[j])) - max(timePointMins[i], timePointMins[j])));
            }
        }
    }
    return minMins;
}
