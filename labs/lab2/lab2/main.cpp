//
//  main.cpp
//  lab2
//
//  Created by Luisa on 1/26/15.
//  Copyright (c) 2015 Luisa. All rights reserved.
//
// cd ~/COMP201-2014/in-class/lab1/lab1
// g++ main.cpp -o main.exe
// ./main.exe input.txt
// less number_table.txt
// press q quit
// writing on a text file

#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <stack>

using namespace std;

bool isOperator(string input);
void performOp(string input, stack<int> calcStack);

int main()
{
    cout << "RPN Calculator" << endl;
    
    stack<int> calcStack;
    string input;
    
    while(true)
    {
        //display
        cout << "Enter number or operator\n" << ">>";
        
        //get input
        cin >> input;
        
        //check for numeric value
        int num;
        if(istringstream(input) >> num)
        {
            calcStack.push(num);
        }
        
        //check for operator
        else if(isOperator(input))
        {
            performOp(input, calcStack);
        }
        
        //check for quit
        else if(input == "q")
        {
            return 0;
        }
        
        //invalid output
        else
        {
            cout << "Invalid input" << endl;
        }
    }
    
    return 0;
}

bool isOperator(string input)
{
    string ops[] = {"-", "+", "*", "/"};
    
    for(int i=0; i<4; i++)
    {
        if(input == ops[i])
        {
            return true;
        }
    }
    return false;
}

void performOp(string input, stack<int> calcStack)
{
    int leftVal, rightVal, result;
    
    rightVal = calcStack.top();
    calcStack.pop();
    
    leftVal = calcStack.top();
    calcStack.pop();
    
    if(input == "-")
    {
        result = leftVal - rightVal;
    }
    else if(input == "+")
    {
        result = leftVal - rightVal;
    }
    else if(input == "*")
    {
        result = leftVal - rightVal;
    }
    else
    {
        result = leftVal / rightVal;
    }
    
    cout << result << endl;
    calcStack.push(result);
}