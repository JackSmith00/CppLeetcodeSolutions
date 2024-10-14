//
//  main.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 19/09/2024.
//

#include "solutions.h"
#include "CoutHelpers.h"

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    vector<vector<int>> testCasesA = {{10,10,10,10,10}, {1,10,3,3,3}, {756902131,995414896,95906472,149914376,387433380,848985151}};
    
    vector<int> testCasesB = {5, 3, 6};

    for(int i = 0; i < testCasesA.size(); i++) {
        cout << "Test case " + to_string(i) + ": ";
        for(auto result : {s.maxKelements(testCasesA[i], testCasesB[i])}) {
            cout << result << endl;
        }
    }
        
    return 0;
}
