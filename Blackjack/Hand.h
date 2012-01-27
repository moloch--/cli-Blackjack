/*
 * Hand.h
 *
 *  Created on: November 18, 2010
 */

#ifndef HAND_H_
#define HAND_H_

#include <vector>
#include "AsciiArt.h"
#include "Card.h"

using std::vector;

class Hand
{
public:
	Hand();
	virtual ~Hand();

	int getScore();
	unsigned int getSize();
	int getCardValue(unsigned int index);
	void setCardValue(unsigned int index, int value);
	string getCardRank(unsigned int index);
	void putInHand(Card card);
	void hideCard(unsigned int index);
	void revealCard(unsigned int index);
	void removeCard();
	void printAsciiHand();

private:
	int score;
	int aceValue;
	int visibleScore;
	vector<Card> hand;

    void printAsciiHeader(AsciiArt & ascii);
	void printAsciiFooter(AsciiArt & ascii);
    void printAsciiTopRank(AsciiArt & ascii);
    void printAsciiBottomRank(AsciiArt & ascii);
    void printAsciiSymbol(AsciiArt & ascii);
};

#endif /* HAND_H_ */
