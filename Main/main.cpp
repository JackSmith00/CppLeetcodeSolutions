//
//  main.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 19/09/2024.
//

#include "solutions.h"

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    vector<vector<int>> testCasesA = {{1,10,100}, {1,2,3}};
    vector<vector<int>> testCasesB = {{1000}, {4,4,4}};
    
    for(int i = 0; i < testCasesA.size(); i++) {
        cout << "Test case " + to_string(i) + ": ";
        for(auto result : {s.longestCommonPrefix(testCasesA[i], testCasesB[i])}) {
            cout << result  << " ";
        }
        cout << endl;
    }
    
    return 0;
}
