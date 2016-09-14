#include "../../inc/util/DatabaseUtil.hpp"

const char CONFIG_COMMENT_MARK = '#';
const char CONFIG_DELIMITER = '=';
const char* MYSQL_CONFIG_FILE_FULLPATH = "./mysql.config";

std::map<std::string, std::string> mysqlConfigValues;

DatabaseUtil::DatabaseUtil() {}

DatabaseUtil::~DatabaseUtil() {}

void extractMySqlCredentialFromConfigFile()
{
	std::ifstream mysqlConfigFile;

	mysqlConfigFile.open(MYSQL_CONFIG_FILE_FULLPATH, std::ios::in);

	std::string line;
	std::string key;
	std::string value;

	int lineMarkIndex = 0;
	int delimiterIndex = 0;

	if(mysqlConfigFile.is_open())
	{
		// can open the file. Read the content
		while(getline(mysqlConfigFile, line))
		{

			// ignore any line which started with a mark sign (#)
			lineMarkIndex = line.find(CONFIG_COMMENT_MARK);

			if(lineMarkIndex == 0)
			{
				continue;
			}

			// search the delimiter position to indicate the anchor to split the line to be key and value pair
			delimiterIndex = line.find(CONFIG_DELIMITER);

			// extract the key part
			key = line.substr(0, delimiterIndex);

			// extract the value part, remove the quotation marks (the last and the first one respectively)
			value = line.substr(delimiterIndex + 1, line.length() - delimiterIndex);
			value = value.erase(value.length()-1);
			value = value.erase(0, 1);

			// add the key value of the line into the map
			mysqlConfigValues.insert(std::pair<std::string, std::string>(key, value));
		}
	}

	mysqlConfigFile.close();
}

std::string getConfigValueByKey(std::string key)
{
	auto findResult = mysqlConfigValues.find(key);

	if(findResult != mysqlConfigValues.end())
	{
		// return the value
		return findResult->second;
	}
	else
	{
		// not found
		return "NOT FOUND!";
	}
}

std::shared_ptr<DB::DBFactory> DatabaseUtil::create(RDBMSType type) {

  extractMySqlCredentialFromConfigFile();

  std::string username = getConfigValueByKey("username");
  std::string password = getConfigValueByKey("password");
  std::string dbname = getConfigValueByKey("dbname");
  std::string host = getConfigValueByKey("host");

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
