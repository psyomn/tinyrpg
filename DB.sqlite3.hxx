#ifndef DB_SQLITE3_HXX 
#define DB_SQLITE3_HXX

#include <iostream>
#include <string> 
#include <vector> 
#include <sqlite3.h> 

/** Helper class for database storage for different stuff for the game. */
class DBSqlite3 {
public:
  DBSqlite3(std::string);
  ~DBSqlite3(); 
  
  int query(std::string); 

private: 
  int mCols; /** Num of cols */
  int mRows; /** Num of rows*/
  int mOpen; /** DB open ? */
  int mRC; /** Return value */ 
  sqlite3* mHandle; 
  char *mError; 
  char **mResult; 

  std::vector<std::string> mHead; 
  std::vector<std::string> mData; 
};

#endif 

