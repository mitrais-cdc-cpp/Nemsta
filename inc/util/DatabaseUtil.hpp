#ifndef INC_UTIL_DATABASEUTIL_HPP_
#define INC_UTIL_DATABASEUTIL_HPP_

#include <DBFactory.hpp>
#include <MySQLFactory.hpp>

#include <iostream>
#include <memory>
#include <string>
#include <fstream>

enum class RDBMSType { MYSQL, MSSQLSERVER, POSTGRESQL, ORACLE, NOTDEFINED };

class DatabaseUtil {
 public:
  /**
   * Default constructor
   * @param dbConn: Database connection
   */
  DatabaseUtil();
  /// Default dtor
  ~DatabaseUtil();
  /// TODO: doc
  std::shared_ptr<DB::DBFactory> create(RDBMSType type);
};

#endif /* INC_UTIL_DATABASEUTIL_HPP_ */
