//
//  Solution1310.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 24/09/2024.
//
#include "solutions.h"

vector<int> attempt1XorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> output(queries.size());
        for(int j = 0; j < queries.size(); j++) {
            int result = arr[queries[j][0]];
            for(int i = queries[j][0] + 1; i <= queries[j][1]; i++) {
                result ^= arr[i];
            }
            output[j] = result;
        }
        return output;
    }

vector<int> Solution::xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    for(int i = 1; i < queries.size(); i++) {
        arr[i] = arr[i - 1] ^ arr[i];
    }
    
    vector<int> output(queries.size());
    
    for(int i = 0; i < queries.size(); i++) {
        if(queries[i][0] > 0) {
            output[i] = arr[queries[i][1]] ^ arr[queries[i][0] - 1];
        } else {
            output[i] = arr[queries[i][1]];
        }
    }
    
    return output;
}
