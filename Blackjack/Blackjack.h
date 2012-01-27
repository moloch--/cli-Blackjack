/***
 * Blackjack.h
 *
 *  Created on: 2010-10-26
 */

#ifndef BLACKJACK_H_
#define BLACKJACK_H_

#include <vector>
#include <string>
#include "Dealer.h"
#include "Player.h"
#include "Deck.h"

using std::string;
using std::vector;

class Blackjack
{
public:
	Blackjack();
	virtual ~Blackjack();

	void playGame();

private:
	int dealerWins;
	int playerWins;
	int wager;
	bool playTurn;
	Deck deck;
	string userInput;
    void findWinner(Player & player, Dealer & dealer);
    void startTurn(Player & player, Dealer & dealer);
    void initialDeal(Player & player, Dealer & dealer);
	string getStringFromUser(string prompt);
};

#endif /* BLACKJACK_H_ */
