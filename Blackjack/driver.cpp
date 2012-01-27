/***
 *   File Name: driver.cpp
 *
 *	     About: A card game in which a player attempts to get as close to 21
 *	     		without going over. The user plays against the dealer (computer).
 *
 * Source Info: Compiles and runs on Linux systems (gcc 4.4.5), should also compile
 *	     		on Windows and OSX machines but I have not tested those.  Added test
 *	     		cases, private copy constructors for certain classes, and betting.
 *
 *     Depends: CPPUNIT (also add -ldl to gcc flags on Linux systems)
 *
 *  Created on: 2011-2-5
 *
 *  Written by: Moloch
 */

#include <cppunit/ui/text/TestRunner.h>
#include <iostream>
#include <string>
#include "Blackjack.h"
#include "TestDeck.h"
#include "TestHand.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;

bool executeAllTests()
{
    CppUnit::TextUi::TestRunner runner;
    runner.addTest(TestDeck::suite());
    runner.addTest(TestHand::suite());
    return runner.run();
}

int main()
{
	string playAgain;
	bool playGame = true;
    if (executeAllTests())
    {
    	Blackjack game;
    	while (playGame)
    	{
    		game.playGame();
    		cout << "Would you like to play again? [Y/n]: ";
    		getline(cin, playAgain);
    		if (playAgain != "y" && playAgain != "Y") // Only check affirmative
    		{
    			playGame = false; // Stop playing game
    		}
    	}
	}
	return 0;
}

