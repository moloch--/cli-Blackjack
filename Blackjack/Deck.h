/*
 * Deck.h
 *
 *  Created on: 2010-10-26
 */

#ifndef DECK_H_
#define DECK_H_

#include <vector>
#include "Card.h"

using std::vector;

class Deck
{
public:
	Deck();
	virtual ~Deck();

	void initialize();       // Reset deck
	void shuffle();          // Randomize deck order
	void printDeckOfCards(); // Print every card in the deck
	Card deal();             // Pop card from desk and give to player
	unsigned int getSize();  // Get the current size of the deck

private:
	/* Private Copy Constructor */
	Deck&  operator = (const Deck& rhs);
	int deckCounter;
	void reset();
    vector<string> faceCards;
    vector<string> suits;
    vector<Card> deckOfCards;

};

#endif /* DECK_H_ */
