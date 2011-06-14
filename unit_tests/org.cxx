#include <iostream> 
using namespace std;

#include "../Org.hxx"

int main() {

  Org o; 

  o.rand(); 

  cout << o.to_s() << endl;
  cout << o.attack() << endl; 
  cout << o.attack() << endl; 
  cout << o.attack() << endl; 
  cout << o.attack() << endl; 

  return 0; 

}
