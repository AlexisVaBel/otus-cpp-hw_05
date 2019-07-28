mkdir ./build
cd ./build
cmake ..
make -j4
#doxygen ../doc/Doxyfile
#./matrix
ltrace -e malloc -e free ./matrix > /dev/null
#valgrind --tool=memcheck ./allocator 
#valgrind --leak-check=full -v  ./matrix
