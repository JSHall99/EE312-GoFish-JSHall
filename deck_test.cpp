// File: deck_test.cpp
// Author: Jackson S. Hall
// Date: 4/11/19
// This is a simple test file for the deck class (deck.h)

#include "deck.h"
#include <iostream>

using namespace std;

void printDeck(Deck &d);

int main(void)
{
   Deck d;

   cout << "Deal deck in order" << endl;
   printDeck(d);
   cout << "---------------------" << endl;

   cout << "Shuffle deck" << endl;
   d.shuffle();
   printDeck(d);
   cout << "---------------------" << endl;

   cout << "Shuffle deck again" << endl;
   d.shuffle();
   printDeck(d);
   
   return 0;
}

void printDeck(Deck &d)
{
   for (int i = 0; i < 52; i++) {
      cout << d.dealCard() << endl;
   }
}
