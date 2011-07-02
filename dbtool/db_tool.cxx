#include <iostream>
#include <string> 
#include <vector>
#include <fstream>
#include <sstream> 

#include "../DB.sqlite3.hxx"


/** This assumes you're not a retard and feed it addresses which do not exist. Counts
10 interations forward */
std::string sql_quotes(std::vector<std::string>& tenlist, int position){
  std::string result;

  result = "(\'"; 

  for (int j=0; j<10; ++j){
    result += tenlist[position+j];
    if (j+1!=10) result += "\', \'"; 
  }

  result += "\')"; 

  return result;
}

/** This is simply a quick tool designed to create, and poppulate a sqlite3 database. 
In other words, you'll find all sorts of bad coding in here, but I don't really care 
because this is not the point. 
*/

int main(){
  DBSqlite3 *db;  // initialize with standard stuff
  std::ifstream ifs; 
  std::ifstream check_db; 
  std::ofstream debug("log.txt"); 
  std::string choice; 
  std::string token; 
  std::string query; 
  std::vector<std::string> flat_vec; 
  int i = 0;   // Looping 
  
  std::cout << "This is a tool to generate and poppulate a database with\n"
  << "enemy player information. Do you wish to continue? [y/n] : " << std::endl;

  std::cin >> choice; 

  if (!(choice == "yes" || choice == "y")){
    std::cout << "Aborted" << std::endl; 
    return -1; 
  }

  // Else! 

  ifs.open("tinyrpg.enemies.db.txt"); 

  if(!ifs) {
    std::cout << "Problem opening flat file" << std::endl; 
    return -1; 
  }

  check_db.open("tinyrpg.sqlite3"); 

  if(check_db) {
    std::cout << "Datbase exists. Delete it and re-run this program" << std::endl; 
    return -1; 
  }
  
  check_db.close(); 

  // Now let's read and store the records! 

  while(ifs >> token){
    flat_vec.push_back(token); 
  }
  
  // Done storing in memory, now store in table

  ifs.close(); 

  std::cout << "There should be " << flat_vec.size() / 10 << " records. " << std::endl; 
  std::cout << "Processing DB generation and poppulation ... "; std::cout.flush(); 

  db = new DBSqlite3("tinyrpg.sqlite3"); 
  
  // Create the table to store the information. 
  db->query("CREATE TABLE Enemies (id int unsigned auto_increment unique, name varchar(50),  \
  attack int unsigned, defense int unsigned, stamina int unsigned, hitpoints int unsigned, \
  speed int unigned, class tinyint unsigned, ally tinyint unsigned, distortion tinyint unsigned, \
  experience bigint unsigned, primary key(id) ); "); 

  std::cout << "[DONE]" << std::endl; 
  std::cout << "Poppulating datbase now ... ";
  std::cout.flush(); 
  // Now dump all the info inside the db! 
  for (i=0; i<flat_vec.size(); i+=10){
    query = "INSERT INTO Enemies (name,attack,defense,stamina,hitpoints,speed,class,ally,distortion,experience) values ";
    query += sql_quotes(flat_vec, i) + "; "; // This returns a string as -> ('asdasd','asdasd','asdasd') 
    db->query(query.c_str());
  }

  std::cout << "[DONE]" << std::endl; 

  std::cout << "Creating the Users table ... "; std::cout.flush(); 

  // Users should have a username and a password. They also must have an id to refer to their character. 

  std::cout << "[DONE]" << std::endl;

  delete db; // We no longer need the db object 

  return 0; 
}

