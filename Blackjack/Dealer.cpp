/*
 * Dealer.cpp
 *
 *  Created on: 2010-10-27
 */
#include <string>
#include "Dealer.h"

using std::string;

Dealer::Dealer(string name)
{
	setName(name);
}

Dealer::~Dealer()
{
	// Blank
}

void Dealer::turn(Deck & deck, int scoreToBeat)
{
	while(getCurrentScore() < scoreToBeat)
	{
		hit(deck.deal());
	}
}
