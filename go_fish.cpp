// File:   go_fish.cpp
// Author: Jackson S. Hall
// Date:   4/12/19
// This program simulates a game of Go Fish with two computer players.
// EE312 Programming Assg #6, Spring 19

#include <iostream>
#include <fstream>
#include <cstdlib>	// Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"

void dealHand(Deck &d, Player &p, int numCards);
void drawCard(Deck &d, Player &p);
void setAsideBooks(Player &p);
bool askForCard(Player &taker, Player &giver, Deck &d);

ofstream outFile;

int main(void)
{
   // Configure output file "gofish.txt"
   outFile.open("gofish_results.txt");
   
   // Determines the starting hand size.  For two players, this is 
   // normally 7 cards.
   int numCards = 7;

   Player p1("Jackson");
   Player p2("Scott");

   Deck d;
   d.shuffle();

   outFile << "Dealing..." << endl;
   dealHand(d, p1, numCards);
   dealHand(d, p2, numCards);

   // After dealing, both players set aside all of their pairs
   setAsideBooks(p1);
   setAsideBooks(p2);

   int turnNo = 1; // Keeps track of the number of turns taken
   enum Turn {GAME_OVER, P1_TURN, P2_TURN};
   Turn whoseTurn = P1_TURN;
   while (whoseTurn != GAME_OVER) {

      outFile << endl;
      outFile << "Turn #" << turnNo << endl;
      outFile << p1.getName() << " has " << p1.showHand() << endl;
      outFile << p2.getName() << " has " << p2.showHand() << endl;

      if (whoseTurn == P1_TURN) {

         // If p1 has no cards in his/her hand, he/she draws a card, then
         // the turn passes to p2.
         if (p1.getHandSize() == 0) {
            drawCard(d, p1);
            whoseTurn = P2_TURN;
         }

         // If p1 does have cards in his/her hand, he/she asks p2 for a
         // card.
         else {
            if(askForCard(p1, p2, d) == true) {
               // If p2 had a card of that rank, it remains p1's turn.
               whoseTurn = P1_TURN;
            }
            else {
               // Otherwise, it is now p2's turn.
               whoseTurn = P2_TURN;
            }
            setAsideBooks(p1);
         }
      }

      else if (whoseTurn == P2_TURN) {

         // If p2 has no cards in his/her hand, he/she draws a card, then
         // the turn passes to p1.
         if (p2.getHandSize() == 0) {
            drawCard(d, p2);
            whoseTurn = P1_TURN;
         }

         // If p2 does have cards in his/her hand, he/she asks p1 for a
         // card.
         else {
            if(askForCard(p2, p1, d) == true) {
               // If p1 had a card of that rank, it remains p2's turn.
               whoseTurn = P2_TURN;
            }
            else {
               // Otherwise, it is now p1's turn.
               whoseTurn = P1_TURN;
            }
            setAsideBooks(p2);
         }
      }

      turnNo++;

      // Check if the total number of books for both players is 26.  If so,
      // the game is over.
      int numBooks = p1.getBookSize() + p2.getBookSize();
      if (numBooks == 26) {
         whoseTurn = GAME_OVER;
      }
   }

   // Output each player's books and determine who won
   outFile << endl;
   outFile << "GAME OVER" << endl;

   outFile << p1.getName() << " has " << p1.getBookSize();
   outFile << " books: " << p1.showBooks() << endl;

   outFile << p2.getName() << " has " << p2.getBookSize();
   outFile << " books: " << p2.showBooks() << endl;
   
   if (p1.getBookSize() > p2.getBookSize()) {
      outFile << p1.getName() << " wins!" << endl;
   }
   else if (p1.getBookSize() < p2.getBookSize()) {
      outFile << p2.getName() << " wins!" << endl;
   }
   else {
      outFile << "It's a tie!" << endl;
   }

   outFile.close();
   return EXIT_SUCCESS;
}

// Deals a hand of [numCards] cards to player [p] from deck [d].  Also
// outputs a message that shows the cards in the player's hand.
void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i = 0; i < numCards; i++) {
      p.addCard(d.dealCard());
   }
   outFile << p.getName() << " was dealt " << p.showHand() << endl;
}

// Player [p] draws a card from Deck [d] and displays a message
void drawCard(Deck &d, Player &p)
{
   if (d.size() > 0) {
      Card nextCard = d.dealCard();
      p.addCard(nextCard);
      outFile << p.getName() << " drew the " << nextCard << "." << endl;
   }
   else {
      outFile << p.getName() << " did not draw a card because ";
      outFile << "the deck is empty!\n";
   }
}

// Player [p] checks his/her hand for all books and sets them aside,
// also outputting a message each time.
void setAsideBooks(Player &p)
{
   Card c1, c2;
   while (p.checkHandForBook(c1, c2) == true) {
      outFile << p.getName() << " booked {" << c1 << " " << c2 << "}\n";
      p.bookCards(c1, c2);
   }
}

// Player [taker] chooses a card from his/her hand and asks Player [giver]
// if he/she has a card of that rank.  If so, [giver] hands the card over.
// Otherwise, [giver] says "Go Fish!" and [taker] draws a card.
//
// If [giver] did have the card, then the function returns true (indicating
// that [taker] gets to go again).  Otherwise, this returns false.
bool askForCard(Player &taker, Player &giver, Deck &d)
{
   // [taker] chooses a card and asks [giver]
   Card takerCard = taker.chooseCardFromHand();
   outFile << taker.getName() << ": Do you have any ";
   outFile << takerCard.rankString(takerCard.getRank()) << "'s?" << endl;

   // If [giver] has a card of that rank, he/she hands it over.  (Note that
   // no players will ever have more than one card of the same rank in their
   // hand, since they would have already booked that pair.)
   Card giverCard;
   if (giver.rankInHand(takerCard, giverCard)) {
      outFile << giver.getName() << ": Yes, I have a ";
      outFile << giverCard.rankString(giverCard.getRank()) << "." << endl;

      outFile << giver.getName() << " gave " << taker.getName();
      outFile << " the " << giverCard << "." << endl;

      taker.addCard(giverCard);
      giver.removeCardFromHand(giverCard);
      return true;
   }
   // Otherwise, [giver] says "Go Fish!" and [taker] draws a card
   else {
      outFile << giver.getName() << ": Go Fish!" << endl;
      drawCard(d, taker);
      return false;
   }
}

