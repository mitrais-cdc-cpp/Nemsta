#include "../../inc/util/DatabaseUtil.hpp"

DatabaseUtil::DatabaseUtil() {}

DatabaseUtil::~DatabaseUtil() {}

void DatabaseUtil::extractMySqlCredentialFromConfigFile()
{
	std::ifstream mysqlConfigFile;

	mysqlConfigFile.open(MYSQL_CONFIG_FILE_FULLPATH.c_str(), std::ios::in);

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

bool DatabaseUtil::getConfigValueByKey(const std::string key, std::string &value)
{
	auto findResult = mysqlConfigValues.find(key);

	if(findResult != mysqlConfigValues.end())
	{
		// return the value
		value = findResult->second;

		return true;
	}
	else
	{
		// not found
		return false;
	}
}

std::shared_ptr<DB::DBFactory> DatabaseUtil::create(RDBMSType type) {

  extractMySqlCredentialFromConfigFile();

  std::string username;
  if(!getConfigValueByKey("username", username))
  {
	  std::cout << "Missing database configuration item key 'username'" << std::endl;
  }
  std::cout<<username<<std::endl;

  std::string password;
  if(!getConfigValueByKey("password", password))
  {
	  std::cout << "Missing database configuration item key 'password'" << std::endl;
  }
  std::cout<<password<<std::endl;

  std::string dbname;
  if(!getConfigValueByKey("dbname", dbname))
  {
	  std::cout << "Missing database configuration item key 'dbname'" << std::endl;
  }
  std::cout<<dbname<<std::endl;

  std::string host;
  if(!getConfigValueByKey("host", host))
  {
	  std::cout << "Missing database configuration item key 'host'" << std::endl;
  }
  std::cout<<host<<std::endl;

  std::shared_ptr<DB::DBFactory> dbFactory;

  switch (type) {
    case RDBMSType::MYSQL:
      dbFactory =
          std::make_shared<DB::MySQLFactory>(username, password, dbname, host);
      break;
    case RDBMSType::MSSQLSERVER:
      dbFactory =
    	  std::make_shared<DB::MicrosoftSQLFactory>(username, password, dbname, host);
      break;
  }

  return dbFactory;
}
