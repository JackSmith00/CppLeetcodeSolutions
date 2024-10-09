//
//  Solution1381.cpp
//  LeetCode Solutions
//
//  Created by Jack Smith on 30/09/2024.
//
#include "CustomStack.h"
#include <algorithm>

CustomStack::CustomStack(int maxSize) : m_maxSize(maxSize) {
    m_stack.reserve(maxSize); // reserve the max size for the stack to save resizing the vector
}

void CustomStack::push(int x) {
    if(m_stack.size() < m_maxSize) { // if there is space, add element to back of stack
        m_stack.push_back(x);
    }
}

int CustomStack::pop() {
    if(m_stack.size() > 0) { // if the stack is not empty
        int top = m_stack.back();
        m_stack.pop_back();
        return top;
    } else {
        return -1;
    }
}

void CustomStack::increment(int k, int val) {
    for(k = std::min(k-1, (int)m_stack.size()-1); k >= 0; k--) { // loop backwards from k-1 or top of stack
        m_stack[k] += val;
    }
}

std::ostream& operator<<(std::ostream& stream, const CustomStack& customStack) {
    if(customStack.m_stack.size() == 0) {
        stream << "[]" << std::endl;
    } else {
        stream << '[';
        for(int i = 0; i < (int)customStack.m_stack.size()-1; i++){
            stream <<customStack.m_stack[i] << ',';
        }
        stream << customStack.m_stack.back() << ']' << std::endl;
    }
    return stream;
}

void print() {
    
}
