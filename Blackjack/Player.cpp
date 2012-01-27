/*
 * Player.cpp
 *
 *  Created on: 2010-10-27
 */
#include <iostream>
#include <string>
#include "Player.h"

using std::cin;
using std::cout;
using std::endl;
using std::getline;

Player::Player(string name) // Overloaded Constructor
{
	setName(name);
}

Player::Player()
{
	setName("default"); // Create blank constructor for inherited classes
}

Player::~Player()
{
	// Auto-generated (Default)
}

void Player::setName(string player)
{
	playerName = player;
}

string Player::getName()
{
	return playerName;
}

int Player::getCurrentScore()
{
	return hand.getScore();
}

void Player::printCurrentHand()
{
	hand.printAsciiHand();
}

bool Player::isBust()
{
	return(getCurrentScore() > 21? true:false);
}

void Player::hideCard()
{
	hand.hideCard(0);
}

void Player::revealCard()
{
	hand.revealCard(0);
}

void Player::resetHand()
{
	while (0 < hand.getSize())
	{
		hand.removeCard();
	}
}

void Player::hit(Card card)
{
	if (card.getRank() == "A" && (hand.getScore() + 11) > 21)
	{
		card.setValue(1);
	}
	else if (card.getRank() == "A")
	{
		card.setValue(11);
	}
	hand.putInHand(card);
	if(isBust()) // Look for aces if player went bust from new card
	{
		for (unsigned int index = 0; index < hand.getSize(); ++index)
		{
			if (hand.getCardRank(index) == "A" && hand.getCardValue(index) == 11)
			{
				hand.setCardValue(index, 1); // Change ace's value to 1
			}
		}
	}
}

void Player::turn(Deck & deck)
{
	playTurn = true;
	while (playTurn)
	{
		printCurrentHand();
		cout << "Do you want to hit or stay? ";
		getline(cin, playerInput);
		if (playerInput == "h" || playerInput == "hit" || playerInput == "Hit")
		{
			hit(deck.deal());
			playTurn = !isBust(); // If the player busts, end their turn
		}
		else
		{
			playTurn = false; // User wants to stay, end their turn
		}
	}
}

/* Money Methods */
int Player::getWager()
{
	if (getMoney() > 50)
	{
		wager = 0;
		while(wager < 50 || getMoney() < wager)
		{
			cout << "How much would you like to wager (min. $50)? " << endl;
			cout << "You have $" << getMoney() << ": ";
			cin >> wager;
			cin.ignore();  // Drop newline char
		}
	}
	else
	{
		wager = getMoney();
	}
	cout << "Your wager is: $" << wager << endl;
	return wager;
}

void Player::setMoney(int amount)
{
	 money = amount;
}

int Player::getMoney()
{
	return money;
}

void Player::giveMoney(int amount)
{
	money += amount;
}

void Player::takeMoney(int amount)
{
	money -= amount;
}
