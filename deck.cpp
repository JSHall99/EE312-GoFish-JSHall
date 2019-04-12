// File:   deck.cpp
// Author: Jackson S. Hall
// Date:   4/11/19

#include "deck.h"
#include <cstdlib> // For random number generation
#include <ctime> // For seeding the random number generator

using namespace std;

// Initialize with cards in order: Ace of Spaces on top, King of
// Clubs on bottom
Deck::Deck()
{
   // Seed the random number generator
   srand(time(0));

   myIndex = 0;
   for (int suit = Card::spades; suit <= Card::clubs; suit++) {
      for (int rank = 1; rank <= 13; rank++) {
         // Safety measure - ensure array size is never exceeded
         if (myIndex >= SIZE) return;

         Card nextCard(rank, Card::Suit(suit));
         myCards[myIndex] = nextCard;
         myIndex++;
      }
   }

   // Start dealing from the top
   myIndex = 0;
}

void Deck::shuffle()
{
   // Swap 1000 randomly chosen pairs of cards
   for (int i = 0; i < 1000; i++) {
      int index1 = rand() % SIZE;
      int index2 = rand() % SIZE;
      
      // Swap the cards at index1 and index2
      Card temp = myCards[index1];
      myCards[index1] = myCards[index2];
      myCards[index2] = temp;
   }

   // All cards have been returned to the deck, so start dealing
   // from the top again.
   myIndex = 0;
}

Card Deck::dealCard()
{
   Card nextCard;
   if (myIndex < SIZE) {
      nextCard = myCards[myIndex];
   }
   else { // Error if there are no cards remaining
      cout << "ERROR: Attempt to draw from empty deck" << endl;
      exit(1);
   }
   myIndex++;

   return nextCard;
}

int Deck::size() const
{
   return SIZE - myIndex;
}

