/*
 * TestDatabaseUtil.cpp
 *
 *  Created on: Sep 16, 2016
 *      Author: developer
 */

#include "TestDatabaseUtil.hpp"

void TestDatabaseUtil::testCreateDatabaseFactory() {
  // ARRANGE
  DatabaseUtil databaseUtil;
  bool connStatus = false;

  // ACT
  std::shared_ptr<DB::DBFactory> dbConn = databaseUtil.create(RDBMSType::MYSQL);
  if (dbConn) {
    connStatus = true;
  }

  // ASSERT
  CPPUNIT_ASSERT(connStatus == true);
}
