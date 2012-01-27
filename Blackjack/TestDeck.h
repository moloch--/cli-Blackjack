/*
 * TestDeck.h
 *
 *  Created on: Feb 6, 2011
 */

#ifndef TESTDECK_H_
#define TESTDECK_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Deck.h"
#include "Card.h"

class TestDeck: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(TestDeck);
    CPPUNIT_TEST(initalTest);
    CPPUNIT_TEST(dealCard);
    CPPUNIT_TEST(testShuffle);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void);
    void tearDown(void);
protected:
    void initalTest();
    void dealCard();
    void testShuffle();
private:
    Deck deck;
    Card card;
};

#endif /* TESTDECK_H_ */
