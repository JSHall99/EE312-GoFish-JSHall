// File:   card.cpp
// Author: Jackson S. Hall
// Date:   4/11/19

#include "card.h"
#include <string>
#include <iostream>

using namespace std;

Card::Card()
{
   // Initialize to Ace of Spades by default
   myRank = 1;
   mySuit = spades;
}

Card::Card(int rank, Suit s)
{
   myRank = rank;
   mySuit = s;
}

string Card::toString() const
{
   string result = rankString(myRank) + suitString(mySuit);
   return result;
}

bool Card::sameSuitAs(const Card& c) const
{
   string compValue = c.toString();
   string myValue = toString();
   return compValue[2] == myValue[2];
}

int Card::getRank() const
{
   return myRank;
}

string Card::suitString(Suit s) const
{
   string suit;
   switch (s) {
      case spades: suit = "s"; break;
      case hearts: suit = "h"; break;
      case diamonds: suit = "d"; break;
      case clubs: suit = "c"; break;
   }
   return suit;
}

string Card::rankString(int r) const
{
   string rank;
   switch (r) {
      case 1: rank = "A"; break;
      case 11: rank = "J"; break;
      case 12: rank = "Q"; break;
      case 13: rank = "K"; break;
      // Otherwise, convert number to ASCII
      default: rank = myRank + '0'; break;
   }

   return rank;
}

bool Card::operator == (const Card& rhs) const
{
   return (toString() == rhs.toString());
}

bool Card::operator != (const Card& rhs) const
{
   return !(*this == rhs);
}

ostream& operator << (ostream& out, const Card& c)
{
   out << c.toString();
   return out;
}

