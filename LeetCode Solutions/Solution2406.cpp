//
//  Solution2406.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 12/10/2024.
//
#include "solutions.h"

int Solution::minGroups(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end());
    priority_queue<int, vector<int>, greater<int>> groups;
    int maxGroups = 1;
    for (int i = 0; i < intervals.size() ; i++) {
        while(!groups.empty() && groups.top() < intervals[i][0]) {
            groups.pop();
        }
        groups.push(intervals[i][1]);
        maxGroups = max(maxGroups, (int) groups.size());
    }
    return maxGroups;
}
