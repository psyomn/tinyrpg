#ifndef DB_SQLITE3_CXX
#define DB_SQLITE3_CXX

#include "DB.sqlite3.hxx"

/** Constructor stuff */
DBSqlite3::DBSqlite3(std::string tname = "tinyrpg.main.db") : 
  mOpen(0),
  mRC(0), 
  mError(0){ 

  mRC = sqlite3_open(tname.c_str(), &mHandle);

  if(mRC) {
    std::cerr << "Error opening db : " << tname; 
    sqlite3_close(mHandle); 
  }

  else mOpen = 1; 

}

/** Destructor stuff */
DBSqlite3::~DBSqlite3(){
  sqlite3_close(mHandle);
  std::cout << "Database successfully closed. " << std::endl; 
}

/** Query whatever you want and need  */
int DBSqlite3::query(std::string query){
  mRC = sqlite3_get_table( mHandle, query.c_str(), &mResult, &mRows, &mCols, &mError ); 

  // Note: before was <, assumed for error code? But then it said that it's unsigned.
  // Keeping as > for now 
  
  if (mHead.size() > 0) mHead.clear(); 
  if (mData.size() > 0) mData.clear(); 

  if ( mRC == SQLITE_OK ){
    for (int i=0; i<mCols; ++i) 
      mHead.push_back(mResult[i]); 
    for (int j=0; j<mCols*mRows; ++j) 
      mData.push_back(mResult[mCols+j]); 
  }

  sqlite3_free_table(mResult); 
  return mRC; 
}


#endif 

