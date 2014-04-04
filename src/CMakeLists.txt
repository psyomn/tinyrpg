set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -lpthread -lsqlite3")
find_package(sqlite3)

add_executable(tinyrpg 
  main.cxx
  Battle.cxx
  Common.cxx
  Config.cxx
  DB.sqlite3.cxx
  Interface.cxx
  Inventory.cxx
  Item.cxx
  Org.cxx
  Ren.cxx
  Socket.cxx
  Tokenizer.cxx)

target_link_libraries(tinyrpg sqlite3)
