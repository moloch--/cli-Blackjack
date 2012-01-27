/*
 * Player.h
 *
 *  Created on: 2010-10-27
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>
#include "Deck.h"
#include "Hand.h"
#include "Card.h"

using std::string;
using std::vector;

class Player
{
public:
	Player();            // Default constructor
	Player(string name); // Create player with name
	virtual ~Player();

	void setName(string player);
	string getName();
	int getCurrentScore();
	void printCurrentHand();
	void resetHand();
	bool isBust();
	void hideCard();
	void revealCard();
	void hit(Card card);
	void turn(Deck & deck);
	int getWager();
	void setMoney(int amount);
	int getMoney();
	void takeMoney(int amount);
	void giveMoney(int amount);

private:
	bool playTurn;
	int visibleScore;
	int money;
	int wager;
	bool bust;
	string playerInput;
	string playerName;
	Hand hand;
};

#endif /* PLAYER_H_ */
