/*
 * Dealer.h
 *
 *  Created on: 2010-10-27
 */

#ifndef DEALER_H_
#define DEALER_H_

#include <vector>
#include <string>
#include "Hand.h"
#include "Deck.h"
#include "Player.h"

using std::vector;
using std::string;

class Dealer: public Player
{
public:
	Dealer(string name);
	virtual ~Dealer();

	/* Dealer hits until bust or win */
	void turn(Deck & deck, int scoreToBeat);
};

#endif /* DEALER_H_ */
