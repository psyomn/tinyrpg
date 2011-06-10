#include <iostream>
#include "../Ren.hxx" 

int main(){
  Ren ren;  
  int i; 
  short j; 
  char a; 
  long l; 
  long long ll; 
  unsigned int ui;
  unsigned long ul; 
  double d; 
  float f; 

  ren.set(i); 
  ren.set(j); 
  ren.set(a); 
  ren.set(l); 
  ren.set(ll);
  ren.set(ui); 
  ren.set(ul); 
  ren.set(d); 
  ren.set(f); 

  std::cout << i << std::endl; 
  std::cout << j << std::endl; 
  std::cout << a << std::endl; 
  std::cout << l << std::endl; 
  std::cout << ll << std::endl; 
  std::cout << ui << std::endl; 
  std::cout << ul << std::endl; 
  std::cout << d << std::endl; 
  std::cout << f << std::endl; 


  return 0; 
}
