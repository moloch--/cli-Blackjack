/***
 * Blackjack.cpp
 *
 *  Created on: 2010-10-26
 */
#include <iostream>
#include <string>
#include "Blackjack.h"
#include "Dealer.h"
#include "Player.h"
#include "Deck.h"

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

Blackjack::Blackjack()
{
	cout << " >> Welcome to Black Jack C++ >> " << endl;
	playerWins = 0; // Both players start at 0 wins
	dealerWins = 0;
}

Blackjack::~Blackjack()
{
	cout << " << Thanks for playing Black Jack C++ << " << endl;
}

void Blackjack::initialDeal(Player & player, Dealer & dealer)
{
    player.hit(deck.deal()); // Deal two cards to the player(s)
    player.hit(deck.deal());
    dealer.hit(deck.deal()); // Deal two cards to the dealer
    dealer.hit(deck.deal());
    dealer.hideCard();       // Hide dealer's card
}

void Blackjack::findWinner(Player & player, Dealer & dealer)
{
    if(player.isBust()) // Check to see if player busted during their turn
    {
        cout << "\n***** [ " << player.getName() << " busted ] *****" << endl;
        player.printCurrentHand();
    }
    else
    {
        dealer.turn(deck, player.getCurrentScore());
    }
    cout << dealer.getName() << " has:" << endl;
    dealer.printCurrentHand();
    /* Find winner and print the results on stdout, remember house wins on a tie */
    if((player.getCurrentScore() > dealer.getCurrentScore() || dealer.isBust()) && !player.isBust())
    {
        cout << player.getName() << " has won the game!" << endl;
        player.giveMoney(wager);
        playerWins++;
    }
    else
    {
        cout << dealer.getName() << " has won the game!" << endl;
        player.takeMoney(wager);
        dealerWins++;
    }
}

void Blackjack::startTurn(Player & player, Dealer & dealer)
{
	deck.initialize();
    deck.shuffle(); // Shuffle the deck
    initialDeal(player, dealer);
    cout << dealer.getName() << " is showing:" << endl;
    dealer.printCurrentHand();
    cout << player.getName() << " is showing:" << endl;
    player.printCurrentHand();
    wager = player.getWager();
    player.turn(deck);  // Give player a turn
    dealer.revealCard(); // Reveal dealer's card
    findWinner(player, dealer);
    cout << "\tTotal " << player.getName() << " wins: " << playerWins;
    cout << " ($" << player.getMoney() << ")" << endl;
    cout << "\tTotal " << dealer.getName() << " wins: " << dealerWins << endl;
    cout << "\nPress enter to continue." << endl;
    player.resetHand();
    dealer.resetHand();
    cin.get();   // Pause console output until next user input
}

void Blackjack::playGame()
{
	Dealer dealer("HAL 9000"); // Create the dealer
	Player player1("Weak Human"); // Create the player(s)
	player1.setMoney(1000);
	while (player1.getMoney() > 0)
	{
		startTurn(player1, dealer);
	}
	cout << "\n [!] You have lost all your money!" << endl;
}

string Blackjack::getStringFromUser(string prompt)
{   /* Prompts the user with the provided string, and returns their input */
	cout << prompt;
	getline(cin, userInput);
	return userInput;
}
