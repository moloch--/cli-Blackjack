/***
 * TestHand.cpp
 *
 *  Created on: Feb 7, 2011
 */

#include "TestHand.h"

void TestHand::setUp()
{
	deck.initialize();
}

void TestHand::tearDown()
{
	// Blank
}

void TestHand::initalTest()
{
	hand.putInHand(deck.deal());
	CPPUNIT_ASSERT(hand.getSize() == 1);
}

void TestHand::scoreTest()
{
	deck.initialize();
	hand.putInHand(deck.deal());
	hand.putInHand(deck.deal());
	CPPUNIT_ASSERT(hand.getScore() == 5);
}
