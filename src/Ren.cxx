#include "Ren.hxx" 

Ren::Ren() :
  mCurSeed(1337)
{
  if (!mCurSeed){
    generate();  
  } 
}

Ren::~Ren(){

}

void Ren::generate(){
  srand (mCurSeed);  
}

// TODO 
void Ren::set(double& r){
  r = 42.42; 
}

// TODO 
void Ren::set(float& r){
  r = 42.43; 
}

/** Get a random name */
std::string Ren::name() {
	using std::string;
	using std::vector;

	vector<string> vec({"Howard", "Sheldon", "Redcap", "Bluecap", "Johnny", 
	  "Jeremy", "Dave", "David", "Ernest", "Eric", "Fred", "George", "Igor",
		"Katrine", "Lenny", "Monstro", "Orpheus", "Preston", "Qadar", "Ren",
		"Solomon", "Tyresse", "Urly", "Xena"
	});

  return vec[getRange(vec.size())];
}

uint64_t Ren::getRange(uint64_t range){
  return rand() % range; 
}

char Ren::getSign() {
  return rand() % 2 == 0 ? -1 : 1; 
}

