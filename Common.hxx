#ifndef COMMON_HXX
#define COMMON_HXX

class Common {
public: 
  static Common* Inst(); 
private: 
  static Common* com; 
};

#endif 

