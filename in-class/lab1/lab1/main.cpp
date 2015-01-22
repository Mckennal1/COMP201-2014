//
//  main.cpp
//  lab1
//
//  Created by Luisa on 1/19/15.
//  Copyright (c) 2015 Luisa. All rights reserved.
//
// cd ~/COMP201-2014/in-class/lab1/lab1
// g++ main.cpp -o main.exe
// ./main.exe input.txt
// less number_table.txt
// press q quit
// writing on a text file

#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(int argc, char*argv[])
{
    int i;
    int n;
    int sum = 0;
    ifstream input;
    ofstream numbertable;

    input.open(argv[1]);
    
    numbertable.open("number_table.txt"); //Writes to a file called number_table.txt
    numbertable << "x\t x^2\t Current Sum\n"; //Line 1 in file (column titles)
    numbertable << "============================\n"; //Line 2 in file
    
    for (i = 0; i <= 6; i++) {
        input >> n;
        numbertable << n;
        numbertable << "\t" << pow(n,2);
        sum = sum + n;
        numbertable << "\t" << sum;
        numbertable << "\n";
        }
    numbertable.close(); //close file
    input.close(); //close file
    return 0;
}