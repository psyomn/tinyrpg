cd ../
make 
cd unit_tests
g++ ../obj/Ren.o random.cxx -o random
g++ ../obj/Org.o ../obj/Ren.o org.cxx -o org 
g++ ../obj/Tokenizer.o tokenizer.cxx -o tok
