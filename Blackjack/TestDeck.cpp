/***
 * TestDeck.cpp
 *
 *  Created on: Feb 6, 2011
 */

#include "TestDeck.h"
#include <iostream>

void TestDeck::setUp()
{
	deck.initialize();
}

void TestDeck::tearDown()
{
	// Blank
}

void TestDeck::initalTest()
{
	deck.initialize();
	CPPUNIT_ASSERT(deck.getSize() == 52);
}

void TestDeck::dealCard()
{
	card = deck.deal();
	CPPUNIT_ASSERT(card.getRank() == "2");
}

void TestDeck::testShuffle()
{
	deck.shuffle();
	CPPUNIT_ASSERT(deck.deal().getRank() != deck.deal().getRank());
}
