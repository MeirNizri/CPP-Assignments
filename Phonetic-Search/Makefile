#!make -f

CXX=clang++-9 
CXXFLAGS=-std=c++2a

HEADERS=PhoneticFinder.hpp
OBJECTS=PhoneticFinder.o

run: test
	./$^

test: TestRunner.o Test_ofek.o Test_snir.o Test.o Test1.o Test2.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o test

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o test
