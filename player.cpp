// File:   player.cpp
// Author: Jackson S. Hall
// Date:   4/11/19

#include "player.h"

Player::Player()
{
   myName = "Jackson";
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

bool Player::rankInHand(card c) const
{
   for (vector<Card>::iterator i = myHand.begin(); i < myHand.end(); i++) {
      if (i->getRank() == c.getRank()) return true;
   }
   return false; // No match found
}

Card Player::chooseCardFromHand() const
{
   // COME UP WITH STRATEGY HERE
}

bool Player::cardInHand(Card c) const
{
   for (vector<Card>::iterator i = myHand.begin(); i < myHand.end(); i++) {
      if (*i == c) return true;
   }
   return false;
   }
}

Card Player::removeCardFromHand(Card c)
{
   
}

