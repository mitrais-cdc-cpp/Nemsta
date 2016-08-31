//============================================================================
// Name        : main.cpp
// Author      : Ari Suarkadipa
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <fstream>
#include <iostream>
#include <memory>
#include <odb/transaction.hxx>
#include "env/SNMPDao/inc/DBFactory.hpp"
#include "env/SNMPDao/inc/Entity/NetworkElement.hpp"
#include "env/SNMPDao/inc/MySQLFactory.hpp"
#include "env/SNMPDao/inc/odb_gen/NetworkElement_odb.h"

using namespace odb::core;
using namespace Mitrais::SNMPDao::Entity;
int main() {
  std::ofstream myfile("example.txt");

  std::cout << "Creating the file" << std::endl;
  if (myfile.is_open()) {
    myfile << "This is a line.\n";
    myfile << "This is another line.\n";
    myfile.close();
  } else
    std::cout << "Unable to open file";

  // Test to create database connection
  std::unique_ptr<DB::DBFactory> dbFactory(new DB::MySQLFactory(
      "NemsTA", "N3m5TA4adm1n", "nemstadb", "172.19.12.251"));
  std::unique_ptr<database> dbConn(dbFactory->createDatabase());
  if (dbConn) {
    std::cout << "Connection Ok" << std::endl;
  }

  // create transaction
  transaction t(dbConn->begin());
  NetworkElement element1("element1", "DA:DB:32:34", "172.19.12.251");
  dbConn->persist(element1);
  t.commit();
  return 0;
}
