/***
 * TestHand.h
 *
 *  Created on: Feb 7, 2011
 */

#ifndef TESTHAND_H_
#define TESTHAND_H_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "Hand.h"
#include "Deck.h"
#include "Card.h"

class TestHand: public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE(TestHand);
    CPPUNIT_TEST(initalTest);
    CPPUNIT_TEST(scoreTest);
    CPPUNIT_TEST_SUITE_END();
public:
    void setUp(void);
    void tearDown(void);
protected:
    void initalTest();
    void scoreTest();
private:
    Deck deck;
    Hand hand;
};

#endif /* TESTHAND_H_ */
