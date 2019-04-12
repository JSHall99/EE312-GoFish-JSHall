// File: player_test.cpp
// Author: Jackson S. Hall
// Date: 4/11/19
// This is a test program for the Player class.

#include "player.h"
#include "card.h"
#include <iostream>

using namespace std;

int main(void)
{
   Player p;
   cout << "getName() : " << p.getName() << endl;
   
   Card c1(10, Card::diamonds);
   Card c2(11, Card::diamonds);
   p.addCard(c1);
   p.addCard(c2);

   cout << "showHand() : " << p.showHand() << endl;

   return 0;
}

