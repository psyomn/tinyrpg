#ifndef COMMON_HXX
#define COMMON_HXX

class Common {
public: 
  static Common* Inst(); 
private: 
  Common();
  ~Common();
  static Common* com; 
};

#endif 

