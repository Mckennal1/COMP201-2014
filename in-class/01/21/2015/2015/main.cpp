//
//  main.cpp
//  2015
//
//  Created by Luisa on 1/21/15.
//  Copyright (c) 2015 Luisa. All rights reserved.
//

#include <iostream>
using namespace std;
//TODO: vector<card>
//shuffling a deck of cards
//drawing cards
//drawing cards onto the screen

//This is an enumeration
// It defines a type, along with the possibilities

enum Suit { HEARTS, SPADES, CLUBS, DIAMONDS };
//4chan-not a good name

string suit_name[]= {
    "Hearts", "SPADES", "CLUBS", "DIAMONDS"
};

// Each possibility must be identifier (legit name)
enum Rank {
    TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, KING, ACE
};

//Array of rank names
const string rank_names[] = {
    "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"
};

//return_type identifier (parameterType Param, ...)
//How about "ace of Spades"

//defines a type called, card
//It consists of asuit and a rank

typedef struct {
    //two varbile;
    Suit suit;
    //two varibale;
    Rank rank;
    
} Card;

void printCard(Rank rank, Suit suit) {
    // instead of having a big IF statment or switch statement we are using an Array
    cout << rank_names[rank] << "of" << suit_name[suit] << endl;
}


//Type
//variable
//Constant

int main() {
    // type variable_name; // Declare a variable
    string name;
    //fake card data with an int
    // not ideal
    
    Card card;
    
    //varible = some_value;
    card.suit = SPADES;
    card.rank = ACE;
    
    printCard(card.rank, card.suit);
    return 0;
}


//return_type identifier (parameterType Param, ...)
//How about "ace of Spades"
void printCard(Card card) {
    cout << rank_names[card.rank] << "of"
    << suit_name[card.suit] << endl;
    
}
