/*
 * Deck.cpp
 *
 *  Created on: 2010-10-26
 */
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "Card.h"
#include "Deck.h"

Deck::Deck()
{
	srand(time(NULL)); // Seed random number generator
    suits.push_back("hearts"); // Valid suits
    suits.push_back("clubs");
    suits.push_back("diamonds");
    suits.push_back("spades");
    faceCards.push_back("J"); // Valid non-numeric ranks
    faceCards.push_back("Q");
    faceCards.push_back("K");
    faceCards.push_back("A"); // The exact value of this card is dealt with in the hand
}

Deck::~Deck()
{
	// Blank Deconstructor
}

/* Remove all cards from deck */
void Deck::reset()
{
	while(!deckOfCards.empty())
	{
		deckOfCards.pop_back();
	}
}

void Deck::initialize()
{
	reset();
    deckCounter = 0; // Location in deck
    // Iterate through each suit, creating cards on the way
    for(unsigned int suitIndex = 0;suitIndex < suits.size();++suitIndex)
    {
        // Create number cards for the current suit
        for(int numberIndex = 2;numberIndex <= 10;++numberIndex)
        {
            Card card(suits[suitIndex], numberIndex, numberIndex);
            deckOfCards.push_back(card);
        }
        // Create face cards for the current suit
        for(unsigned int faceIndex = 0;faceIndex < faceCards.size();++faceIndex)
        {
            Card card(suits[suitIndex], 10, faceCards[faceIndex]);
            deckOfCards.push_back(card);
        }
    }
}

Card Deck::deal()
{
	return deckOfCards.at(deckCounter++); // Return card and increment counter
}

void Deck::shuffle()
{
	std::random_shuffle(deckOfCards.begin(), deckOfCards.end());
}

unsigned int Deck::getSize()
{
	return deckOfCards.size();
}
