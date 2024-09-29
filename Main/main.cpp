//
//  main.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 19/09/2024.
//

#include "solutions.h"

int main(int argc, const char * argv[]) {
    
    Solution s;
    
    vector<TreeNode*> testCasesA = {new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3))), new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(3)), new TreeNode(2, nullptr, new TreeNode(3))), nullptr, new TreeNode(1, new TreeNode(2), new TreeNode(3))};
    
    for(int i = 0; i < testCasesA.size(); i++) {
        cout << "Test case " + to_string(i) + ": ";
        for(auto result : {s.isSymmetric(testCasesA[i])}) {
            cout << result << endl;
        }
    }
    
    return 0;
}
