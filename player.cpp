// File:   player.cpp
// Author: Jackson S. Hall
// Date:   4/11/19

#include "player.h"
#include <cstdlib> // For random number generation
#include <ctime> // For seeding the random number generator

Player::Player()
{
   srand(time(0)); // Seed random number generator
   myName = "Jackson";
}

Player::Player(string name)
{
   srand(time(0)); // Seed random number generator
   myName = name;
}

void Player::addCard(Card c)
{
   myHand.push_back(c);
}

void Player::bookCards(Card c1, Card c2)
{
   myBook.push_back(c1);
   myBook.push_back(c2);
}

bool Player::checkHandForBook(Card &c1, Card &c2)
{
   // Check all pairs of cards to see if they are the same rank.  (There
   // are faster algorithms that would, for example, count the number of
   // occurrences of each rank first, then once one rank occurs twice,
   // find the first two cards of that rank and return.  However, this way
   // was faster to write.)
   for (vector<Card>::iterator i = myHand.begin(); i < myHand.end(); i++) {
      for (vector<Card>::iterator j = i + 1; j < myHand.end(); j++) {
         if (i->getRank() == j->getRank()) {
            c1 = *i;
            c2 = *j;
            return true;
         }
      }
   }
   return false; // No pairs found.
}

bool Player::rankInHand(Card c) const
{
   for (vector<Card>::const_iterator i = myHand.begin();
      i < myHand.end(); i++) {
         if (i->getRank() == c.getRank()) return true;
   }
   return false; // No match found
}

Card Player::chooseCardFromHand() const
{
   // For now, just choose randomly
   int index = rand() % getHandSize();
   return myHand[index];
}

bool Player::cardInHand(Card c) const
{
   for (vector<Card>::const_iterator i = myHand.begin();
      i < myHand.end(); i++) {
         if (*i == c) return true;
   }
   return false;
}

Card Player::removeCardFromHand(Card c)
{
   Card result;
   for (vector<Card>::iterator i = myHand.begin(); i < myHand.end(); i++) {
      if (*i == c) {
         result = *i;
         myHand.erase(i);
         return result;
      }  
   }
}

// Returned string is a list of cards separated by spaces (and ending in
// a space)
string Player::showHand() const
{
   string result;
   for (vector<Card>::const_iterator i = myHand.begin();
      i < myHand.end(); i++) {
         //cout << i->toString() << endl; // Debugging
         result += i->toString();
         result += " ";
   }
   return result;
}

// Format: {2c, 2d} {Jh, Jd} etc.
string Player::showBooks() const
{
   string result;
   for (vector<Card>::const_iterator i = myHand.begin();
      i < myHand.end(); i++) {
         result += ("{" + i->toString() + ", " + (i+1)->toString() + "} ");
   }
}

int Player::getHandSize() const
{
   return myHand.size();
}

int Player::getBookSize() const
{
   return myBook.size();
}

// This seems to be identical to checkHandForBook - ?
bool Player::checkHandForPair(Card &c1, Card &c2)
{
   return checkHandForBook(c1, c2);
}

// Same as rankInHand
bool Player::sameRankInHand(Card c) const
{
   return rankInHand(c);
}

