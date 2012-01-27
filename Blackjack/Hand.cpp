/*
 * Hand.cpp
 *
 *  Created on: Nov 18, 2010
 */
#include <iostream>
#include "Hand.h"

using std::cout;
using std::endl;

Hand::Hand()
{
	// Auto-generated constructor stub
}

Hand::~Hand()
{
	// Auto-generated (Default)
}

int Hand::getScore()
{
	score = 0; // Re-calculate score
	for (unsigned int index = 0; index < hand.size(); ++index)
	{
		if (!hand[index].isHidden()) // Do not include hidden values
		{
			score += hand[index].getValue();
		}
	}
	return score;
}

unsigned int Hand::getSize()
{
	return hand.size();
}

int Hand::getCardValue(unsigned int index)
{
	return hand[index].getValue();
}

void Hand::setCardValue(unsigned int index, int value)
{
	hand[index].setValue(value);
}

string Hand::getCardRank(unsigned int index)
{
	return hand[index].getRank();
}

void Hand::putInHand(Card card)
{
	hand.push_back(card);
}

void Hand::hideCard(unsigned int index)
{
	hand[index].hide(true);
}

void Hand::revealCard(unsigned int index)
{
	hand[index].hide(false);
}

void Hand::removeCard()
{
	hand.pop_back();
}

/* This function prints out all the cards in a hand (ascii style) */
void Hand::printAsciiHand()
{
    AsciiArt ascii;
    printAsciiHeader(ascii); // An entire line must be printed before another can start
    printAsciiTopRank(ascii);
    printAsciiSymbol(ascii);
    printAsciiBottomRank(ascii);
    printAsciiFooter(ascii);
    cout << "Total value: " << getScore() << endl;
}

/* Print header for all cards */
void Hand::printAsciiHeader(AsciiArt & ascii)
{
    for (unsigned int index = 0;index < ascii.getHeaderSize();++index)
    {
        for (unsigned int cardIndex = 0;cardIndex < hand.size();++cardIndex)
        {
            cout << ascii.getCardHeader(index) << " ";
        }
        cout << endl; // End line
    }
}

/* Prints a footer for all cards */
void Hand::printAsciiFooter(AsciiArt & ascii)
{
    for (unsigned int index = 0;index < ascii.getFooterSize();++index)
    {
        for (unsigned int cardIndex = 0;cardIndex < hand.size();++cardIndex)
        {
            cout << ascii.getCardFooter(index) << " ";
        }
        cout << endl;
    }
}

/* Print top rank for all cards */
void Hand::printAsciiTopRank(AsciiArt & ascii)
{
    for (unsigned int cardIndex = 0;cardIndex < hand.size();++cardIndex)
    {
        if (hand[cardIndex].isHidden())
        {
            cout << ascii.getTopRank("?") << " ";
        }
        else
        {
            cout << ascii.getTopRank(getCardRank(cardIndex)) << " ";
        }
    }
    cout << endl; // End line
}

/* Print bottom rank for all cards */
void Hand::printAsciiBottomRank(AsciiArt & ascii)
{
    for (unsigned int cardIndex = 0;cardIndex < hand.size();++cardIndex)
    {
        if (hand[cardIndex].isHidden())
        {
            cout << ascii.getBottomRank("?") << " ";
        }
        else
        {
            cout << ascii.getBottomRank(getCardRank(cardIndex)) << " ";
        }
    }
    cout << endl; // End line & flush buffer
}

/* Print symbols for all cards */
void Hand::printAsciiSymbol(AsciiArt & ascii)
{
    for (unsigned int index = 0;index < ascii.getSymbolSize();++index)
    {
        for (unsigned int cardIndex = 0;cardIndex < hand.size();++cardIndex)
        {
            if (hand[cardIndex].isHidden())  // Check to if card is hidden
            {
                cout << ascii.printSymbol("hidden", index) << " ";
            }
            else
            {
                cout << ascii.printSymbol(hand[cardIndex].getSuit(), index) << " ";
            }
        }
        cout << endl;
    }
}
