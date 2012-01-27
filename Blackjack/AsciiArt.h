/*
 * AsciiArt.h
 *
 *  Created on: Nov 20, 2010
 */

#ifndef ASCIIART_H_
#define ASCIIART_H_

#include <string>
#include <vector>

using std::string;
using std::vector;

class AsciiArt
{
public:
	AsciiArt();
	virtual ~AsciiArt();

	string getCardHeader(int segment);
	string getCardFooter(int segment);
	string getTopRank(string rank);
	string getBottomRank(string rank);
	string getClubsSymbol(int segment);
	string getHeartsSymbol(int segment);
	string getDiamondsSymbol(int segment);
	string getSpadesSymbol(int segment);
	string getHiddenSymbol(int segment);
	string printSymbol(string suit, int segment);
	unsigned int getHeaderSize();
	unsigned int getSymbolSize();
	unsigned int getFooterSize();

private:
	string topRank;    // Both topRank and bottomRank will always print one line
	string bottomRank;
	vector<string> cardHeader; // These will be one or more lines each
	vector<string> cardFooter;
	vector<string> clubsSymbol;  // All the symbols will be the same number of lines
	vector<string> heartsSymbol;
	vector<string> diamondsSymbol;
	vector<string> spadesSymbol;
	vector<string> hiddenSymbol;
};

#endif /* ASCIIART_H_ */
