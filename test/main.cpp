/*
 * main.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: Ari Suarkadipa
 */

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

int main()
{
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();

	runner.addTest( registry.makeTest() );
	bool wasSuccessful = runner.run();

	return 0;
}

