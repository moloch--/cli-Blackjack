/*
 * Card.h
 *
 *  Created on: 2010-10-26
 */

#ifndef CARD_H_
#define CARD_H_

#include <string>

using std::string;

class Card
{
public:
	Card();
	Card(string suit, int value, string rank); // Create card with a given value/rank
	Card(string suit, int value, int rank);    // Create card with a given value/rank
	virtual ~Card();

	int getValue();                 // Returns the card's value
	void setValue(int cardValue);   // Sets the value variable

	void setSuit(string cardSuit);  // Sets the suit variable
	string getSuit();               // Returns the card's suit

	void setRank(string cardRank);  // Set card's rank (face cards)
	void setRank(int cardRank);     // Set card's rank (numeric cards)
	string getRank();               // Return card's rank as a string

	bool isHidden();                // Defines if the card is hidden or not
	void hide(bool attribute);      // Hides card from user (hidden = true)

private:
	int value;
	bool hidden;
	string rank;
	string suit;
	string toString(int value);     // Create a string from an integer
};

#endif /* CARD_H_ */
