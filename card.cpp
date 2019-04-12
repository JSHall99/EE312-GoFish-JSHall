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
   return compValue[2] == suitString(mySuit);
}

int Card::getRank()
{
   return myRank;
}

string Card::suitString(Suit s)
{
   string suit;
   switch (s) {
      case spades: suit = "s";
      case hearts: suit = "h";
      case diamonds: suit = "d";
      case clubs: suit = "c";
   }
   return suit;
}

string Card::rankString(int r)
{
   char rank;
   switch (r) {
      case 1: rank = 'A';
      case 11: rank = 'J';
      case 12: rank = 'Q';
      case 13: rank = 'K';
      // Otherwise, convert number to ASCII
      default: rank = myRank + '0';
   }

   string s = rank;
   return s;
}

bool Card::operator == (const Card& rhs) const
{
   return (toString() == rhs.toString());
}

bool Card::operator != (Const Card& rhs) const
{
   return !(*this == rhs);
}

ostream& operator << (ostream& out, const Card& c)
{
   out << c.toString();
   return out;
}

