/*
 * TestNemstaUtil.h
 *
 *  Created on: Aug 16, 2016
 *      Author: developer
 */

#ifndef TEST_TESTNEMSTAUTIL_H_
#define TEST_TESTNEMSTAUTIL_H_


#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>

#include "../inc/util/NemstaUtil.h"


class TestNemstaUtil: public CppUnit::TestFixture
{
public:

	CPPUNIT_TEST_SUITE(TestNemstaUtil);
	CPPUNIT_TEST(testInitialFunction);
	CPPUNIT_TEST_SUITE_END();


private:
	void testInitialFunction();

};

CPPUNIT_TEST_SUITE_REGISTRATION( TestNemstaUtil );


#endif /* TEST_TESTNEMSTAUTIL_H_ */
