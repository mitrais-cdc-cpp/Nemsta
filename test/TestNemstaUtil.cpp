/*
 * TestNemstaUtil.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: Ari Suarkadipa
 */

#include "TestNemstaUtil.h"

using namespace Mitrais::Nemsta;

void TestNemstaUtil::testInitialFunction()
{
	NemstaUtil util;
	std::string result = util.captureTRAP();

	std::string actual = "TRAP captured";

	int status = result.compare(actual);

	CPPUNIT_ASSERT(status == 0);
}


