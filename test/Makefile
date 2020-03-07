

objects = test_example.o utils.o cppwrapper.o logger.o
test_example:$(objects)
	g++ $(objects) -o test_example
test_example.o:test_example.cpp
	g++ -std=c++11 -I../3rdparty/Catch2/single_include -Wall -c test_example.cpp -o test_example.o
	echo test_example.o done
utils.o:../src/Utils.cpp
	g++ -std=c++11 -c ../src/Utils.cpp -Wall -o utils.o
cppwrapper.o:../src/CppWrapper.cpp
	g++ -std=c++11 -c ../src/CppWrapper.cpp -Wall -o cppwrapper.o
logger.o:../src/Logger.cpp
	g++ -std=c++11 -c ../src/Logger.cpp -Wall -o logger.o
clean:
	- rm *.o test_example
