/*
 * Card.cpp
 *
 *  Created on: 2010-10-26
 */

#include <iostream>
#include <sstream>
#include <string>
#include "Card.h"

using std::cout;
using std::endl;
using std::string;
using std::ostringstream;

Card::Card()
{
	// Blank Constructor
}

/* Set card rank based on a string (face cards) */
Card::Card(string cardSuit, int cardValue, string cardRank)
{
	setValue(cardValue);
	setSuit(cardSuit);
	setRank(cardRank);
	hidden = false;
}

/* Set card rank based on an integer */
Card::Card(string cardSuit, int cardValue, int cardRank)
{
	setValue(cardValue);
	setSuit(cardSuit);
	setRank(cardRank);
	hidden = false;
}

Card::~Card()
{
	// Auto-generated Deconstructor (Default)
}

int Card::getValue()
{
	return value;
}

void Card::setValue(int cardValue)
{
	value = cardValue;
}

void Card::setSuit(string cardSuit)
{
	suit = cardSuit;
}

string Card::getSuit()
{
	return suit;
}

void Card::setRank(int cardRank)
{
	rank = toString(cardRank);
}

void Card::setRank(string cardRank)
{
	rank = cardRank;
}

string Card::getRank()
{
	return rank;
}

bool Card::isHidden()
{
	return hidden;
}

void Card::hide(bool attribute)
{
	hidden = attribute;
}

string Card::toString(int value)
{
	ostringstream result;
	result << value;
	return result.str();
}
