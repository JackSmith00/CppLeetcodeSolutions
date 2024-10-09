//
//  main.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 19/09/2024.
//

#include "solutions.h"
#include "CustomStack.h"

ostream& operator<<(ostream& stream, TreeNode* treeNodePtr) {
    Solution s;
    vector<vector<int>> order = s.levelOrder(treeNodePtr);
    for(vector<int> level : order) {
        for(int node : level) {
            stream << node << ' ';
        }
    }
    return stream;
}

ostream& operator<<(ostream& stream, vector<int> intVector) {
    stream << "[";
    for(int i = 0; i < intVector.size()-1; i++) {
        stream << intVector[i] << ",";
    }
    stream << intVector[intVector.size()-1] << "]";
    return stream;
}

int main(int argc, const char * argv[]) {
    
    Solution s;

    vector<string> testCasesA = {"][][", "]]][[[", "[]"};
    
//    vector<int> testCasesB = {5, 7, 10, 3, 85};

    for(int i = 0; i < testCasesA.size(); i++) {
        cout << "Test case " + to_string(i) + ": ";
        for(auto result : {s.minSwaps(testCasesA[i])}) {
            cout << result << endl;
        }
    }
    
    return 0;
}
