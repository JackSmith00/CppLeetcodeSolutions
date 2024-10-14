//
//  Solution116.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 10/10/2024.
//
#include "solutions.h"

Node* Solution::connect(Node* root) {
    if(!root) {
        return nullptr;
    }
    
    queue<Node*> nodeQueue;
    nodeQueue.push(root);
    
    while(!nodeQueue.empty()) {
        int queueSize = (int) nodeQueue.size();
        for(int i = 0; i < queueSize; i++) {
            Node* current = nodeQueue.front();
            nodeQueue.pop();
            
            if(i < queueSize-1) {
                current->next = nodeQueue.front();
            }
            
            if(current->left) {
                nodeQueue.push(current->left);
            }
            if(current->right) {
                nodeQueue.push(current->right);
            }
        }
    }
    
    return root;
}
