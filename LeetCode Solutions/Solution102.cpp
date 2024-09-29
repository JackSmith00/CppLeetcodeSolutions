//
//  Solution102.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 27/09/2024.
//
#include "solutions.h"

vector<vector<int>> oldLevelOrder(TreeNode* root) {
    if (!root) {
        return {};
    }
    vector<vector<int>> output;
    vector<int> thisLevelOutput;
    queue<TreeNode*> thisLevelQueue;
    queue<TreeNode*> nextLevelQueue;
    thisLevelQueue.push(root);
    while (!thisLevelQueue.empty()) {
        root = thisLevelQueue.front();
        thisLevelOutput.push_back(root->val);
        thisLevelQueue.pop();
        if (root->left) {
            nextLevelQueue.push(root->left);
        }
        if (root->right) {
            nextLevelQueue.push(root->right);
        }
        if (thisLevelQueue.empty()) {
            output.push_back(thisLevelOutput);
            thisLevelOutput.clear();
            thisLevelQueue = nextLevelQueue;
            nextLevelQueue = {};
        }
    }
    return output;
}

vector<vector<int>> Solution::levelOrder(TreeNode* root) {
    if (!root) {  // check for null node
        return {};
    }
    vector<vector<int>> output;
    queue<TreeNode*> nodeQueue;  // holds nodes for processing
    nodeQueue.push(root);  // put root as first item in queue
    while(!nodeQueue.empty()) {  // loop until all nodes have been added
        vector<int> level; // the current level to add
        int queueSize = (int) nodeQueue.size(); // size of queue at this level (to not check size when more nodes are added)
        for(int i = 0; i < queueSize; i++) { // loop all items currently in the queue (same level)
            root = nodeQueue.front(); // move to first node
            level.push_back(root->val); // add its value to this level's output
            nodeQueue.pop(); // remove from queue now added
            // add any child nodes to queue (will be processed next it of the while loop)
            if (root->left) {
                nodeQueue.push(root->left);
            }
            if(root->right) {
                nodeQueue.push(root->right);
            }
        }
        output.push_back(level); // this level has been built, now add it to overall output
    }
    return output;
}
