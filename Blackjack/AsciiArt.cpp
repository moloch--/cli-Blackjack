/*
 * AsciiArt.cpp
 *
 *  Created on: Nov 20, 2010
 */

#include "AsciiArt.h"
#include <sstream>

using std::ostringstream;

AsciiArt::AsciiArt() // TODO There may be a better way of doing this?
{
	/* Create ascii card header and footer */
	cardHeader.push_back(" _________ ");
	cardHeader.push_back("/         \\");
	cardFooter.push_back("\\_________/"); // Don't forget to escape chars!

	/* Create ascii symbols for each suit
	 * All symbols must be the same length!
	 */
	clubsSymbol.push_back("|    _    |"); // Clubs symbol
	clubsSymbol.push_back("|   (_)   |");
	clubsSymbol.push_back("|  (_)_)  |");
	clubsSymbol.push_back("|   /_\\   |");
	clubsSymbol.push_back("|         |");
	heartsSymbol.push_back("|   _ _   |");  // Hearts symbol
	heartsSymbol.push_back("|  / ^ \\  |");
	heartsSymbol.push_back("|  \\   /  |");
	heartsSymbol.push_back("|   \\ /   |");
	heartsSymbol.push_back("|    `    |");  // Spades symbol
	spadesSymbol.push_back("|    ,    |");
	spadesSymbol.push_back("|   / \\   |");
	spadesSymbol.push_back("|  (_ _)  |");
	spadesSymbol.push_back("|   /_\\   |");
	spadesSymbol.push_back("|         |");   // Diamonds symbol
	diamondsSymbol.push_back("|         |");
	diamondsSymbol.push_back("|   /\\    |");
	diamondsSymbol.push_back("|  <  >   |");
	diamondsSymbol.push_back("|   \\/    |");
	diamondsSymbol.push_back("|         |");
	hiddenSymbol.push_back("|         |");  // Hidden symbol
	hiddenSymbol.push_back("|         |");
	hiddenSymbol.push_back("|   ???   |");
	hiddenSymbol.push_back("|         |");
	hiddenSymbol.push_back("|         |");
}

AsciiArt::~AsciiArt()
{
	// Blank
}

string AsciiArt::getCardHeader(int segment)
{
	return cardHeader.at(segment);
}

string AsciiArt::getCardFooter(int segment)
{
	return cardFooter.at(segment);
}

string AsciiArt::getTopRank(string rank)
{
	ostringstream result; // Create string stream
	result << "|" << rank;
	while (result.str().length() < 10) // Length of rank is not fixed
	{
		result << " ";
	}
	result << "|";
	return result.str();
}

string AsciiArt::getBottomRank(string rank)
{
	ostringstream result; // Create string stream
	result << "|";
	while (result.str().length() + rank.length() < 10) // Length of rank is not fixed
	{
		result << " ";
	}
	result << rank << "|";
	return result.str();
}

string AsciiArt::getClubsSymbol(int segment)
{
	return clubsSymbol.at(segment);
}

string AsciiArt::getHeartsSymbol(int segment)
{
	return heartsSymbol.at(segment);
}

string AsciiArt::getDiamondsSymbol(int segment)
{
	return diamondsSymbol.at(segment);
}

string AsciiArt::getSpadesSymbol(int segment)
{
	return spadesSymbol.at(segment);
}

string AsciiArt::getHiddenSymbol(int segment)
{
	return hiddenSymbol.at(segment);
}

unsigned int AsciiArt::getHeaderSize()
{
	return cardHeader.size();
}

unsigned int AsciiArt::getSymbolSize()
{
	return hiddenSymbol.size();
}

unsigned int AsciiArt::getFooterSize()
{
	return cardFooter.size();
}

string AsciiArt::printSymbol(string suit, int segment)
{
	/* Switch statements are evil */
	if (suit == "clubs")
	{
		return getClubsSymbol(segment);
	}
	else if (suit == "hearts")
	{
		return getHeartsSymbol(segment);
	}
	else if (suit == "diamonds")
	{
		return getDiamondsSymbol(segment);
	}
	else if (suit == "spades")
	{
		return getSpadesSymbol(segment);
	}
	else if (suit == "hidden")
	{
		return getHiddenSymbol(segment);
	}
	else
	{
		/* Just return something */
		return "Error: Not a valid suit";
	}
}
