// File: card_test.cpp
// Author: Jackson S. Hall
// This file tests the card class

#include "card.h"
#include <iostream>

using namespace std;

int main(void)
{
   Card card1(11, Card::diamonds);
   Card card2(5, Card::diamonds);
   cout << "card1 = " << card1 << endl;
   cout << "card2 = " << card2 << endl;
   cout << "same suit? = " << card1.sameSuitAs(card2) << endl;
   cout << "card1 rank = " << card1.getRank() << endl;
   cout << "card1 == card2 " << (card1 == card2) << endl;
   cout << "card1 != card2 " << (card1 != card2) << endl;
   return 0;
}
