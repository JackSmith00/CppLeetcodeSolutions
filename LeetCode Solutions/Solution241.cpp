#include "solutions.h"

int charOperation(int num1, char operation, int num2) {
    switch (operation) {
        case '+':
            return num1 + num2;
            break;
        case '-':
            return num1 - num2;
            break;
        case '*':
            return num1 * num2;
            break;
        default:
            return 0;
    }
}

vector<int> recursiveOperationGrouper(vector<int> numbers, vector<char> operands) {
    if(numbers.size() == 1) {
        // only 1 number, return that number
        return numbers;
    } else if (numbers.size() == 2) {
        // 2 numbers, so perform operation and return result
        return {charOperation(numbers[0], operands[0], numbers[1])};
    } else {
        // more than 2 numbers, grow grouping from left to right and work out all possible results
        vector<int> possibleResults;
        
        // start with only first number in bracket and loop untill all but
        // last number is in the left side bracket
        for (int leftExpressionMaxIndex = 0; leftExpressionMaxIndex < numbers.size() - 1; leftExpressionMaxIndex++) {
            // combine all left results with all right results
            for(int leftResult : recursiveOperationGrouper(vector<int>(numbers.begin(), numbers.begin()+leftExpressionMaxIndex+1), vector<char>(operands.begin(), operands.begin()+leftExpressionMaxIndex))){
                for(int rightResult : recursiveOperationGrouper(vector<int>(numbers.begin()+leftExpressionMaxIndex+1, numbers.end()), vector<char>(operands.begin()+leftExpressionMaxIndex+1, operands.end()))) {
                    possibleResults.push_back(charOperation(leftResult, operands[leftExpressionMaxIndex], rightResult));
                }
            }
                
        }
        return possibleResults;
    }
}

vector<int> Solution::diffWaysToCompute(string expression) {
    vector<int> numbers;
    vector<char> operands;
    
    { // in brackets because `operatorPosition` is not needed outside of this scope
        int operatorPosition = (int) expression.find_first_of("+-*");
        while(operatorPosition != string::npos) {
            numbers.push_back(stoi(expression.substr(0, operatorPosition)));
            operands.push_back(expression[operatorPosition]);
            expression = expression.substr(operatorPosition + 1);
            operatorPosition = (int) expression.find_first_of("+-*");
        }
        numbers.push_back(stoi(expression));
    }
    
    return recursiveOperationGrouper(numbers, operands);
}
