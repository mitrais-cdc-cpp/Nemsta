#include "../../inc/util/DatabaseUtil.hpp"

DatabaseUtil::DatabaseUtil() {}

DatabaseUtil::~DatabaseUtil() {}

std::shared_ptr<DB::DBFactory> DatabaseUtil::create(RDBMSType type) {
  std::string username = "NemsTA";
  std::string password = "N3m5TA4adm1n";
  std::string dbname = "nemstadb";
  std::string host = "172.19.12.251";

  std::shared_ptr<DB::DBFactory> dbFactory;

  switch (type) {
    case RDBMSType::MYSQL: {
      dbFactory =
          std::make_shared<DB::MySQLFactory>(username, password, dbname, host);
      break;
    }
  }
  return dbFactory;
}
