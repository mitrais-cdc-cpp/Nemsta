#ifndef INC_UTIL_DATABASEUTIL_HPP_
#define INC_UTIL_DATABASEUTIL_HPP_

#include <DBFactory.hpp>
#include <MySQLFactory.hpp>
#include <MicrosoftSQLFactory.hpp>

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

 private:

  /*
   * The marking to indicate that any line prefixed with it will be considered as a comment only
   */
  const char CONFIG_COMMENT_MARK = '#';

  /*
   * The delimiter applied within a configuration file to separate the Key and Value pair within a single line
   */
  const char CONFIG_DELIMITER = '=';

  /*
   * The fullpath to the mysql credentials configuration. It is referring to the file at the same folder as the executable output filename
   */
  const std::string MYSQL_CONFIG_FILE_FULLPATH = "./mysql.config";

  /*
     * The fullpath to the mssql credentials configuration. It is referring to the file at the same folder as the executable output filename
     */
  const std::string MSSQL_CONFIG_FILE_FULLPATH = "./mssql.config";

  /*
   * The collection of all mysql configuration
   */
  std::map<std::string, std::string> mysqlConfigValues;

  /*
   * Extract the database credentials which are stored on a physical file into the memory variable
   */
  void extractMySqlCredentialFromConfigFile();

  /*
   * Get the value of the configuration based on the supplied key
   * @param key: the configuration key
   * @param value: the value that is referred by the supplied key
   */
  bool getConfigValueByKey(const std::string key, std::string &value);

};

#endif /* INC_UTIL_DATABASEUTIL_HPP_ */
