//
//  Node.h
//  LeetCode Solutions
//
//  Created by Jack Smith on 10/10/2024.
//
#pragma once

struct Node {
    int val;
    Node* left;
    Node* right;
    Node* next;
    
    Node(): val(0), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int val): val(val), left(nullptr), right(nullptr), next(nullptr) {}
    Node(int val, Node* left, Node* right): val(val), left(left), right(right), next(nullptr) {}
    Node(int val, Node* left, Node* right, Node* next): val(val), left(left), right(right), next(next) {}
};
