/*
 * TestDatabaseUtil.hpp
 *
 *  Created on: Sep 15, 2016
 *      Author: developer
 */

#ifndef TEST_TESTDATABASEUTIL_HPP_
#define TEST_TESTDATABASEUTIL_HPP_

#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include <memory>

#include "../env/SNMPDao/inc/DBFactory.hpp"
#include "../inc/util/DatabaseUtil.hpp"

class TestDatabaseUtil : public CppUnit::TestFixture {
 public:
  CPPUNIT_TEST_SUITE(TestDatabaseUtil);
  CPPUNIT_TEST(testCreateDatabaseFactory);
  CPPUNIT_TEST_SUITE_END();

 private:
  void testCreateDatabaseFactory();
};

CPPUNIT_TEST_SUITE_REGISTRATION(TestDatabaseUtil);

#endif /* TEST_TESTDATABASEUTIL_HPP_ */
