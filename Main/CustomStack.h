//
//  CustomStack.h
//  LeetCode Solutions
//
//  Created by Jack Smith on 30/09/2024.
//
/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
#pragma once
#include <vector>
#include <iostream>

class CustomStack {
public:
    CustomStack(int maxSize);
    void push(int x);
    int pop();
    void increment(int k, int val);
    friend std::ostream& operator<<(std::ostream& stream, const CustomStack& customStack); // for checking test cases
private:
    int m_maxSize;
    std::vector<int> m_stack;
};
