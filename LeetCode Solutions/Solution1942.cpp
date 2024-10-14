//
//  Solution1942.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 11/10/2024.
//
#include "solutions.h"

bool sortedArrivalTimes(vector<int>time1, vector<int> time2) {
    return time1[0] < time2[0];
}

int Solution::smallestChair(vector<vector<int>>& times, int targetFriend) {
    targetFriend = times[targetFriend][0]; // get the arrival time of the sorted target friend
    sort(times.begin(), times.end(), sortedArrivalTimes);
    
    priority_queue<int, vector<int>, greater<int>> availableChairs;
    
    for(int i = 0; i < times.size(); i++) {
        availableChairs.push(i);
        
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> usedChairs;
    for (int i = 0; ; i++) {
        while(!usedChairs.empty() && times[i][0] >= usedChairs.top().first) {
            availableChairs.push(usedChairs.top().second);
            usedChairs.pop();
        }
        if(times[i][0] == targetFriend) {
            return availableChairs.top();
        }
        usedChairs.push({times[i][1], availableChairs.top()});
        availableChairs.pop();
    }
}
