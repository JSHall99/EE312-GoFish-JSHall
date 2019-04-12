// File: player_test.cpp
// Author: Jackson S. Hall
// Date: 4/11/19
// This is a test program for the Player class.

#include "player.h"
#include "card.h"
#include "deck.h"
#include <iostream>

using namespace std;

int main(void)
{
   Player p;
   cout << "getName() : " << p.getName() << endl;
   
   Deck d;
   d.shuffle();

   // Deal 7 random cards
   for (int i = 0; i < 7; i++) {
      p.addCard(d.dealCard());
   }

   cout << "showHand() : " << p.showHand() << endl;

   // Set aside books
   cout << "Checking for books" << endl;
   Card pair1, pair2;
   while (p.checkHandForBook(pair1, pair2)) {
      cout << "Book found: " << pair1 << " " << pair2 << endl;
      p.bookCards(pair1, pair2);
   }

   // Display books
   cout << "showBooks() : " << p.showBooks() << endl;
   cout << "getBookSize() : " << p.getBookSize() << endl;
   cout << "showHand() : " << p.showHand() << endl;
   cout << "getHandSize() : " << p.getHandSize() << endl;
   cout << "chooseCardFromHand() : " << p.chooseCardFromHand() << endl;

   return 0;
}

