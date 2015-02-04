//
//  main.cpp
//  jack age
//
//  Created by Luisa on 1/30/15.
//  Copyright (c) 2015 Luisa. All rights reserved.
//

#include <iostream>
using namespace std;

//c++ has references, which are nicer syntax for C-style pointers
//
void age_a_year(int & age) {
    age++;
}

//C-style version
void age_a_year_old_c_way(int * age){
    (*age)++;
}

int main() {
    int jack = 50;
    age_a_year(jack);
    age_a_year_old_c_way(&jack);
    cout << jack << endl;
}


